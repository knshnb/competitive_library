template <class T, class S> vector<T> make_vec(size_t n, S x) { return vector<T>(n, x); }
template <class T, class... Ts> auto make_vec(size_t n, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(n, make_vec<T>(ts...));
}
