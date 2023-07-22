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
map<int,int> cnt;
int cntcoord[MAXN];

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        int n; scanf("%d",&n);

        forn(i,n+2) cntcoord[i] = 0;
        cnt.clear();

        forn(i,n) scanf("%d",&arr[i]), cnt[arr[i]]++;
        for (auto &i : cnt) {
            for (int j = 0; j <= n; j += i.fst)
                cntcoord[j] += i.snd;
        }

        int maxi = 0;
        forsn(i,1,n+1)
            maxi = max(maxi,cntcoord[i]);

        printf("%d\n",maxi);
    }
          
    return 0;
}
