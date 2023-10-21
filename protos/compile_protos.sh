#!/bin/sh


cmd_dir=`dirname $0`
echo "start to compile proto files: \n`ls ${cmd_dir}/*.proto`"

out_path="${cmd_dir}/protos_pkg"

if [ ! -d ${out_path} ]; then
  echo "mkdir -p ${out_path}"
  mkdir ${out_path}
fi

for file in `ls ${cmd_dir}/*.proto`
do
  protoc-24.0.0 --grpc_out ${out_path} --cpp_out ${out_path} -I . --plugin=protoc-gen-grpc="/usr/local/grpc/bin/grpc_cpp_plugin" ${file} 
done
