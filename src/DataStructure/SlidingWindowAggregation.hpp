/// @docs src/DataStructure/SlidingWindowAggregation.md
template <class T, class F> struct SlidingWindowAggregation {
    const F op;
    const T e;
    std::stack<std::pair<T, T>> st1, st2;  // それぞれ、{val, acc}を要素に持つような前方向と後ろ方向のstack
    SlidingWindowAggregation(F op_, T e_) : op(op_), e(e_) { st1.emplace(e, e), st2.emplace(e, e); }
    int size() { return st1.size() + st2.size() - 2; }
    void push(T x) {
        T acc = op(st2.top().second, x);
        st2.emplace(x, acc);
    }
    void pop() {
        assert(st1.size() > 1 || st2.size() > 1);
        if (st1.size() > 1) {
            st1.pop();
        } else {
            while (st2.size() > 2) {
                T acc = op(st1.top().second, st2.top().first);
                st1.emplace(st2.top().first, acc);
                st2.pop();
            }
            st2.pop();
        }
    }
    T fold_all() { return op(st1.top().second, st2.top().second); }
};
template <class T, class F> auto make_swag(F op, T e_) { return SlidingWindowAggregation<T, F>(op, e_); }
