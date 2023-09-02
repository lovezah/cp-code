#include <bits/stdc++.h>
using namespace std;

template<class T> struct matrix {
    int n, m;
    std::vector<T> v;
    matrix() : matrix(0, 0) {}
    matrix(int n_, int m_, T val = T()) : n(n_), m(m_), v(n * m, val) {}

    T& operator [](std::array<int, 2> c) {
        assert(0 <= c[0] && c[0] < n);
        assert(0 <= c[1] && c[1] < m);
        return v[c[0] * m + c[1]];
    }
    const T& operator [](std::array<int, 2> c) const {
        assert(0 <= c[0] && c[0] < n);
        assert(0 <= c[1] && c[1] < m);
        return v[c[0] * m + c[1]];
    }

    matrix power(long long p) {
        assert(n == m);
        matrix res(n, m), tmp = *this;
        for (int i = 0; i < n; i++)
            res[{i,i}] = 1;
        for (; p; p /= 2) {
            if (p & 1) res = res * tmp;
            tmp = tmp * tmp;
        }
        return res;
    }
    matrix& operator *= (const matrix &o) {
        return *this = *this * o;
    }
    matrix& operator += (const matrix &o) {
        assert(n == o.n && m == o.m);
        for (int i = 0; i < n * m; i++)
            v[i] += o.v[i];
        return *this;
    }
    matrix& operator -= (const matrix &o) {
        assert(n == o.n && m == o.m);
        for (int i = 0; i < n * m; i++)
            v[i] -= o.v[i];
        return *this;
    }
    friend matrix operator * (const matrix &a, const matrix &b) {
        assert(a.m == b.n);
        matrix r(a.n, b.m, 0);
        for (int i = 0; i < a.n; i++)
            for (int j = 0; j < b.m; j++)
                for (int k = 0; k < a.m; k++)
                    r[{i,j}] += a[{i,k}] * b[{k,j}];
        return r;
    }
    friend matrix operator + (const matrix &a, const matrix &b) {
        return matrix(a) += b;
    }
    friend matrix operator - (const matrix &a, const matrix &b) {
        return matrix(a) -= b;
    }
};
