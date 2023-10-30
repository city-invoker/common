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

#include "ggg_template_service_impl.h"
#include <grpc/support/log.h>


grpc::Status GggTemplateServiceImpl::TemplateReqHandler(grpc::ServerContext* context, const ggg_template_server::TemplateReq* request, ggg_template_server::TemplateRsp* response) {

  gpr_log(GPR_INFO, "TemplateReq service process");

  response->set_uid(request->uid());
  response->set_message(request->uid() + ":message info, everything is ok!");
  response->set_extra(request->sid());

  gpr_log(GPR_INFO, "TemplateReq service end");

  return grpc::Status::OK;
}


