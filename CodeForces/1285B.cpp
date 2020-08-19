#include <bits/stdc++.h>

#define forn(i,n) for(ll i = 0; i < ll(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const ll INF = 10e9+2;

int main() {
    FAST_IO;

    ll t;
    cin >> t;

    forn (i,t) {
        ll n;
        vector<ll> sweets;
        ll yas = 0;
        cin >> n;

        bool positives = false;
        ll maxi = -INF;
        forn (i,n) {
            ll x;
            cin >> x;
            yas += x;
            sweets.push_back(x);
            if (x > 0) positives = true;
            maxi = max(maxi,x);
        }

        if (!positives) {
            if (maxi >= yas) cout << "NO";
            else cout << "YES";
            cout << '\n';
            continue;
        }

        ll accum = 0, best = 0;
        bool reset = false;
        forn (i,sweets.size()) {
            accum += sweets[i];
            if (accum <= 0) {
                accum = 0;
                reset = true;
            }
            if (!reset and i == sweets.size()-1) {
                if (sweets[i] > sweets[0]) accum -= sweets[0];
                else accum -= sweets[i];
                /* CODIGO QUE FUNCA A PESAR QUE EL CASO NO ESTÁ. CUBRE
                A DIFERENCIA DEL PRIMERO, CUANDO EN VEZ DE DESCARTAR EL
                ÚLTIMO SI SE DIERA UN PICO, LO HAGO EL PRIMERO SEGÚN
                CONVIENE PUES, POR EJ, EL FINAL > ELEMENTO DEL PRINCIPIO.
                */
            }
            best = max(best,accum);
        }

        if (yas > best) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }

    return 0;
}