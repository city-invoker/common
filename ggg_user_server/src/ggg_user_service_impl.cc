#include "ggg_user_service_impl.h"


grpc::Status GggUserServiceImpl::UserLogin(grpc::ServerContext* context, const ggg_user::UserLoginReq* request, ggg_user::UserLoginRsp* response) {
  return grpc::Status::OK;
}

grpc::Status GggUserServiceImpl::UserLogOut(grpc::ServerContext* context, const ggg_user::UserLogOutReq* request, ggg_user::UserLogOutRsp* response) {
  return grpc::Status::OK;
}


