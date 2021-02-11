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

const int MAXN = 2e5+5;

int arr[MAXN];
map<int,int> appear;
priority_queue<int,vi,greater<int>> missing;

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> arr[i];

    forn(i,n) appear[arr[i]]++;
    forn(i,n) if (!appear.count(i+1)) missing.push(i+1);
    int cnt = 0;
    forn(i,n) {
        if (!appear.count(arr[i]) || (appear[arr[i]] > 1 && missing.top() < arr[i])) {
            if (appear.count(arr[i])) appear[arr[i]]--;
            arr[i] = missing.top(), missing.pop();
            cnt++;
        }
        if (appear.count(arr[i])) appear.erase(arr[i]);
    }

    cout << cnt << '\n';
    forn(i,n) cout << arr[i] << ' ';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
