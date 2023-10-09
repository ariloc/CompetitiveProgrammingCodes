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

    ll A,S,L,R; cin >> A >> S >> L >> R;

    int skip = 1;
    int rta = 0;
    while (A - skip >= L || A + skip <= R) {
        ll r = A, l = A;
        ll s = A;

        while (s < S && l - skip >= L) l -= skip, s += l;
        if (s == S && l != A) ++rta;

        while (r + skip <= R) {
            r += skip; s += r;
            while (l + skip <= A && s > S) s -= l, l += skip;
            if (s == S) ++rta;
        }
        
        ++skip;
    }
    if (A == S) ++rta;

    cout << rta << '\n';

    return 0;
}
