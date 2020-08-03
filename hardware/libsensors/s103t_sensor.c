/*
 * s103t_sensor.c
 *
 *      Created on: 19.04.2011
 *      Author: Oliver Dill (oliver@ratio-informatik.de)
 *      Licensed under GPLv2 or later
 */

#define LOG_TAG "S103TSensors"

#include <inttypes.h>
#include <linux/types.h>
#include <linux/input.h>
#include <fcntl.h>
#include <cutils/sockets.h>
#include <cutils/log.h>
#include <cutils/native_handle.h>
#include <dirent.h>
#include <math.h>
#include <hardware/sensors.h>

#define DRIVER_DESC             "Lenovo front-screen buttons driver"
#define SKEY_ROTATE_MAPPING     KEY_F12
#define ID_ACCELERATION         (SENSORS_HANDLE_BASE + 0)

typedef struct SensorContext {
    struct sensors_poll_device_1 device;
    int fd;
    uint32_t active_sensors;
    sensors_event_t orientation;
    struct timespec delay;
} SensorContext;

static int context__activate(struct sensors_poll_device_t *dev, int handle, int enabled)
{
    ALOGD("%s: called", __FUNCTION__);
    return 0;
}

static int context__setDelay(struct sensors_poll_device_t *dev, int handle, int64_t ns)
{
    ALOGD("%s: called", __FUNCTION__);
    return 0;
}

static int context__close(struct hw_device_t *dev)
{
    ALOGD("%s: called", __FUNCTION__);
    return 0;
}

static int context__poll(struct sensors_poll_device_t *dev, sensors_event_t* data, int count)
{
    bool bChanged = false;
    SensorContext* ctx = (SensorContext*) dev;
    ALOGD("%s: dev=%p data=%p count=%d", __FUNCTION__, dev, data, count);
    while (1) {
        struct input_event iev;
        size_t res = read(ctx->fd, &iev, sizeof(iev));
        if (res == sizeof(iev)) {
            const double angle = 20.0;
            const double cos_angle = GRAVITY_EARTH * cos(angle / M_PI);
            const double sin_angle = GRAVITY_EARTH * sin(angle / M_PI);
            if (iev.type == EV_KEY) {
                ALOGD("type=%d scancode=%d value=%d from fd=%d", iev.type, iev.code, iev.value, ctx->fd);
                if (iev.code == SKEY_ROTATE_MAPPING && iev.value == 1) {
                    if (ctx->orientation.acceleration.x != 0.0) {
                        // ROT_0
                        ctx->orientation.acceleration.x = 0.00;
                        ctx->orientation.acceleration.y = cos_angle;
                        ctx->orientation.acceleration.z = sin_angle;
                    } else {
                        // ROT_90
                        ctx->orientation.acceleration.x = cos_angle;
                        ctx->orientation.acceleration.y = 0.00;
                        ctx->orientation.acceleration.z = sin_angle;
                    }
                    bChanged = true;
                }
            }
            else if (iev.type == EV_SW) {
                ALOGD("%s: switching to/from Table Mode type=%d scancode=%d value=%d", __FUNCTION__,iev.type, iev.code, iev.value);
                if (iev.value == 0) {
                    // ROT_0
                    ctx->orientation.acceleration.x = 0.00;
                    ctx->orientation.acceleration.y = cos_angle;
                    ctx->orientation.acceleration.z = sin_angle;
                } else {
                    // ROT_90
                    ctx->orientation.acceleration.x = cos_angle;
                    ctx->orientation.acceleration.y = 0.00;
                    ctx->orientation.acceleration.z = sin_angle;
                }
                bChanged = true;
            }
            if (bChanged) {
                nanosleep(&ctx->delay, 0);
                ALOGI("orientation changed");
                data[0] = ctx->orientation;
                data[0].timestamp = iev.time.tv_sec*1000000000LL + iev.time.tv_usec*1000; 
                data[1] = ctx->orientation;
                data[1].timestamp = data[0].timestamp + 200000000LL;
                data[2] = ctx->orientation;
                data[2].timestamp = data[1].timestamp + 200000000LL;
                return 3;
            }
        }
    }
}

static int context__batch(struct sensors_poll_device_1* dev, int sensor_handle,
		int flags, int64_t sampling_period_ns, int64_t max_report_latency_ns)
{
    ALOGD("%s: dev=%p sensor_handle=%d flags=%d sampling_period_ns=%" PRId64 " max_report_latency_ns=%" PRId64,
            __FUNCTION__, dev, sensor_handle, flags, sampling_period_ns, max_report_latency_ns);
    return EXIT_SUCCESS;
}

static int context__flush(struct sensors_poll_device_1* dev, int sensor_handle)
{
    ALOGD("%s: dev=%p sensor_handle=%d", __FUNCTION__, dev, sensor_handle);
    return EXIT_SUCCESS;
}

static const struct sensor_t sSensorListInit[] = {
    { .name =
        "S103T Orientation sensor",
        .vendor = "Oliver Dill",
        .version = 1,
        .handle = ID_ACCELERATION,
        .type = SENSOR_TYPE_ACCELEROMETER,
        .maxRange = 2.8f,
        .resolution = 1.0f/4032.0f,
        .power = 3.0f,
        .reserved = { }
    },
};

static int sensors__get_sensors_list(struct sensors_module_t* module, struct sensor_t const** list)
{
    ALOGD("%s: sensors__get_sensors_list called", __FUNCTION__);
    // there is exactly one sensor available, the accelerometer sensor
    *list = sSensorListInit;
    return 1;
}

static int open_sensors(const struct hw_module_t* module, const char* id, struct hw_device_t **device)
{
    ALOGD("%s: id=%s", __FUNCTION__, id);

    SensorContext *ctx = malloc(sizeof(*ctx));
    if (!ctx)
        return -EINVAL;

    ALOGD("%s: init sensors device", __FUNCTION__);
    memset(ctx, 0, sizeof(*ctx));

    ctx->device.common.tag = HARDWARE_DEVICE_TAG;
    ctx->device.common.version = SENSORS_DEVICE_API_VERSION_1_3;
    ctx->device.common.module = (struct hw_module_t*) module;
    ctx->fd = -1;
    const char *dirname = "/dev/input";
    DIR *dir = opendir(dirname);
    if (dir != NULL) {
        struct dirent *de;
        // loop over all "eventXX" in /dev/input and look for our driver
        ALOGD("%s: looping over all eventXX...", __FUNCTION__);
        while ((de = readdir(dir))) {
            if (de->d_name[0] != 'e') // eventX
                continue;
            char name[PATH_MAX];
            snprintf(name, PATH_MAX, "%s/%s", dirname, de->d_name);
            ALOGD("%s: open device %s", __FUNCTION__, name);
            ctx->fd = open(name, O_RDWR);
            if (ctx->fd < 0) {
                ALOGE("could not open %s, %s", name, strerror(errno));
                continue;
            }
            name[sizeof(name) - 1] = '\0';
            if (ioctl(ctx->fd, EVIOCGNAME(sizeof(name) - 1), &name) < 1) {
                ALOGE("could not get device name for %s, %s\n", name, strerror(errno));
                name[0] = '\0';
            }

            if (!strcmp(name, DRIVER_DESC)) {
                // ok, it's our driver, stop the loop ...
                ALOGI("found device %s", name);
                break;
            }
            close(ctx->fd);
        }
        ALOGD("%s: stop loop and closing directory", __FUNCTION__);
        closedir(dir);
    }

    ctx->device.common.close = context__close;
    ctx->device.activate = context__activate;
    ctx->device.setDelay = context__setDelay;
    ctx->device.poll = context__poll;
    ctx->device.batch = context__batch;
    ctx->device.flush = context__flush;
    ctx->orientation.version = sizeof(sensors_event_t);
    ctx->orientation.sensor = ID_ACCELERATION;
    ctx->orientation.type = SENSOR_TYPE_ACCELEROMETER;
    ctx->orientation.acceleration.status = SENSOR_STATUS_ACCURACY_HIGH;
    ctx->delay.tv_sec = 0;
    ctx->delay.tv_nsec = 300000000L;

    *device = &ctx->device.common;

    return 0;
}

static struct hw_module_methods_t sensors_module_methods = {
   .open = open_sensors
};

struct sensors_module_t HAL_MODULE_INFO_SYM = {
    .common = {
        .tag = HARDWARE_MODULE_TAG,
        .module_api_version = 1,
        .hal_api_version = 0,
        .id = SENSORS_HARDWARE_MODULE_ID,
        .name = "s103t SENSORS Module",
        .author = "Oliver Dill",
        .methods = &sensors_module_methods,
        .dso = 0,
        .reserved = { }
    },
    .get_sensors_list = sensors__get_sensors_list
};
