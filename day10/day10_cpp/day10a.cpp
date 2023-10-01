#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string in;
  int cval;
  int cycle = 0;
  int x = 1;
  int sum = 0;
  while (std::cin >> in) {
    ++cycle;
    if (in == "noop") {
      if ((cycle-20) % 40 == 0) {sum += cycle * x;}
      continue;
    }
    if (in == "addx") {
      std::cin >> cval;
      if ((cycle-20) % 40 == 0) {sum += cycle * x;}
      ++cycle;
      if ((cycle-20) % 40 == 0) {sum += cycle * x;}
      x += cval;
    }
  }
  std::cout << sum;
}
