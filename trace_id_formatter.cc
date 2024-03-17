#include "trace_id_formatter.h"

#include <spdlog/details/fmt_helper.h>

#include "trpc/server/server_context.h"

namespace trpc {
namespace sample {


void TraceIdFormatter::format(const spdlog::details::log_msg &, const std::tm &, spdlog::memory_buf_t &dest) {

  auto context = ::trpc::GetLocalServerContext();
  if (context != nullptr) {
    spdlog::details::fmt_helper::append_int(context->GetRequestId(), dest);
  }
}

std::unique_ptr<spdlog::custom_flag_formatter> TraceIdFormatter::clone() const {

    return spdlog::details::make_unique<TraceIdFormatter>();
}

}
}
