template <class A, class B, class C, class D>
std::pair<A, B>& operator+=(std::pair<A, B>& x, const std::pair<C, D>& y) {
    return x = {x.first + y.first, x.second + y.second};
}
template <class A, class B, class C, class D> std::pair<A, B> operator+(std::pair<A, B> x, const std::pair<C, D>& y) {
    return x += y;
}
