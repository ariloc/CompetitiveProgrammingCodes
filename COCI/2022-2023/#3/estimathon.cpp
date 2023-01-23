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

int main() {
    int n,m; scanf("%d %d",&n,&m);

    bool posib = (m <= n);
    int cnt_posib = 0;
    forn(i,m) {
        int x; scanf("%d",&x);
        posib &= (x >= 4);
        cnt_posib += (x/4);
    }
    posib &= (cnt_posib >= n);

    printf("%s",posib ? "DA" : "NE");

    return 0;
}
