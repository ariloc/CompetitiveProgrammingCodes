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

const int MAXN = 1e5+5;

int match[MAXN];
int histo[MAXN][2];
vector<ii> rta;
bitset<MAXN> done;

int sumq (int l, int r, int player) {
    assert(l > 0); assert(r < MAXN);
    assert(player == 0 || player == 1);
    return histo[r][player] - histo[l-1][player];
}

int op (int l, int r) {
    return max( sumq(l,r,0), sumq(l,r,1) );
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> match[i+1], match[i+1]--;

    forsn(i,1,n+1) { // desfasado en 1
        histo[i][0] += histo[i-1][0];
        histo[i][1] += histo[i-1][1];
        histo[i][match[i]]++;
    }

    int winner = match[n];
    int acc[] = {0,0};
    dforsn(i,1,n+1) { 
        acc[match[i]]++;

        int t = acc[winner]; // serves
        int setsWon[] = {0,0};
        //setsWon[winner]++;

        if (acc[winner] > acc[1-winner] && !done[t]) { // como me valgo de logs, no me puedo permitir repetir búsquedas (done)
            done[t] = true;
            int l = 1;

            bool posib = true; // se mantiene sólo si toda ventana me dio su ganador correspondiente
            while (l <= n) { // mientras esté lejos de intersecarme
                // binary search en el extremo derecho
                int low = l, high = n; 
                while (high-low > 1) {
                    int mid = (high+low)/2;

                    int max_sum = op(l,mid);

                    if (max_sum < t) low = mid;
                    else high = mid;
                }
                if (op(l,low) < t) low = high; // low es mi rta

                int actWinner = (sumq(l,low,1) > sumq(l,low,0));

                //cerr << high << ' ' << r << ' ' << "!?" << endl;
                /*|| sumq(l,low,actWin) == sumq(l,low,1-actWin))*/ // probablemente no necesito la otra cond

                if (sumq(l,low,actWinner) < t || match[low] != actWinner) { // si no llegué, o el ganador del serve por puntos no coincide con el punto final
                    posib = false; break;
                }

                setsWon[actWinner]++;
                l = low+1;
            }

            //cerr << t << ' ' << l << ' ' << haveTwoRanges << ' ' << posib << endl;

            //cerr << posib << "!!" << endl;
            if (posib && setsWon[winner] > setsWon[1-winner])
                rta.pb({setsWon[winner], t});
        }
    }
    
    sort(all(rta));
    cout << rta.size() << '\n';
    for (auto &i : rta) cout << i.fst << ' ' << i.snd << '\n';

    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!