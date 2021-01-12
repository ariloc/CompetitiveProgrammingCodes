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

bool tryMe (string &s, ii obs) {
    ii coords = {0,0};
    forn(j,s.size()) {
        ii tmp = coords;
        if (s[j] == 'L') tmp.fst--;
        else if (s[j] == 'R') tmp.fst++;
        else if (s[j] == 'U') tmp.snd++;
        else tmp.snd--;

        if (tmp != obs) coords = tmp;
    }
    return (!coords.fst && !coords.snd);
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        string s; cin >> s;

        ii coords = {0,0}, rta = {0,0}; // x,y
        forn(j,s.size()) {
            if (s[j] == 'L') coords.fst--;
            else if (s[j] == 'R') coords.fst++;
            else if (s[j] == 'U') coords.snd++;
            else coords.snd--;
            if (tryMe(s,coords)) {rta = coords; break;}
        }

        cout << rta.fst << ' ' << rta.snd << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
