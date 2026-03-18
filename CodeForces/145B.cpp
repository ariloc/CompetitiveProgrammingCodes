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

    int a,b,c,d; cin >> a >> b >> c >> d;

    if (abs(c-d) > 1) 
        return cout << "-1\n", 0;

    string s;

    if (c > d) {
        forn(i,c) s += "47";

        a -= c;
        b -= c;

        if (a < 0 || b < 0)
            return cout << "-1\n", 0;

        s = string(a,'4') + s;
        s += string(b,'7');

        cout << s << '\n';
    }
    else if (c < d) {
        forn(i,d) s += "74";

        b -= d;
        a -= d;

        if (a < 0 || b < 0)
            return cout << "-1\n", 0;
        
        s.pop_back();
        // cuando agrego 7s, al final de todo posible
        s += string(b,'7');
        s.pb('4');

        // cuando agrego 4s, al principio de todo posible
        s = "7" + string(a,'4') + s.substr(1);

        cout << s << '\n';

    }
    else if (c == d) {
        if (a > c) { // voy con la que me da un número más chico si me alcanza la cant de 4s
            forn(i,c) s += "47";

            a--; // saco el 4 de antemano

            a -= c;
            b -= c;

            if (a < 0 || b < 0)
                return cout << "-1\n", 0;

            s = string(a,'4') + s;
            s += string(b,'7');
            s.pb('4'); // pongo el 4 que saqué

            cout << s << '\n';
        }
        else { // sino a == c, en cuyo caso es de la forma 7474747 (menos 4s que 7s)
            forn(i,d) s += "74";

            b--; // saco el 7 de antemano

            b -= d;
            a -= d;

            if (a < 0 || b < 0)
                return cout << "-1\n", 0;
            
            s += string(a,'4');
            s += string(b+1,'7'); // +1 para contar el que saco de antemano, bien al final

            cout << s << '\n';
        }
    }

    return 0;
}
