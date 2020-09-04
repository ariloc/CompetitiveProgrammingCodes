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

const int MAXN = 2e5+5;
const int INF = 1e9+5;

vi G[MAXN];
int tin[MAXN],col[MAXN],posTP[MAXN],actT = 0,pos = 0,prox_libre = 1;
bool matched[MAXN];

vi pila;
int tarjan(int st) {
    tin[st] = actT++;
    pila.pb(st);

    int mini = actT-1; // min tin[]
    for (auto &i : G[st]) {
        if (tin[i] == -1) mini = min(tarjan(i),mini);
        if (!matched[i]) mini = min(tin[i],mini);
    }

    if (mini >= tin[st]) {
        while (not pila.empty()) {
            auto e = pila.back(); pila.pop_back();
            matched[e] = true; col[e] = prox_libre;
            posTP[e] = pos++;
            if (e == st) {prox_libre++; break;}
        }
    }
    return mini;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn (i,t) {
        string s,rta; cin >> s;

        forn(j,MAXN) {
            G[j].clear();
            tin[j] = -1;
            col[j] = posTP[j] = matched[j] = 0;
        }
        actT = pos = 0; prox_libre = 1; // reset

        rta.resize((int)s.size(),'x');
        int x; cin >> x;

        // 0 false, +1 true
        bool posib = true;
        forn(j,s.size()) {
            int rew = j-x, fwd = j+x;
            if (rew >= 0 and fwd < (int)s.size()) {
                if (s[j] == '1') {
                    G[2*rew].pb(2*fwd+1); // si uno es falso, el otro es verdadero
                    G[2*fwd].pb(2*rew+1);
                }
                else {
                    G[2*rew+1].pb(2*rew); // tengo que ser 0
                    G[2*fwd+1].pb(2*fwd);
                }
            }
            else if (rew >= 0) G[2*rew+(s[j]=='0')].pb(2*rew+(s[j]=='1'));
            else if (fwd < (int)s.size()) G[2*fwd+(s[j]=='0')].pb(2*fwd+(s[j]=='1'));
            else if (s[j] == '1') posib = false; // caso hay un 1 donde no llego a nada
        }

        forn(j,2*(int)s.size()) if (tin[j] == -1) tarjan(j);
        for (int j = 0; j < 2*(int)s.size(); j+=2) {
            if (col[j] == col[j+1]) {posib = false; break;}
            rta[(j+1)/2] = (posTP[j+1] < posTP[j])+'0';
        }
        if (posib) cout << rta << '\n';
        else cout << "-1\n";
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
