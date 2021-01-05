#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 2e5+2;
const int INF = 1e9+5;

int arr[MAXN],blocks[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        set<int> num;
        forn(j,n) {cin >> arr[j]; arr[j]--; num.insert(arr[j]);}
        forn(j,n) blocks[j] = 0;

        int cnt = 1; bool counted = 0;
        forsn(j,1,n) {
            if (arr[j] == arr[j-1]) cnt++;
            else {
                if (!blocks[arr[j-1]]) blocks[arr[j-1]]++;
                blocks[arr[j-1]]++;
                if (!counted) blocks[arr[j-1]]--;
                cnt = 1; counted = true;
            }
        }
        if (cnt) {
            if (blocks[arr[n-1]] || !counted) blocks[arr[n-1]]--;
            blocks[arr[n-1]]++;
        }
        int mini = INF;
        forn(j,n) if (num.count(j)) mini = min(mini,blocks[j]);

        cout << (mini == INF ? -1 : mini) << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
