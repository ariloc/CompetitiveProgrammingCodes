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

    int n; cin >> n;

    string s; cin >> s;
    int w1 = 0, w2 = 0;
    int l1 = -1, l2 = -1;
    forn(i,s.size()) {
        if (s[i] == 'T') w1++, l1 = i;
        else w2++, l2 = i;
    }

    if (w1 > w2) printf("T");
    else if (w2 > w1) printf("A");
    else if (l1 < l2) printf("T");
    else printf("A");
    
    return 0;
}
