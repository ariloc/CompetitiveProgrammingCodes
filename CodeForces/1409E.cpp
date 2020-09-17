
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

const int MAXN = 2e5+5;

int X[MAXN],posib[MAXN],TAd[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n,k; cin >> n >> k;
        forn(j,n) cin >> X[j];
        forn(j,n) {int x; cin >> x;}

        sort(X,X+n);

        int j = 0;
        forn(i,n) {
            while (j < n and X[j] <= X[i]+k) j++;
            posib[i] = j-i; // para cada i
            TAd[i] = j-i;
        }
        int myMax = 0;
        dforn(i,n) {
            myMax = max(myMax,posib[i]);
            TAd[i] = myMax;
        }

        int maxi = 0;
        forn(i,n) maxi = max(maxi,posib[i]+(i+posib[i] < n ? TAd[i+posib[i]] : 0));

        cout << maxi << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
