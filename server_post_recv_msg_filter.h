// copyright skylanwei 2024-04-22

#pragma once

#include "trpc/filter/server_filter_base.h"

namespace trpc {
namespace sample {

class ServerPostRecvMsgFilter : public ::trpc::MessageServerFilter {

public:
    std::string Name() override { return "server_post_recv_msg_filter"; }

    std::vector<::trpc::FilterPoint> GetFilterPoint() override {
      std::vector<::trpc::FilterPoint> points = {::trpc::FilterPoint::SERVER_POST_RECV_MSG,
                                                 ::trpc::FilterPoint::SERVER_PRE_SEND_MSG};
      return points;
    }

    void operator()(::trpc::FilterStatus& status,
                    ::trpc::FilterPoint point, 
                    const ::trpc::ServerContextPtr& context);
};


}
}
