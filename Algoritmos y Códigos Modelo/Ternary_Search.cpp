#include <bits/stdc++.h>
using namespace std;
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforr(i, a, b) for(int i = (int)(b-1); i >= (a); i--)
#define dforn(i, n) dforr(i, 0, n)
#define db(v) cerr << #v << " = " << v << endl
#define pb push_back
#define sz(x) ((int)x.size())
#define fst first
#define snd second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
const int MAXN = -1;

ld fun(ld t){ return sqrtl((t-4)*(t-4));}

// Todas estas son para hallar el mínimo
// Si querés el máximo cambiá el sentido del operador en el if()

// Quite unpopular, pero similar a BS()
ll TS(ll l, ll r){
    while(r - l > 2){
        ll tl = (2*l + r)/3, tr = (l + 2*r)/3;
        if(fun(tl) < fun(tr))r = tr;
        else l = tl;
    }
    while(fun(l+1) < fun(l))l++; // Prueba a lo sumo 3 veces
    return l;
}

// Igual al anterior pero en flotantes funciona mucho mejor
// Por lo tanto en este caso es popular
ld TSD(ld l, ld r){
    int cnt = 50; // Ajustable si estás jugado con el tiempo
    while(cnt--){
        ld tl = (2*l + r)/3, tr = (l + 2*r)/3;
        if(fun(tl) < fun(tr))r = tr;
        else l = tl;
    }
    return l;
}

// Para enteros es mucho más popular usar una BS() de la siguiente forma
ll BS(ll l, ll r){
    while(r - l > 1){ // Recordá procurar que la respuesta sea estrictamente mayor a l y menor a r;
        ll m = (l + r)/2;
        if(fun(m) <= fun(m+1))r = m;
        else l = m;
    }
    return r;
}


int n;

int main(){
//	freopen("input.txt", "r", stdin);
//  ios :: sync_with_stdio(false); cin.tie(NULL);
//    while(scanf("%d", &n) >= 1){
    printf("Con la primer ternary: %lld\n", TS(0, 10));
    printf("Con la segunda ternary: %.20Lf\n", TSD(0.0, 10.0));
    printf("Con la binary: %lld\n", BS(0, 10));
//    }
	return 0;
}
