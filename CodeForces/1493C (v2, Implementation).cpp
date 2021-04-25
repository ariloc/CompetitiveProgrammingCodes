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

const int MAXA = 26;

int need[MAXA];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n,k; cin >> n >> k;
        string s; cin >> s;

        if (n%k) {cout << "-1\n"; continue;}

        forn(i,MAXA) need[i] = 0; // reset

        int totN = 0; map<int,int> letNeed;
        forn(i,n) need[s[i]-'a']++;
        forn(i,MAXA) need[i] %= k, need[i] = (need[i] ? k-need[i] : 0), totN += need[i];
        forn(i,MAXA) if (need[i]) letNeed[i] += need[i];

        if (!totN) {cout << s << '\n'; continue;}

        dforn(i,n) { // fijando el prefijo i-1
            totN -= need[s[i]-'a'], need[s[i]-'a'] = (need[s[i]-'a']+1)%k, totN += need[s[i]-'a']; // en cada paso suma hasta que llega a k y vuelve a 0

            /* nunca se va a dar que pueda lograr las cantidades pero no puedo por cuestión que me queda más chico
               pensar que mi need de c/u aumenta al sacar, que al volver a poner sería como ponerlo en su lugar
               o si no libero espacio de los mismos que tenían need, pudiendo satisfacerse entre ellos
               así la cosa está más bien que pueda nomás meterlos todos en el espacio según el need en un determinado momento
            */

            int dif = (n-i-totN);
            if (dif >= 0) {
                if (dif && !need[s[i]-'a'+1]) need[s[i]-'a'+1] += k, dif -= k;
                need[0] += dif;

                char cut = 'A';
                forsn(j,s[i]-'a'+1,MAXA) if (need[j]) {cut = (j+'a'); need[j]--; break;}

                if (cut == 'A') continue; // por las dudas que no hay ninguno, de la forma que sea (si había dif simplemente no puede pasar)

                forn(j,i) cout << s[j];
                cout << cut;
                forn(j,MAXA) cout << string(need[j],j+'a');
                goto CONT;
            }
        }

        cout << "-1";
        CONT: cout << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
