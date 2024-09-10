// copyright skylanwei 2024-04-23

#ifndef TRPC_COMMON_UTIL_CONST_H_
#define TRPC_COMMON_UTIL_CONST_H_

const static std::regex kRgx(R"(^(19|20)\d\d-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01]) (0[0-9]|1\d|2[0-3]):([0-5]\d):([0-5]\d)$)");

static const uint32_t kGzLen = 60;
static const std::vector<std::string> kTg = {"甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸"}; 
static const std::vector<std::string> kDz = {"子", "丑", "寅", "卯", "辰", "巳", "午", "未", "申", "酉", "戌", "亥"}; 

static const std::vector<std::string> kSolarTerm = {"立春","雨水","惊蛰","春分","清明","谷雨","立夏","小满","芒种","夏至","小暑","大暑","立秋","处暑","白露","秋分","寒露","霜降","立冬","小雪","大雪","冬至",  "小寒","大寒"};

static const std::vector<std::string> kMgXnames = {"破", "难", "犯", "贵", "寿", "艺", "刃", "孤", "驿", "福", "文", "如"};

static const std::vector<std::string> kSixGod = {"比肩", "劫财", "食神", "伤官", "偏财", "正财", "偏官", "正官", "偏印", "正印"}; 

//for dz six god's shift index, minus means switch each 2
static const std::vector<std::vector<int32_t> > kZSixGodIndex = {
 {9}, {9,5,7}, {-3,-1,5}, {-1}, {-1,-5,9}, {-5,-3,-7}, {3,5}, {1,5,3}, {-5,-7,-9}, {7}, {7,-5,3}, {-9,-1}
};

#endif // TRPC_COMMON_UTIL_CONST_H_
