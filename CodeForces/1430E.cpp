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
const int MAXA = 26;

int dpL[MAXN][MAXA], dpLR[MAXN][MAXA];
vi posic[MAXA];
int curr_ind[MAXA];

int main() {
    FAST_IO;

    int n; cin >> n;
    string s; cin >> s;

    forn(j,n) dpL[j+1][s[j]-'a']++;
    reverse(all(s));
    forn(j,n) dpLR[j+1][s[j]-'a']++;
    forsn(i,1,n+1) forn(k,MAXA) dpL[i][k] += dpL[i-1][k];
    forsn(i,1,n+1) forn(k,MAXA) dpLR[i][k] += dpLR[i-1][k];
    forn(j,n) posic[s[j]-'a'].pb(j+1);
    reverse(all(s));

    ll cnt = 0;
    forn(i,s.size()) {
        int ind = curr_ind[s[i]-'a'];
        forn(k,MAXA) cnt += max(0,dpLR[posic[s[i]-'a'][ind]-1][k]-dpL[i][k]);
        curr_ind[s[i]-'a']++;
    }

    cout << cnt;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
