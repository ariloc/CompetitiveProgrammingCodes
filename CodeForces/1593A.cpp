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

    int t; cin >> t;
    forn(i,t) {
        int a,b,c; cin >> a >> b >> c;

        int maxi = max(a,max(b,c));
        int cntMaxi = (a == maxi) + (b == maxi) + (c == maxi) - 1;
        
        cout << maxi-a + (a != maxi || cntMaxi) << ' ' << 
                maxi-b + (b != maxi || cntMaxi) << ' ' <<
                maxi-c + (c != maxi || cntMaxi) << '\n';
        }

    return 0;
}