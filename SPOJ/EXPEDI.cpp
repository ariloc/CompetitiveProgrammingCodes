#include<bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXL = 1e6+5;
int const INF = 1e9;

vi stops[MAXL];
vector<ii> inp;
priority_queue<int> reach;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;

        while (!reach.empty()) reach.pop();
        inp.clear();

        forn(i,n) {
            int d,f; cin >> d >> f;
            inp.pb({d,f});
        }
        int l,p; cin >> l >> p;

        forn(i,l+1) stops[i].clear();

        forn(i,n) {
            int d,f;
            tie(d,f) = inp[i];
            d = l-d;
            if (d < 0) continue;
            stops[d].pb(f);
        }

        int rta = 0;
        bool arrives = true;
        ++p;
        forn(i,l+1) {
            --p;
            if (p < 0) {
                if (reach.empty()) {
                    arrives = false; break;
                }
                p += reach.top(); reach.pop(); ++rta;
            }

            for (auto &j : stops[i])
                reach.push(j);
        }

        cout << (arrives ? rta : -1) << '\n';
    }
  
    return 0;
}
