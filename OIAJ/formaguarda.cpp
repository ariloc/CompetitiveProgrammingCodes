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

string formaguarda(int N, string &tipo, string &patron) {
    string r, rev = patron;
    reverse(all(rev));
    if (tipo == "NORMAL") {
        while ((int)r.size() < N)
            r += patron;
    }
    else {
        bool swap = 0;
        while ((int)r.size() < N) {
            if (!swap) r += patron;
            else r += rev;
            swap ^= 1;
        }
    }

    while ((int)r.size() > N)
        r.pop_back();
    
    return r;
}
