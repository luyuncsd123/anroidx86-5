//
// Copyright (C) 2014 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "shill/net/io_handler_factory.h"

#include "shill/net/io_input_handler.h"
#include "shill/net/io_ready_handler.h"

namespace shill {

IOHandlerFactory::IOHandlerFactory() {}
IOHandlerFactory::~IOHandlerFactory() {}

IOHandler* IOHandlerFactory::CreateIOInputHandler(
    int fd,
    const IOHandler::InputCallback& input_callback,
    const IOHandler::ErrorCallback& error_callback) {
  IOHandler* handler = new IOInputHandler(fd, input_callback, error_callback);
  handler->Start();
  return handler;
}

IOHandler* IOHandlerFactory::CreateIOReadyHandler(
    int fd,
    IOHandler::ReadyMode mode,
    const IOHandler::ReadyCallback& ready_callback) {
  IOHandler* handler = new IOReadyHandler(fd, mode, ready_callback);
  handler->Start();
  return handler;
}

}  // namespace shill
