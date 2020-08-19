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

const int MAXN = 2e5+2;
const int MAXM = 201;

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int N; cin >> N;

        int maxL = 0;
        vector<vi> TAd(MAXM,vi(N+2)); // 2D TAd
        vector<vi> each(MAXM);

        forn (j,N) {
            cin >> arr[j];

            TAd[arr[j]][j]++; // sumo a TAd
            each[arr[j]].pb(j); // cadena ordenada de apariciones de c/u
        }
        forsn (j,1,N) forn (k,MAXM) TAd[k][j] += TAd[k][j-1]; // completo TAd

        forsn (j,1,MAXM) { // if x == j
            maxL = max(maxL,(int)each[j].size()); // por si no tengo elementos medios
            forn (k,(int)each[j].size()/2) { // eligiendo primeros y últimos k elementos
                forsn (l,1,MAXM) { // dado los medios
                    if (l == j) continue; // no quiero volver a contarme :P
                    int r = each[j][each[j].size()-1-k]; // limite derecho
                    int cant = TAd[l][r]-(each[j][k]-1 < 0 ? 0 : TAd[l][each[j][k]-1]); // Suma de elementos TAd medio
                    maxL = max(maxL,(k+1)*2+cant);
                }
            }
        }

        cout << maxL << '\n';
    }

    return 0;
}