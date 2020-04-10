/// @docs src/String/SuffixArray.md
class SuffixArray {
    std::vector<int> sa_is(const std::vector<int>& str, const int k) {
        const int n = str.size();
        std::vector<bool> is_S(n);
        is_S[n - 1] = true;
        std::vector<bool> is_LMS(n);
        std::vector<int> LMSs;
        for (int i = n - 2; i >= 0; i--) {
            is_S[i] = str[i] < str[i + 1] || (str[i] == str[i + 1] && is_S[i + 1]);
        }
        for (int i = 0; i < n; i++) {
            if (is_S[i] & (i == 0 || !is_S[i - 1])) {
                is_LMS[i] = true;
                LMSs.push_back(i);
            }
        }
        std::vector<int> pseudo_sa = induced_sort(str, LMSs, is_S, k);
        std::vector<int> orderedLMSs(LMSs.size());
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
        for (int i =  1; i < orderedLMSs.size() - 1; i++) {
            bool is_diff = false;
            for (int j = 0; j < n; j++) {
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
        std::vector<int> new_str(LMSs.size());
        index = 0;
        for (int i = 0; i < n; i++) {
            if (is_LMS[i]) {
                new_str[index++] = pseudo_sa[i];
            }
        }
        std::vector<int> LMS_sa;
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

    std::vector<int> induced_sort(const std::vector<int>& str, const std::vector<int>& LMSs, const std::vector<bool>& is_S, const int k) {
        int n = str.size();
        std::vector<int> buckets(n);
        std::vector<int> chars(k + 1);
        for (int c : str) {
            chars[c + 1]++;
        }
        for (int i = 0; i < k; i++) { chars[i + 1] += chars[i]; }
        std::vector<int> count(k);
        for (int i = LMSs.size() - 1; i >= 0; i--) {
            int c = str[LMSs[i]];
            buckets[chars[c + 1] - 1 - count[c]++] = LMSs[i];
        }
        count = std::vector<int>(k);
        for (int i = 0; i < n; i++) {
            if (buckets[i] == 0 || is_S[buckets[i] - 1]) {
                continue;
            }
            int c = str[buckets[i] - 1];
            buckets[chars[c] + count[c]++] = buckets[i] - 1;
        }
        count = std::vector<int>(k);
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
    std::string S;
    int N;
    std::vector<int> sa;  // sa[i]: suffixが辞書順i番目となる開始位置のindex
    SuffixArray(std::string str_in) : S(str_in), N(str_in.size()) {
        str_in += "$";
        std::vector<int> str(N + 1);
        for (int i = 0; i < N + 1; i++) { str[i] = str_in[i] - '$'; }
        sa = sa_is(str, 128);
        sa.erase(sa.begin());
    }
    int operator[](int index) { return sa[index]; }

    // sizeがTと等しく初めてT以上になるようなSの部分文字列(sa)
    std::vector<int>::iterator lower_bound(std::string T) {
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
    std::vector<int>::iterator upper_bound(std::string T) {
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
    int count(std::string S2) { return upper_bound(S2) - lower_bound(S2); }
};
