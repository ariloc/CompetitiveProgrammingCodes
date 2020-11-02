// https://www.hackerrank.com/contests/simulacro-1-oia-2020/challenges/problem-0-contest-timing
#include <bits/stdc++.h>

using namespace std;

int contest_timing(int D, int H, int M)
{
    int r = 0;
    if (D != 11) {
        r += 769; r += (D-12)*1440; r += M; r += H*60;
    }
    else if (H != 11) {
        r += 49; r += (H-12); r += M;
    }
    else r += (M-11);

    if (D < 11) return -1;
    if (D == 11 && H < 11) return -1;
    if (D == 11 && H == 11 && M < 11) return -1;

    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int D, H, M;
    cin >> D >> H >> M;

    cout << contest_timing(D, H, M) << endl;

    return 0;
}
