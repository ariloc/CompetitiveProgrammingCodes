#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1002;

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        int maxi = 0, ind = -1; vector<bool> done(n);
        forn(j,n) {cin >> arr[j]; if (arr[j] > maxi) {maxi = arr[j]; ind = j;}}
        cout << maxi << ' '; done[ind] = true;
        forn(j,n-1) {
            int cind = -1, myMax = 0;
            forn(k,n) if (!done[k]) {
                int dcm = __gcd(maxi,arr[k]);
                if (dcm > myMax) {myMax = dcm; cind = k;}
            }
            done[cind] = true;
            cout << arr[cind] << ' ';
            maxi = __gcd(maxi,arr[cind]);
        }
        cout << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
