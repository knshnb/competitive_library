// 自分を含んだK個前までの中での最小値のindexの配列を返す
// 最小(最大)値のindexを返すことに注意!
template <class T = int>
vector<int> slide_min(const vector<T>& a, int w, function<bool(T, T)> cmp = less<T>()) {
    int n = a.size();
    vector<int> ret(n);
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && !cmp(a[dq.back()], a[i])) {
            dq.pop_back();
        }
        dq.push_back(i);
        while (dq.front() <= i - w) {
            dq.pop_front();
        }
        ret[i] = dq.front();
    }
    return ret;
}
