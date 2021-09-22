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

const int MAXN = 101;
const int MAXM = 20;
const int MAXPB = (1<<MAXM);
const ll INF = 3e18+2;

struct person {
    int p,m,s; // problems, money, screens/monitors

    bool operator< (const person &o) const{
        return o.s > s;
    }
};

person fr[MAXN];
ll dp[MAXPB];

int main() {
    FAST_IO;

    int n,m,b; cin >> n >> m >> b; // input

    forn (i,n) {
        int x,k,l; cin >> x >> k >> l;
        int prob = 0; // bitmask de problemas que puede resolver cierta persona

        forn (j,l) {int o; cin >> o; o--; prob |= (1<<o);}

        fr[i] = {prob,x,k};
    }
    sort(fr,fr+n); // ordeno los amigos por cantidad de monitores que piden para facilitar dsps

    forsn (i,1,(1<<m)) dp[i] = INF; // lleno tabla, excepto 0 problemas resueltos, que es caso trivial
    ll best = INF; // variable para la mejor posibilidad

    forn (i,n) { // DP-Bitmask Bottom-Up
        ll monitors = (ll)b*fr[i].s; // si llegué a este punto, requiero hasta fr[i].s monitores
        forn (j,(1<<m)) { // dado una persona, las posibilidades de llegar a dicha persona
            int bitmask = j | fr[i].p; // cantidad de problemas que resuelve amigo i + otra combinación antes
            dp[bitmask] = min(dp[bitmask], dp[j] + fr[i].m); // mejor suma para esta combinación
        }
        best = min(best,dp[(1<<m)-1] + monitors);
        // considerando que tengo cierta cantidad de monitores hasta este punto si o si,
        // agarro la mejor combinación considerando la cantidad de monitores que necesito
    }

    cout << (best==INF ? -1 : best); // output + verifico si existe combinación

    return 0;
}