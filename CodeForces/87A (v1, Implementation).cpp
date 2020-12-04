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

int main() {
    FAST_IO;

    ll a,b; cin >> a >> b;
    ll lcm = (a*b)/__gcd(a,b);
    ll s1 = 0, s2 = 0, tmp1 = 0, tmp2 = 0, lstPt = 0;
    while (tmp1 < lcm || tmp2 < lcm) {
        if (tmp1+a < tmp2+b) {
            tmp1 += a;
            if (tmp1 != lcm || a > b) s1 += tmp1-lstPt;
            else if (tmp1 == lcm) s2 += tmp1-lstPt;
            lstPt = tmp1;
        }
        else {
            tmp2 += b;
            if (tmp2 != lcm || b > a) s2 += tmp2-lstPt;
            else if (tmp2 == lcm) s1 += tmp2-lstPt;
            lstPt = tmp2;
        }
    }

    if (s1 > s2) cout << "Dasha";
    else if (s2 > s1) cout << "Masha";
    else cout << "Equal";

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
