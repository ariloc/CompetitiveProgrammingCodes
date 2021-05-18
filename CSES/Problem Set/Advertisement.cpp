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
 
const int MAXN = 2e5+5;
const int INF = 1e9+5;
 
int arr[MAXN];
int ans[MAXN],ans2[MAXN];
 
int main() {
    FAST_IO;
 
    int n; cin >> n;
    forn (i,n) cin >> arr[i+1]; arr[n+1] = arr[0] = -INF;
 
    ll rta = 1; int j;
    dforsn (i,1,n+1) {for (j = i+1; arr[j] >= arr[i]; j = ans[j]); ans[i] = j;}
    forsn (i,1,n+1) {for (j = i-1; arr[j] >= arr[i]; j = ans2[j]); ans2[i] = j;}
    forsn (i,1,n+1) rta = max(rta,(ll)(ans[i]-ans2[i]-1)*arr[i]);
 
    cout << rta;
 
    return 0;
}
 
/// ESCRIB� en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO B�SICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!