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

const int MAXN = 1e6+5;

ii win[MAXN], lose[MAXN];
int idx1 = 0, idx2 = 0;

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {
        int a,b; cin >> a >> b;
        if (b >= a) win[idx1++] = {a,b};
        else lose[idx2++] = {a,b};
    }

    sort(win,win+idx1);
    sort(lose,lose+idx2,[](const ii &lhs, const ii &rhs){return lhs.snd > rhs.snd;});

    ll init = 0, act = 0;
    forn(i,idx1) {
        if (win[i].fst > act) init += win[i].fst-act, act = win[i].fst;
        act += win[i].snd; act -= win[i].fst;
    }

    forn(i,idx2) {
        if (lose[i].fst > act) init += lose[i].fst-act, act = lose[i].fst;
        act += lose[i].snd; act -= lose[i].fst;
    }

    cout << init;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
