#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
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

bool mismoSigno (int &a, int &b) {
    if (a >= 0 and b >= 0) return true;
    if (a <= 0 and b <= 0) return true;
    return false;
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    forn (i,t) {
        int n,x,r = 0;
        string s;
        cin >> n >> x;
        cin >> s;

        int cantC = 0, cantU = 0;
        forn (j,n) // cuento cant de ceros y unos
            if (s[j] == '0') cantC++;
            else cantU++;

        int bal = cantC - cantU;

        int balAux = 0;
        if (!x) r++;
        forn (j,n) {
            if (s[j] == '0') balAux++; // prefixes a la derecha
            else balAux--;

            if (!bal)
                if (balAux == x) {r = -1; break;}
                else continue;
            int calc = ((x-balAux) / bal);
            if (! ((x-balAux) % bal) and calc >= 0) r++;

            //cerr << (x-balAux)/(float)bal << ' ' << r << ' ' << bal << endl;
        }

        cout << r << '\n';
    }

    return 0;
}