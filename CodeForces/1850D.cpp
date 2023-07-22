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

int const MAXN = 2e5+5;

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,k; cin >> n >> k;
        forn(i,n) cin >> arr[i];

        sort(arr,arr+n);

        int maxi = 1, j = 1;
        forn(i,n) {
            while(j < n && arr[j]-arr[j-1] <= k) j++;
            maxi = max(maxi,j-i);
            i = j-1, ++j;
        }

        cout << n-maxi << '\n';
    }
          
    return 0;
}
