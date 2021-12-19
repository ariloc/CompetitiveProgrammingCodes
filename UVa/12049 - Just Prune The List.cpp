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

map<int,ii> occur;

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        occur.clear();

        int n,m; scanf("%d %d",&n,&m);
        forn(i,n) {
            int x; scanf("%d",&x);
            occur[x].fst++;
        }

        forn(i,m) {
            int x; scanf("%d",&x);
            occur[x].snd++;
        }

        int r = 0;
        for (auto &i : occur) r += abs(i.snd.fst - i.snd.snd);

        printf("%d\n",r);
    }

    return 0;
}