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
typedef long double ld;

const int MAXN = 1e5+5;

int arr[MAXN];

int main() {
    int t; scanf("%d",&t);

    forn(_,t) {
        int n; scanf("%d",&n);

        forn(i,n) scanf("%d",&arr[i]);

        int l = 0, r = n-1, cnt = 0;
        while (l < r) {
            while (l < n && !arr[l]) l++;
            while (r >= 0 && arr[r]) r--;
            if (l < r) cnt++;
            l++, r--;
        }

        printf("%d\n",cnt);
    }

    return 0;
}
