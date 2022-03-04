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

int door[MAXN];

int main() {
    int n,m; scanf("%d %d",&n,&m);
    forn(i,n) scanf("%d",&door[i]);

    int ind = 0; ll acc = 0;
    forn(i,m) {
        int x; scanf("%d",&x);
        while (ind < n && acc+door[ind] <= x) acc += door[ind++];
        acc = 0;
    }

    printf("%d",ind);

    return 0;
}
