/// @docs src/Helper/MakeFixPoint.md
template <typename F> struct FixPoint : F {
    FixPoint(F&& f) : F(std::forward<F>(f)) {}
    template <typename... Args> decltype(auto) operator()(Args&&... args) const {
        return F::operator()(*this, std::forward<Args>(args)...);
    }
};
template <typename F> decltype(auto) make_fix_point(F&& f) { return FixPoint<F>{std::forward<F>(f)}; }
