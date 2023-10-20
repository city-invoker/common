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
set(pb_src "pkg_config")
# Proto file
get_filename_component(us_proto "../protos/${server_name}.proto" ABSOLUTE)
get_filename_component(us_proto_path "${us_proto}" PATH)


# Generated sources

set(us_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/${pb_src}/${server_name}.pb.cc")
set(us_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/${pb_src}/${server_name}.pb.h")
set(us_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/${pb_src}/${server_name}.grpc.pb.cc")
set(us_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/${pb_src}/${server_name}.grpc.pb.h")
add_custom_command(
      OUTPUT "${us_proto_srcs}" "${us_proto_hdrs}" "${us_grpc_srcs}" "${us_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}/${pb_src}/"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}/${pb_src}/"
        -I "${us_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${us_proto}"
      DEPENDS "${us_proto}")

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}/${pb_src}/")

# us_grpc_proto
add_library(us_grpc_proto
  ${us_grpc_srcs}
  ${us_grpc_hdrs}
  ${us_proto_srcs}
  ${us_proto_hdrs})
target_link_libraries(us_grpc_proto
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})


add_executable(${server_name})
aux_source_directory(src source)
target_sources(${server_name} PUBLIC ${source})
target_link_libraries(${server_name}
    us_grpc_proto
    absl::flags
    absl::flags_parse
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF})

