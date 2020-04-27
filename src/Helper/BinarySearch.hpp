/// @docs src/Helper/BinarySearch.md
template <class F> long long binary_search(long long ok, long long ng, F check) {
    while (std::abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;
        (check(mid) ? ok : ng) = mid;
    }
    return ok;
}
