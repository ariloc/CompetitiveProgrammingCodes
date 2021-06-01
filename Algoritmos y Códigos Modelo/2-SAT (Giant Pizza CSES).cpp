// AC -> CSES - Giant Pizza

#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

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

void fastscan (int &x) {
    int c; x = 0;
    c=getchar_unlocked();
    for(; c>='0' && c <='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}

vi G[MAXN];
int stTime[MAXN], col[MAXN], posTopSort[MAXN];
bitset<MAXN> matched, rta;
int prox_libre = 1, actTime = 0, pos = 0;

vi pila;
int tarjan (int st) { // SCC con Tarjan
    stTime[st] = actTime++;
    pila.pb(st);

    int mini = actTime-1;
    for (auto &i : G[st]) {
        if (stTime[i] == -1) mini = min(mini,tarjan(i));
        if (!matched[i]) mini = min(mini,stTime[i]);
    }

    if (mini >= stTime[st])
        while (not pila.empty()) {
            int e = pila.back(); pila.pop_back();
            col[e] = prox_libre; matched[e] = true;

            // si están en la misma componente los opuestos chau, así que
            // no me importa que meta esto de la pila y lo cuente al revés
            // y directamente me guardo posiciones hipotéticas así puedo comparar
            // de a pares
            posTopSort[e] = pos++;

            if (e == st) {prox_libre++; break;}
        }

    return mini;
}

int main() {
    memset(stTime,-1,sizeof(stTime)); // reset, si no tengo tiempo inicio

    int n,m; fastscan(n); fastscan(m);
    forn(i,n) { // duplicar es +, de lo contrario -
        char s1,s2; int x1,x2;
        s1=getchar_unlocked(); getchar_unlocked();
        fastscan(x1);
        s2=getchar_unlocked(); getchar_unlocked();
        fastscan(x2);
        x1--; x2--;

        x1 *= 2; x2 *= 2; // duplico así tengo mis opuestos, adyacentes en el array
        // +1 si opuesto es positivo, osea si es negativo. Y x2 +1 si es positivo
        G[x1+(s1 == '-')].pb(x2+(s2 == '+'));
        // +1 x2 si opuesto es positivo, osea si es negativo. Y x1 +1 si es positivo
        G[x2+(s2 == '-')].pb(x1+(s1 == '+'));
    }

    forn(i,2*m) if (stTime[i] == -1) tarjan(i);

    bool posib = true;
    for (int i = 0; i < 2*m; i += 2) { // comparo adyacentes, salto de a 2
        if (col[i] == col[i+1]) {posib = false; break;} // y si están en la misma SCC, chau
        // si lo puse primero, está debajo en el topSort, y a es verdadero si está después de ¬a
        // es decir, al hacer el reverse con Tarjan, la posA < pos¬A.
        rta[(i+1)/2] = (posTopSort[i+1] < posTopSort[i]);
    }

    if (!posib) printf("IMPOSSIBLE");
    else forn(i,m) {putchar_unlocked(rta[i] ? '+' : '-'); putchar_unlocked(' ');}

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
