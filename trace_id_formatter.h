// copyright skylanwei 2023-11-18

#pragma once

#include "spdlog/pattern_formatter.h"

namespace trpc {
namespace sample {

class TraceIdFormatter : public spdlog::custom_flag_formatter
{
public:
    void format(const spdlog::details::log_msg &, const std::tm &, spdlog::memory_buf_t &dest) override;

    std::unique_ptr<custom_flag_formatter> clone() const override;
};

}
}
