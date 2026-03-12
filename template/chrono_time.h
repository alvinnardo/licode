#pragma once
#include <bits/stdc++.h>
using namespace std;

#include <chrono>
#include <ctime>
#include <iomanip>
using sys_clock = std::chrono::system_clock;
using time_point_t = sys_clock::time_point;
using time_duration_t = sys_clock::duration;  // 时间间隔

// 获取当前时间点
std::string getTimeStr(const time_point_t &);
time_point_t getNowTimePoint() { return sys_clock::now(); }
std::string getNowTimePointStr() { return getTimeStr(getNowTimePoint()); }

// 时间点比较
bool cmpTimePoint(const time_point_t &time1, const time_point_t &time2) {
    return time1 < time2;
}

// 获取之前（或之后）的一个时间点
// 1小时
time_duration_t m_hour_duration = std::chrono::hours(1);

// 1 天
time_duration_t m_day_duration = std::chrono::hours(24 * 1);

// 时间前
time_point_t getBeforeTimePoint(const time_point_t &tp,
                                const time_duration_t &dur) {
    return tp - dur;
}

// 时间后
time_point_t getAfterTimePoint(const time_point_t &tp,
                               const time_duration_t &dur) {
    return tp + dur;
}

// 时间点转字符串
// 转成 "YYYYmmDDTHHMMSS111" 格式，精确到 ms
std::string getTimeStr(const time_point_t &tp) {
    std::time_t time = sys_clock::to_time_t(tp);

    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        tp.time_since_epoch());
    auto millis = ms.count() % 1000;

    std::ostringstream oss;
    oss << std::put_time(std::localtime(&time), "%Y%m%dT%H%M%S") << std::setw(3)
        << std::setfill('0') << millis;

    return oss.str();
}

// 字符串转时间点
// 从 "YYYYmmDDTHHMMSS111" 转入
time_point_t getTimePointFromStr(const std::string &raw_time) {
    std::istringstream ss(raw_time);
    std::tm tm{};

    ss >> std::get_time(&tm, "%Y%m%dT%H%M%S");
    std::time_t time = std::mktime(&tm);

    return sys_clock::from_time_t(time);
}

// 时间戳转时间点
time_point_t getTimePointFromTimestamp(const long long timestamp) {
    int ms = timestamp % 1000;
    std::time_t time = (std::time_t)(timestamp / 1000);
    return sys_clock::from_time_t(time);
}

// 用法：
// 第一个参数可以是以下几种形式得到
// std::chrono::minutes min{2}; // 自定义一个间隔
// sys_clock::now().time_since_epoch() // 起始点到当前点的时间间隔
std::string durationCast(const time_duration_t &dur,
                         const std::string &unit = "ms") {
    std::stringstream ss;
    if (unit == "ns") {
        ss << std::chrono::duration_cast<std::chrono::nanoseconds>(dur);
    } else if (unit == "ms") {
        ss << std::chrono::duration_cast<std::chrono::milliseconds>(dur);
    } else if (unit == "s") {
        ss << std::chrono::duration_cast<std::chrono::seconds>(dur);
    } else if (unit == "min") {
        ss << std::chrono::duration_cast<std::chrono::minutes>(dur);
    } else if (unit == "h") {
        ss << std::chrono::duration_cast<std::chrono::hours>(dur);
    } else if (unit == "days") {
        ss << std::chrono::duration_cast<std::chrono::days>(dur);
    } else if (unit == "weeks") {
        ss << std::chrono::duration_cast<std::chrono::weeks>(dur);
    } else if (unit == "months") {
        ss << std::chrono::duration_cast<std::chrono::months>(dur);
    } else if (unit == "years") {
        ss << std::chrono::duration_cast<std::chrono::years>(dur);
    } else {
        throw std::string("cannot cast to " + unit);
    }

    return ss.str();
}

// 时间分割：以分钟分割时间，常用于计算时间间隔内的频数
void TimeSplit() {
    // 精确时间
    auto now = sys_clock::now();
    std::cout << now << std::endl;

    // 法1: 获取根时间到当前时间的间隔，并转为分钟
    auto res = std::chrono::duration_cast<std::chrono::minutes>(
        now.time_since_epoch());
    std::cout << "time: " << res << std::endl;

    // 法2：获取当前时间的时间结构体，并获取秒的值
    std::time_t tm = sys_clock::to_time_t(sys_clock::now());  // 以秒结尾
    std::tm *tmm = std::localtime(&tm);
    std::cout << tmm->tm_min << std::endl;

    // 经测试，法1 比 法2 平均快 7 倍
}
