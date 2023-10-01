#include <iostream>
#include <vector>
#include <array>
#include <functional>
#include <queue>

std::ostream& operator<< (std::ostream &dest, __uint128_t val) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = val;
    char buffer[128];
    char* d = std::end(buffer);
    do{
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while(tmp != 0);
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

struct monkey {
  std::queue<__uint128_t> held;
  std::string op;
  bool other_arg;
  __uint128_t arg;
  __uint128_t div_test;
  __uint128_t to_success;
  __uint128_t to_failure;
  __uint128_t ins_cnt = 0;
};

int main() {
  std::string in;
  __uint128_t monkey_idx = 0;
  std::array<monkey, 8> monkeys;
  while(std::cin >> in) {
    std::cin >> in >> in >> in >> in;
    while (in != "Operation:") {
      __uint128_t item;
      if (in[in.size()-1] == ',') {
        item = std::stoi(in.substr(0, in.size()-1));
      } else {
        item = std::stoi(in);
      }
      monkeys[monkey_idx].held.push(item);
      std::cin >> in;
    }
    std::string op;
    std::cin >> in >> in >> in >> op >> in;
    monkeys[monkey_idx].op = op;
    monkeys[monkey_idx].other_arg = (in != "old");
    monkeys[monkey_idx].arg = (in == "old") ? 0 : std::stoi(in);
    std::cin >> in >> in >> in >> in; 
    __uint128_t div_test = std::stoi(in);
    monkeys[monkey_idx].div_test = div_test;
    std::cin >> in >> in >> in >> in >> in >> in;
    monkeys[monkey_idx].to_success = std::stoi(in);
    std::cin >> in >> in >> in >> in >> in >> in;
    monkeys[monkey_idx].to_failure = std::stoi(in);
    monkey_idx++;
  }

  __uint128_t div_mod = 1;
  for (auto monkey : monkeys) {
    div_mod *= monkey.div_test;
  }

  for (size_t i = 0; i < 10000; ++i) {
    for (auto& monkey : monkeys) {
      monkey.ins_cnt += monkey.held.size();
      while (monkey.held.size() > 0) {
        __uint128_t item = monkey.held.front();
        monkey.held.pop();
        auto fn = [](std::string op, __uint128_t a, __uint128_t b) {
          if (op == "*") {
            return a * b;
          }
          if (op == "+") {
            return a + b;
          }
          return __uint128_t(0);
        };
        __uint128_t wl = fn(monkey.op, item, (monkey.other_arg) ? monkey.arg : item) % div_mod;
        if (wl % monkey.div_test == 0) {
          monkeys[monkey.to_success].held.push(wl);
        } else {
          monkeys[monkey.to_failure].held.push(wl);
        }
      }
    }
  }

  __uint128_t max_active = 0, next_active = 0;
  for (auto monkey : monkeys) {
    if (monkey.ins_cnt > next_active) {
      if (monkey.ins_cnt > max_active) {
        next_active = max_active;
        max_active = monkey.ins_cnt;
      } else {
        next_active = monkey.ins_cnt;
      }
    }
    std::cout << monkey.ins_cnt << "\n";
  }
  std::cout << max_active * next_active << "\n";
}