template <char margin = 'A', int char_size = 26>
struct Trie {
    struct TrieNode {
        array<int, char_size> node;
        TrieNode() { node.fill(-1); };
        typename array<int, char_size>::iterator begin() { return node.begin(); }
        typename array<int, char_size>::iterator end() { return node.end(); }
        int& operator[](int i) { return node[i]; }
    };
    vector<TrieNode> tree;
    vector<int> num;
    Trie() : tree(1), num(1) {}
    void add(string& s) {
        int t = 0;
        for (char c : s) {
            int d = c - margin;
            if (tree[t][d] == -1) {
                tree[t][d] = tree.size();
                tree.emplace_back();
                num.push_back(0);
            }
            t = tree[t][d];
        }
        num[t]++;
    }
};
