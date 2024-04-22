#include "server_post_recv_msg_filter.h"

#include <uuid/uuid.h>

#include "trpc/server/server_context.h"

namespace trpc {
  namespace sample {

void ServerPostRecvMsgFilter::operator()(::trpc::FilterStatus& status,
                                         ::trpc::FilterPoint point, 
                                         const ::trpc::ServerContextPtr& context) {
    uuid_t uuid;
    uuid_generate(uuid);
    char uuid_str[37];
    uuid_unparse(uuid, uuid_str);
    uint32_t filter_id = static_cast<uint32_t>(::trpc::FilterPoint::SERVER_POST_RECV_MSG); 
    context->SetFilterData(filter_id, static_cast<std::string>(uuid_str));

    ::trpc::SetLocalServerContext(context);

    TRPC_FMT_INFO("set uuid thread local : filter_id={}, uuid={}", filter_id, uuid_str);

}


}
}


