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

ii blocks[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n,k; cin >> n >> k;
        string s; cin >> s;
        int cnt = 0, ind = -1, bk = 0; bool foundW = false;
        forn(j,n) {
            if (!foundW) {if (s[j] == 'L') continue; else foundW = true;}
            if (s[j] == 'L') {cnt++; if (ind == -1) ind = j;}
            else {
                if (ind == -1) continue;
                blocks[bk++] = {cnt,ind};
                cnt = 0; ind = -1;
            }
        }
        sort(blocks,blocks+bk);
        vi ord; forn(j,n) if (s[j] == 'W') break; else ord.pb(j);
        while (!ord.empty()) {blocks[bk++] = {1,ord.back()}; ord.pop_back();}
        if (foundW) {dforn(j,n) if (s[j] == 'W') break; else ord.pb(j);}
        while (!ord.empty()) {blocks[bk++] = {1,ord.back()}; ord.pop_back();}
        forn(j,bk)
            if (k > 0) for (int o = blocks[j].snd; o-blocks[j].snd < blocks[j].fst && k > 0; o++)
                s[o] = 'W', k--;

        int rta = 0;
        forn(j,n) rta += (s[j] == 'W')+(j-1 >= 0 && s[j-1] == 'W' && s[j] == 'W');

        cout << rta << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
