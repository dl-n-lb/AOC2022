#include <cstdint>
#include <iostream>
#include <vector>
#include <unordered_set>



int main(int argc, char** argv) {
  int64_t target_y = std::stoi(argv[1]);

  std::unordered_set<int64_t> impossible_xs;
  std::unordered_set<int64_t> beacon_xs;
  
  std::string tmp, x, y;
  while(std::cin >> tmp) {
    std::cin >> tmp >> x >> y;
    std::string sxp = x.substr(2, x.size()-3);
    std::string syp = y.substr(2, y.size()-3);
    int64_t xp = std::stoi(sxp);
    int64_t yp = std::stoi(syp);

    std::cin >> tmp >> tmp >> tmp >> tmp >> x >> y;
    std::string sbxp = x.substr(2, x.size()-3);
    std::string sbyp = y.substr(2, y.size()-2);
    int64_t bxp = std::stoi(sbxp);
    int64_t byp = std::stoi(sbyp);

    if (byp == target_y) {
      beacon_xs.emplace(bxp);
    }

    int64_t mhd = std::abs(xp-bxp) + std::abs(yp - byp);

    int64_t yd = std::abs(target_y - yp);
    int64_t max_xd = mhd - yd;
    for(int64_t i = xp-max_xd; i <= xp+max_xd; ++i) {
      impossible_xs.emplace(i);
    }
  }
  std::cout << impossible_xs.size() - beacon_xs.size() << "\n";
}
