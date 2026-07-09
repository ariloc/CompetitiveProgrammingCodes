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

const int MAX = 5002;
const int tendX[] = {1,0,-1,0};
const int tendY[] = {0,1,0,-1};

struct point {
    int x,y;
};

struct rectang {
    point a,b;
};

vi X,Y;
vector< pair<point,int> > P; // pto, id
rectang rectangulos[MAX];
int plano[MAX][MAX];
ll r[MAX/2];
int N, MAXN, rSz = 0;

int update(int &e, vi &E) {
    return lower_bound(all(E),e) - E.begin();
}

void compress() {
    for (auto &i : P) {
        X.push_back(i.fst.x);
        Y.push_back(i.fst.y);
    }

    sort(all(X));
    sort(all(Y));

    for (auto &i : P) {
        int x = i.fst.x, y = i.fst.y;
        i.fst.x = update(i.fst.x,X);
        i.fst.y = update(i.fst.y,Y);

        if (rectangulos[i.snd].a.x == x and rectangulos[i.snd].a.y == y)
            rectangulos[i.snd].a = {i.fst.x,i.fst.y};
        else
            rectangulos[i.snd].b = {i.fst.x,i.fst.y};
    }
}

bool valid(int &x, int &y);

ll bfs (int x, int y) {
    queue<point> Q;
    ll totSup = 0;
    plano[y][x] = true;
    bool posib = valid(x,y);
    Q.push({x,y});

    while (not Q.empty()) {
        point e = Q.front(); Q.pop();

        if (e.x+1 >= (int)X.size() || e.y+1 >= (int)Y.size())
            posib = false;
        if (posib) {
            totSup += ll(abs(X[e.x]-X[e.x+1]))*abs(Y[e.y]-Y[e.y+1]);
        }

        forn (i,4) {
            int actX = e.x+tendX[i];
            int actY = e.y+tendY[i];

            if (!valid(actX,actY)) {posib = false; continue;}
            if (plano[actY][actX]) continue;

            plano[actY][actX] = true;
            Q.push({actX,actY});
        }
    }
    if (posib)
        return totSup;
    else return -1;
}

int main() {
    //freopen("agujeros.in","r",stdin);
    //freopen("agujeros.out","w",stdout);

    scanf("%d",&N);
    MAXN = (2*N)+2;
    P.reserve(MAXN);

    forn(i,N) {
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        P.push_back({{x1,y1},i});
        P.push_back({{x2,y2},i});
        rectangulos[i] = {{x1,y1},{x2,y2}};
    }

    if (N <= 3) {
        printf("0\n");
        return 0;
    }

    compress();

    for (auto &r : rectangulos) {
        if (r.a.x > r.b.x) swap(r.a.x, r.b.x);
        if (r.a.y > r.b.y) swap(r.a.y, r.b.y);
    }

    for (auto &r : rectangulos) {
        plano[r.a.y][r.a.x]++;
        plano[r.a.y][r.b.x]--;
        plano[r.b.y][r.a.x]--;
        plano[r.b.y][r.b.x]++;
    }

    forn(y,MAXN) {
        int cnt = 0;
        forn(x,MAXN) {
            int act = plano[y][x];
            cnt+=act;
            if (y+1 < MAXN)
                plano[y+1][x]+=act;
            plano[y][x] = cnt > 0;
        }
    }

    forn (y,MAXN)
        forn (x,MAXN) {
            if (plano[y][x]) continue;
            ll result = bfs(x,y);
            if (result != -1)
                r[rSz++] = result;
        }

    printf("%d\n",rSz);
    sort(r,r+rSz);
    forn(i,rSz)
        printf("%lld\n",r[i]);

    return 0;
}

bool valid(int &x, int &y) {
    if (x < 0 or x >= MAXN) return false;
    if (y < 0 or y >= MAXN) return false;
    return true;
}