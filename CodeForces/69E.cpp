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

const int MAXN = 1e5+5;

map<int,int> appear;
set<int> posib;
int arr[MAXN];

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;
    forn(i,n) cin >> arr[i];

    forn(i,k) {
        appear[arr[i]]++;
        if (appear[arr[i]] != 1) posib.erase(arr[i]);
        else posib.insert(arr[i]);
    }
    
    forsn(i,1,n-k+1) {
        if (!posib.empty()) cout << *posib.rbegin() << '\n';
        else cout << "Nothing\n";

        appear[arr[i-1]]--;
        appear[arr[i+k-1]]++;

        if (appear[arr[i-1]] != 1) posib.erase(arr[i-1]);
        else posib.insert(arr[i-1]);

        if (appear[arr[i+k-1]] != 1) posib.erase(arr[i+k-1]);
        else posib.insert(arr[i+k-1]);
    }

    if (!posib.empty()) cout << *posib.rbegin() << '\n';
    else cout << "Nothing\n";

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!