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

vector<pair<int,ii>> pts;
vector<pair<ii,ii>> rangs;
bool posib = true;

void check(int n) {
    pts.clear();
    forn(i,n) {
        int s1 = rangs[i].fst.fst, e1 = rangs[i].fst.snd, s2 = rangs[i].snd.fst, e2 = rangs[i].snd.snd;
        pts.pb({s1,{s2,e2}});
        pts.pb({-(e1+1),{s2,e2}});
    }

    sort(all(pts),[](const pair<int,ii> &lhs, const pair<int,ii> &rhs) {
        if (abs(lhs.fst) != abs(rhs.fst))
            return abs(lhs.fst) < abs(rhs.fst);
        return lhs.fst < rhs.fst;
    });

    multiset<int> sts, nds;
    forn(i,pts.size()) {
        if (pts[i].fst > 0) {
            if (!nds.empty() && (*nds.begin() < pts[i].snd.fst || *sts.rbegin() > pts[i].snd.snd))
                posib = false;
            sts.insert(pts[i].snd.fst);
            nds.insert(pts[i].snd.snd);
        }
        else {
            sts.erase(sts.find(pts[i].snd.fst));
            nds.erase(nds.find(pts[i].snd.snd));
        }
    }
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {
        int s1,e1,s2,e2; cin >> s1 >> e1 >> s2 >> e2;
        rangs.pb({{s1,e1},{s2,e2}});
    }

    check(n);
    forn(i,n) swap(rangs[i].fst,rangs[i].snd);
    check(n);

    cout << (posib ? "YES" : "NO") << '\n';

    return 0;

}
