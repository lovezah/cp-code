#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    map<array<int, 2>, char> edges;
    int both = 0, same = 0;
    for (int m = 0; m < M; m++) {
        char opt; cin >> opt;
        if (opt == '+') {
            int u, v; char c;
            cin >> u >> v >> c;
            u--, v--;
            edges[{u,v}] = c;
            if (edges.find({v,u}) != edges.end()) {
                both += 1;
                same += edges[{v,u}] == c;
            }
        } else if (opt == '-') {
            int u, v;
            cin >> u >> v;
            u--, v--;
            if (edges.find({v,u}) != edges.end()) {
                both -= 1;
                if (edges[{v,u}] == edges[{u,v}])
                    same -= 1;
            }
            edges.erase(edges.find({u,v}));
        } else if (opt == '?') {
            int k; cin >> k;
            if (k & 1) 
                cout << (both > 0 ? "YES" : "NO") << '\n';
            else   
                cout << (same > 0 ? "YES" : "NO") << '\n';
        } else assert(false);
    }
    return 0;
}