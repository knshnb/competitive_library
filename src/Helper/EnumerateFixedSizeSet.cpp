// |S| = kな集合(nCk)(昇順)
for (long long S = (1LL << k) - 1; S < (1LL << n);
     S = ((S | (S - 1)) + 1) | (((~(S | (S - 1)) & -~(S | (S - 1))) - 1) >> (__builtin_ctz(S) + 1))) {
}
