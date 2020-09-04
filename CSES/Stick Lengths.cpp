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

const int MAXN = 2e5+5;
const ll INF = 1e18+5;

int arr[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn (i,n) cin >> arr[i];

    sort(arr,arr+n);

    ll sum = 0, mini = INF;
    forn(i,n-1) sum += arr[n-1]-arr[i]; mini = sum;

    dforn(i,n-1) {
        sum += (ll)(arr[i+1]-arr[i])*(n-1-i);
        sum -= (ll)(arr[i+1]-arr[i])*(i+1);
        mini = min(mini,sum);
    }

    cout << mini;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
