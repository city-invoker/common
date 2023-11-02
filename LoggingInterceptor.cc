/*
 *
 * Copyright 2023-11-02 skylanwei 
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "LoggingInterceptor.h"


using grpc::experimental::InterceptionHookPoints;

void LoggingInterceptor::Intercept(InterceptorBatchMethods* methods) {
  if (methods->QueryInterceptionHookPoint(InterceptionHookPoints::POST_RECV_MESSAGE)) {
      //TODO GLOG info
      //TODO add request_id in metadata if there isn't any
  }
  methods->Proceed();
}


