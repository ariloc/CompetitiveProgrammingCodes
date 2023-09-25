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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        ll a,b,c; cin >> a >> b >> c;

        cout << "Case #" << o+1 << ": ";
        if (b <= a) {
            cout << max(0LL,(c/b)*2LL - 1);
        }
        else if (c >= a) {
            ll rest = c-a;
            cout << max(rest/b * 2LL + (rest%b)/a, rest/a) + 1;
        }
        else cout << "0";

        cout << '\n';
    }

    return 0;
}
