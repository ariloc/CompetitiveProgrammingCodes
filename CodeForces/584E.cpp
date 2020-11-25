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

const int MAXN = 2002;
const int INF = 1e9+5;

ii p[MAXN];
int s[MAXN];
vector<ii> mov;
ll sum = 0;

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {
        int x; cin >> x;
        p[i] = {x,i};
    }
    forn(i,n) cin >> s[i];

    forn(i,n) forn(j,n) if (s[j] == p[i].fst) {p[i].snd = j; break;}

    int ind = -1;
    forn(j,n) forn(i,n) {
        if (p[i].snd != i) {
            if (p[i].snd < i) {
                if (ind != -1) {
                    mov.pb({ind+1,i+1});
                    sum += i-ind; swap(p[i],p[ind]);
                    ind = -1;
                }
            } else ind = i;
        }
    }

    cout << sum << '\n' << mov.size() << '\n';
    for (auto &i : mov) cout << i.fst << ' ' << i.snd << '\n';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
