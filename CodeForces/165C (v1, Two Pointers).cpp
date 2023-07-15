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

int main() {
    FAST_IO;

    int k; cin >> k;
    string s; cin >> s;
    int n = (int)s.size();
    s.pb('0'); // dummy

    if (!k) {
        ll cnt = 0, r = 0;
        forn(i,n) {
            if (s[i] == '0') cnt++;
            else r += cnt*(cnt+1)/2LL, cnt = 0;
        }
        r += cnt*(cnt+1)/2LL;
        return cout << r, 0; 
    }

    ll rta = 0;
    int r1 = 0, r2 = 0, acc1 = 0, acc2 = 0;
    forn(l,n) {
        r1 = max(r1,l);
        r2 = max(r2,l);

        while (r1 <= n && acc1 < k) acc1 += (s[r1] == '1'), r1++; // el primero que cumple
        while (r2 <= n && acc2 <= k) acc2 += (s[r2] == '1'), r2++; // el último que cumple

        rta += r2-r1;

        acc1 -= (s[l] == '1');
        acc2 -= (s[l] == '1');
    }

    cout << rta;

    return 0;
}