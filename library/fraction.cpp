template<class T> struct fraction {
    T a;
    T b;
    fraction() : a(0), b(1) {}
    fraction(T x) : a(x), b(1) {}
    fraction(T x, T y) : a(x), b(y) { reduce(); }
    friend std::ostream& operator << (std::ostream& out, const fraction &n) { return out << n.a << '/' << n.b; }

    fraction neg() const {
        fraction res {-a, b};
        return res;
    }
    friend fraction neg(const fraction &m) { return m.neg(); }

    fraction abs() const {
        fraction res {a.abs(), b.abs()};
        return res;
    }
    friend fraction abs(const fraction &m) { return m.abs(); }

    fraction operator- () const {
        return neg();
    }
    fraction operator+ () const {
        return fraction(*this);
    }

    friend bool operator == (const fraction &x, const fraction &y) {
        return x.a * y.b == x.b * y.a;
    }
    friend bool operator != (const fraction &x, const fraction &y) {
        return x.a * y.b != x.b * y.a;
    }
    friend bool operator < (const fraction &x, const fraction &y) {
        return x.a * y.b < x.b * y.a;
    }
    friend bool operator <= (const fraction &x, const fraction &y) {
        return x.a * y.b <= x.b * y.a;
    }
    friend bool operator > (const fraction &x, const fraction &y) {
        return x.a * y.b > x.b * y.a;
    }
    friend bool operator >= (const fraction &x, const fraction &y) {
        return x.a * y.b >= x.b * y.a;
    }
    
    void reduce() {
        T g = gcd(a.abs(), b.abs());
        a /= g;
        b /= g;
        if (b < 0) { a = -a; b = -b; }
    }

    fraction& operator += (const fraction &o) {
        *this = {a * o.b + b * o.a, b * o.b};
        reduce();
        return *this;
    }
    fraction& operator -= (const fraction &o) {
        *this = {a * o.b - b * o.a, b * o.b};
        reduce();
        return *this;
    }
    fraction& operator *= (const fraction &o) {
        *this = {a * o.a, b * o.b};
        reduce();
        return *this;
    }
    fraction& operator /= (const fraction &o) {
        *this = {a * o.b, b * o.a};
        reduce();
        return *this;
    }
    friend fraction operator + (const fraction &a, const fraction &b) { return fraction(a) += b; }
    friend fraction operator - (const fraction &a, const fraction &b) { return fraction(a) -= b; }
    friend fraction operator * (const fraction &a, const fraction &b) { return fraction(a) *= b; }
    friend fraction operator / (const fraction &a, const fraction &b) { return fraction(a) /= b; }
};
