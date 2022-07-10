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

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        int n,b; scanf("%d %d",&n,&b);

        int choc_tot = 0;
        forn(i,b) {
            int k; scanf("%d",&k);
            int boxes = 1;
            forn(j,k) {int x; scanf("%d",&x); boxes = (boxes*x)%n;}
            choc_tot = (choc_tot + boxes)%n;
        }

        cout << choc_tot << '\n';
    }
    
    return 0;
}