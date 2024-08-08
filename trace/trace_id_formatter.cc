#include "trace_id_formatter.h"

#include <spdlog/details/fmt_helper.h>

#include "trpc/server/server_context.h"
#include "trpc/filter/server_filter_base.h"
#include "trpc/filter/filter_point.h"
#include "../util/filter_id.h"

namespace trpc {
namespace app {

void TraceIdFormatter::format(const spdlog::details::log_msg &, const std::tm &, spdlog::memory_buf_t &dest) {

  auto context = ::trpc::GetLocalServerContext();
  if (context != nullptr) {
    uint32_t filter_id = static_cast<uint32_t>(FilterId::TRACE_ID_FILTER);
    auto uuid_ptr = context->GetFilterData<std::string>(filter_id);
    if (uuid_ptr != nullptr) {
      spdlog::details::fmt_helper::append_string_view(*uuid_ptr, dest);
    }
  }
}

std::unique_ptr<spdlog::custom_flag_formatter> TraceIdFormatter::clone() const {

  return spdlog::details::make_unique<TraceIdFormatter>();
}

}
}
