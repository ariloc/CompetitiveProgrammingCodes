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

const ll MAXV = 11000005; // MAX VALOR
const int MAXL = 100005; // MAX LUCHADORES

struct luchador {
    ll p,h,id;

    bool operator< (const luchador &o) const{
        if (o.p == p) return o.h > h;

        return o.p > p;
    }
};

vector<luchador> L;
ll FT[MAXV];

int getFT (int a){
    int v = 0;
    for (int x = a; x; x -= x & -x)
        v += FT[x];
    return v;
}

void setFT (int a, int v) {
    for (int x = a; x < MAXV; x += x & -x)
        FT[x] += v;
}

int main() {
    //FAST_IO;
    //freopen("sumo.in","r",stdin);
    //freopen("sumo.out","w",stdout);

    int l;
    scanf("%d",&l);

    forn (i,l) {
        int p,h;
        scanf("%d %d",&p,&h);
        p++; h++;
        L.push_back({p,h,i});
    }

    sort(all(L));

    vi r(l);
    forn (i,L.size()) {
        r[L[i].id] = getFT(L[i].h);
        setFT(L[i].h,1);
    }

    for (auto &i : r) printf("%d\n",i);

    return 0;
}
