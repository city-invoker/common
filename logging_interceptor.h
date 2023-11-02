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

#ifndef GGG_PROJECT_COMMON_LOGGING_INTERCEPTOR_H
#define GGG_PROJECT_COMMON_LOGGING_INTERCEPTOR_H

#include <grpcpp/grpcpp.h>


using grpc::experimental::Interceptor;
using grpc::experimental::InterceptorBatchMethods;
using grpc::experimental::ServerInterceptorFactoryInterface;
using grpc::experimental::ServerRpcInfo;

// This is a interceptor that logs whenever it gets a request, which on
// the server side happens when initial metadata is received.
class LoggingInterceptor : public Interceptor {
  public:
    void Intercept(InterceptorBatchMethods* methods) override;
};

class LoggingInterceptorFactory : public ServerInterceptorFactoryInterface {
 public:
  Interceptor* CreateServerInterceptor(ServerRpcInfo* info) override {
    return new LoggingInterceptor();
  }
};

#endif // GGG_PROJECT_COMMON_LOGGING_INTERCEPTOR_H
