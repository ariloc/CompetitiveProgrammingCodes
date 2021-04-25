#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
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
typedef unsigned long long ull;
typedef pair<int,int> ii;

const int X[] = {2,-2,2,-2};
const int Y[] = {1,1,-1,-1};
const int INF = 100;
const int MAXN = 8;

void fs (int &x) {
    int c; x = 0; bool neg = false;
    c = getchar_unlocked(); neg |= (c == '-');
    if (c < '0' || c > '9') c = getchar_unlocked(), neg |= (c == '-');
    for (; c>='0' && c<='9'; c = getchar_unlocked())
        x = 10*x + c-'0';
    if (neg) x *= -1;
}

void fp (ll x) {
    if (!x) {putchar_unlocked('0'); return;}
    int i = 19;
    char buf[20];
    while (x) buf[i--] = (x%10)+'0', x /= 10LL;
    while ((++i) < 20) putchar_unlocked(buf[i]);
}

int rta[MAXN][MAXN], no_mov = MAXN*MAXN;
vector<ii> posib[MAXN][MAXN];

bool backtrack (int x, int y, ull mk) {
    if (mk == ULLONG_MAX) {rta[y][x] = no_mov--; return true;}
    priority_queue<pair<int,ii>,vector<pair<int,ii>>,greater<pair<int,ii>>> toTry;
    for (auto &i : posib[y][x])
        toTry.push({posib[i.fst][i.snd].size(),i});

    while (!toTry.empty()) {
        auto e = toTry.top(); toTry.pop();
        ull flipBit = (((ull)1)<<(e.snd.fst*8+e.snd.snd));
        if (mk&flipBit) continue;
        if (backtrack(e.snd.snd,e.snd.fst,mk|flipBit)) {rta[y][x] = no_mov--; return true;}
    }
    return false;
}

void precompPosib () {
    forn(y,MAXN) forn(x,MAXN) {
        forn(l,2) forn(k,4) {
            int dX  = X[k], dY = Y[k];
            if (l) swap(dX,dY);
            int tX = x+dX, tY = y+dY;
            if (tX >= MAXN || tX < 0 || tY >= MAXN || tY < 0) continue;
            posib[y][x].pb({tY,tX});
        }
    }
}

int main() {
    int x,y; fs(x), fs(y); x--, y--;

    precompPosib();
    backtrack(x,y,(((ull)1)<<(y*8+x)));

    forn(i,MAXN) forn(j,MAXN) fp(rta[i][j]), putchar_unlocked(" \n"[j == MAXN-1]);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
