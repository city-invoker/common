// copyright skylanwei 2024-08-13

#ifndef TRPC_COMMON_UTIL_SOLAR_TERM_CALENDER_H_
#define TRPC_COMMON_UTIL_SOLAR_TERM_CALENDER_H_

namespace trpc {
namespace app {


static const std::vector<std::string> solar_tg = {"甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸"}; 
static const std::vector<std::string> solar_dz = {"子", "丑", "寅", "卯", "辰", "巳", "午", "未", "申", "酉", "戌", "亥"}; 
static const uint64_t anchor_point = 0; //the timestamp of gz first point

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
  SolarTerm(uint64_t ts) : ts(ts) {
    date = trpc::TimeStringHelper::ConvertUnixTimeToStr(ts);
    uint64_t diff_ts = ts - anchor_point;
    uint32_t y_idx = std::ceil(diff_ts / 31556952); //365.2425 days, a solar circle seconds
    uint32_t m_idx = std::ceil(diff_ts / 2629746);  //30.436875 days 1/12 of a year
    uint32_t d_idx = std::ceil(diff_ts / 86400);
    uint32_t h_idx = std::ceil(diff_ts / 3600 * 2);
    gz_year = GZ(y_idx % 10, y_idx % 12);
    gz_month = GZ(m_idx % 10, m_idx % 12);
    gz_day = GZ(d_idx % 10, d_idx % 12);
    gz_hour = GZ(h_idx % 10, h_idx % 12);
  }

  SolarTerm(const std::string& datetime) : SolarTerm(trpc::time::ConvertHttpDateToEpoch(datetime)) {
  }

private:
  uint64_t ts;
  std::string date;
  GZ gz_year;
  GZ gz_month;
  GZ gz_day;
  GZ gz_hour;
};


}
}

#endif // TRPC_COMMON_UTIL_SOLAR_TERM_CALENDER_H_
