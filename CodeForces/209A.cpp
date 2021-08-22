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

const int MAXN = 1e6+5;
const int MOD = 1e9+7;

ll fibo[MAXN];

int main() {
    FAST_IO;

    int N; cin >> N;

    /*int cnt = 0;
    forsn (i,1,(1<<N)) {
        int me = i; bool par = 0;
        vector<char> cad;
        while (me) {
            if (me & 1) {
                if (!par) cad.pb('R');
                else cad.pb('B');
            }
            me >>= 1; par = !par;
        }
        bool posib = true;
        forsn (o,1,cad.size()) if (cad[o] == cad[o-1]) {posib = false; break;}
        if (!posib) continue;
        cnt++;
    }*/

    fibo[0] = fibo[1] = 1;
    forsn (i,2,MAXN) fibo[i] = (fibo[i-1] + fibo[i-2]) % MOD;

    int cnt = 0;
    forn (i,N) cnt =  (cnt+fibo[i+1])%MOD;

    cout << cnt;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!