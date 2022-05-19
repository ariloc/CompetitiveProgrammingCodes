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
    forn(o,t) {
        string s; cin >> s;

        vi highlight;
        forn(i,s.size()-1) {
            bool ok = 0;
            forsn(j,i+1,s.size()) {
                if (s[j] < s[i]) break;
                if (s[j] > s[i]) {ok = 1; break;}
            }
            if (s[i] < s[i+1] || (s[i] == s[i+1] && ok)) {
                highlight.pb(i);
            }
        }

        reverse(all(highlight));
        
        string r;
        forn(i,s.size()) {
            r.pb(s[i]);
            if (!highlight.empty() && highlight.back() == i)
                highlight.pop_back(), r.pb(s[i]);
        }

        cout << "Case #" << o+1 << ": " << r << '\n';
    }
    
    return 0;
}
