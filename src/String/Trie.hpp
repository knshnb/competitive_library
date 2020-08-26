template <char margin = 'A', int char_size = 26> struct Trie {
    struct TrieNode {
        std::array<int, char_size> node;
        TrieNode() { node.fill(-1); };
        typename std::array<int, char_size>::iterator begin() { return node.begin(); }
        typename std::array<int, char_size>::iterator end() { return node.end(); }
        int& operator[](int i) { return node[i]; }
    };
    std::vector<TrieNode> tree;
    std::vector<int> num;  // 部分木内の個数
    Trie() : tree(1), num(1) {}
    void insert(const std::string& s) {
        num[0]++;
        int t = 0;
        for (char c : s) {
            int d = c - margin;
            if (tree[t][d] == -1) {
                tree[t][d] = tree.size();
                tree.emplace_back();
                num.push_back(0);
            }
            t = tree[t][d];
            num[t]++;
        }
    }
    void erase(const std::string& s) {
        int par = 0;
        num[par]--;
        for (char c : s) {
            int d = c - margin;
            int nxt = tree[par][d];
            assert(nxt != -1 && "s does not exist");
            if (--num[nxt] == 0) tree[par][d] = -1;
            par = nxt;
        }
    }
};
