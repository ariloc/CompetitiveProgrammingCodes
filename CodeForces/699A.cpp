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

const int MAXN = 2e5+2;
const int INF = 1e9+5;

int cL[MAXN], cR[MAXN], ind1 = 0, ind2 = 0;

int main() {
    FAST_IO;

    int n; cin >> n;
    string s; cin >> s;
    forn(j,n) {
        int x; cin >> x;
        if (s[j] == 'L') cL[ind1++] = x;
        else cR[ind2++] = x;
    }

    if (!ind1 || !ind2) return cout << -1, 0;

    int mini = INF;
    forn(j,ind2) {
        int pos = lower_bound(cL,cL+ind1,cR[j])-cL;
        if (pos >= ind1) continue;
        mini = min(mini,(cL[pos]-cR[j])/2);
    }

    if (mini == INF) return cout << -1, 0;
    cout << mini;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
