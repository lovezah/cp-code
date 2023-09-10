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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector A(N, vector<int>(N));
    for (auto &a : A) for (auto &v : a) cin >> v;
    vector<int> ids(N);
    iota(ids.begin(), ids.end(), 0);
    vector<array<int, 2>> edges;
    vector<int> salary(N);
    for (int i = 0; i < N; i++)
        salary[i] = A[i][i];
    auto split = std::y_combinator([&](auto self, vector<int> tmp) -> int {
        if (tmp.size() == 1) {
            return tmp[0];
        }
        int big = 0;
        for (int i = 0; i < tmp.size(); i++)
            for (int j = i; j < tmp.size(); j++)
                big = max(big, A[tmp[i]][tmp[j]]);
        vector<vector<int>> groups{{tmp[0]}};
        for (int i = 1; i < tmp.size(); i++) {
            int group = -1;
            for (int j = 0; j < groups.size(); j++) {
                if (A[groups[j][0]][tmp[i]] != big) {
                    group = j;
                    break;
                }
            }
            if (group == -1)
                groups.push_back({tmp[i]});
            else
                groups[group].push_back(tmp[i]);
        }
        vector<int> roots;
        for (auto &group : groups)
            roots.push_back(self(group));
        int S = salary.size();
        salary.push_back(big);
        for (auto rt : roots)
            edges.push_back({rt, S});
        return S;
    });
    int root = split(ids);
    cout << root + 1 << '\n';
    for (auto v : salary)
        cout << v << ' ';
    cout << '\n';
    cout << root + 1 << '\n';
    for (auto [u, v] : edges) {
        cout << u+1 << ' ' << v+1 << '\n';
    }
    return 0;
}
