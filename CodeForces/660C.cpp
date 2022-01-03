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

const int MAXN = 3e5+5;

int arr[MAXN];

int main() {
    int n,k; scanf("%d %d",&n,&k);
    forn(i,n) scanf("%d",&arr[i]);

    int r = 0, zeroes = 0;
    int maxi = -1, ml = -1, mr = -1;
    forn(l,n) {
        while (r < n && (zeroes < k || arr[r]))
            zeroes += (!arr[r]), r++;
        if (r-l > maxi)
            maxi = r-l, ml = l, mr = r;
        zeroes -= (!arr[l]);
    }

    printf("%d\n",maxi);
    forsn(i,ml,mr) arr[i] = 1;
    forn(i,n) printf("%d ",arr[i]);
    
    return 0;
}