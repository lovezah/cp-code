#include <bits/stdc++.h>

using namespace std;

const int SZ = 26;
const int MAXN = 30010 * 26;
struct node {
    node *son[SZ], *go[SZ], *fail;
    vector<node*> fson;
} pool[MAXN], *cur = pool, *root = pool;

node *newnode() {
    return cur++;
}

node *insert(string T) {
    node *u = root;
    for (char ch : T) {
        int t = ch - 'a';
        if (!u->son[t]) u->son[t] = newnode();
        u = u->son[t];
    }
    return u;
}

vector<node*> work() {
    vector<node*> que(1, root);
    for (int i = 0; i < (int)que.size(); i++) {
        node *u = que[i];
        for (int j = 0; j < SZ; j++) {
            if (u->son[j]) {
                u->go[j] = u->son[j];
                if (u == root) u->go[j]->fail = root;
                else u->go[j]->fail = u->fail->go[j];
                que.push_back(u->son[j]);
            } else {
                if (u == root) u->go[j] = root;
                else u->go[j] = u->fail->go[j];
            }
        }
    }
    for (int i = 1; i < (int)que.size(); i++)
        que[i]->fail->fson.push_back(que[i]);
    return que;
}

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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    root = newnode();
    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string S; cin >> S;
        insert(S);
    }
    auto que = work();
    int M = (int)que.size();
    vector<node *> st(M), en(M), seq;
    std::y_combinator([&](auto dfs, node *u) -> void {
        st[u] = seq.size();
        seq.push_back(u);
        for (auto v : u->fson) {
            dfs(v);
        }
        en[u] = seq.size();
    })(root);

    int MX = 1;
    while (MX * 2 < N) MX *= 2;
    vector<multiset<int>> seg(MX * 2);
    std::y_combinator([&](auto dfs, int u, int fa) -> void {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    })();

    return 0;
}
