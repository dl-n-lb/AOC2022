#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string in;
  int cval;
  int cycle = 0;
  int x = 1;
  char crt[40 * 6];
  for (int i = 0; i < 240; ++i) {
    crt[i] = '.';
  }
  while (std::cin >> in) {
    ++cycle;
    if (in == "noop") {
      if (std::abs(x - (cycle%40) + 1) < 2) { crt[cycle-1] = '#'; }
      continue;
    }
    if (in == "addx") {
      std::cin >> cval;
      if (std::abs(x - (cycle%40) + 1) < 2) { crt[cycle-1] = '#'; }
      ++cycle;
      if (std::abs(x - (cycle%40) + 1) < 2) { crt[cycle-1] = '#'; }
      x += cval;
    }
  }
  for (int j = 0; j < 6; ++j) {
    for (int i = 0; i < 40; ++i) {
      std::cout << crt[i + j * 40];
    }
    std::cout << "\n";
  }
}
