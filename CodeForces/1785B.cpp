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

const string WIN = "win";

struct exch {
    int a,b,ca,cb;
};

vi r[3][3]; // remain
int ady[3][3];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        forn(i,3) forn(j,3) ady[i][j] = 0, r[i][j].clear();

        int n; cin >> n;
        forn(i,n) {
            string s; cin >> s;
            int cnt[] = {0,0,0};
            for (auto &j : s) {
                if (j == 'w') cnt[0]++;
                else if (j == 'i') cnt[1]++;
                else cnt[2]++;
            }
            
            int excess = -1;
            forn(k,3) if (cnt[k] > 1) excess = k;
            if (excess != -1) {
                forn(k,3) {
                    if (!cnt[k]) {
                        ady[excess][k]++;
                        r[excess][k].pb(i);
                    }
                }
            }
        }

        vector<exch> rta;
        
        int p[] = {0,1,2};
        do {
            forsn(i,1,3) { // len perm
                int aux = ady[p[i]][p[0]];
                forn(j,i) aux = min(aux, ady[p[j]][p[j+1]]);

                forn(j,aux) { // for each link
                    int last = r[p[0]][p[1]].back(); r[p[0]][p[1]].pop_back();
                    forn(k,i) { // follow the chain
                        ady[p[k]][p[k+1]]--;

                        auto &vec = r[p[k+1]][p[(k+2)%(i+1)]];
                        int x = vec.back(); vec.pop_back();
                        rta.pb({last,x,p[0],p[k+1]});
                        last = x;
                    }
                    ady[p[i]][p[0]]--;
                }
            }
        } while(next_permutation(p,p+3));

        cout << (int)rta.size() << '\n';
        for (auto &i : rta) {
            cout << i.a+1 << ' ' << WIN[i.ca] << ' ' << i.b+1 << ' ' << WIN[i.cb] << '\n';
        }
    }

    return 0;
}
