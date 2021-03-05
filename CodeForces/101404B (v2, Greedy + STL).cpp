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

const int MAXN = 1005;

ii vals[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n; cin >> n;
        string s; cin >> s;
        forn(i,n) cin >> vals[i].fst >> vals[i].snd;

        auto cmp = [](const ii &lhs, const ii &rhs) { // al swappear se hace igual, no olvidarse de favorecer al otro
            if (lhs.fst == rhs.fst) return lhs.snd < rhs.snd;
            return lhs.fst > rhs.fst;
        };

        sort(vals,vals+n,cmp);

        int idx = 0;
        ll pr = 0, jr = 0;
        if (s == "Petra") idx++, pr += vals[0].fst;

        forn(i,n) swap(vals[i].fst,vals[i].snd); // así en la PQ está para orden de Jan

        priority_queue<ii,vector<ii>,decltype(cmp)> Q(cmp);
        for (int i = idx; i < n; i += 2) { // agarro de un mov, el mejor de dos (porque no puedo dos consec), y saco el peor (si agarro dos consec, es porque lo reemplazo por orden alguno anterior)
            if (i+1 >= n) {Q.push(vals[i]); break;}
            Q.push(vals[i]), Q.push(vals[i+1]);
            pr += Q.top().snd, Q.pop();
        }

        while (!Q.empty()) jr += Q.top().fst, Q.pop();

        cout << pr << ' ' << jr << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
