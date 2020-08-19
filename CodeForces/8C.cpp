#include <bits/stdc++.h>

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

const int MAXN = 24;
const int INF = 1e9+5;

int dp[(1<<MAXN)], calc[(1<<MAXN)];
int P[(1<<MAXN)];

ii coords[MAXN],st;

int dist (ii a, ii b) {
    return abs(a.fst-b.fst)*abs(a.fst-b.fst)+abs(a.snd-b.snd)*abs(a.snd-b.snd);
}

int main() {
    FAST_IO;

    memset(P,-1,sizeof(P));

    forn (i,(1<<MAXN)) {dp[i] = INF;}

    cin >> st.fst >> st.snd;
    int N; cin >> N;
    forn (i,N) cin >> coords[i].fst >> coords[i].snd;

    forn (i,N) { // marcando el bit i
        forn (j,N) { // con el bit k
            calc[((1<<i)|(1<<j))] = dist(st,coords[i])+dist(st,coords[j])+dist(coords[i],coords[j]);
        }
    }

    dp[0] = 0;
    forn (m,(1<<N)) {
        int add = 0, me = m;
        forn (j,N) if (!(m & (1<<j))) {add |= (1 << j); break;} // no importa el orden, nomás agarro uno
        me |= add;

        forn (j,N) { // y el otro
            if (m & (1<<j)) continue;
            int act = me, addAct = add;
            act |= (1<<j); addAct |= (1<<j);

            int calcMe = dp[m]+calc[addAct];
            if (dp[act] > calcMe) {
                dp[act] = calcMe;
                P[act] = m;
            }
        }
    }

    cout << dp[(1<<N)-1] << '\n';

    vi path; path.pb(0);
    int bm = (1<<N)-1;
    for (int i = (1<<N)-1; i != -1; i = P[i]) {
        //sum += calc[i];
        if (bm != i) {
            forn (j,MAXN) if (((1<<j) & bm)^((1<<j) & i)) path.pb(j+1);
            path.pb(0);
        }
        bm = i;
    }

    for (auto &i : path) cout << i << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!