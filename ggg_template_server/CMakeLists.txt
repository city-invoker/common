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
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_BINARY_DIR}/bin") 

find_library(pb_lib grpc_proto "../protos/lib/")
#link_directories("/usr/local/lib/")
include_directories("lib")
add_executable(${server_name})
aux_source_directory(src source)
target_sources(${server_name} PUBLIC ${source})
target_link_libraries(${server_name}
    ${pb_lib}
    absl::flags_parse
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF}
    -lglog
    )

