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

const int INF = 1e9;
const int MAXN = 52;

char board[MAXN][MAXN];
ii last[MAXN][2];
int minis[MAXN][2];

int main() {
    FAST_IO;

    freopen("output.txt","w",stdout);

    int t; cin >> t;
    forn(o,t) {
        forn(i,MAXN) last[i][0] = last[i][1] = {-1,-1}, minis[i][0] = minis[i][1] = -1;

        int n; cin >> n;
        forn(i,n) cin >> board[i];

        int mini = INF, sets = 0;
        forn(i,n) {
            forn(k,2) {
                bool posib = 1; int cnt = 0; ii lst_aux = {-1,-1};
                forn(j,n) {
                    if (k&1) swap(i,j); // to column

                    if (board[i][j] == 'O') posib = 0;
                    if (board[i][j] == '.') cnt++, lst_aux = {i,j};

                    if (k&1) swap(i,j); // and back to normal
                }

                if (posib) {
                    if (cnt < mini) mini = cnt, sets = 0;
                    if (cnt == mini) sets++;
                    last[i][k] = lst_aux;
                    minis[i][k] = cnt;
                }
            }
        }

        if (mini == INF) cout << "Case #" << o+1 << ": Impossible\n";
        else {
            if (mini == 1) {
                set<ii> aux_subsets;
                forn(i,n) forn(k,2) if (last[i][k].fst != -1 && minis[i][k] == mini) aux_subsets.insert(last[i][k]);

                sets = (int)aux_subsets.size();
            }

            cout << "Case #" << o+1 << ": " << mini << ' ' << sets << '\n';
        }
    }

    return 0;
}