/// @docs src/String/ZAlgorithm.md
template <class T> std::vector<int> Z_algorithm(const T& s) {
    std::vector<int> a(s.size());
    for (int i = 1, rm_idx = 0; i < s.size(); i++) {
        if (a[i - rm_idx] < a[rm_idx] - (i - rm_idx)) {
            a[i] = a[i - rm_idx];
        } else {
            a[i] = std::max(0, a[rm_idx] - (i - rm_idx));
            while (i + a[i] < s.size() && s[a[i]] == s[i + a[i]]) a[i]++;
            rm_idx = i;
        }
    }
    a[0] = s.size();
    return a;
}
