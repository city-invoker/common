// copyright skylanwei 2024-04-22

#ifndef TRPC_COMMON_TRACE_TRACE_ID_FILTER_H_
#define TRPC_COMMON_TRACE_TRACE_ID_FILTER_H_

#include "trpc/filter/server_filter_base.h"

namespace trpc {
namespace app {

class TraceIdFilter : public ::trpc::MessageServerFilter {

public:
    std::string Name() override { return "trace_id_filter"; }

    std::vector<::trpc::FilterPoint> GetFilterPoint() override {
      std::vector<::trpc::FilterPoint> points = {
                      ::trpc::FilterPoint::CLIENT_PRE_SEND_MSG,
                      ::trpc::FilterPoint::CLIENT_POST_RECV_MSG,
                      ::trpc::FilterPoint::SERVER_POST_RECV_MSG,
                      ::trpc::FilterPoint::SERVER_PRE_SEND_MSG,
                      };
      return points;
    }

    void operator()(::trpc::FilterStatus& status,
                    ::trpc::FilterPoint point, 
                    const ::trpc::ServerContextPtr& context);
};


}
}

#endif // TRPC_COMMON_TRACE_TRACE_ID_FILTER_H_
