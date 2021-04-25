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

const int MAXN = 105;

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;

    forn(o,t) {
        int n,c; cin >> n >> c;

        forn(i,n) arr[i] = i+1;

        cout << "Case #" << o+1 << ": ";
        if (c < n-1 || c > (n*(n+1))/2-1) cout << "IMPOSSIBLE\n";
        else {
            int sum = n-1;
            bool right = 1;
            int l = 0, r = n, ind = 0;
            for (ind = 0; ind < n-1 && sum + n-ind-1 < c; ind++) {
                sum += n-ind-1;
                reverse(arr+l,arr+r);

                if (right) r--;
                else l++;
                right ^= 1;
            }

            if (right) r -= (sum+n-ind-c-1);
            else l += (sum+n-ind-c-1);
            reverse(arr+l,arr+r);

            forn(i,n) cout << arr[i] << ' ';
            cout << '\n';
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
