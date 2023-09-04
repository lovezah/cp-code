#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string S; cin >> S;
    int N = int(S.size());
    bool found_rcb = false;
    int rp = -1;
    for (int i = N - 1; i >= 0; i--) {
        if (S[i] == ']') {
            found_rcb = true;
        }
        if (found_rcb && S[i] == ':') {
            rp = i;
            break;
        }
    }
    if (rp == -1) {
        cout << -1 << '\n';
        return 0;
    }
    bool found_cb = false, can_count = false;
    int len = 4;
    for (int i = 0; i < rp; i++) {
        if (can_count && S[i] == '|') {
            len++; continue;
        }
        if (S[i] == '[') {
            found_cb = true;
        }
        if (found_cb && S[i] == ':') {
            can_count = true;
        }
    }
    if (can_count)
        cout << len << '\n';
    else
        cout << -1 << '\n';
    return 0;
}
