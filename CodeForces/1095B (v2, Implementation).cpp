#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int INF = 1e9+5;

int main() {
    FAST_IO;

    int n; cin >> n;
    int maxi1 = -1, maxi2 = -1, mini1 = INF, mini2 = INF;
    forn(i,n) {
        int x; cin >> x;
        if (x > maxi1) {swap(maxi1,maxi2); maxi1 = x;}
        else if (x > maxi2) maxi2 = x;
        if (x < mini1) {swap(mini1,mini2); mini1 = x;}
        else if (x < mini2) mini2 = x;
    }

    cout << min(maxi1-mini2,maxi2-mini1);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
