# suffix array
* 	### [AHOI2013] 差异
    $\sum_{1\leq i< j\leq N}{\|T[i]\| + \|T[j]\| - 2 * lcp(T[i], T[j])}$
    
    其中T[i]表示从i开始的后缀。
    
    化简公式，每个后缀在式子中出现N-1次，一部分是当T[i]的贡献，一部分是T[j]的贡献，唯独没和自己贡献所以N-1次。

    主要是后面lcp的问题。对其求SA，问题转化为对ht数组做区间RMQ求和问题。用单调栈维护即可
    ```c++
    buildSA(S); 
    ll ans = (ll)(N - 1) * (N + 1) * N / 2; // 此为公式除了lcp部分的总和
    std::vector<int> L(N, 0), R(N, N); 
    std::vector<int> q; q.push_back(0);
    for (int i = 1; i < N; i++) {
        while (q.size() && ht[i] < ht[q.back()]) { // 对于右边界我们取小于号
            R[q.back()] = i;
            q.pop_back();
        }
        L[i] = q.back(); // 对于左边界我们取小于等于号（和右边界不同），防止求和重复或遗漏
        q.push_back(i);
    }
    for (int i = 1; i < N; i++) {
        ans -= 2LL * ht[i] * (i - L[i]) * (R[i] - i);
    }
    cout << ans << '\n';
    ```