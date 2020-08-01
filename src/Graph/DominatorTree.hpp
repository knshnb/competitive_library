/// @docs src/Graph/DominatorTree.md
// 根付き森と、根から各頂点までのaggregationを管理
template <class T, class F> struct DirectedUnionFind {
    std::vector<int> par;
    std::vector<T> val;
    F op;
    DirectedUnionFind(F op_) : op(op_) {}
    void set_by_vector(const std::vector<T>& val_) {
        par.resize(val_.size()), std::iota(par.begin(), par.end(), 0);
        val = val_;
    }
    void set_by_value(int n, T a) {
        par.resize(n), std::iota(par.begin(), par.end(), 0);
        val.resize(n, a);
    }
    int compress(int v) {
        if (par[v] == v) return v;
        int root = compress(par[v]);
        val[v] = op(val[par[v]], val[v]);
        return par[v] = root;
    }
    int eval(int v) {
        compress(v);
        return val[v];
    }
    // rootをtoにつなげる
    void link(int to, int root) {
        assert(par[root] == root);
        par[root] = to;
    }
};
template <class T, class F> DirectedUnionFind<T, F> make_directed_unionfind(F op_) {
    return DirectedUnionFind<T, F>(op_);
}

// 親をさすvectorを返す。rootの親はroot、rootから到達できない頂点の親は-1
std::vector<int> construct_domnator_tree(const std::vector<std::vector<int>>& edge, int root) {
    int n = edge.size();
    std::vector<std::vector<int>> redge(n);
    for (int u = 0; u < n; u++)
        for (int v : edge[u]) redge[v].push_back(u);
    // dfs木を作る
    std::vector<int> par(n, -1), to_vertex, to_ord(n, -1);
    auto dfs = [&](auto&& self, int v) -> void {
        to_ord[v] = to_vertex.size();
        to_vertex.push_back(v);
        for (int u : edge[v]) {
            if (to_ord[u] != -1) continue;
            self(self, u);
            par[to_ord[u]] = to_ord[v];
        }
    };
    dfs(dfs, root);
    int m = to_vertex.size();  // rootから到達可能な頂点数
    // dfs逆順
    std::vector<int> sdom(m), U(m, -1);
    for (int i = 1; i < m; i++) sdom[i] = i;  // Theorem 4の左側をカバーできるように、iで初期化しておく
    auto uf = make_directed_unionfind<int>([&](int i, int j) { return sdom[i] < sdom[j] ? i : j; });
    uf.set_by_value(m, 0);
    for (int i = 0; i < m; i++) uf.val[i] = i;
    std::vector<std::vector<int>> bucket(n);
    for (int i = m - 1; i >= 1; i--) {
        // dfs逆順にsemidominatorを求める(Theorem 4)
        for (int v : redge[to_vertex[i]]) {
            int j = to_ord[v];
            if (j == -1) continue;  // rootから到達できない頂点
            sdom[i] = std::min(sdom[i], sdom[uf.eval(j)]);
        }
        // Corollary 1
        bucket[sdom[i]].push_back(i);
        for (int j : bucket[par[i]]) U[j] = uf.eval(j);
        uf.link(par[i], i);
    }
    // dfs順にimmediate dominatorを求める
    std::vector<int> idom(n, -1);  // dfs順序ではなくではなく元の頂点番号で表していることに注意！
    for (int i = 1; i < m; i++) {
        int u = U[i];
        idom[to_vertex[i]] = sdom[i] == sdom[u] ? to_vertex[sdom[i]] : idom[to_vertex[u]];
    }
    idom[root] = root;
    return idom;
}