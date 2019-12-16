Int n = in();
vector<vector<Int>> g(n);
REP(i, n - 1) {
    Int u = in(), v = in();
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
}
