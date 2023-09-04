#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        int L, R, D; cin >> L >> R >> D;
        if (D < L) {
            cout << D << '\n';
        } else {
            cout << R / D * D + D << '\n';
        }
    }
    return 0;
}
