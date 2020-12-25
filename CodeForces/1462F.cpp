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

const int MAXN = 2e5+20;
const int INF = 1e9+5;

ii pts[MAXN];
int FT[2*MAXN];

void setFT (int p, int v) {
    for (int i = p; i < 2*MAXN; i += i & -i)
        FT[i] += v;
}

int getFT (int p) {
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        vi lst(2*n);
        forn(j,n) {int l,r; cin >> l >> r; pts[j] = {l,r}; lst[2*j] = l; lst[2*j+1] = r;}

        // compress
        sort(all(lst));
        lst.erase(unique(all(lst)),lst.end());

        // update
        forn(j,n) pts[j] = {lower_bound(all(lst),pts[j].fst)-lst.begin()+2,lower_bound(all(lst),pts[j].snd)-lst.begin()+2};

        sort(pts,pts+n);

        int maxi = 0;
        vi nds, toDel;
        forn(j,n) {
            if (j && pts[j].fst != pts[j-1].fst)
                while (!nds.empty()) setFT(nds.back(),1), toDel.pb(nds.back()), nds.pop_back();

            int r = lower_bound(pts,pts+n,(ii){pts[j].snd+1,-INF})-pts; // último con inicio <= pts[j].snd
            int l = lower_bound(pts,pts+n,(ii){pts[j].fst,-INF})-pts; // primero con inicio >= pts[j].fst
            int cantOut = getFT(pts[j].snd)-getFT(pts[j].fst-1); // empiezan antes pero me interseca

            maxi = max(maxi,cantOut+max(0,r-l));
            nds.pb(pts[j].snd);
        }

        for (auto &j : toDel) setFT(j,-1); // reset para el siguiente

        cout << n-maxi << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
