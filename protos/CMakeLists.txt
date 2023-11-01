# Copyright 2023-11-02 skylanwei 
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
project(libgrpc_proto.a C CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)

# Generated sources
#execute_process(COMMAND sh compile_protos.sh)

# Include generated files
set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/lib")
include_directories("/usr/local/grpc/include/")
aux_source_directory("protos_pkg" pb_src)
add_library(grpc_proto STATIC ${pb_src})

