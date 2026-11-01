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

int const INF = 2e9;

vector<ii> pts;

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;

    int t,d,l,r;
    l = t = INF, d = r = -INF;
    forn(i,n) {
        int R,C; cin >> R >> C;
        pts.pb({R,C});
        r = max(r,C);
        l = min(l,C);
        t = min(t,R);
        d = max(d,R);
    }

    if (n == 1) return cout << "1\n", 0;

    vector<ii> corn = {{t,r},{t,l},{d,r},{d,l}};

    ll maxi = 0;
    forn(i,k+1) 
        maxi = max(maxi, (abs(r-l)+1+i) * (ll)(abs(t-d)+1+k-i));
    for (auto &i : pts) {
        for (auto &c : corn) {
            int cx = abs(r-l)+1, cy = abs(t-d)+1;
            int dy = abs(c.fst-i.fst), dx = abs(c.snd-i.snd);
            int curk = k;
            int mov = min(dx,dy);
            curk -= mov;
            if (curk <= 0) continue;
            dx -= mov, dy -= mov;
            if (dx) cy += min(dx,curk), curk -= min(dx,curk);
            else cx += min(dy,curk), curk -= min(dy,curk);
            cx += curk, cy += curk;
            maxi = max(maxi, cx * (ll)cy);
        }
    }

    cout << maxi << '\n';

    return 0;
}
