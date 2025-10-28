#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 1e5+5;
int const MAXCO = 4e5+30;

struct range {
    int s1,e1,s2,e2;
};

vector<range> rns, bye1, bys1;
vi pts;
int FT1[MAXCO], FT2[MAXCO];
bool posib = true;

void setFT(int *FT, int p, int v) {
    p += 3;
    for (int i = p; i < MAXCO; i += i & -i)
        FT[i] += v;
}

int getFT(int *FT, int p) {
    p += 3;
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

void update(int &x) {
    x = lower_bound(all(pts),x)-pts.begin();
}

void check(int n) {
    bye1 = rns;
    bys1 = rns;
    sort(all(bye1),[](const range &lhs, const range &rhs){
        return lhs.e1 < rhs.e1;
    });
    sort(all(bys1),[](const range &lhs, const range &rhs){
        return lhs.s1 < rhs.s1;
    });

    forn(i,MAXCO) FT1[i] = FT2[i] = 0;

    int idx = 0;
    forn(i,n) {
        while (idx < n && bye1[idx].e1 < bys1[i].s1) {
            setFT(FT1,bye1[idx].s2,1);
            setFT(FT1,bye1[idx].e2+1,-1);
            setFT(FT2,bye1[idx].s2,1);
            setFT(FT2,bye1[idx].e2,1);
            idx++;
        }
        // any end of range bys1[i] is inside any passed bye1 range
        if (getFT(FT1,bys1[i].s2) != 0 || getFT(FT1,bys1[i].e2) != 0)
            posib = false;
        // any end of any passed bye1 range is inside range bys1[i]
        if (getFT(FT2,bys1[i].e2)-getFT(FT2,bys1[i].s2-1) != 0)
            posib = false;
    }
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {
        int s1,e1,s2,e2; cin >> s1 >> e1 >> s2 >> e2;
        rns.pb({s1,e1,s2,e2});
        pts.pb(s1);
        pts.pb(s2);
        pts.pb(e1);
        pts.pb(e2);
    }

    sort(all(pts));
    pts.erase(unique(all(pts)),pts.end());

    for (auto &i : rns) {
        update(i.s1);
        update(i.s2);
        update(i.e1);
        update(i.e2);
    }

    check(n);
    forn(i,n) swap(rns[i].s1,rns[i].s2), swap(rns[i].e1,rns[i].e2);
    check(n);

    cout << (posib ? "YES" : "NO") << '\n';

    return 0;

}
