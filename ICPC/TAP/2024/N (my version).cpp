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

int const MAXN = 5005;

ll arr[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> arr[i];

    sort(arr,arr+n);

    ll r = 0;
    forn(i,n) forn(j,n)
        r = max(r, arr[i]*arr[i] + arr[j]*arr[j] + arr[n-1]*arr[n-1] - arr[i]*arr[j] - arr[j]*arr[n-1] - arr[n-1]*arr[i]);

    cout << r;

    return 0;
}
