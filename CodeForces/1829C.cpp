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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int INF = 1e9;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;

        int mini1 = INF, mini2 = INF, mini3 = INF;
        forn(i,n) {
            int m; string s; cin >> m >> s;
            if (s == "01") mini1 = min(mini1,m);
            if (s == "10") mini2 = min(mini2,m);
            if (s == "11") mini3 = min(mini3,m);
        }
        if ((mini1 == INF || mini2 == INF) && mini3 == INF) cout << "-1\n";
        else cout << min(mini1+mini2, mini3) << '\n';
    }
    
    return 0;
}
