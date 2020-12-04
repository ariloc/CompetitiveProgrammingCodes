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

ii light[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    int maxi = 0;
    string s; cin >> s;
    forn(i,n) cin >> light[i].snd >> light[i].fst;
    forn(i,n) if (s[i] == '1') maxi++;
    forsn(i,1,1001) {
        int sum = 0;
        forn(j,n) {
            int calc = (max(0,(i-light[j].fst))/light[j].snd)+(i >= light[j].fst); // toggles
            bool r = (s[j] == '1');
            sum += ((calc&1)^r);
        }
        maxi = max(maxi,sum);
    }

    cout << maxi;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
