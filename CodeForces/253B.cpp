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

const int MAXN = 1e5+5;

int arr[MAXN];

int main() {
    FAST_IO;

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n; cin >> n;
    forn(i,n) cin >> arr[i];

    sort(arr,arr+n);

    int r = 0;
    int maxi = 0;
    forn(l,n) {
        while (r < n && arr[r] <= 2*arr[l]) r++;
        maxi = max(maxi,r-l);
    }

    cout << n-maxi;

    return 0;
}