#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXA = 26;

bitset<MAXA> ok;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,m; cin >> n >> m;

        forn(i,MAXA) ok[i] = false;

        forn(i,n) {
            string s; cin >> s;
            ok[s[0]-'a'] = true;
        }

        bool posib = true;
        forn(i,m) {
            string s; cin >> s;
            for (auto &j : s) if (!ok[j-'A']) posib = false;
        }

        cout << (posib ? "YES" : "NO") << '\n';
    }

    return 0;
}
