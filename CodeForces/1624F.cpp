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

int acc = 0, last = 0, n;
int query (int mid) {
    int tg = (last+1)*n;
    int q = tg - acc - mid;

    printf("+ %d\n", q);
    fflush(stdout);
    int ans; scanf("%d",&ans);
    acc += q;

    return ans;
}

int main() {
    scanf("%d",&n);

    int low = 1, high = n;
    while (high - low > 1) {
        int mid = (high + low)/2;

        int aux = query(mid);
        if (aux != last) low = mid;
        else high = mid;
        last = aux;
    }

    printf("! %d",low+acc);
    
    return 0;
}
