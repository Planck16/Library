const int MOD = 1e9+7;


struct Combination {
  vector<long long> fact, fact_inv, inv;
  int size;

  Combination(int size)
      : size(size),
        fact(vector<long long>(size + 10)),
        fact_inv(vector<long long>(size + 10)), 
        inv(vector<long long>(size + 10)) {
  }

  void init() {
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