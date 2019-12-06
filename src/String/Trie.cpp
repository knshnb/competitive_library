template <char margin = 'A', int char_size = 26> struct Trie {
    struct TrieNode {
        array<int, char_size> node;
        TrieNode() { node.fill(-1); };
        typename array<int, char_size>::iterator begin() { return node.begin(); }
        typename array<int, char_size>::iterator end() { return node.end(); }
        int& operator[](int i) { return node[i]; }
    };
    vector<TrieNode> tree;
    vector<int> num;  // 部分木内の個数
    Trie() : tree(1), num(1) {}
    void insert(string& s) {
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
    void erase(string& s) {
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
