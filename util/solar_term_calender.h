// copyright skylanwei 2024-08-13

#ifndef TRPC_COMMON_UTIL_SOLAR_TERM_CALENDER_H_
#define TRPC_COMMON_UTIL_SOLAR_TERM_CALENDER_H_

#include "trpc/util/singleton.h"

namespace trpc {
namespace app {


static const std::vector<std::string> solar_tg = {"甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸"}; 
static const std::vector<std::string> solar_dz = {"子", "丑", "寅", "卯", "辰", "巳", "午", "未", "申", "酉", "戌", "亥"}; 

static const std::vector<std::string> solar_terms = {"立春","雨水","惊蛰","春分","清明","谷雨","立夏","小满","芒种","夏至","小暑","大暑","立秋","处暑","白露","秋分","寒露","霜降","立冬","小雪","大雪","冬至",  "小寒","大寒"};

//a tropical year is 365 days 5 hours 48 minutes 46 seconds, equal to 31556926 seconds,
//we use 31556928(two more seconds) to make it divisible by 12 to define the month's
//len is 2629744 seconds
//static const uint32_t tropical_year_len = 31556928;
using tropical_years = std::chrono::duration<int64_t, std::ratio<31556928>>;
using tropical_months = std::chrono::duration<int64_t, std::ratio<2629744>>;
using tropical_days = std::chrono::duration<int64_t, std::ratio<24 * 60 * 60>>;
using tropical_hours = std::chrono::duration<int64_t, std::ratio<60 * 60 * 2>>; //一个时辰等于2h

std::chrono::system_clock::time_point DateStrToTimePoint(std::string& datetime) {
  std::tm tm = {};
  std::istringstream ss(datetime);
  ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
  st_tm.tm_isdst = -1;
  std::time_t tt = std::mktime(&st_tm);
  std::chrono::system_clock::time_point tp = std::chrono::system_clock::from_time_t(tt);
  return tp;
}

class AnchorPoint : public Singleton<AnchorPoint, CreateUsingNew, DefaultLifetime> {

private:
  AnchorPoint() {
    //甲子年丙寅月甲寅日立春起始点
    std::string year_month_anchor_str = "1924-02-05 09:49:00";
    year_month = DateStrToTimePoint(year_month_anchor_str);

    //甲子年丙寅月甲寅日甲子时起始点
    std::string day_hour_anchor_str = "1924-02-04 23:00:00";
    day_hour = DateStrToTimePoint(day_hour_anchor_str);
  }

public:
  std::chrono::system_clock::time_point YearMonth() {
    return year_month;
  }
  std::chrono::system_clock::time_point DayHour() {
    return day_hour;
  }

private:
  std::chrono::system_clock::time_point year_month;
  std::chrono::system_clock::time_point day_hour;
};

class GZ {
public:
  GZ() {}
  GZ(uint32_t idx_g, uint32_t idx_z) : idx_g(idx_g), idx_z(idx_z) {
    name = solar_tg[idx_g] + solar_dz[idx_z];
  }

private:
  uint32_t idx_g; //index of tg in range 0-9
  uint32_t idx_z; //index of dz in range 0-11 
  std::string name; //gz in chinese
};

class SolarTerm {
public:

  SolarTerm(const std::string& datetime) : datetime(datetime) {
    tp = DateStrToTimePoint(datetime);

    //this algorithm is wrong for solar term's year and months, coz the tropical point of 
    //the sun can not be caculate. but we can define the tropical year's duration, and divid it 
    //into 12 months to make every solar term is close to the real tropical time,
    //diviations within 10 mins.
    auto ym_dur = tp - AnchorPoint::GetInstance()->YearMonth();
    uint32_t elapse_years = std::chrono::duration_cast<tropical_years>(ym_dur).count();
    uint32_t elapse_months = std::chrono::duration_cast<tropical_months>(ym_dur).count();

    gz_year = GZ(y_idx % 10, y_idx % 12); //for anchor point's offset idx is g=0,z=0
    gz_month = GZ(m_idx % 10 + 2, m_idx % 12 + 2); //for anchor point's offset idx is g=2,z=2

    //for day and hour, this algorithm is absolutely right,
    //coz there's no relation between tropical day and month,
    //for the day's gz is tick 1 for every 24 hours
    //and for the hours's gz is tick 1 for every 2 hours
    auto dh_dur = tp - AnchorPoint::GetInstance()->DayHour();
    uint32_t elapse_days = std::chrono::duration_cast<tropical_days>(dh_dur).count();
    uint32_t elapse_hours = std::chrono::duration_cast<tropical_hours>(dh_dur).count();
    gz_day = GZ(elapse_days % 10, elapse_days % 12 + 2); //for anchor point's offset idx is g=0,z=2
    gz_hour = GZ(elapse_hours % 10, elapse_hours % 12); //for anchor point's offset idx is g=0,z=0

  }

private:
  std::string datetime;
  std::chrono::system_clock::time_point tp;
  GZ gz_year;
  GZ gz_month;
  GZ gz_day;
  GZ gz_hour;
};


}
}

#endif // TRPC_COMMON_UTIL_SOLAR_TERM_CALENDER_H_
