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

const int MAXN = 3e5+2;

struct rectang {
    int x,y,d,id; // side1, side2, other dimesnsion, id

    bool operator< (const rectang &o) const{
        if (o.x == x) {
            if (o.y == y) return o.d > d;
            return o.y > y;
        }
        return o.x > x;
    }
};

bool compareStones (rectang &a, rectang &b) {
    if (a.x == b.x and a.y == b.y) return true;
    return false;
}

rectang stones[MAXN]; int sz = 0;

int main() {
    FAST_IO;

    int N; cin >> N;

    forn (i,N) {
        int s[3]; cin >> s[0] >> s[1] >> s[2];
        sort(s,s+3);

        stones[sz++] = {s[0],s[1],s[2],i+1};
        stones[sz++] = {s[0],s[2],s[1],i+1};
        stones[sz++] = {s[1],s[2],s[0],i+1};
    }

    sort(stones,stones+(3*N));

    int id1, id2, best = 0;
    int idS, bestS = 0;
    forn (i,3*N-1) {
        if (compareStones(stones[i],stones[i+1])) {
            int val = min({stones[i].x, stones[i].y, stones[i].d + stones[i+1].d});
            if (val > best)
                {best = val; id1 = stones[i].id; id2 = stones[i+1].id;}
        }
        int val2 = min({stones[i].x, stones[i].y, stones[i].d});
        if (val2 > bestS) {idS = stones[i].id; bestS = val2;}
    }

    if (best > bestS) cout << "2\n" << id1 << ' ' << id2;
    else cout << "1\n" << idS;

    return 0;
}