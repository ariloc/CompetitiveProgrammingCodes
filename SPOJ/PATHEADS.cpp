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

const int MAXN = 1e5+5;
const int MAXNUM = 1e6+5;

int a[MAXN], cnt[MAXNUM], rta[MAXNUM];

int main() {
    int n; scanf("%d",&n);

    forn(i,n) scanf("%d",&a[i]), cnt[a[i]]++;

    forn(i,MAXNUM) {
        if (cnt[i])
            for (int j = i; j < MAXNUM; j += i)
                rta[j] += cnt[i];
    }

    forn(i,n) printf("%d\n",rta[a[i]]-1);
    
    return 0;
}
