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

const int MAXM = 5;

struct rondas {
    int mar[MAXM];
    int ind;

    bool operator< (const rondas &o) const {
        int cnt = 0;
        forn(i,MAXM) cnt += (mar[i] < o.mar[i]);
        return (cnt >= 3);
    }
};

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;

        vector<rondas> ath;
        forn(j,n) {
            rondas x;
            forn(k,MAXM) cin >> x.mar[k];
            x.ind = j;
            ath.pb(x);
        }

        sort(all(ath));

        bool posib = 1;
        forsn(j,1,n) if (!(ath[0] < ath[j])) posib = 0;

        if (posib) cout << ath[0].ind+1 << '\n';
        else cout << "-1\n";
        
    }

    return 0;
}