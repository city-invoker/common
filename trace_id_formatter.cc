
#include "trace_id_formatter.h"

namespace trpc {
namespace sample {


void TraceIdFormatter::format(const spdlog::details::log_msg &, const std::tm &, spdlog::memory_buf_t &dest) {

  //auto context = ::trpc::GetThreadLocalContext();
  //if (context != nullptr) {
  //  std::string trace_id =::trpc::opentelemetry::GetTraceID(context);
  //  fmt_helper.append_string_view(trace_id, dest);
  //}
}

std::unique_ptr<spdlog::custom_flag_formatter> TraceIdFormatter::clone() const {

    return spdlog::details::make_unique<TraceIdFormatter>();
}

}
}
