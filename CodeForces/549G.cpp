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

const int MAXN = 2e5+5;

int arr[MAXN];

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%d",&arr[i]);

    forn(i,n) arr[i] -= (n-i);
    sort(arr,arr+n);

    forn(i,n) arr[i] += (n-i);
    
    forsn(i,1,n)
        if (arr[i] < arr[i-1])
            return printf(":("), 0;

    forn(i,n) printf("%d ",arr[i]);

    return 0;
}