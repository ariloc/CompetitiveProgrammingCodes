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

const int MAXN = 1005;

bool ady[MAXN][MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;

    cin.ignore(20,'\n'); 
    forn(i,n) {
        string s;
        getline(cin,s);
        stringstream ss; ss << s;
        while (ss) {
            int x; ss >> x; x--;
            if (!ss) break;
            ady[i][x] = ady[x][i] = true;
        }
    }

    vi rta;
    forn(i,n) rta.pb(i);
    rta.pb(0);

    int cnt = n+2;
    while (cnt--) {
        forn(i,n) {
            if (!ady[rta[i]][rta[i+1]]) {
                forn(j,n) {
                    if (ady[rta[j]][rta[i]] && ady[rta[j+1]][rta[i+1]]) {
                        reverse(rta.begin()+min(i,j)+1, rta.begin()+max(i,j)+1); 
                        break;
                    }
                }
                break;
            }
        }
    }

    forn(i,n)
        assert(ady[rta[i]][rta[i+1]]);

    for (auto &i : rta)
        cout << i+1 << ' ';

    return 0;
}
