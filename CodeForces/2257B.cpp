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

int const MAXN = 105;

int a[MAXN], b[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,m; cin >> n >> m;
        forn(i,n) cin >> a[i];
        forn(i,m) cin >> b[i];

        a[n] = b[m] = 0;

        int l = 0, r = 0;
        while (l < n && r < m) {
            int dif = min(a[l]-a[l+1],b[r]-b[r+1]);
            a[l] -= dif, b[r] -= dif;
            if (!b[r]) {++r; continue;}
            if (!a[l]) {++l; continue;}
            b[r]--;
            if (b[r+1] > b[r] || !b[r]) {
                ++r;
                if (r == m) continue;
            }
            a[l]--;
            if (a[l+1] > a[l] || !a[l]) {
                ++l;
                if (l == n) continue;
            }
        }

        if (l >= n) cout << "2\n"; else cout << "1\n";
    }

    return 0;
}
