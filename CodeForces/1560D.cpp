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

const int INF = 2e9;
const ll TOP = 1e18;

int tryIt (string x, string pot) {
    int ind = 0; pot += 'x';
    forn(i,x.size()) if (x[i] == pot[ind]) ind++;
    
    int add = (int)pot.size()-1-ind;
    int remove = (int)x.size()-ind;
    return add + remove;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        string s; cin >> s;

        int mini = INF; // peor caso borro todo y pongo la potencia más chica
        for (ll pot = 1; pot <= TOP; pot <<= 1) {
            stringstream ss;
            ss << pot;
            string aux; ss >> aux;

            mini = min(mini, tryIt(s,aux));
        }

        cout << mini << '\n';
    }

    return 0;
}