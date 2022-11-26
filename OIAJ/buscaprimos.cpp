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

const int MAXP = 10005;

bitset<MAXP> done;

void criba (int N) {
    done[0] = done[1] = true;
    for (int i = 4; i < MAXP; i += 2)
        done[i] = true;
    
    for (int i = 3; i*i <= MAXP; i += 2)
        for (int j = i+i; j < MAXP; j += i)
            if (!done[j]) done[j] = true;
}

vector<int> buscaprimos(string &s) {
    criba(MAXP);

    int n = (int)s.size();

    vi rta(4,0);
    forn(i,n) {
        if (s[i] == '0') continue;
        int val = 0;
        forn(j,4) {
            if (i+j >= n) break;
            val = val*10 + s[i+j]-'0';
            rta[j] += (!done[val]);
        }
    }

    return rta;
}
