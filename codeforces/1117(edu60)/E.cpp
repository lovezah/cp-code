#include <bits/stdc++.h>

using namespace std;

string query(string t) {
    cout << "? " << t << '\n';
    cout.flush();
    string a; cin >> a;
    return a;
}
void answer(string t) {
    cout << "! " << t << '\n';
    cout.flush();
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string S; cin >> S;
    int N = int(S.size());
    map<array<char, 3>, int> A;
    vector<array<char, 3>> B; B.reserve(N);
    for (char i = 'a'; i < 'z'; i++) {
        for (char j = 'a'; j < 'z'; j++) {
            for (char k = 'a'; k < 'z'; k++) {
                A[{i,j,k}] = B.size();
                B.push_back({i,j,k});
                if (B.size() == N) goto done;
            }
        }
    }
    done:;
    vector<string> ans;
    for (int i = 0; i < 3; i++) {
        string T;
        for (int j = 0; j < N; j++)
            T += B[j][i];
        ans.push_back(query(T));
    }
    string T(N, '?');
    for (int i = 0; i < N; i++) {
        array<char, 3> who;
        for (int j = 0; j < 3; j++) {
            who[j] = ans[j][i];
        }
        T[A[who]] = S[i];
    }
    answer(T);
    //bac
    //abc
    return 0;
}
