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

int const INF = 2e9+5;

struct box {
    int x,y,z;

    bool operator== (const box &o) const {
        return x == o.x & y == o.y && z == o.z;
    }

    bool operator<= (const box &o) const {
        return x <= o.x && y <= o.y && z <= o.z;
    }

    int area() {
        return x*y*z;
    }
};

vector<box> boxes;

int supercajas(int N, int X, int Y, int Z, vector<int> &a, vector<int> &b, vector<int> &c) {
    int m = sz(a);
    forn(i,m) {
        vi auxi = {a[i],b[i],c[i]};
        sort(all(auxi));
        boxes.pb({auxi[0],auxi[1],auxi[2]});
    }

    vi auxi = {X,Y,Z};
    sort(all(auxi));
    box p = {auxi[0],auxi[1],auxi[2]};
    int mini = INF;
    forn(i,m) {
        if (p <= boxes[i]) {
            int cnt = 0;
            forsn(j,i,m) cnt += (boxes[j] == boxes[i]);
            if (cnt >= N) {
                mini = min(mini, boxes[i].area() - p.area());
            }
        }
    }
    return mini == INF ? -1 : mini;
}
