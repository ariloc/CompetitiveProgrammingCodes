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

const int charSym[10] = {1,1,1,0,0,1,0,0,1,0};

struct myTime {
    int h,m;
    int hmax,mmax;

    myTime operator+ (const int &o) const {
        int rm = (m+o)%mmax;
        int rh = (h+((m+o)/mmax))%hmax;
        return {rh,rm,hmax,mmax};
    }
};

bool isSym (myTime x) {
    int aux1 = x.h, aux2 = x.m;
    vi d1, d2;
    while (aux1) d1.pb(aux1%10), aux1 /= 10; // el 0 simetrico, así que no me preocupo
    while (aux2) d2.pb(aux2%10), aux2 /= 10;
    while ((int)d1.size() < 2) d1.pb(0);
    while ((int)d2.size() < 2) d2.pb(0);
    for (auto &i : d1) if (!charSym[i]) return false;
    for (auto &i : d2) if (!charSym[i]) return false;

    // si llego acá entonces tengo chars potencialmente sym
    for (auto &i : d1) i = (i == 2 ? 5 : i == 5 ? 2 : i); // swap corresp
    for (auto &i : d2) i = (i == 2 ? 5 : i == 5 ? 2 : i);

    //cerr << d2[0] << ' ' << d2[1] << ' ' << x.m << endl;
    int auxh = d2[0]*10+d2[1], auxm = d1[0]*10+d1[1];
    return (auxh < x.hmax && auxm < x.mmax);
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int h,m; cin >> h >> m;
        string tim; cin >> tim;

        myTime act = {tim[1]-'0'+(tim[0]-'0')*10, tim[4]-'0'+(tim[3]-'0')*10,h,m};

        while (!isSym(act)) act = act+1;

        cout << (act.h/10)%10 << act.h%10 << ':' << (act.m/10)%10 << act.m%10 << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
