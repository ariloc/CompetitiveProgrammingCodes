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

const int MAXA = 26;
const int INF = 1e9+5;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        string s; cin >> s;
        vi prox((int)s.size()+2,-1),ant((int)s.size()+2,-1);

        int mov = 0;
        forn(j,s.size()) mov += min(s[j]-'A',('A'-s[j]+MAXA)%MAXA); // each letter

        int mini = INF;

        // caso mitad y mitad
        int prv = -1;
        forn(j,s.size()) if (s[j] != 'A') { // registro el próximo sin A para c/u
            if (prv != -1) prox[prv] = j;
            prv = j;
        }
        int nxt = -1;
        dforn(j,s.size()) if (s[j] != 'A') {
            if (nxt != -1) ant[nxt] = j;
            nxt = j;
        }
        forn(j,s.size()) if (s[j] != 'A')
            mini = min(mini,j*(1+(prox[j] != -1)) + (prox[j] != -1)*((int)s.size()-prox[j]));

        dforn(j,s.size()) if (s[j] != 'A')
            mini = min(mini,((int)s.size()-j)*(1+(ant[j] != -1)) + (ant[j] != -1)*ant[j]);

        cout << mov + (mini == INF ? 0 : mini) << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
