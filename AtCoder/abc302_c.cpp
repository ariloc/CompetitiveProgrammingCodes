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

    int n,m; cin >> n >> m;
    vector<string> a;
    forn(i,n) {
        string s; cin >> s;
        a.pb(s);
    }

    sort(all(a));

    bool posib = false;
    do {
        bool posibh = true;
        forn(i,n-1) {
            int cnt = 0;
            forn(j,m) {
                cnt += a[i][j] != (a[i+1][j]);
            }
            if (cnt != 1) posibh = false;
        }
        posib |= posibh;
    } while (next_permutation(all(a)));

    cout << (posib ? "Yes" : "No");
   
    return 0;
}
