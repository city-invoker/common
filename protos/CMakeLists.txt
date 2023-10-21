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
project(protos_pkg C CXX)
include(../cmake/common.cmake)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(pb_pkg "${CMAKE_CURRENT_BINARY_DIR}/protos_pkg")

## Include generated *.pb.h files
#include_directories("${CMAKE_CURRENT_BINARY_DIR}/${pb_pkg}/")
file(GLOB pb_inc "${pb_pkg}/*.h")
file(GLOB pb_src "${pb_pkg}/*.cc")
set(LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_BINARY_DIR}/lib")
add_library(grpc_proto STATIC ${pb_inc} ${pb_src})
target_link_libraries(grpc_proto
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})

