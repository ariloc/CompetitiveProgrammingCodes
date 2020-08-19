#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(ll i = ll(s); i < ll(n); i++)
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

const int INF = 1e9;
const int MAXN = 1e6+2;
const int MAX = 30;

int arr[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn (i,n) cin >> arr[i];

    int rta = 0;
    dforn (maxi,MAX+1) { // considerando que mi mayor elemento es maxi
        int sum = 0;
        forn (i,n) { // me fijo los subsegmentos que no tengan valores mayores a maxi, pues no cumpliría la regla
            if (arr[i] > maxi) sum = 0; // reset si supera a maxi
            else {
                sum += arr[i]; // agregamos
                // suponemos que maxi está. Si no lo estuviera, daría una peor rta, por lo que no me afecta ya que sobrevive la mejor.
                rta = max(rta,sum-maxi);
                if (sum < 0) sum = 0; // Kadane, si nos vamos negativos, volvemos con un nuevo subsegmento
            }
        }
    }

    cout << rta;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!