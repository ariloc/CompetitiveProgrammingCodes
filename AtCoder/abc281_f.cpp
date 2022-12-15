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

const int MAXN = 2e5;

int arr[MAXN];

int solve (int l, int r, int mk) {
    if (!mk) return 0;
    if (r <= l) return 0;

    int mid = l-1;
    forsn(i,l,r) {
        if (!(arr[i]&mk)) mid = i;
    }
    mid++;
    if (l == mid) return solve(mid,r,mk>>1);
    if (r == mid) return solve(l,mid,mk>>1);
    return min(solve(l,mid,mk>>1), solve(mid,r,mk>>1)) | mk;
}

int main() {
    int N; scanf("%d",&N);
    forn(i,N) scanf("%d",&arr[i]);

    sort(arr,arr+N);

    printf("%d", solve(0,N,1<<29));
   
    return 0;
}
