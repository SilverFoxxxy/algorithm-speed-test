#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <vector>

using std::cin;
using std::cout;
using std::rand;
using std::vector;

vector<vector<int32_t> > GenTest() {
  int64_t n = 2 + 10'000'000 + rand() % 10'000'000;
  int32_t m = std::min((int64_t)4e8, rand() % (n * n + 1));

  vector<vector<int32_t> > g(n);

  for (int32_t i = 0; i < m; i++) {
    int32_t u = rand() % n;
    int32_t v = rand() % n;

    g[u].push_back(v);
    g[v].push_back(u);
  }

  return g;
}

// Global Solve

vector<vector<int32_t> > g;
vector<bool> used;
vector<int32_t> tin;
vector<int32_t> tout;
vector<int32_t> cur_path;
int32_t t = 0;

void GlobalDFS(int32_t u) {
  if (used[u]) {
    return;
  }

  tin[u] = t;
  t++;

  used[u] = true;
  cur_path.push_back(u);

  for (auto v : g[u]) {
    if (!used[v]) {
      GlobalDFS(v);
    }
  }

  t++;
  tout[u] = t;
  cur_path.pop_back();
}

double SolveGlobal(vector<vector<int32_t> >& g_test) {
  used.clear();
  tin.clear();
  tout.clear();
  cur_path.clear();
  
  g = g_test;
  int32_t size = g.size();
  
  used.resize(size, false);
  tin.resize(size, -1);
  tout.resize(size, -1);

  double start_time = clock();

  for (int32_t i = 0; i < size; i++) {
    GlobalDFS(i);
  }

  double finish_time = clock();

  return finish_time - start_time;
}

// Class Solve

class Graph {
public:
  Graph(vector<vector<int32_t> >& g) {
    g_ = g;
    size_ = g_.size();
    used_.resize(size_, false);
    tin_.resize(size_, -1);
    tout_.resize(size_, -1);
  }

  void ClassDFS(int32_t u) {
    if (used_[u]) {
      return;
    }

    tin_[u] = t;
    t_++;

    used_[u] = true;
    cur_path_.push_back(u);

    for (auto v : g_[u]) {
      if (!used_[v]) {
        ClassDFS(v);
      }
    }

    t_++;
    tout_[u] = t;
    cur_path_.pop_back();
  }

private:
  vector<vector<int32_t> > g_;
  int32_t size_ = 0;

  vector<bool> used_;
  vector<int32_t> tin_;
  vector<int32_t> tout_;
  vector<int32_t> cur_path_;
  int32_t t_ = 0;
};

double SolveClass(vector<vector<int32_t> > g) {
  Graph graph(g);

  double start_time = clock();

  for (int32_t i = 0; i < g.size(); i++) {
    graph.ClassDFS(i);
  }

  double finish_time = clock();

  return finish_time - start_time;
}

// Reference Solve

void ReferenceDFS(int32_t& u, vector<vector<int32_t> >& g, vector<bool>& used, vector<int32_t>& tin,
  vector<int32_t>& tout, int32_t& t, vector<int32_t>& cur_path) {
  if (used[u]) {
    return;
  }

  tin[u] = t;
  t++;

  used[u] = true;
  cur_path.push_back(u);

  for (auto v : g[u]) {
    if (!used[v]) {
      ReferenceDFS(v, g, used, tin, tout, t, cur_path);
    }
  }

  t++;
  tout[u] = t;
  cur_path.pop_back();
}

double SolveReference(vector<vector<int32_t> >& g) {
  int32_t size = g.size();
  vector<bool> used(size, false);
  vector<int32_t> tin(size, -1);
  vector<int32_t> tout(size, -1);
  vector<int32_t> cur_path(size, -1);
  int32_t t = 0;

  double start_time = clock();

  for (int32_t i = 0; i < size; i++) {
    ReferenceDFS(i, g, used, tin, tout, t, cur_path);
  }

  double finish_time = clock();

  return finish_time - start_time;
}

// Test

void Test(vector<vector<int32_t> >& g, std::fstream& test_file) {
  double t1 = SolveGlobal(g) / CLOCKS_PER_SEC;
  double t2 = SolveClass(g) / CLOCKS_PER_SEC;
  double t3 = SolveReference(g) / CLOCKS_PER_SEC;

  cout << t1 << "       " << t2 << "       " << t3 << '\n';
}

int main() {
  std::fstream test_file;
  cout << "        Global      Class       Refer\n";

  int n = 100;
  for (int32_t i = 0; i < n; i++) {
    cout << "Test " << i << ": ";

    vector<vector<int32_t> > g = GenTest();
    Test(g, test_file);
  }
}
