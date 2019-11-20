int get_msb(long long x) {
    assert(x != 0);
    return 63 - __builtin_clzll(x);
}
int get_lsb(long long x) {
    assert(x != 0);
    return __builtin_ctzll(x);
}
