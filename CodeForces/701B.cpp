#include <bits/stdc++.h>

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

const int MAXN = 1e5+2;

bool row[MAXN], col[MAXN];

int main() {
    FAST_IO;

    ll n,m; cin >> n >> m;

    ll cnt = n*n, r = 0, c = 0;
    forn (i,m) {
        int x,y; cin >> x >> y;
        if (!col[x]) {cnt-=(n-r); c++;}
        if (!row[y]) {cnt-=(n-c); r++;}
        col[x] = true; row[y] = true;
        cout << cnt << ' ';
    }

    return 0;
}