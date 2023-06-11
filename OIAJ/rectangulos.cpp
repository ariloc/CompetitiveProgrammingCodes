#include <algorithm>
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

const int MAXN = 5005;
const int INF = 2e9;

struct pt {
    int x,y,id;

    pt() {}
    pt(int a, int b, int c) : x(a), y(b), id(c) {}

    bool operator< (const pt &o) const {
        if (x != o.x) return x < o.x;
        return y < o.y;
    }
};

vector<pt> pts;
vector<vector<pt>> groups;
vector<pt> filtered;
int dp[MAXN];

int query_mid (int l, int r) {
    int s = 0;
    forsn(i,l,r+1) s += (int)groups[i].size();

    int acc = 0;
    int dif = INF, choose = -1;
    forsn(i,l,r+1) {
        acc += (int)groups[i].size() * 2;
        if (abs(s-acc) < dif) choose = i, dif = abs(s-acc);
    }
    return choose;
}

int consulta(int i,int W,int H);

int rectangulos(vector<int> x, vector<int> y) {
    int n = (int)x.size();
    forn(i,n) pts.pb(pt(x[i],y[i],i+1));

    sort(all(pts));

    int prv = -INF;
    forn(i,n) {
        if (pts[i].x != prv) {
            groups.pb({});
            prv = pts[i].x;
        }
        groups.back().pb(pts[i]);
    }

    int m = (int)groups.size();

    int low = -1, high = m-1;
    while (high - low > 1) {
        int mid = query_mid(low+1,high);
        int dif = max(1, 2*(groups[mid].back().x - groups[0].back().x));
        //cerr << low << ' ' << high << ' ' << mid << endl;
        if (consulta(groups[0].back().id,dif,INF)) high = mid;
        else low = mid;
    }

    filtered = groups[high];
    low = -1, high = (int)filtered.size()-1;
    while (high - low > 1) {
        int mid = (high + low)/2;
        int dif = max(1, 2*(filtered[mid].y - filtered[0].y));
        if (consulta(filtered[0].id,1,dif)) high = mid;
        else low = mid;
    }

    return filtered[high].id;
}
