#include<bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        string s; cin >> s;

        int bini = 0, bfin = 0;
        int inid = -1, finid = n; // indices "fuera de rango" por defecto

        int cntini = 0;
        forn(i,n) if (s[i] == '1') cntini++; 

        if (!cntini) {
            if (n <= 3) cout << "1\n";
            else cout << (n-4)/3 + 2 << '\n';
            continue; // siguiente test
        }
        
        if (s[0] == '0') {
            forn(i,n) {
                if (s[i] == '1') {
                    inid = i;
                    break;
                }
                else bini++;
            }
        }
        
        if (s.back() == '0') {
            dforn(i,n) {
                if (s[i] == '1') {
                    finid = i;
                    break;
                }
                else bfin++;
            }
        }


        int cnt = 0;
        vi blocks;
        forsn(i,inid+1,finid+1) { // voy hasta el último 1 *inclusive*, para forzar a pushear el último conjunto de 0s al vector en el else
            if (s[i] == '0') {
                cnt++;
            }
            else {
                blocks.pb(cnt); // si inid == finid (no hay bloques intermedios), pushea uno de 0, no me molesta después la cuenta
                cnt = 0;
            }
        }

        // la respuesta es *total* number, entonces incluimos los que contamos al principio
        int rta = cntini;

        if (bini >= 2) rta += 1 + (bini-2)/3;
        if (bfin >= 2) rta += 1 + (bfin-2)/3;

        // proceso bloques intermedios, asumiendo que a sus costados ya hay 1s puestos
        for (auto &b : blocks) {
            rta += max(0, b/3); // (b-2 + 3 - 1) = b
        }

        cout << rta << '\n';
    }
   
    return 0;
}
