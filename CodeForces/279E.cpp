#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int main() {
    FAST_IO;

    string s; cin >> s;

    int a = 0, b = 1; // base
    forn (i,s.size())
        if (s[i] == '1') a = min(a,b)+1; // voy yendo, si tengo todo consecutivo mantengo
        else b = min(a,b)+1; // cuando hay un cambio, tendría que hacer una operación

    // Es como que voy acumulando de uno, y cada cambio implica luego que salte otro
    // se puede ver como que si hay un cambio abrupto lo tapa

    cout << a;

    return 0;
}