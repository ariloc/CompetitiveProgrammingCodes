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
typedef long double ld;

map<int,int> cnt;

int main() {
    FAST_IO;

    int n,m;
    while (cin >> n >> m) {
        if (!n && !m) break;
        forn(i,n) {int x; cin >> x; cnt[x]++;}

        int r = 0;
        forn(i,m) {
            int x; cin >> x;
            auto it = cnt.find(x);
            if (it != cnt.end()) {
                r++;
                (*it).snd--;
                if (!((*it).snd)) cnt.erase(it);
            }
        }

        cout << r << '\n';
    }

    return 0;
}