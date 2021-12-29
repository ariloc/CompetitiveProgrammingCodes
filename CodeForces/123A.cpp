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

const int MAXN = 1005;
const int MAXA = 30;

bitset<MAXN> done, done2;
vi primes;
int cnt[MAXA];

void criba() {
    for (int i = 4; i < MAXN; i += 2) done[i] = true;
    for (int i = 3; i*i < MAXN; i += 2)
        if (!done[i])
            for (int j = i+i; j < MAXN; j += i)
                done[j] = true;

    forsn(i,2,MAXN) if (!done[i]) primes.pb(i);
}

int main() {
    FAST_IO;

    criba();

    string s; cin >> s;
    for (auto &i : s) cnt[i-'a']++;
    int n = (int)s.size();

    int maxi = 0; char chosen = 'A';
    forn(i,MAXA)
        if (cnt[i] > maxi)
            maxi = cnt[i], chosen = i+'a';

    string r = string(n,'A');
    for (auto &i : primes)
        if (n/i >= 2) {
            for (int j = i; j <= n; j += i) {
                if (r[j-1] != 'A') continue;
                if (maxi <= 0) return cout << "NO", 0;
                r[j-1] = chosen, --maxi;
            }
        }
    

    cnt[chosen-'a'] = maxi;

    int aux_ind = 0;
    forn(i,n) 
        if (r[i] == 'A') {
            while (aux_ind < MAXA && cnt[aux_ind] <= 0) aux_ind++;
            if (aux_ind >= MAXA) return cout << "NO", 0; // no debería llegar acá, pero por las dudas...
            r[i] = aux_ind+'a', cnt[aux_ind]--;
        }

    cout << "YES\n" << r;

    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!