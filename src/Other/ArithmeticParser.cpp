// 四則演算のParser
#include <bits/stdc++.h>
#define int long long
using namespace std;

// exp1 = exp2 [ ('+'|'-') exp2 ]*
// exp2 = exp3 [ ('*'|'/') exp3 ]*
// exp3 = '(' exp1 ')' | number

int exp1(const string& s, int& i);
int exp2(const string& s, int& i);
int exp3(const string& s, int& i);
int number(const string& s, int& i);
int exp1(const string& s, int& i) {
    int acc = exp2(s, i);
    while (1) {
        if (s[i] == '+')
            acc += exp2(s, ++i);
        else if (s[i] == '-')
            acc -= exp2(s, ++i);
        else
            return acc;
    }
}
int exp2(const string& s, int& i) {
    int acc = exp3(s, i);
    while (1) {
        if (s[i] == '*')
            acc *= exp3(s, ++i);
        else if (s[i] == '/')
            acc /= exp3(s, ++i);
        else
            return acc;
    }
}
int exp3(const string& s, int& i) {
    if (s[i] == '(') {
        int ret = exp1(s, ++i);
        assert(s[i] == ')');
        i++;
        return ret;
    }
    return number(s, i);
}
int number(const string& s, int& i) {
    int acc = 0;
    while (isdigit(s[i])) {
        acc = acc * 10 + (s[i++] - '0');
    }
    return acc;
}

void solve() {
    string s;
    cin >> s;
    int i = 0;
    cout << exp1(s, i) << endl;
    assert(s[i] == '=');
}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}
