ifeq ($(BOARD_WLAN_DEVICE),bcmdhd)
    include $(call all-subdir-makefiles)
else ifneq ($(filter x86%,$(TARGET_ARCH)),)
    include $(call all-named-subdir-makefiles,wpa_supplicant_8_lib)
endif
