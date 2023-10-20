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
project(GggUserServer C CXX)
include(../cmake/common.cmake)

set(server_name "ggg_user_server")
set(pb_inc "../protos_include")
# Proto file
get_filename_component(proto "../protos/${server_name}.proto" ABSOLUTE)
get_filename_component(proto_path "${proto}" PATH)


# Generated sources

set(proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/${pb_inc}/${server_name}.pb.cc")
set(proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/${pb_inc}/${server_name}.pb.h")
set(grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/${pb_inc}/${server_name}.grpc.pb.cc")
set(grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/${pb_inc}/${server_name}.grpc.pb.h")
add_custom_command(
      OUTPUT "${proto_srcs}" "${proto_hdrs}" "${grpc_srcs}" "${grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}/${pb_inc}/"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}/${pb_inc}/"
        -I "${proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${proto}"
      DEPENDS "${proto}")

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}/${pb_inc}/")

# grpc_proto
add_library(grpc_proto
  ${grpc_srcs}
  ${grpc_hdrs}
  ${proto_srcs}
  ${proto_hdrs})
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

