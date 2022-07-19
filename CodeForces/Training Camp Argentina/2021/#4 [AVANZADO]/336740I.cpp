// Statement: https://codeforces.com/group/gXivUSZQpn/contest/336740/problem/I

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
typedef unsigned long long ull;
typedef pair<int,int> ii;

ll xx, yy;

ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}
ull mulmod(ull a, ull b, ull m){ // 0 <= a, b < m
   long double x; ull c; ll r;
   x = a; c = x * b / m;
   r = (ll)(a * b - c * m) % (ll)m;
   return r < 0 ? r + m : r;
}

ll expmod(ll b, ll e, ll m){
	if(!e)return 1;
	ll q=expmod(b,e/2,m);q=mulmod(q,q,m);
	return e&1?mulmod(b,q,m):q;
}
bool is_prime_prob(ll n, int a){
	if(n==a)return true;
	ll s=0,d=n-1;
	while(d%2==0)s++,d/=2;
	ll x=expmod(a,d,n);
	if((x==1)||(x+1==n))return true;
	forn(_,s-1){
		x=mulmod(x,x,n);
		if(x==1)return false;
		if(x+1==n)return true;
	}
	return false;
}
bool rabin(ll n){ // true iff n is prime
	if(n==1)return false;
	int ar[]={2,3,5,7,11,13,17,19,23};
	forn(i,9)if(!is_prime_prob(n,ar[i]))return false;
	return true;
}

ll rho(ll n){
    if(!(n&1))return 2;
    ll x=2,y=2,d=1;
    ll c=rand()%n+1;
    while(d==1){
        x=(mulmod(x,x,n)+c)%n;
        y=(mulmod(y,y,n)+c)%n;
        y=(mulmod(y,y,n)+c)%n;
        if(x>=y)d=gcd(x-y,n);
        else d=gcd(y-x,n);
    }
    return d==n?rho(n):d;
}
void fact(ll n, map<ll,int>& f){ //O (lg n)^3
	if(n==1)return;
	if(rabin(n)){f[n]++;return;}
	ll q=rho(n);fact(q,f);fact(n/q,f);
}

ll phi (ll x) { // factorizo con Pollard Rho rápido, y luego saco phi(x) de los fact. primos
    map<ll,int> F;
    fact(x,F);
    ll rta = 1;

    // phi(n) = \prod_{i=0}^{n-1} (p_i^k - p_i^(k-1))
    // phi(n) = \prod_{i=0}^{n-1} (p_i^k - (p_i^k / p_i))
     // EN ENTEROS -> evito overflow por meros productos desde 1
    for (auto &i : F) {
        ll p_k = 1;
        forn(j,i.snd) p_k *= i.fst;
        rta = rta * (p_k - (p_k / i.fst));
    }

    return rta;
}

void recurDivs (vector<ll> &divs, vector<pair<ll,int>> &F, ll acc = 1, int st = 0) {
    if (st < (int)F.size()) {
        recurDivs(divs,F,acc,st+1); // recordar que puedo hacerlo con 0 usos
        forn(j,F[st].snd) {
            acc *= F[st].fst;
            divs.pb(acc);
            recurDivs(divs,F,acc,st+1);
        }
    }
}

vector<ll> divFromFact (vector<pair<ll,int>> &F_vec) {
    vector<ll> divs;
    recurDivs(divs,F_vec);
    return divs;
}

ll binModExp (ll a, ll k, ll m) {
    ll r = 1;
    while (k) {
        if (k&1) r = mulmod(r%m,a%m,m);
        a = mulmod(a%m,a%m,m); k >>= 1;
    }
    return r;
}

int main() {
    FAST_IO;

    ll a,m; cin >> a >> m;
    //if (gcd(a,m) != 1) cout << "Maradona e muito mais grande que o Pele"; // no existe si no son coprimos

    ll phiMod = phi(m);

    map<ll,int> fact_phi;
    fact(phiMod,fact_phi); // obtengo los factores primos de phi

    vector<pair<ll,int>> F_vec; // los paso a una lista
    for (auto &i : fact_phi) F_vec.pb(i);

    vector<ll> divs_phi = divFromFact(F_vec); // obtengo los divisores partiendo de los factores

    // los ordeno y pruebo del más chico al más grande
    divs_phi.pb(1); // no lo saco en las cuentas, pero está incluido
    sort(all(divs_phi));
    divs_phi.erase(unique(all(divs_phi)),divs_phi.end());

    /*for (auto &i : divs_phi) cerr << i << ' ';
    cerr << endl;*/

    ll rta = -1;
    for (auto &i : divs_phi) {
        if (binModExp(a,i,m) == 1) {
            rta = i; break;
        }
    }

    if (rta != -1) cout << rta << '\n';
    else cout << "Maradona e muito mais grande que o Pele";

    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!