#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 805;
int const X[] = {0,1,-1,0};
int const Y[] = {1,0,0,-1};

char pic[MAXN][MAXN];

ll euclid(ll a, ll b, ll& x, ll& y){ // a*(x+k*(b/d))+b*(y-k*(a/d))=d
	if(!b){x=1;y=0;return a;}          // (for any k)
	ll d=euclid(b,a%b,x,y);
	ll t=y;y=x-(a/b)*y;x=t;
	return d;
}

ii calc(int n)  {
    int sumcol = 0, sumrow = 0, w = 0;
    forn(i,n) forn(j,n) if (pic[i][j] == '#') sumrow += i, sumcol += j, ++w;
    sumcol %= n, sumrow %= n;
    ll winv,auxi;
    euclid(w,n,winv,auxi);
    winv = (winv + n)%n;
    sumcol = (sumcol * winv)%n, sumrow = (sumrow * winv)%n;
    return {sumrow,sumcol};
}

int main() {
    FAST_IO;

    string s; cin >> s;

    if (s == "first") {
        int t; cin >> t;
        forn(_,t) {
            int n; cin >> n;
            forn(i,n) forn(j,n) cin >> pic[i][j];
            int r,c; cin >> r >> c; --r, --c;

            int sumcol = 0, sumrow = 0, w = 0;
            forn(i,n) forn(j,n) if (pic[i][j] == '#') sumrow += i, sumcol += j, ++w;
            sumcol %= n, sumrow %= n;

            ii c1, c2;
            c1 = c2 = {0,0}; // swap with itself when not found (dc = dr = 0)
            int dc = (w * (ll)c - sumcol)%n , dr = (w * (ll)r - sumrow)%n;
            forn(i,n) forn(j,n) if (pic[i][j] == '#') {
                int ti = (i+dr+n)%n, tj = (j+dc+n)%n;
                if (pic[ti][tj] == '.') c1 = {i,j}, c2 = {ti,tj};
            }

            cout << c1.fst+1 << ' ' << c1.snd+1 << ' ';
            cout << c2.fst+1 << ' ' << c2.snd+1 << '\n';
        }
    }
    else {
        int t; cin >> t;
        forn(_,t) {
            int n; cin >> n;
            forn(i,n) forn(j,n) cin >> pic[i][j];
            ii auxi = calc(n);
            cout << auxi.fst+1 << ' ' << auxi.snd+1 << '\n';
        }
    }

    return 0;
}
