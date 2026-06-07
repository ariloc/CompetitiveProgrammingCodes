#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (c).size()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int main() {
    FAST_IO;
    
    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        bool ok = 0;
        forn(i,n) {
            int x; cin >> x;
            if (x == 100) ok = true;
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
