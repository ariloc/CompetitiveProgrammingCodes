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

    int t; cin >> t;
    forn(_,t) {
        int n,k; cin >> n >> k;
        string s; cin >> s;

        int c1 = 0, c2 = 0;
        forn(i,sz(s)) {
            if (s[i] == '1') {
                if (s[(i+1)%sz(s)] == '0') {
                    if (i&1) c1++;
                    else c2++;
                }
                else {
                    if (i&1) c2++;
                    else c1++;
                }
            }
        }

        cout << c2 << ' ' << c1 << '\n';
    }

    return 0;
}
