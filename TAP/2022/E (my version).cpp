
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

const int MAXN = 5e5+5;

int h[MAXN];

int main() {
    int n; scanf("%d",&n);

    forn(i,n) scanf("%d",&h[i]);

    map<int,int> avail;
    int cnt = 0;
    forn(i,n) {
        if (!avail.count(h[i]))
            cnt++;
        else {
            avail[h[i]]--;
            if (!avail[h[i]]) avail.erase(h[i]);
        }
        avail[h[i]-1]++;
    }

    printf("%d",cnt);
    
    return 0;
}
