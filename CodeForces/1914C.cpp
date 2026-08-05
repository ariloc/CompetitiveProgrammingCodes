#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long long ll;

int const MAXN = 2e5+5;

int a[MAXN], b[MAXN];

int main(){
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,k; cin >> n >> k;
        forn(i,n) cin >> a[i];
        forn(i,n) cin >> b[i];

        ll maxi = 0, acc = 0;
        int maxval = 0;
        forn(i,n+1) {
            maxi = max(maxi, maxval*(ll)(k-i) + acc);
            if (!(k-i)) break;
            maxval = max(maxval,b[i]);
            acc += a[i];
        }

        cout << maxi << '\n';
    }

    return 0;
}
