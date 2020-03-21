---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: src/String/Trie.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac276d2326c527c8c7dbcbb63d85c6c7">src/String</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/String/Trie.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-06 23:02:24+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/String/Trie.cpp"
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

