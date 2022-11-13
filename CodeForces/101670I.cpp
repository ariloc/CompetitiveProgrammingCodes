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

const int MAXN = 1e5+5;
const int INF = 2e9;

struct pt {
    int x,y;
    pt(){}
    pt(int x, int y) : x(x), y(y) {}

    bool operator< (const pt &o) const {
        if (y != o.y) return y > o.y; // top to bottom 
        return x < o.x;
    }
};

pt coords[MAXN];
map<int,int> diag, diag2;

int main() {
    int n;
    while (scanf("%d",&n) != -1) {
        forn(i,n) scanf("%d %d", &coords[i].x, &coords[i].y);

        sort(coords, coords+n);
        diag.clear();
        diag2.clear();

        ld prob = 0;
        forn(i,n) {
            int cnt = 0;
            int s1 = coords[i].x - coords[i].y;
            int s2 = coords[i].x + coords[i].y;

            auto it1 = diag.find(s1);
            auto it2 = diag2.find(s2);

            if (it1 != diag.end()) cnt += (*it1).snd;
            if (it2 != diag2.end()) cnt += (*it2).snd;

            prob += (cnt/(ld)n) * (1/(ld)n);

            diag[s1]++; diag2[s2]++;
        }

        printf("%.7Lf\n", prob*2);
    }

    return 0;
}
