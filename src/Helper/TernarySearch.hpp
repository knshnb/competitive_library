/// @docs src/Helper/TernarySearch.md
template <class F, class T = long long> T ternary_search(T l, T r, F f, bool is_max = true) {
    auto g = [&f, &is_max](T x) { return is_max ? f(x) : -f(x); };
    while (std::abs(l - r) > 2) {
        Int m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
        if (g(m1) < g(m2))
            l = m1;
        else
            r = m2;
    }
    // 極値のindexは[l, r)の範囲で、abs(l - r) <= 2になっている
    if (l + 1 < r && g(l + 1) > g(l)) l = l + 1;
    return l;
}
