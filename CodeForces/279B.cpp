#include <bits/stdc++.h>

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

const int INF = 1e9;
const int MAXN = 1e5+2;

int arr[MAXN];

int main() {
    FAST_IO;

    int n,t; cin >> n >> t;

    forn (i,n) cin >> arr[i];

    int r = 0; ll sum = arr[0];
    int maxi = 0;
    forn (i,n) {
        while (r < n and sum <= t)
            sum += arr[++r];
        maxi = max(maxi,r-i);
        sum -= arr[i];
    }

    cout << maxi;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!