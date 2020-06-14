template <class T> std::vector<std::pair<T, int>> run_length_encode(const std::vector<T>& a) {
    std::vector<std::pair<T, int>> ret;
    int cur = 0;
    for (int i = 0; i < a.size(); i++) {
        cur++;
        if (i == a.size() - 1 || a[i] != a[i + 1]) {
            ret.emplace_back(a[i], cur);
            cur = 0;
        }
    }
    return ret;
}
std::vector<std::pair<char, int>> run_length_encode(const std::string& a) {
    std::vector<std::pair<char, int>> ret;
    int cur = 0;
    for (int i = 0; i < a.size(); i++) {
        cur++;
        if (i == a.size() - 1 || a[i] != a[i + 1]) {
            ret.emplace_back(a[i], cur);
            cur = 0;
        }
    }
    return ret;
}
