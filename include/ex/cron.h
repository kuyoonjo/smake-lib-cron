#pragma once

#include "../croncpp.h"
#include <ctime>

namespace ex {
class cron {
public:
  explicit cron(const std::string &expr) : m_cron(::cron::make_cron(expr)) {
    m_next = ::cron::cron_next(m_cron, std::time(nullptr));
  }
  auto difftime() {
    auto dt = std::difftime(std::time(nullptr), m_next);
    if (dt >= 0)
      m_next = ::cron::cron_next(m_cron, std::time(nullptr));
    return dt;
  }

  auto next() { return m_next; }

  std::string next(const std::string &format) {
    char buf[100];
    std::strftime(buf, sizeof(buf), format.c_str(), std::localtime(&m_next));
    return buf;
  }

private:
  std::time_t m_next;
  ::cron::cronexpr m_cron;
};
} // namespace ex