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

const int MAXN = 130;

int FT[MAXN];

int getFT (int a) {
    int v = 0;
    for (int x = a; x; x -= x & -x)
        v += FT[x];
    return v;
}

void setFT (int a, int v) {
    for (int x = a; x < MAXN; x += x & -x)
        FT[x] += v;
}

struct temp {
    int mini,maxi,id;

    bool operator< (const temp &o) const{
        if (o.mini == mini) return o.maxi > maxi;

        return o.mini < mini;
    }
};

struct comp {
    int h,noC,id;

    bool operator< (const comp &o) const{
        if (o.h == h) return o.id > id;

        return o.h < h;
    }
};

vector<temp> temps;
vector<comp> r;
map<ii, int> repeticiones;

int main() {
    //FAST_IO;
    freopen("clima.in","r",stdin);
    freopen("clima.out","w",stdout);

    int P;
    scanf("%d",&P);

    forn (i,P) {
        int R;
        scanf("%d",&R);

        int mini = MAXN,maxi = -MAXN;
        forn (j,R) {
            int m,M;
            scanf("%d %d",&m,&M);
            m+=60; M+=60;

            mini = min(m,mini);
            maxi = max(M,maxi);
        }
        temps.push_back({mini,maxi,i+1});

        repeticiones[{mini,maxi}]++;
    }
    sort(all(temps));

    forn (i,temps.size()) {
        int h = getFT(temps[i].maxi), repet = repeticiones[{temps[i].mini,temps[i].maxi}];
        int noC = P-repet-h;

        setFT(temps[i].maxi,repet);
        while (repet--) {r.push_back({h,noC,temps[i].id}); i++;}
        i--;
    }

    sort(all(r));

    int st = r[0].h;
    forn (i,r.size()) {
        if (r[i].h != st) break;
        printf("%d %d\n",r[i].id,r[i].noC);
    }

    return 0;
}
