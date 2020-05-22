template <class T> struct Compressor {
    std::vector<T> val;
    void insert(T x) { val.push_back(x); }
    void insert(const std::vector<T>& v) { val.insert(val.begin(), v.begin(), v.end()); }
    void build() {
        std::sort(val.begin(), val.end());
        val.erase(std::unique(val.begin(), val.end()), val.end());
    }
    int operator()(T x) { return std::lower_bound(val.begin(), val.end(), x) - val.begin(); }
    T operator[](int idx) { return val[idx]; }
    int size() { return val.size(); }
};
