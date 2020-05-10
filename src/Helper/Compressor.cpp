template <class T> struct Compressor {
    std::vector<T> val;
    void insert(T x) { val.push_back(x); }
    void build() {
        std::sort(val.begin(), val.end());
        val.erase(std::unique(val.begin(), val.end()), val.end());
    }
    int operator[](T x) { return std::lower_bound(val.begin(), val.end(), x) - val.begin(); }
    int size() { return val.size(); }
};
