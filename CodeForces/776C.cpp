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

const int MAXN = 1e5+2;
const ll MAXP = 1e14+2;
const int MAXPS = 100;

ll TAd[MAXN];
ll powers[MAXPS];
map<ll,int> P;

int main() {
    FAST_IO;

    int N,k; cin >> N >> k;

    ll acc = 0, rta = 0;
    forsn (i,1,N+1) {cin >> TAd[i]; acc+=TAd[i]; TAd[i]=acc;} // TAd en input

    ll potencia = 1;
    if (!k) powers[0] = 1; // caso 0
    else if (abs(k) == 1) {powers[0] = k; if (k < 0) powers[1] = k*k;}
    else for (int i = 0; potencia <= MAXP; i++) {powers[i] = potencia; potencia*=k;}

    for (int i = 0; powers[i]; i++) {
        P.clear();
        forn (j,N+1) {
            rta += P[TAd[j]-powers[i]];
            P[TAd[j]]++;
        }
    }

    cout << rta;

    return 0;
}