#include <bits/stdc++.h>

using namespace std;

const int nax = 1000*1007;
int sa[nax], rk[nax], ht[nax];
// 0-based sa 表示第i大的为哪个，rk 表示第i个后缀第几大
// ht表示 lcp(sa[i], sa[i-1])
void buildSA(std::string &s, int m = 128) {
	static int x[nax], y[nax], c[nax];
    int n = (int)s.size();
    s.push_back(0);
	for (int i = 0; i < m; i++) c[i] = 0;
	for (int i = 0; i < n; i++) c[x[i] = s[i]]++;
	for (int i = 1; i < m; i++) c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
	for (int k = 1; k < n; k <<= 1) {
		int p=0;
		for (int i = n - 1; i >= n - k; i--) y[p++] = i;
		for (int i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;
		for (int i = 0; i < m; i++) c[i] = 0;
		for (int i = 0; i < n; i++) c[x[y[i]]]++;
		for (int i = 1; i < m; i++) c[i] += c[i - 1];
		for (int i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
		swap(x, y);
		p = 1; x[sa[0]] = 0; y[n] = -1;
		for (int i = 1; i < n; i++) {
			if (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k])
				x[sa[i]] = p - 1;
			else
				x[sa[i]] = p++;
		}
		if (p == n) break;
		m = p;
	}
	for (int i = 0; i < n; i++) rk[sa[i]] = i;
	int k = 0;
	for (int i = 0; i < n; i++) {
		k = max(k - 1, 0);
		if (rk[i] == 0) continue;
		int j = sa[rk[i] - 1];
		while (s[i + k] == s[j + k]) k++;
		ht[rk[i]] = k;
	}
}

using ll = int64_t;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    std::string S; cin >> S;
    int N = S.size();
    buildSA(S);
    ll ans = (ll)(N - 1) * (N + 1) * N / 2;
    // 1...(n-1)
    std::vector<int> L(N, 0), R(N, N);
    std::vector<int> q; q.push_back(0);
    for (int i = 1; i < N; i++) {
        while (q.size() && ht[i] < ht[q.back()]) {
            R[q.back()] = i;
            q.pop_back();
        }
        L[i] = q.back();
        q.push_back(i);
    }
    for (int i = 1; i < N; i++) {
        ans -= 2LL * ht[i] * (i - L[i]) * (R[i] - i);
    }
    cout << ans << '\n';
    return 0;
}
