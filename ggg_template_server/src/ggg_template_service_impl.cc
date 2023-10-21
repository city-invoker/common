#include "ggg_template_service_impl.h"


grpc::Status GggTemplateServiceImpl::TemplateReqService(grpc::ServerContext* context, const ggg_template_server::TemplateReq* request, ggg_template_server::TemplateRsp* response) {
  return grpc::Status::OK;
}


