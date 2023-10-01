#include <iostream>
#include <vector>
#include <deque>

void print_stacks(std::vector<std::deque<char>> stacks) {
  for (auto stack : stacks) {
    for (auto dmp = stack; !dmp.empty(); dmp.pop_back()){
      std::cout << dmp.back();
    }
    std::cout << std::endl;
  }
}

int main() {
  std::string tmp;
  int stack_cnt;
  std::cin >> stack_cnt;
  bool stacking = true;
  std::vector<std::deque<char>> stacks;
  stacks.resize(stack_cnt);
  int stack_ind = 0;
  while (std::cin >> tmp) {
    if (tmp[0] == 'm') {
      stacking = false;
    }
    if (stacking) {
      if (tmp[0] != '-')
        stacks[stack_ind].push_front(tmp[1]);
      
      stack_ind++;
      stack_ind %= stack_cnt;
    } else {
      print_stacks(stacks);
      int amt, from, to;
      std::cin >> amt >> tmp >> from >> tmp >> to;
      for(int i = 0; i < amt; ++i) {
        stacks[to-1].push_back(stacks[from-1].back());
        stacks[from-1].pop_back();
      }
    }
  }  
  print_stacks(stacks);
  std::string out;
  for (auto stack : stacks) {
    out += stack.back();
  }
  std::cout << out << std::endl;
}
