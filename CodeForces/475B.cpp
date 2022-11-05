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

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    string a,b; cin >> a >> b;

    bool posib = true;

    if (a[0] == '<' && b[0] == '^')
        posib = false;
    if (a.back() == '<' && b[0] == 'v')
        posib = false;
    if (a[0] == '>' && b.back() == '^')
        posib = false;
    if (a.back() == '>' && b.back() == 'v')
        posib = false;

    printf("%s",posib ? "YES" : "NO");

    return 0;
}
