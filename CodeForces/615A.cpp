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

const int MAXN = 110;

bitset<MAXN> turned;
int cnt = 0;

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn (i,n) {
        int x; cin >> x;
        forn (j,x) {
            int b; cin >> b;
            if (!turned[b]) {turned[b] = true; cnt++;}
        }
    }

    cout << (cnt < m ? "NO" : "YES");

    return 0;
}