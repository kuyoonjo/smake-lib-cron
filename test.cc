#include <chrono>
#include <ctime>
#include <ex/cron.h>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

int main() {
  auto c = ex::cron("*/5 * * * * *");
  for (;;) {
    auto now = std::time(nullptr);
    char buf_now[100];
    std::strftime(buf_now, sizeof(buf_now), "%F %T", std::localtime(&now));
    auto fire = c.difftime() >= 0;
    std::cout << buf_now << " - " << c.next("%F %T") << " -> "
              << (fire ? "fired" : "waiting") << std::endl;
    std::this_thread::sleep_for(1s);
  }
  return 0;
}