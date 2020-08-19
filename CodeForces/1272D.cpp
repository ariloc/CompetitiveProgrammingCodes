#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 2e5+2;

int num[MAXN],dpR[MAXN],dpL[MAXN];

int main() {
    FAST_IO;

    int N; cin >> N;
    forn (i,N) {cin >> num[i]; dpL[i] = dpR[i] = 1;}

    int j = 1, r = 1;
    forn (i,N) { // all subsegments increasing (no extra)
        if (j == i) j++;
        while (j < N and num[j] > num[j-1]) {
            dpR[j] = max(dpR[j],j-i+1);
            j++;
        }
        dpL[i] = max(dpL[i],j-i);
    }
    forsn (i,1,N-1) // best by removing ith element
        if (num[i+1]-num[i-1] > 0) r = max(r,dpR[i-1]+dpL[i+1]);
    forn (i,N) r = max({r,dpL[i],dpR[i]});

    cout << r;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!