struct FFT {
    using comp = complex<double>;
    static void fft(vector<comp>& a, bool inv = false) {
        int N = a.size();
        if (N == 1) {
            return;
        }
        vector<comp> even(N / 2), odd(N / 2);
        for (int i = 0; i < N / 2; i++) {
            even[i] = a[2 * i];
            odd[i] = a[2 * i + 1];
        }
        fft(even, inv);
        fft(odd, inv);
        comp omega = polar(1.0, (-2 * inv + 1) * 2 * M_PI / N);
        comp acc_omega = comp(1);
        for (int i = 0; i < N / 2; i++) {
            a[i] = even[i] + acc_omega * odd[i];
            a[i + N / 2] = even[i] - acc_omega * odd[i];
            acc_omega *= omega;
        }
    }
    static void conv(vector<int>& a, vector<int>& b) {
        int N = 1;
        while (N < 2 * (max(a.size(), b.size() + 1))) {
            N *= 2;
        }
        vector<comp> ac(N, comp(0)), bc(N, comp(0));
        for (int i = 0; i < a.size(); i++) ac[i] = comp(a[i]);
        for (int i = 0; i < b.size(); i++) bc[i] = comp(b[i]);
        multiply(ac, bc);
        a.resize(N);
        for (int i = 0; i < N; i++) {
            a[i] = (int)(ac[i].real() + 0.5);
        }
    }

private:
    static void multiply(vector<comp>& a, vector<comp>& b) {
        int n = a.size();
        fft(a);
        fft(b);
        for (int i = 0; i < n; i++) {
            a[i] *= b[i] / comp(n);
        }
        fft(a, true);
    }
};
