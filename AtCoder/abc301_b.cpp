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
    int prv = -1;
    forn(i,n) {
        int x; cin >> x;
        if (i && abs(x-prv) != 1) {
            int aux = prv, dif = (prv < x ? 1 : -1);
            while ((aux+dif) != x) {
                aux += dif;
                cout << aux << ' ';
            }
        }
        cout << x << ' ';
        prv = x;
    }
    
    return 0;
}
