// ret[x]: xの約数のvector
// 構築: O(nlogn)
vector<vector<signed>> divisor(signed n) {
    vector<vector<signed>> ret(n + 1);
    for (signed i = 1; i < n + 1; i++) {
        ret[i].reserve(log(n) + 1);
    }
    for (signed i = 1; i < n + 1; i++) {
        for (signed j = i; j < n + 1; j += i) {
            ret[j].push_back(i);
        }
    }
    return ret;
}
