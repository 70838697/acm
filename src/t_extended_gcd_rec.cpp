//T must be a signed type, such as int, long.
template <class T> T ext_gcd(T n, T m, T &x, T &y) {
    if (m == 0) {
        x = 1;
        y = 0;
        return n;
    }
    T g = ext_gcd(m, n % m, x, y);
    T t = x - n / m * y;
    x = y;
    y = t;
    return g;
}