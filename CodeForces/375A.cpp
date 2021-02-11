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

int main() {
    FAST_IO;

    string s; cin >> s;

    string z,norm;
    bool cond[4] = {0,0,0,0}; // 1,6,8,9 found
    forn(j,s.size()) {
        if (s[j] == '0') z.pb('0');
        else if (s[j] == '1' && !cond[0]) cond[0] = 1;
        else if (s[j] == '6' && !cond[1]) cond[1] = 1;
        else if (s[j] == '8' && !cond[2]) cond[2] = 1;
        else if (s[j] == '9' && !cond[3]) cond[3] = 1;
        else norm.pb(s[j]);
    }

    int rest = 0;
    forn(j,norm.size()) rest = (rest*10 + norm[j]-'0')%7;// sacamos resto hasta acá

    int arr[4] = {1,6,8,9};
    do {
        int aux = rest; forn(i,4) aux = (10*aux + arr[i])%7;
        if (!aux) break;
    } while (next_permutation(arr,arr+4));

    cout << norm;
    forn(i,4) cout << arr[i];
    cout << z;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
