#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
#define rng(a) (a).begin(),(a).end()
#define rrng(a) (a).rbegin(),(a).rend()
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;


struct Combination {
  const int MOD = 1e9+7;
  vector<long long> fact, fact_inv, inv;
  int size;

  Combination(int sz)
      : size(sz),
        fact(vector<long long>(sz + 10)),
        fact_inv(vector<long long>(sz + 10)), 
        inv(vector<long long>(sz + 10)) {
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;

    for (int i = 2; i < size + 10; ++i) {
      fact[i] = fact[i - 1] * i % MOD;
      inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
      fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }
  }

  long long comb(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;

    return fact[n] * (fact_inv[k] * fact_inv[n - k] % MOD) % MOD;
  }
};


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  
  return 0;
}