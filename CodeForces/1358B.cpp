#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(ll i = ll(s); i < ll(n); i++)
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

const int MAXN = 2e5+20;

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int n; cin >> n;
        forn (j,n) cin >> arr[j];
        sort(arr,arr+n);
        int cnt = 1;
        int cntMax = 1;
        forn (j,n) {
            cnt++;
            if (cnt-1 >= arr[j]) cntMax = max(cntMax,cnt);
        }

        cout << cntMax << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!