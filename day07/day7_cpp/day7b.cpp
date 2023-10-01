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
        if (flinf == "$") {continue;}
        if (flinf == "dir") {
          std::cin >> flinf;
        } else {
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
  int threshold = -40000000 + contents_size[""];
  std::cout << threshold << std::endl;
  int minimum_valid = contents_size[""];
  for (auto [key, element] : contents_size) {
    std::cout << key << '\t' << element << "\n";
    if (element > threshold) {
      minimum_valid = (minimum_valid < element) ? minimum_valid : element;
    }
  }
  std::cout << "\n" << minimum_valid << "\n";
}
