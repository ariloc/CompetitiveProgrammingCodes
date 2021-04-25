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

const int MAXN = 12;
const string refer = "codeforces";

int cant[MAXN];

int main() {
    //FAST_IO;

    forn (i,MAXN) cant[i] = 1;

    ll n; scanf("%lld",&n);
    ll tmp = 1, ind = 0; int cnt = 2;
    while (tmp < n) {
        tmp /= cant[ind];
        cant[ind] = cnt; tmp *= cnt;
        ind++; ind %= 10; if (!ind) cnt++;
    }

    forn (i,10) forn (j,cant[i]) printf("%c",refer[i]);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!