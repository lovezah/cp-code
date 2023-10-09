#include <bits/stdc++.h>
#include <functional>
#include <utility>

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

using namespace std;

struct DSU {
    vector<int> par, sz;
    vector<array<int, 2>> store;
    int n = 0, comp = 0;

    DSU(int n_) { init(n_); }

    void init(int m) {
        n = m, comp = m;
        par.assign(n, -1);
        sz.assign(n, 1);
    }
    int find(int x) {
        if (x == par[x]) return x;
        return find(par[x]);
    }
    int operator[](int x) {
        return find(x);
    }
    bool join(int x, int y) {
        x = (*this)[x], y = (*this)[y];
        if (x == y) { store.push_back({-1, -1}); return false; }
        if (sz[x] < sz[y]) swap(x, y);
        store.push_back({x, y});
        sz[x] += sz[y];
        par[y] = x;
        return true;
    }
    bool same(int x, int y) {
        return (*this)[x] == (*this)[y];
    }
    int size(int x) {
        x = (*this)[x];
        return -par[x];
    }
    void rollback() {
        auto [x, y] = store.back();
        store.pop_back();
        if (x == -1) return;
        sz[x] -= sz[y];
        par[y] = y;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    vector<array<int, 3>> event;
    for (int m = 0; m < M; m++) {
        int opt, x, y; cin >> opt >> x >> y;
        x--, y--;
        event.push_back({opt, x, y});
    }
    std::y_combinator([&](auto solve, int p, int l, int r) -> void {
        for (auto [x, y] : ins[p]) {
            g.join(x, y);
        }
        if (l == r) {
            
        } else {
            int m = (l + r) / 2;
            solve(p * 2, l, m);
            solve(p * 2 + 1, m + 1, r);
        }
        for (auto [x, y] : ins[p]) {
            g.rollback();
        }
    })(1, 0, M-1);
    return 0;
}
