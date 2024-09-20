// copyright skylanwei 2024-09-20

#include "solar_term_calender.h"

#include "trpc/util/time.h"

namespace trpc {
namespace app {

uint32_t SolarTerm::GetCurAge() {
  std::time_t now = std::time(NULL);
  std::string now_date_str = trpc::TimeStringHelper::ConvertUnixTimeToStr(now);
  std::chrono::system_clock::time_point tp_now = AnchorPoint::DateStrToTimePoint(now_date_str);
  std::chrono::system_clock::time_point tp = AnchorPoint::DateStrToTimePoint(datetime);

  auto dur = tp_now - tp;
  uint32_t age = std::chrono::duration_cast<tropical_years>(dur).count();
  return age;
}


uint32_t SolarTerm::GetCurYearShiftStep() {
  std::time_t now = std::time(NULL);
  std::string now_date_str = trpc::TimeStringHelper::ConvertUnixTimeToStr(now);
  std::chrono::system_clock::time_point tp_now = AnchorPoint::DateStrToTimePoint(now_date_str);

  auto ym_dur = tp_now - AnchorPoint::GetInstance()->YearMonth();
  uint32_t elapse_years = std::chrono::duration_cast<tropical_years>(ym_dur).count();
  uint32_t shift_step = elapse_years % 12;
  return shift_step;
}


} // app
} // trpc
