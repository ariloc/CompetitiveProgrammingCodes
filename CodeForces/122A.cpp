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

bool islucky (int i) {
    while (i) {
        int dig = i%10;
        if (dig != 4 && dig != 7) return false;
        i /= 10;
    }
    return true;
}

int main() {
    int n; scanf("%d",&n);

    forsn(i,1,n+1) {
        if (!islucky(i)) continue;
        if (!(n % i)) {
            printf("YES");
            return 0;
        }
    }

    printf("NO");
    
    return 0;
}
