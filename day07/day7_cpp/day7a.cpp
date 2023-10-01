#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <algorithm>
#include <numeric>

std::string pwd(std::vector<std::string> cwd) {
  std::string out;
  for (auto& fo : cwd) {
    out += "/" + fo;
  }
  return out;
}

int main() {
  std::unordered_map<std::string, int> contents_size;
  std::vector<std::string> cwd = {""};
  std::string cmd;
  std::cin >> cmd >> cmd >> cmd >> cmd;
  while(std::cin >> cmd) {
    if (cmd == "cd") {
      std::string loc;
      std::cin >> loc;
      if (loc == "..") {
        cwd.pop_back();
      } else {
        cwd.push_back(loc);
      }
    } else if (cmd == "ls") {
      std::string flinf = cmd;
      while(std::cin >> flinf && flinf != "$") {
        std::cout << flinf << std::endl;
        if (flinf == "$") {continue;}
        if (flinf == "dir") {
          std::cin >> flinf;
        } else {
          std::cout << flinf << " " << pwd(cwd) << "\n";
          int add = std::stoi(flinf);
          for(int i = 0; i <= cwd.size(); ++i) {
            auto wd = std::vector<std::string>(cwd.begin(), cwd.begin()+i);
            contents_size[pwd(wd)] += add;
          }
          std::cin >> flinf;
        }
      }
    }
  }
  int sum_of_valid = 0;
  for (auto [key, element] : contents_size) {
    std::cout << key << '\t' << element << "\n";
    if (element < 100000) {
      sum_of_valid += element;
    }
  }
  std::cout << "\n" << sum_of_valid << "\n";
}
