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
typedef long double ld;

const int MAXN = 1005;
const int INF = 2e9;

// ^\ |^ /^ > (0,1,2,3)
const int X[] = {-1, 0, 1, 1};
const int Y[] = {1,  1, 1, 0};

struct pt {
    int x,y;
    pt(){}
    pt(int x, int y) : x(x), y(y) {}

    bool operator< (const pt &o) const {
        if (y != o.y) return y < o.y;
        return x < o.x;
    }
};

// (x,y) -> (x,y+1)
// (x,y) -> (x+1,y)
// (x,y) -> (x+1,y+1)
// (x,y) -> (x-1,y+1)

pt segs[MAXN];
vector<pt> pts_input;

vector<ii> segsV_y[MAXN]; //   \ | /  (0,1,2)
vector<ii> segsH_x[MAXN]; //   \ - /  (0,1,2)
set<pt> hit[4]; // ^\ |^ /^ > (0,1,2,3)
set<pair<pt,pt>> hit_segs;

int getTyp (pt a, pt b) {
    if (a.x == b.x) return 0; // vertical
    if (a.y == b.y) return 1; // horizontal
    if (a.y > b.y || (a.y == b.y && a.x > b.x)) swap(a,b);
    if (b.x > a.x) return 2; // diag cw
    return 3; // diag ccw
}

pt rectifySlope (pt p, int typ, int sent) {
    pt a = p, b = pt(p.x + X[typ], p.y + Y[typ]);
    if (a.y > b.y || (a.y == b.y && a.x > b.x)) swap(a,b);
    
    switch (sent) {
        case 0: a.x = b.x = min(a.x,b.x); break;
        case 1: a.y = b.y = max(a.y,b.y); break;
        case 2: a.x = b.x = max(a.x,b.x); break;
        case 3: a.y = b.y = min(a.y,b.y); break;
    }

    if (a.y > b.y || (a.y == b.y && a.x > b.x)) swap(a,b);
    return a;
}

// coords: horiz is lower x, vert is lower y
// sentido de mov: 0,1,2,3 -> left-up-right-bottom
// son siempre segmentos a 0º o 90º, por lo que el sentido determina la orientación
void trySeg (pt coords, int sent) {
    int ind = -1;
    if (!sent || sent == 2) {
        if (sent == 2) ind = (int)(lower_bound(all(segsV_y[coords.y]),(ii){coords.x,1}) - segsV_y[coords.y].begin());
        else ind = (int)(upper_bound(all(segsV_y[coords.y]),(ii){coords.x,1}) - segsV_y[coords.y].begin()) - 1;

        if (ind >= 0 && ind < (int)segsV_y[coords.y].size()) {
            auto aux = segsV_y[coords.y][ind];

            if (hit[aux.snd].count(pt(aux.fst,coords.y))) return;
            hit[aux.snd].insert(pt(aux.fst,coords.y)); 

            if (aux.snd != 1) {
                int newSent = (sent + aux.snd + 1 + 4)%4; // depends on actual direction and slope
                pt toPt = rectifySlope(pt(aux.fst, coords.y), aux.snd, newSent);
                trySeg(toPt, newSent);
            }
        }
    }
    else {
        if (sent == 1) ind = (int)(lower_bound(all(segsH_x[coords.x]),(ii){coords.y,1}) - segsH_x[coords.x].begin());
        else ind = (int)(upper_bound(all(segsH_x[coords.x]),(ii){coords.y,1}) - segsH_x[coords.x].begin()) - 1;
        
        if (ind >= 0 && ind < (int)segsH_x[coords.x].size()) {
            auto aux = segsH_x[coords.x][ind];

            if (aux.snd == 0) aux.fst--, coords.x++; // caso especial, vuelvo a convencion original
            if (hit[(aux.snd == 1 ? 3 : aux.snd)].count(pt(coords.x,aux.fst))) return; // avoid infinite loop
            hit[(aux.snd == 1 ? 3 : aux.snd)].insert(pt(coords.x,aux.fst));

            if (aux.snd != 1) {
                int newSent = (sent - aux.snd + 3 + 4)%4; // depends on actual direction and slope
                pt toPt = rectifySlope(pt(coords.x, aux.fst), aux.snd, newSent);
                trySeg(toPt, newSent);
            }
        }
    }
}

int main() {
    freopen("billar.in","r",stdin);
    freopen("billar.out","w",stdout);
    int n; scanf("%d",&n);
    if (n == 1) return 0; // ok (?)

    forn(i,n) scanf("%d %d",&segs[i].x,&segs[i].y);

    // los puntos son el de menor y primero, luego menor x
    forn(i,n) {
        pt a = segs[i], b = segs[(i+1)%n];

        while (a.x != b.x || a.y != b.y) {
            pts_input.pb(a);
            if (a.x != b.x) a.x += (a.x > b.x ? -1 : 1);
            if (a.y != b.y) a.y += (a.y > b.y ? -1 : 1);
        }
        pts_input.pb(b);

        a = segs[i], b = segs[(i+1)%n];
        if (a.y > b.y || (a.y == b.y && a.x > b.x)) swap(a,b);
        int typ = getTyp(a,b);

        while (a.x != b.x || a.y != b.y) {
            if (typ != 0) {
                if (typ != 3) segsH_x[a.x].pb({a.y,typ});
                else segsH_x[a.x-1].pb({a.y+1,0}); // caso especial lo pongo en el otro vértice (porque sino no puedo encontrarlo)
            }
            if (typ != 1) segsV_y[a.y].pb({a.x,(typ == 0 ? 1 : typ == 2 ? 2 : 0)});
            if (a.x != b.x) a.x += (a.x > b.x ? -1 : 1);
            if (a.y != b.y) a.y += (a.y > b.y ? -1 : 1);
        }
    }

    forn(i,MAXN) sort(all(segsV_y[i])), sort(all(segsH_x[i]));

    int x1,y1,x2,y2; scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    if (x1 > x2) swap(x1,x2);
    if (y1 > y2) swap(y1,y2);

    // left-top-right-bottom
    forsn(i,x1,x2) trySeg(pt(i,y1),3), trySeg(pt(i,y2),1);
    forsn(i,y1,y2) trySeg(pt(x1,i),0), trySeg(pt(x2,i),2);

    forn(i,4)
        for (auto &j : hit[i]) {
            pt a = j, b = pt(j.x + X[i], j.y + Y[i]);
            hit_segs.insert({a,b});
        }

    pt a = {-1,-1}, b = {-1,-1};
    int last_typ = getTyp(pts_input[0], pts_input[1]);
    forn(i,(int)pts_input.size()-1) {
        if (getTyp(pts_input[i], pts_input[i+1]) != last_typ && a.x != -1) { // cambio de direccion, flush old
            printf("%d %d %d %d\n",a.x,a.y,b.x,b.y);
            a = b = {-1,-1};
        }

        last_typ = getTyp(pts_input[i], pts_input[i+1]); // update last_typ

        // if segment is hit
        if (hit_segs.count({pts_input[i],pts_input[i+1]}) || hit_segs.count({pts_input[i+1],pts_input[i]})) {
            if (a.x == -1) a = pts_input[i]; // join to building maximal segment
            b = pts_input[i+1];
        }
        else if (a.x != -1) { // else flush last segment
            printf("%d %d %d %d\n",a.x,a.y,b.x,b.y);
            a = b = {-1,-1};
        }
    }
    if (a.x != -1) printf("%d %d %d %d",a.x,a.y,b.x,b.y);

    return 0;
}