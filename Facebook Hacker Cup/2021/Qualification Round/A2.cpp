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

const ll INF = 9e18;
const int MAXA = 26;

int D[MAXA][MAXA];

int main() {
    FAST_IO;

    freopen("output.txt","w",stdout);

    int t; cin >> t;
    forn(o,t) {
        string s; cin >> s;

        forn(i,MAXA) forn(j,MAXA) D[i][j] = -1;
        forn(i,MAXA) D[i][i] = 0;
        
        int K; cin >> K;
        forn(i,K) {
            string aux; cin >> aux;
            D[aux[0]-'A'][aux[1]-'A'] = 1;
        }

        forn(k,MAXA) forn(i,MAXA) forn(j,MAXA)
            if (D[i][k] != -1 && D[k][j] != -1) {
                if (D[i][j] != -1) D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                else D[i][j] = D[i][k] + D[k][j];
            }

        ll mini = INF;
        forn(k,MAXA) {
            ll acc = 0; bool posib = 1;

            forn(j,s.size()) 
                if (D[s[j]-'A'][k] != -1) acc += D[s[j]-'A'][k];
                else posib = 0;
            
            if (posib) mini = min(mini, acc);
        }

        cout << "Case #" << o+1 << ": " << (mini == INF ? -1LL : mini) << '\n';
    }

    return 0;
}