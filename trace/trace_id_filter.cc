#include "trace_id_filter.h"

#include "util/gen_uuid.h"
#include "util/filter_id.h"
#include "trpc/server/server_context.h"

namespace trpc {
namespace app {

void TraceIdFilter::operator()(::trpc::FilterStatus& status,
                                         ::trpc::FilterPoint point, 
                                         const ::trpc::ServerContextPtr& context) {

  if (point == ::trpc::FilterPoint::SERVER_POST_RECV_MSG || 
      point == ::trpc::FilterPoint::CLIENT_PRE_SEND_MSG ) {
    uint32_t filter_id = static_cast<uint32_t>(FilterId::TRACE_ID_FILTER); 
    auto dptr = context->GetFilterData<std::string>(filter_id);
    if (dptr == nullptr) {
      std::string uuid = UUID::uuid();
      context->SetFilterData<std::string>(filter_id, std::move(uuid));
      ::trpc::SetLocalServerContext(context);
  
      TRPC_FMT_DEBUG("set uuid thread local : point={}, filter_id={}, uuid={}", static_cast<uint32_t>(point), filter_id, uuid);
    }
  }
}


}
}


