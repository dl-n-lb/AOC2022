#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <limits.h>

std::vector<std::vector<bool>> adjmat(std::vector<char> map, int size) {
  std::vector<std::vector<bool>> res;
  for(int i = 0; i < map.size(); ++i) {
    std::vector<bool> v; v.resize(map.size());
    std::fill(v.begin(), v.end(), false);
    res.push_back(v);
  }

  for (int i = 0; i < map.size(); ++i) {
    for (int j = 0; j < map.size(); ++j) {
      if (std::abs(i - j) == 1 || std::abs(i - j) == size) {
        if (map[i] == 'S') map[i] = 'a';
        if (map[i] == 'E') map[i] = 'z';
        res[i][j] = map[i] >= (map[j]-1);
      }
    }
  }
  
  return res;
}

int min_dist(std::vector<int> dist, std::vector<bool> spt) {
  int min = INT_MAX, min_index = 0;
  for (int v = 0; v < dist.size(); ++v) {
    if (spt[v] == false && dist[v] < min) {
      min = dist[v], min_index = v;
    }
  }

  return min_index;
}

int dijkstra(std::vector<std::vector<bool>> adj, std::vector<char> map) {
  int start = std::find(map.begin(), map.end(), 'S') - map.begin();
  int end = std::find(map.begin(), map.end(), 'E') - map.begin();
  std::vector<int> dist; dist.resize(map.size());
  std::vector<bool> sptSet; sptSet.resize(map.size());

  for(int i = 0; i < map.size(); ++i) {
    dist[i] = INT_MAX;
    sptSet[i] = false;
  }
  dist[start] = 0;

  for(int cnt = 0; cnt < map.size() - 1; ++cnt) {
    int u = min_dist(dist, sptSet);
    sptSet[u] = true;
    for(int v = 0; v < map.size(); ++v) {
      if (!sptSet[v] && adj[u][v] 
        && dist[u] != INT_MAX 
        && dist[u] + adj[u][v] < dist[v]) {
        dist[v] = dist[u] + adj[u][v];
      }  
    }
  }
  return dist[end];
}

int main() {
  std::string ln;
  std::vector<char> map;
  int length;
  while (std::cin >> ln) {
    length = ln.size();
    for(char c : ln) {
      map.push_back(c);
    }
  }

  auto adj = adjmat(map, length);

  int idx = std::find(map.begin(), map.end(), 'S') - map.begin();
  map[idx] = 'a';  

  std::vector<std::vector<char>> maps;
  for(int i = 0; i < map.size(); ++i) {
    if (map[i] == 'a') {
      std::vector<char> cp = map;
      cp[i] = 'S';
      maps.push_back(cp);
    }
  }

  int min = INT_MAX;
  for(auto m : maps) {
    min = std::min(min, dijkstra(adj, m));
    std::cout << min << std::endl;
  }

  std::cout << min << "\n";
}