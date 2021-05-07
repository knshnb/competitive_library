template <class T> std::vector<T> xor_basis(const std::vector<T>& a) {
    std::vector<T> regularized, original_basis;
    for (const T x : a) {
        T sweeped = x;
        for (const T b : regularized) sweeped = std::min(sweeped, sweeped ^ b);
        if (sweeped) regularized.push_back(sweeped), original_basis.push_back(x);
    }
    return original_basis;
}