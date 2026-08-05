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

int main() {
    FAST_IO;

    int t;cin  >> t;
    forn(_,t) {
        string s; cin >> s;

        int idx1 = -1, idx2 = -1;
        forn(i,sz(s)) if (s[i] == '1') {idx1 = i; break;}
        forn(i,sz(s)) if (s[i] == '0') {idx2 = i; break;}

        string auxi;
        forn(i,sz(s)) if (i != idx1 && i != idx2) auxi.pb(s[i]);

        cout << auxi << '\n';
    }

    return 0;
}
