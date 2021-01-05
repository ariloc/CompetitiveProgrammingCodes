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

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        string s; cin >> s;
        int cnt1 = 0, cnt2 = 0, cmp1 = 0, cmp2 = 0;
        forn(j,n) {
            if (((s[j]-'0')&1) != (j&1)) {
                cnt1++;
                if (cnt2) cmp2++;
                cnt2 = 0;
            }
            else {
                cnt2++;
                if (cnt1) cmp1++;
                cnt1 = 0;
            }
        }
        if (cnt2) cmp2++;
        if (cnt1) cmp1++;

        cout << min(cmp1,cmp2) << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
