#include <iostream>
#include <ncurses.h>
#include <vector>

struct line {
  int x0, y0, x1, y1;
};

enum Tile {
  AIR = 0,
  GROUND,
};

int main() {
  std::vector<line> lines;
  while (true) {
    std::string line;
    std::getline(std::cin, line);
    if (line == "")
      break;

    size_t pos = 0;
    std::string token;
    int x0, y0, x1, y1;
    bool first = true;
    while ((pos = line.find(" -> ")) != std::string::npos) {
      token = line.substr(0, pos);
      line.erase(0, pos + 4);
      auto split = token.find(",");
      auto x = token.substr(0, split);
      auto y = token.substr(split+1, token.size()-1);
      if (first) {
        x1 = std::stoi(x);
        y1 = std::stoi(y);
        first = false;
      } else {
        x0  = x1;
        y0 = y1;
        x1 = std::stoi(x);
        y1 = std::stoi(y);
        lines.push_back({x0, y0, x1, y1});
      }
    }
    auto split = token.find(",");
    auto x = line.substr(0, split);
    auto y = line.substr(split+1, token.size()-1);
    x0  = x1;
    y0 = y1;
    x1 = std::stoi(x);
    y1 = std::stoi(y);
    lines.push_back({x0, y0, x1, y1});
  }
  int max_x = 0, max_y = 0;
  for (auto l : lines) {
    max_x = std::max(max_x, std::max(l.x0+1, l.x1+1));
    max_y = std::max(max_y, std::max(l.y0+1, l.y1+1));
  }
  std::vector<std::vector<Tile>> tiles;
  tiles.resize(max_y+2);
  for (auto& tile : tiles) {
    tile.resize(1200);
  }
  std::cout << tiles.size() << " " << tiles[0].size() << "\n";
  for (auto l : lines) {
    if (l.x0 == l.x1) {
      for (int y = std::min(l.y0, l.y1); y <= std::max(l.y0, l.y1); ++y) {
        tiles[y][l.x0] = GROUND;
      }
    }
    if (l.y0 == l.y1) {
      for (int x = std::min(l.x0, l.x1); x <= std::max(l.x0, l.x1); ++x) {
        tiles[l.y0][x] = GROUND;
      }
    }
  }

  for (int x = 0; x < 1200; ++x) {
    tiles[tiles.size()-1][x] = GROUND;
  }

  int units = 0;
  bool nf = true;
  while (1) {
    int x, y, nx = 500, ny = 0;
    do {
      x = nx;
      y = ny;
      if (tiles[y+1][x] == AIR) {
        ny = y+1;
      } else if (tiles[y+1][x-1] == AIR) {
        ny = y+1;
        nx = x-1;
      } else if (tiles[y+1][x+1] == AIR) {
        ny = y+1;
        nx = x+1;
      }
    } while(!(nx == x && ny == y));
    tiles[y][x] = GROUND;
    units++;
    if (y == 0 && x == 500) {
      break;
    }
  }
  std::cout << units << "\n";
}