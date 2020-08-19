#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 6e4+4;

int FT[MAXN];
map <ii,int> otherY;

int getFT(int a) {
    int v = 0;
    for (int x = a; x; x -= x & -x)
        v += FT[x];
    return v;
}

void setFT (int a, int v) {
    for (int x = a; x < MAXN; x += x & -x)
        FT[x] += v;
}

struct tramo {
    int x,y;
    bool start; // true -> menor coordX/Y del segm | false -> mayor coord X/Y del segm
    bool sent; // true -> vertical | false -> horizontal

    bool operator< (const tramo &o) const{
        if (o.x == x) return !sent;

        return o.x > x;
    }
};

vector<tramo> autodromos;

int solve() {
    int r = 0;
    for (auto &i : autodromos) {
        if (!i.sent)
            if (i.start) setFT(i.y,1);
            else setFT (i.y,-1);
        else {
            if (!i.start) continue;
            r += getFT(otherY[{i.x,i.y}]-1)-getFT(i.y); // -1 para no incluir esquinas
        }
    }
    return r;
}

void input(int &M);

int main() {
    freopen("autodromo.in","r",stdin);
    freopen("autodromo.out","w",stdout);

    int M1,M2;
    scanf("%d",&M1);
    input(M1);
    scanf("%d",&M2);
    input(M2);

    sort(all(autodromos));

    printf("%d",solve());

    return 0;
}

void input (int &M) {
    ii prev = {-1,-1};
    ii st = {-1,-1};
    forn (i,M+1) {
        int x,y;
        if (i < M) {
            scanf("%d %d",&x,&y);
            x++; y++;
        }
        else {x = st.fst; y = st.snd;}

        if (st.fst == -1) st = {x,y};

        bool vertical = false;
        if (i) {
            bool st = true;
            if (x == prev.fst) {
                vertical = true;
                if (prev.snd < y) st = false;
                otherY[{x,min(y,prev.snd)}] = max(y,prev.snd);
            }
            else if (prev.fst < x) st = false;

            autodromos.push_back({x,y,st,vertical});
            autodromos.push_back({prev.fst,prev.snd,!st,vertical});
        }
        prev = {x,y};
    }
}
