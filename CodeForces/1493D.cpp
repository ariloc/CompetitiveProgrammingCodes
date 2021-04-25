#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const int INF = 1e9+5;

bitset<MAXN> done;
int spf[MAXN],n,q,dcm = 1;
map<int,int> byPosic[MAXN],byVal[MAXN];

void criba() {
    forn(i,MAXN) spf[i] = i;
    for (int i = 4; i < MAXN; i+=2) done[i] = true, spf[i] = 2;
    for (int i = 3; i*i < MAXN; i+=2)
        if (!done[i])
            for (int j = i+i; j < MAXN; j+=i)
                done[j] = true, spf[j] = i;
}

void solveN (int x, int pos) {
    int cnt = 0, prv = spf[x];
    while (x >= 1) {
        if (spf[x] != prv) {
            int i = prv;

            auto it = byPosic[i].find(pos);
            int prvVal = 0;
            if (!byVal[i].empty() && (int)byPosic[i].size() == n) prvVal = (*byVal[i].begin()).fst; // vale el anterior solo si toqué todos
            if (it != byPosic[i].end()) {
                auto it2 = byVal[i].find((*it).snd);
                (*it2).snd--;
                if (!((*it2).snd)) byVal[i].erase(it2);
            }
            byPosic[i][pos] += cnt;
            byVal[i][byPosic[i][pos]]++;

            int dif = (*byVal[i].begin()).fst-prvVal;
            if ((int)byPosic[i].size() == n) // si cambia y si toqué todos los nums
                while ( (--dif) >= 0) dcm = (dcm*(ll)i)%MOD;

            cnt = 0;
        }
        if (x <= 1) break;
        prv = spf[x], x /= prv, cnt++;
    }
}

int main() {
    FAST_IO;

    criba();

    cin >> n >> q;

    forn(i,n) {
        int x; cin >> x;
        solveN(x,i);
    }

    forn(i,q) {
        int p,x; cin >> p >> x; p--;
        solveN(x,p);
        cout << dcm << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
