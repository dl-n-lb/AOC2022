#include <cstdint>
#include <iostream>
#include <vector>
#include <unordered_map>

#define R2 1.41421356237
#define HR2 0.70710678118

struct pos {
  int64_t x, y;
};

bool operator == (const pos l, const pos r) {
  return l.x == r.x && l.y == r.y;
}

template<>
struct std::hash<pos> {
  size_t operator()(const pos& p) const noexcept {
    auto h1 = std::hash<int64_t>{}(p.x);
    auto h2 = std::hash<int64_t>{}(p.y);
    return h1 ^ (h2 << 1);
  }
};


// transform rhombus -> square space
pos t(pos p) {
  return {
    p.x - p.y,
    p.x + p.y
  };
}

// square space -> rhombus space
pos ti(pos p) {
  return {
    (p.x + p.y)/2,
    (-p.x + p.y)/2
  };
}

struct square {
  square(int64_t xc, int64_t yc, int64_t r) {
    pos top = t({xc, yc - r});
    pos bottom = t({xc, yc+r});
    pos left = t({xc - r, yc});
    pos right = t({xc + r, yc});
    tl = {
      std::min(top.x, std::min(left.x, right.x)),
      std::min(bottom.y, std::min(top.y, right.y))
    };
    br = {
      std::max(top.x, std::max(left.x, right.x)),
      std::max(bottom.y, std::max(top.y, right.y))
    };
  }
  pos tl, br;
};

// returns number of intersections
int intersect(square l, square r, pos* o1, pos* o2) {
  if (l.br.x < r.tl.x || l.tl.x > r.br.x
    || l.br.y > r.tl.y || l.tl.y > r.br.y) {
    return 0;
  }
  *o1 = {
    std::min(l.br.x, r.br.x), std::max(l.tl.y, r.tl.y)
  };
  *o2 = {
    std::max(l.tl.x, r.tl.x), std::min(l.br.y, r.br.y)
  };
  if (o1 == o2) {
    return 1;
  }
  return 2;
}

int main(int argc, char** argv) {
  int64_t max_x = std::stoi(argv[1]);
  int64_t max_y = max_x;
  std::string tmp, x, y;

  std::vector<square> beacon_zones;
  std::unordered_map<pos, uint64_t> positions;
  
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

    int64_t mhd = std::abs(bxp-xp) + std::abs(byp-yp);
    
    beacon_zones.push_back(square(xp, yp, mhd));
  }

  for(auto& z1 : beacon_zones) {
    for (auto& z2 : beacon_zones) {
      // calculate intersections
      pos p1, p2;
      int i = intersect(z1, z2, &p1, &p2);
      if (i == 2) {
        positions[ti(p1)] += 1;
        positions[ti(p2)] += 1;
      }
      if (i == 1) {
        positions[ti(p1)] += 1;
      }
    }
  }
  for (auto [p, v] : positions) {
    std::cout << p.x << ", " << p.y << ": " << v << "\n";
  }
  std::cout << positions[{14, 11}] << "\n";
}
