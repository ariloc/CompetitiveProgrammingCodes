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

set<int> nums;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n,k; cin >> n >> k;

        nums.clear();

        forn(i,n) {
            int x; cin >> x;
            nums.insert(x);
        }

        int oldSz = nums.size();

        forn(i,min(k,3)) {
            int mex = 0;
            for (auto &j : nums) {
                if (mex != j) break;
                mex++;
            }

            nums.insert((*nums.rbegin()+mex+1)/2);
        }

        if (k <= 3) cout << nums.size() << '\n';
        else {
            if ((int)nums.size() == oldSz) cout << oldSz << '\n';
            else if ((int)nums.size()-oldSz == 1) cout << oldSz+1 << '\n';
            else cout << oldSz+k << '\n';
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!