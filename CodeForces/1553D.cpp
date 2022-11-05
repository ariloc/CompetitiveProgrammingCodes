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

    int q; cin >> q;

    forn(_,q) {
        string s; cin >> s;
        string t; cin >> t;

        int n = (int)s.size(), m = (int)t.size();
    
        int idx = -1, cur = m-1;
        dforn(i,s.size())
            if (s[i] == t[cur] && (n-i)&1) {
                idx = i, cur--; break;
            }
    
        if (cur == m-1) {cout << "NO\n"; continue;}

        dforn(i,idx) {
            if (cur < 0) break;
            if (s[i] == t[cur] && ((idx-i)&1))
                cur--, idx = i;
        }

        if (cur < 0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
