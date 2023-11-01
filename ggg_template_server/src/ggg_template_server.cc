/*
 *
 * Copyright 2023 skylanwei.
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

#include <iostream>
#include <memory>
#include <string>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/strings/str_format.h"

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include <glog/logging.h>

#include "../../protos/protos_pkg/ggg_template_server.grpc.pb.h"
#include "ggg_template_service_impl.h"


ABSL_FLAG(uint16_t, port, 50051, "Server port for the service");

void RunServer(uint16_t port) {


  std::string server_address = absl::StrFormat("0.0.0.0:%d", port);
  GggTemplateServiceImpl service;
  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  grpc::ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

void CustomPrefix(std::ostream &s, const google::LogMessageInfo &l, void*) {
  s << "" 
    << "[" << std::setw(4) << 1900 + l.time.year() << "-"
    << std::setw(2) << 1 + l.time.month() << "-"
    << std::setw(2) << l.time.day() << " "
    << std::setw(2) << l.time.hour() << ":" 
    << std::setw(2) << l.time.min()  << ":" 
    << std::setw(2) << l.time.sec() << "."
    << std::setw(6) << l.time.usec() << "]"
    << "[" << std::setfill(' ') << std::setw(5)
    << l.thread_id << std::setfill('0') << "]"
    << "[" << l.filename << ':' << l.line_number << "]"
    << "[" << __func__ << "]"
    << "[" << l.severity[0] << "]";
}

void InitLogConfig(int argc, char** argv) {
  //google::DisableLogCleaner();
  //google::SetLogDestination();
  //google::SetBaseName(argv[0]);
  InitGoogleLogging(argv[0], &CustomPrefix);
}


int main(int argc, char** argv) {

  //google::SetLogDestination();
  InitGoogleLogging(argv[0], &CustomPrefix);
  absl::ParseCommandLine(argc, argv);
  RunServer(absl::GetFlag(FLAGS_port));
  return 0;
}
