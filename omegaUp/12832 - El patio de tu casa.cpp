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
    ld x,y,r; scanf("%Lf %Lf %Lf",&x,&y,&r);

    int rta = 0;
    for (int ax = ceil(x-r); ax <= (x+r); ax++) {
        ld difY = sqrt(r*r - (x-ax)*(x-ax));
        rta += (int)(y + difY) - ceil(y - difY) + 1;
        if ((y + difY) == (int)(y + difY)) rta -= 1 + (difY >= 1);
    }

    printf("%d",rta);
    
    return 0;
}