// https://ibero1.contest.codeforces.com/group/BXJ6xt3tnH/contest/361753/problem/K
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

const int MAXN = 1e6+5;
const int INF = 2e9;

int arr[MAXN];
int menR[MAXN], menL[MAXN];

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%d",&arr[i+1]);

    arr[0] = arr[n+1] = -INF;
    dforsn(i,1,n+1) {int j; for (j = i+1; arr[j] >= arr[i]; j = menR[j]); menR[i] = j;}
    forsn(i,1,n+1) {int j; for (j = i-1; arr[j] >= arr[i]; j = menL[j]); menL[i] = j;}
    
    ll maxi = 0;
    forsn(i,1,n+1) maxi = max(maxi, (ll)(menR[i]-menL[i]-1)*arr[i]);

    printf("%lld",maxi);

    return 0;
} 
