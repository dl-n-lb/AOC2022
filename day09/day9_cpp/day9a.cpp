#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

struct pos {
  int x, y;

  bool operator==(const pos& other) const {
    return x == other.x && y == other.y;
  }
};

template<>
struct std::hash<pos> {
  size_t operator()(const pos& p) const {
    return std::hash<int>{}(p.x) ^ (std::hash<int>{}(p.y) << 4);
  }
};

void move_tail(int hx, int hy, int& tx, int& ty) {
  if (std::abs(hx - tx) > 1) {
    if (hy != ty) {
      ty += (hy > ty) ? 1 : -1;
    }
    tx += (hx > tx) ? 1 : -1;
  }
  if (std::abs(hy - ty) > 1) {
    if (hx != tx) {
      tx += (hx > tx) ? 1 : -1;
    }
    ty += (hy > ty) ? 1 : -1;
  }
}

int main() {
  std::unordered_map<pos, bool> map;
  std::string dir;
  int amt;
  int hx = 0, hy = 0;
  int tx = 0, ty = 0;
  while(std::cin >> dir) {
    std::cin >> amt;
    for (int i = 0; i < amt; ++i) {
      hx += (dir == "L") ? -1 : (dir == "R") ? 1 : 0;
      hy += (dir == "U") ? 1 : (dir == "D") ? -1 : 0;

      move_tail(hx, hy, tx, ty);
      map[{tx, ty}] = true;
    }
  }
  std::cout << map.size() << "\n";
}
