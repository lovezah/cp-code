#include <bits/stdc++.h>
using namespace std;

vector<int> minp;
vector<bool> prime;
vector<int> primes;

void sieve(int n) {
    n = max(n, 1);
    minp.assign(n + 1, 0);
    prime.assign(n + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int p = 2; p <= n; p++)
        if (prime[p]) {
            minp[p] = p;
            primes.push_back(p);

            for (int64_t i = (int64_t)p * p; i <= n; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    minp[i] = p;
                }
        }
}
