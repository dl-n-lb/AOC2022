#include <iostream>
#include <vector>

int count_visible(std::vector<std::vector<int>> grid, int x, int y) {
  int cntl = 0, cntr = 0, cntu = 0, cntd = 0;
  for (int i = x+1; i < grid[y].size(); ++i) {
    ++cntr;
    if (grid[y][i] >= grid[y][x]) {
      break;
    }
  }
  for (int i = x-1; i >= 0; --i) {
    ++cntl;
    if (grid[y][i] >= grid[y][x]) {
      break;
    }
  }
  for (int i = y+1; i < grid.size(); ++i) {
    ++cntd;
    if (grid[i][x] >= grid[y][x]) {
      break;
    }
  }
  for (int i = y-1; i >= 0; --i) {
    ++cntu;
    if (grid[i][x] >= grid[y][x]) {
      break;
    }
  }
  return cntl * cntr * cntu * cntd;
}

int main() {
  std::string line;
  std::vector<std::vector<int>> grid;
  int i = 0;
  while (std::cin >> line) {
    grid.emplace_back();
    for (auto c: line) {
      grid[i].push_back(std::atoi(&c));
    }
    i++;
  }
  int rows = grid.size();
  int cols = grid[0].size();
  
  int max = 0;
  for (int y = 1; y < rows-1; ++y) {
    for (int x = 1; x < cols-1; ++x) {
      max = std::max(max, count_visible(grid, x, y));
    }
  }
  std::cout << max << std::endl;
}