#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1e5+5;

int c[MAXN],t[MAXN];

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%d",&c[i]);
    forn(i,n) scanf("%d",&t[i]);

    if (c[0] != t[0]) return printf("No"), 0;

    forn(i,n)
        c[i] = c[i+1] - c[i], t[i] = t[i+1] - t[i];

    n--;
    sort(c,c+n), sort(t,t+n);

    forn(i,n) if (c[i] != t[i]) return printf("No"), 0;

    printf("Yes");

    return 0;
}