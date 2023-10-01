#include <iostream>
#include <vector>
#include <array>
#include <functional>
#include <queue>

struct monkey {
  std::queue<int> held;
  std::string op;
  bool other_arg;
  int arg;
  int div_test;
  int to_success;
  int to_failure;
  int ins_cnt = 0;
};

int main() {
  std::string in;
  int monkey_idx = 0;
  std::array<monkey, 8> monkeys;
  while(std::cin >> in) {
    std::cin >> in >> in >> in >> in;
    while (in != "Operation:") {
      int item;
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
    int div_test = std::stoi(in);
    monkeys[monkey_idx].div_test = div_test;
    std::cin >> in >> in >> in >> in >> in >> in;
    monkeys[monkey_idx].to_success = std::stoi(in);
    std::cin >> in >> in >> in >> in >> in >> in;
    monkeys[monkey_idx].to_failure = std::stoi(in);
    monkey_idx++;
  }

  for (int i = 0; i < 20; ++i) {
    for (auto& monkey : monkeys) {
      monkey.ins_cnt += monkey.held.size();
      while (monkey.held.size() > 0) {
        int item = monkey.held.front();
        monkey.held.pop();
        auto fn = [](std::string op, int a, int b) {
          if (op == "*") {
            return a * b;
          }
          if (op == "+") {
            return a + b;
          }
          return 0;
        };
        int wl = fn(monkey.op, item, (monkey.other_arg) ? monkey.arg : item) / 3;
        if (wl % monkey.div_test == 0) {
          monkeys[monkey.to_success].held.push(wl);
        } else {
          monkeys[monkey.to_failure].held.push(wl);
        }
      }
    }
  }

  int max_active = 0, next_active = 0;
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