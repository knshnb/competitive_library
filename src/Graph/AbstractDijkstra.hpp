/// @docs src/Graph/AbstractDijkstra.md
template <class Dist, class Key, class Delta>  // Delta: Key from, (Key to, Dist d -> void) update -> void
std::map<Key, Dist> dijkstra(Key s, Delta delta) {
    std::map<Key, Dist> dist;
    using P = std::pair<Dist, Key>;
    auto cmp_first = [](const P& a, const P& b) { return a.first > b.first; };
    std::priority_queue<P, std::vector<P>, decltype(cmp_first)> q{cmp_first};
    q.push({dist[s] = Dist(), s});
    while (!q.empty()) {
        std::pair<Dist, Key> p = q.top();
        q.pop();
        if (dist[p.second] < p.first) continue;
        delta(p.second, [&](Key to, Dist d) -> void {
            if (dist.count(to) && dist[to] <= p.first + d) return;
            q.push({dist[to] = p.first + d, to});
        });
    }
    return dist;
}
