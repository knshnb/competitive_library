auto check = [&](int mid) -> bool {};
Int ok = 0, ng = 1e18;
while (abs(ok - ng) > 1) {
    Int mid = (ok + ng) / 2;
    (check(mid) ? ok : ng) = mid;
}
