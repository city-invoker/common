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
# cmake build file for C++ ggg_user_server example.
# Assumes protobuf and gRPC have been installed using cmake.
# See cmake_externalproject/CMakeLists.txt for all-in-one cmake build
# that automatically builds all the dependencies before building ggg_user_server.

cmake_minimum_required(VERSION 3.8)

project(GggUserServer C CXX)

include(../cmake/common.cmake)

# Proto file
get_filename_component(us_proto "../protos/ggg_user_server.proto" ABSOLUTE)
get_filename_component(us_proto_path "${us_proto}" PATH)


# Generated sources

set(us_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/pkg_config/ggg_user_server.pb.cc")
set(us_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/pkg_config/ggg_user_server.pb.h")
set(us_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/pkg_config/ggg_user_server.grpc.pb.cc")
set(us_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/pkg_config/ggg_user_server.grpc.pb.h")
add_custom_command(
      OUTPUT "${us_proto_srcs}" "${us_proto_hdrs}" "${us_grpc_srcs}" "${us_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}/pkg_config/"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}/pkg_config/"
        -I "${us_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${us_proto}"
      DEPENDS "${us_proto}")

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}/pkg_config/")

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


add_executable(ggg_user_server)
aux_source_directory(src source)
target_sources(ggg_user_server PUBLIC ${source})
target_link_libraries(ggg_user_server
    us_grpc_proto
    absl::flags
    absl::flags_parse
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF})


#set(service_cc "${CMAKE_CURRENT_BINARY_DIR}/src/ggg_user_service_impl.cc")
#add_library(service
#  ${service_cc}
#  )
#target_link_libraries(service
#  ${_REFLECTION}
#  )
#
#
## Targets ggg_user_server 
#foreach(_target
#  ggg_user_server
#  )
#  add_executable(${_target} "src/${_target}.cc")
#  target_link_libraries(${_target}
#    service
#    us_grpc_proto
#    absl::flags
#    absl::flags_parse
#    ${_REFLECTION}
#    ${_GRPC_GRPCPP}
#    ${_PROTOBUF_LIBPROTOBUF})
#endforeach()
