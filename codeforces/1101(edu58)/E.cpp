#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    int mxX = 0, mxY = 0;
    for (int n = 0; n < N; n++) {
        char opt; cin >> opt;
        if (opt == '+') {
            int X, Y; cin >> X >> Y;
            if (X > Y) swap(X, Y);
            mxX = max(mxX, X);
            mxY = max(mxY, Y);
        } else {
            int H, W; cin >> H >> W;
            if (H > W) swap(H, W);
            cout << (H >= mxX && W >= mxY ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}
