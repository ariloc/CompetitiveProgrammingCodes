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

const int MAXN = 1e6+5;
const int MAXC = 5;

vi flam[MAXC];
int N[MAXC];

bool findBin (int col, int h) {
    int low = -1, high = (int)flam[col].size()-1;
    while (high - low > 1) {
        int mid = (high + low)/2;
        if (flam[col][mid] >= h) high = mid;
        else low = mid;
    }
    if (high < 0 || high >= (int)flam[col].size()) return false;
    return (flam[col][high] == h);
}

int main() {
    int n; scanf("%d",&n);
    forn(i,n) {
        int x; char c; scanf("%d %c",&x,&c);
        flam[c-'A'].pb(x);
    }

    forn(i,MAXC) sort(all(flam[i]));

    int q; scanf("%d",&q);
    forn(i,q) {
        int a,b; scanf("%d %d",&a,&b);
        bool posib = false;
        forn(j,MAXC)
            if (findBin(j,a) && findBin(j,b))
                putchar('1'), posib = true;
        if (!posib) putchar('0');
        puts("");
    }

    return 0;
}