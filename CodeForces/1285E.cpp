#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int MAXN = 4e5+2;
const int INF = 1e9+5;

struct pt {
    int x,id; bool add;

    bool operator< (const pt &o) const {
        if (x == o.x) return add > o.add; // primero los add y luego los del, por si se reduce a un pto
        return x < o.x;
    }
};

pt pts[MAXN];
int ranges[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        forn(j,n) ranges[j] = 0; // reset
        forn(j,n) {
            int l,r; cin >> l >> r;
            pts[2*j] = {l,j,1};
            pts[2*j+1] = {r,j,0};
        }
        sort(pts,pts+n+n);
        set<int> ids; int cnt = 0, maxi = 0, addedPrev = -1, maxSuperp = 1;
        forn(j,2*n) {
            int ant = ids.size();
            while (true) {
                if (pts[j].add) ids.insert(pts[j].id);
                else ids.erase(pts[j].id);
                if (j+1 >= 2*n || pts[j+1].x != pts[j].x || pts[j+1].add != pts[j].add) break;
                j++;
            }
            if (ids.empty()) cnt++;
            else {
                if (addedPrev != -1)
                    ranges[addedPrev]++; maxi = max(maxi,ranges[addedPrev]);
                maxSuperp = max(maxSuperp,(int)ids.size());
            }
            addedPrev = -1;
            if (ids.size() == 1 && ant >= 1) addedPrev = *ids.begin();
        }

        cout << cnt+maxi+(-1)*(!maxi && maxSuperp == 1) << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
