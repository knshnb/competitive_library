template <class Dist, class Key, class Delta>  // Delta: Key, (Key, Dist -> void) -> void
std::map<Key, Dist> dijkstra(Key s, Delta delta) {
    std::map<Key, Dist> dist;
    using P = std::pair<Dist, Key>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> q;
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
