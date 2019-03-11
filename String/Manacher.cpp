template <class T>
vector<int> manacher(const vector<T>& s) {
  vector<int> R(s.size());
  int i = 0, j = 0;
  while (i < s.size()) {
    while (i-j >= 0 && i+j < s.size() && s[i-j] == s[i+j]) ++j;
    R[i] = j;
    int k = 1;
    while (i-k >= 0 && i+k < s.size() && k+R[i-k] < j) R[i+k] = R[i-k], ++k;
    i += k; j -= k;
  }
  return R;
}

struct Manacher {
  vector<int> a;
  template <class T> Manacher(const vector<T>& s, T DUMMY = -1) {
    int m = s.size() * 2 - 1;
    vector<T> t(m, DUMMY);
    for (int i = 0; i < s.size(); i++) {
      t[i * 2] = s[i];
    }
    a = manacher(t);
  }
  Manacher(const string& s, char DUMMY = '$') {
    int m = s.size() * 2 - 1;
    vector<char> t(m, DUMMY);
    for (int i = 0; i < s.size(); i++) {
      t[i * 2] = s[i];
    }
    a = manacher(t);
  }

  // [l, r)が回文かどうか
  bool is_palindrome(int l, int r) {
    return a[l + r - 1] >= r - l;
  }
};
