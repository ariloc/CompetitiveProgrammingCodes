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

int const MAXN = 1e5+5;

int a[MAXN], b[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        forn(i,n) cin >> a[i];
        forn(i,n) cin >> b[i];

        ll nk = 0, pk = 0;
        forn(i,n) {
            ll nk1 = nk, pk1 = pk;
            nk = min(nk1-a[i],b[i]-pk1);
            pk = max(pk1-a[i],b[i]-nk1);
        }

        cout << pk << '\n';
    }

    return 0;
}
