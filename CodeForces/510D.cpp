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

const int MAXN = 305;
const int MAXDP = 1<<10;
const int INF = 2e9;

ii cards[MAXN];
int dp[MAXDP];
map<int,int> F[MAXN];

void fact (int x, map<int,int> &f) {
    for (int i = 2; i*i <= x; i++)
        while (!(x%i)) x /= i, f[i]++;
    if (x > 1) f[x]++;
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> cards[i].snd;
    forn(i,n) cin >> cards[i].fst;

    forn(i,n) fact(cards[i].snd,F[i]);

    int mini = INF;
    forn(i,n) { // suponiendo que este está sí o sí
        int TOP = 1 << (int)F[i].size();

        forn(j,TOP) dp[j] = INF;
        dp[TOP - 1] = cards[i].fst;
        forn(j,n) {
            if (i != j) {
                int mk = 0, shift = 0;
                for (auto &k : F[i]) {
                    if (F[j].find(k.fst) != F[j].end()) mk |= (1<<shift);
                    shift++;
                }

                forn(k,TOP) dp[k & mk] = min(dp[k & mk], dp[k] + cards[j].fst);
            }
        }

        mini = min(mini,dp[0]);
    }

    if (mini == INF) cout << -1;
    else cout << mini;

    return 0;
}