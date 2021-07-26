// Statement: https://codeforces.com/group/gXivUSZQpn/contest/336740/problem/H

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

const int MAXN = 2e5+5;
const ll INF = 9e18;
 
struct pt {
    ll x,y;
};
 
pt plane[MAXN],aux[MAXN];
pair<ll,ll> rta = {INF,INF};
 
bool comp_y (const pt &lhs, const pt &rhs) {
    return lhs.y < rhs.y;
}
 
bool comp_x (const pt &lhs, const pt &rhs) {
    if (lhs.x == rhs.x) return lhs.y < rhs.y;
    return lhs.x < rhs.x;
}
 
ll hypotSq (pt &a, pt &b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

void upd (pt &a, pt &b) {
    ll dist = hypotSq(a,b);
    if (dist <= rta.fst) {
        if (dist < rta.fst) swap(rta.fst, rta.snd);
        rta.fst = dist;
    }
    else if (dist < rta.snd) rta.snd = dist;
}
 
void divide (int l, int r) {
    if (r-l <= 3) {
        forsn(i,l,r) forsn(j,i+1,r) upd(plane[i],plane[j]);
        sort(plane+l,plane+r,comp_y);
        return;
    }
 
    int mid = (l+r)/2;
    int xmid = plane[mid].x;
    divide(l,mid); divide(mid,r);
 
    merge(plane+l,plane+mid,plane+mid,plane+r,aux,comp_y);
    copy(aux,aux+r-l,plane+l);
 
    int tsz = 0;
    forsn(i,l,r) if ((plane[i].x-xmid)*(plane[i].x-xmid) < rta.snd) {
        for (int j = tsz-1; j >= 0 && (plane[i].y-aux[j].y)*(plane[i].y-aux[j].y) < rta.snd; j--)
            upd(plane[i],aux[j]);
        aux[tsz++] = plane[i];
    }
}
 
int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {
        int x,y; cin >> x >> y;
        plane[i] = {x,y};
    }
 
    sort(plane,plane+n,comp_x); // first by x, then by y coord
    divide(0,n);
 
    cout << fixed << setprecision(10) << sqrt(rta.snd);
 
    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!