#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long XS, YS, XG, YG; cin >> XS >> YS >> XG >> YG;
    int N; cin >> N;
    string S; cin >> S;
    vector<array<int, 4>> pref(N+1, array<int, 4>{});
    const string T = "UDLR";
    for (int i = 0; i < N; i++) {
        pref[i+1] = pref[i];
        for (int j = 0; j < 4; j++)
            if (S[i] == T[j])
                pref[i+1][j]++;
    }
    long long low = 0, high = (long long)1e16 + 1;
    while (low < high) {
        long long mid = (low + high) / 2;
        long long up = mid / N * pref[N][0] + pref[mid%N][0];
        long long down = mid / N * pref[N][1] + pref[mid%N][1];
        long long left = mid / N * pref[N][2] + pref[mid%N][2];
        long long right = mid / N * pref[N][3] + pref[mid%N][3];
        long long X = XS + right - left;
        long long Y = YS + up - down;
        if (abs(X - XG) + abs(Y - YG) <= mid)
            high = mid;
        else low = mid + 1;
    }
    if (low == (long long)1e16 + 1)
        low = -1;
    cout << low << '\n';
    return 0;
}
