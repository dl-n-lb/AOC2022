#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int main() {
  bool success = false;
  int successes = 0;
  for (int n = 0;; ++n) {
    if (success) {
      std::cout << n << "\n";
      successes += n;
    }
    success = true;
    std::string left, right;
    std::getline(std::cin, left);
    std::getline(std::cin, right);

    if (left == right && right == "") {
      break;
    }
    int lin = 0;
    std::vector<char> lv;
    std::vector<int> li;
    for (auto c : left) {
      if (c == '[') {
        lin++;
        continue;
      }
      if (c == ']') {
        lin--;
        continue;
      }
      if (c == ',') {
        continue;
      }
      lv.push_back(c);
      li.push_back(lin);
    }
    int rin = 0;
    std::vector<char> rv;
    std::vector<int> ri;
    for (auto c : right) {
      if (c == '[') {
        rin++;
        continue;
      }
      if (c == ']') {
        rin--;
        continue;
      }
      if (c == ',') {
        continue;
      }
      rv.push_back(c);
      ri.push_back(rin);
    }

    // need to handle the empty list case
    if (rv.size() == 0) {
      if (lv.size() == 0) {
        success = left.size() <= right.size();
        continue;
      }
      success = false;
      continue;
    }

    bool skip_l_indent = false;
    bool skip_r_indent = false;
    int i_to_skip = 0;
    int lo = 0;
    for (int i = 0; i < std::min(lv.size(), rv.size());) {
      if (skip_l_indent) {
        if (li[i+lo] == i_to_skip) {
          lo++;
          continue;
        } 
        skip_l_indent = false;
      }
      if (skip_r_indent) {
        if (ri[i] == i_to_skip) {
          lo--;
          i++;
          continue;
        } 
        skip_r_indent = false;
      }
      if (li[i+lo] == ri[i]) {
        if (lv[i+lo] > rv[i]) {
          success = false; 
          break;;
        }
        i++;
        continue;
      }
      if (li[i+lo] > ri[i]) {
        if (ri[i] > ri[i-1]) {
          if (lv[i+lo] > rv[i]) {
            success = false;
            break;
          }
          i++;
          continue;
        } else {
          success = false;
          break;
        }
      }
      if (ri[i] > li[i+lo]) {
        if (li[i-1+lo] < li[i+lo]) {
          if (li[i+lo] > ri[i]) {
            success = false;
            break;  
          }
          i++;
          continue;
        }
                
      }
    }
    
    std::getline(std::cin, left);
  }
  std::cout << successes << "\n";
}