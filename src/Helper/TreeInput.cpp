int n;
std::cin >> n;
std::vector<std::vector<int>> g(n);
for (int i = 0; i < n - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
}
