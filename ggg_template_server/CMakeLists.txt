# Copyright 2018 gRPC authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

cmake_minimum_required(VERSION 3.8)
project(GggTemplateServer C CXX)
include(../cmake/common.cmake)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(server_name "ggg_template_server")
set(pb_pkg "../protos/protos_pkg")

## Include generated *.pb.h files
#include_directories("${CMAKE_CURRENT_BINARY_DIR}/${pb_pkg}/")
file(GLOB pb_inc "${pb_pkg}/*.h")
file(GLOB pb_src "${pb_pkg}/*.cc")
add_library(grpc_proto STATIC ${pb_inc} ${pb_src})
target_link_libraries(grpc_proto
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})


add_executable(${server_name})
aux_source_directory(src source)
target_sources(${server_name} PUBLIC ${source})
target_link_libraries(${server_name}
    grpc_proto
    absl::flags
    absl::flags_parse
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF})

