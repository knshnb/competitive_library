template <class T, class S> T make_vec(S x) { return x; }
template <class T, class... Ts> auto make_vec(size_t n, Ts... ts) {
    return std::vector<decltype(make_vec<T>(ts...))>(n, make_vec<T>(ts...));
}
