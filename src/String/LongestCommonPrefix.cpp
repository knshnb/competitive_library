template <class T = int> class SegTree {
    using VT = vector<T>;
    int orig_n;
    // k番目のノードの[l, r)について[a, b)を求める
    T query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return UNIT;
        }
        if (a <= l && r <= b) {
            return dat[k];
        }
        T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return f(vl, vr);
    }

public:
    int N;
    VT dat;
    function<T(T, T)> f;
    int UNIT;
    SegTree(int n, function<T(T, T)> f_, const T unit) {
        orig_n = n;
        f = f_;
        UNIT = unit;
        for (N = 1; N < n; N *= 2)
            ;
        dat = VT(2 * N - 1, UNIT);
    }
    SegTree(
        VT a = {}, function<T(T, T)> f_ = [](int a, int b) { return min(a, b); }, T unit = 1e15) {
        orig_n = a.size();
        f = f_;
        UNIT = unit;
        for (N = 1; N < a.size(); N *= 2)
            ;
        dat = VT(2 * N - 1);
        REP(i, a.size()) { dat[N - 1 + i] = a[i]; }
        for (int k = N - 2; k >= 0; k--) {
            dat[k] = f(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
    // k番目をaに
    void update(int k, int a) {
        k += N - 1;
        dat[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = f(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
    // [a, b)でのクエリ
    T query(int a, int b) {
        assert(0 <= a && a < b && b <= orig_n);
        return query(a, b, 0, 0, N);
    }
};

// SA-ISによるSuffix Arrayの実装。構築O(N)
class SuffixArray {
    vector<int> sa_is(const vector<int>& str, const int k) {
        const int n = str.size();
        vector<bool> is_S(n);
        is_S[n - 1] = true;
        vector<bool> is_LMS(n);
        vector<int> LMSs;
        for (int i = n - 2; i >= 0; i--) {
            is_S[i] = str[i] < str[i + 1] || (str[i] == str[i + 1] && is_S[i + 1]);
        }
        REP(i, n) {
            if (is_S[i] & (i == 0 || !is_S[i - 1])) {
                is_LMS[i] = true;
                LMSs.push_back(i);
            }
        }
        vector<int> pseudo_sa = induced_sort(str, LMSs, is_S, k);
        vector<int> orderedLMSs(LMSs.size());
        int index = 0;
        for (int x : pseudo_sa) {
            if (is_LMS[x]) {
                orderedLMSs[index++] = x;
            }
        }
        pseudo_sa[orderedLMSs[0]] = 0;
        int rank = 0;
        if (orderedLMSs.size() > 1) {
            pseudo_sa[orderedLMSs[1]] = ++rank;
        }
        REPI(i, 1, orderedLMSs.size() - 1) {
            bool is_diff = false;
            REP(j, n) {
                int p = orderedLMSs[i] + j;
                int q = orderedLMSs[i + 1] + j;
                if (str[p] != str[q] || is_LMS[p] != is_LMS[q]) {
                    is_diff = true;
                    break;
                }
                if (j > 0 && is_LMS[p]) {
                    break;
                }
            }
            pseudo_sa[orderedLMSs[i + 1]] = is_diff ? ++rank : rank;
        }
        vector<int> new_str(LMSs.size());
        index = 0;
        REP(i, n) {
            if (is_LMS[i]) {
                new_str[index++] = pseudo_sa[i];
            }
        }
        vector<int> LMS_sa;
        if (rank + 1 == LMSs.size()) {
            LMS_sa = orderedLMSs;
        } else {
            LMS_sa = sa_is(new_str, rank + 1);
            for (int& x : LMS_sa) {
                x = LMSs[x];
            }
        }
        return induced_sort(str, LMS_sa, is_S, k);
    }

    vector<int> induced_sort(const vector<int>& str, const vector<int>& LMSs, const vector<bool>& is_S, const int k) {
        int n = str.size();
        vector<int> buckets(n);
        vector<int> chars(k + 1);
        for (int c : str) {
            chars[c + 1]++;
        }
        REP(i, k) { chars[i + 1] += chars[i]; }
        vector<int> count(k);
        for (int i = LMSs.size() - 1; i >= 0; i--) {
            int c = str[LMSs[i]];
            buckets[chars[c + 1] - 1 - count[c]++] = LMSs[i];
        }
        count = vector<int>(k);
        REP(i, n) {
            if (buckets[i] == 0 || is_S[buckets[i] - 1]) {
                continue;
            }
            int c = str[buckets[i] - 1];
            buckets[chars[c] + count[c]++] = buckets[i] - 1;
        }
        count = vector<int>(k);
        for (int i = n - 1; i >= 0; i--) {
            if (buckets[i] == 0 || !is_S[buckets[i] - 1]) {
                continue;
            }
            int c = str[buckets[i] - 1];
            buckets[chars[c + 1] - 1 - count[c]++] = buckets[i] - 1;
        }
        return buckets;
    }

public:
    string S;
    int N;
    vector<int> sa;  // sa[i]: suffixが辞書順i番目となる開始位置のindex
    SuffixArray(string str_in) : S(str_in), N(str_in.size()) {
        str_in += "$";
        vector<int> str(N + 1);
        REP(i, N + 1) { str[i] = str_in[i] - '$'; }
        sa = sa_is(str, 128);
        sa.erase(sa.begin());
    }
    int operator[](int index) { return sa[index]; }

    // sizeがTと等しく初めてT以上になるようなSの部分文字列(sa)
    vector<int>::iterator lower_bound(string T) {
        int l = -1, r = N;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (S.compare(sa[mid], T.size(), T) < 0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return sa.begin() + r;
    }

    // sizeがTと等しく初めてTより大きくなるようなSの部分文字列(sa)
    vector<int>::iterator upper_bound(string T) {
        int l = -1, r = N;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (S.compare(sa[mid], T.size(), T) <= 0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return sa.begin() + r;
    }

    // S2が部分文字列として何回出現するか
    int count(string S2) { return upper_bound(S2) - lower_bound(S2); }
};

class LongestCommonPrefix {
    SegTree<> rmq;
    vector<int> lcp;  // lcp[i]: S[sa[i]..]とS[sa[i + 1]..]が先頭何文字一致しているか、lcp[N - 1] = 0
    vector<int> lcp_begin;  // lcp_begin[i]: S[0..]とS[i]が先頭何文字一致しているか
public:
    const string S;
    int N;
    vector<int> sa;
    vector<int> rank;  // rank[i]: iから始まるsuffixの辞書順での順位
    LongestCommonPrefix();
    LongestCommonPrefix(const string& str) : S(str), N(str.size()), rank(str.size()), lcp(str.size()) {
        sa = SuffixArray(str).sa;
        // rankの設定
        REP(i, N) { rank[sa[i]] = i; }
        // S[i]を順番に見ていきS[i - 1] -　1文字以上が共通することを利用してしゃくとり
        lcp = vector<int>(N);
        int h = 0;
        REP(i, N) {
            if (h > 0) h--;
            if (rank[i] == N - 1) continue;
            int j = sa[rank[i] + 1];  // 比べる対象(辞書順が一つ大きいもの)
            for (; i + h < N && j + h < N; h++) {
                if (S[i + h] != S[j + h]) break;
            }
            lcp[rank[i]] = h;
        }
        // 必要に応じてコメントアウト
        set_query1();
        set_query2();
    }
    int operator[](int index) { return lcp[index]; }

    // S[i..], S[j..]が先頭何文字一致しているか
    int query(int i, int j) {
        assert(0 <= i && 0 <= j && i < N && j < N);
        if (i == j) return N - i;
        int l = min(rank[i], rank[j]);
        int r = max(rank[i], rank[j]);
        return rmq.query(l, r);
    }
    void set_query2() {
        // S[i..], S[j..]のlcpが求められるようにRMQ上にのせる
        rmq = SegTree<int>(
            lcp, [](int a, int b) { return min(a, b); }, 1e15);
    }

    // S[i..]がS[0..]と先頭文字一致しているか
    int query(int i) { return lcp_begin[i]; }
    void set_query1() {
        lcp_begin = vector<int>(N);
        lcp_begin[0] = N;
        for (int i = rank[0] - 1; i >= 0; i--) {
            lcp_begin[sa[i]] = min(lcp_begin[sa[i + 1]], lcp[i]);
        }
        for (int i = rank[0] + 1; i < N; i++) {
            lcp_begin[sa[i]] = min(lcp_begin[sa[i - 1]], lcp[i - 1]);
        }
    }
};
