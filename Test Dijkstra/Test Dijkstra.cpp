#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <queue>
#include <set>
#include <vector>
#include <iomanip>

using namespace std;

int64_t k_inf = 20'000'000'000;

vector<vector<pair<int64_t, int32_t> > > GenTest() {
  int64_t n = 2 + 1'000'000 + rand() % 1'000'000;
  int32_t m = 2 + 10'000'000 + rand() % 10'000'000;
  // std::min((int64_t)1e8, rand() % (n * n + 1));

  vector<vector<pair<int64_t, int32_t> > > g(n);

  for (int32_t i = 0; i < m; i++) {
    int32_t u = rand() % n;
    int32_t v = rand() % n;
    int32_t w = rand() % 1000000;

    g[u].emplace_back(w, v);
    g[v].emplace_back(w, u);
  }

  return g;
}

class Heap {
public:
  void Insert(int64_t w, int32_t v) {
    heap_.emplace_back(w, v);
    size_++;
    SiftUp(size_ - 1);
  }

  pair<int64_t, int32_t> GetMinEdge() {
    if (!heap_.empty()) {
      return heap_[0];
    }

    return { k_inf, -1 };
  }

  void ExtractMin() {
    std::swap(heap_[0], heap_[size_ - 1]);
    heap_.pop_back();
    size_--;

    if (size_ > 0) {
      SiftDown(0);
    }
  }

private:
  void SiftUp(int32_t id) {
    while (id > 0) {
      int32_t id_parent = (id - 1) / 2;
      if (heap_[id_parent].first <= heap_[id].first) {
        break;
      }
      std::swap(heap_[id_parent], heap_[id]);
      id = id_parent;
    }
  }

  void SiftDown(int32_t id) {
    while (id * 2 + 1 < size_) {
      int32_t id_ch1 = id * 2 + 1;
      int32_t id_ch2 = id * 2 + 2;
      int32_t id_max = id_ch1;
      if (id_ch2 < size_ && heap_[id_ch2].first < heap_[id_max].first) {
        id_max = id_ch2;
      }
      if (heap_[id].first < heap_[id_max].first) {
        break;
      }
      std::swap(heap_[id], heap_[id_max]);
      id = id_max;
    }
  }

  vector<pair<int64_t, int32_t> > heap_;
  int32_t size_ = 0;
};

class Graph {
public:
  explicit Graph(vector<vector<pair<int64_t, int32_t> > >& g) {
    g_ = g;
    vertices_ = g.size();
  }

  double HeapSolve(vector <int64_t>& dist) {
    double start_time = clock();

    HeapDijkstra(dist);

    double finish_time = clock();

    return finish_time - start_time;
  }

  double PQSolve(vector <int64_t>& dist) {
    double start_time = clock();

    PQDijkstra(dist);

    double finish_time = clock();

    return finish_time - start_time;
  }

  double MultisetSolve(vector <int64_t>& dist) {
    double start_time = clock();

    MultisetDijkstra(dist);

    double finish_time = clock();

    return finish_time - start_time;
  }

private:
  void HeapDijkstra(vector<int64_t>& dist) {
    dist.assign(vertices_, k_inf);
    vector<bool> used(vertices_, false);
    Heap edges;
    dist[0] = 0;
    edges.Insert(0, 0);

    for (int32_t i = 0; i < vertices_; i++) {
      pair<int64_t, int32_t> edge = edges.GetMinEdge();
      int64_t cur_d = edge.first;
      int32_t v = edge.second;
      if (v == -1) {
        break;
      }
      edges.ExtractMin();

      if (used[v] || dist[v] < cur_d) {
        continue;
      }

      used[v] = true;
      for (auto e : g_[v]) {
        int32_t weight = e.first;
        int32_t u = e.second;

        if (dist[v] + weight < dist[u]) {
          dist[u] = dist[v] + weight;
          edges.Insert(dist[u], u);
        }
      }
    }
  }

  void PQDijkstra(vector<int64_t>& dist) {
    dist.assign(vertices_, k_inf);
    vector<bool> used(vertices_, false);
    auto ÑompareDists = [](const pair<int64_t, int32_t>& A, const pair<int64_t, int32_t>& B) {
      return A.first > B.first;
    };
    std::priority_queue<pair<int64_t, int32_t>, std::vector<pair<int64_t, int32_t>>, decltype(ÑompareDists)> pq(ÑompareDists);

    dist[0] = 0;
    pq.push({ 0, 0 });

    while (!pq.empty()) {
      auto edge = pq.top();
      pq.pop();

      int64_t cur_d = edge.first;
      int32_t v = edge.second;

      if (used[v] || dist[v] < cur_d) {
        continue;
      }

      used[v] = true;
      for (auto e : g_[v]) {
        int32_t weight = e.first;
        int32_t u = e.second;

        if (dist[v] + weight < dist[u]) {
          dist[u] = dist[v] + weight;
          pq.emplace(dist[u], u);
        }
      }
    }
  }

  void MultisetDijkstra(vector<int64_t>& dist) {
    dist.assign(vertices_, k_inf);
    vector<bool> used(vertices_, false);
    auto ÑompareDists = [](const pair<int64_t, int32_t>& A, const pair<int64_t, int32_t>& B) {
      return A.first < B.first;
    };
    std::multiset<pair<int64_t, int32_t>, decltype(ÑompareDists)> mlset(ÑompareDists);
    // std::set<pair<int64_t, int32_t>> mlset;
    dist[0] = 0;
    mlset.insert({ 0, 0 });

    while (!mlset.empty()) {
      auto edge = *(mlset.begin());
      mlset.erase(mlset.begin());

      int64_t cur_d = edge.first;
      int32_t v = edge.second;

      if (used[v] || dist[v] < cur_d) {
        continue;
      }

      used[v] = true;
      for (auto e : g_[v]) {
        int32_t weight = e.first;
        int32_t u = e.second;

        if (dist[v] + weight < dist[u]) {
          dist[u] = dist[v] + weight;
          mlset.emplace(dist[u], u);
        }
      }
    }
  }

private:
  int32_t vertices_ = 0;
  vector<vector<pair<int64_t, int32_t> > > g_;
};

void Test() {
  vector<vector<pair<int64_t, int32_t> > > g = GenTest();

  Graph graph(g);
  vector <int64_t> dist1;
  vector <int64_t> dist2;
  vector <int64_t> dist3;
  cout << "HEAP: " << graph.HeapSolve(dist1) / CLOCKS_PER_SEC << "     ";
  cout << "PQ: " << graph.PQSolve(dist2) / CLOCKS_PER_SEC << "     ";
  cout << "MULTISET: " << graph.MultisetSolve(dist3) / CLOCKS_PER_SEC << '\n';
  for (int i = 0; i < dist1.size(); i++) {
    if (dist1[i] != dist2[i]) {
      cout << "OMAGAD1!" << endl;
      exit(0);
    }
    if (dist1[i] != dist3[i]) {
      cout << "OMAGAD2!" << endl;
      exit(0);
    }
  }
}

int32_t main() {
  std::fstream test_file;

  int32_t n = 10;
  cout << fixed;
  cout << setprecision(3);
  for (int32_t i = 0; i < n; i++) {
    cout << "Test " << i + 1 << '\n' << "---------\n";

    Test();
  }
}
