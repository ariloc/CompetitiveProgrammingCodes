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

const int MAX = 40000;
const int MAXN = MAX+5;
const int MOD = 40009;

int fact[MAXN];
vi primes;
bitset<MAXN> done;

void criba() {
    for (int i = 4; i <= MAX; i += 2) done[i] = true;
    for (int i = 3; i <= MAX; i += 2)
        for (int j = i+i; j <= MAX; j += i)
            if (!done[j]) done[j] = true;

    forsn(i,2,MAX+1) if (!done[i]) primes.pb(i);
}
 
int main() {
    criba();

    fact[0] = 1;
    forsn(i,1,MAXN) fact[i] = (fact[i-1] * (ll)i)%MOD;

    int low = 0, high = (int)primes.size();
    string s;

    while (high - low > 1) {
        int mid = (high+low)/2;

        cout << "? " << primes[mid] << ' ' << primes[mid] << endl;
        cin >> s;

        if (s == "SI") low = mid;
        else high = mid;
    }

    /*cout << "? " << primes[high] << ' ' << primes[high] << endl;
    cin >> s;
    if (s != "SI") high = low;*/

    // considero que siempre es el low
    if (!low) {
        cout << "? 2 2" << endl;
        cin >> s;
        if (s == "NO") return cout << "! 1" << endl, 0;
    }

    primes.pb(40001);
    forsn(j,primes[low],primes[low+1]) {
        int toSum = MOD - fact[j];
        cout << "? " << toSum << ' ' << MOD << endl;
        cin >> s;
        if (s == "SI") cout << "! " << j << endl;
    }

    //cout << "! " << high << endl;

    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!