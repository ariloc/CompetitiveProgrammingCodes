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

map<int,int> F;

void fact(int N) {
    for (int i = 2; i*i <= N; i++)
        while (!(N%i)) {F[i]++; N/=i;}
    if (N > 1) F[N]++;
}

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;
    fact(n);

    vi myfact;
    for (auto &i : F) {
        while (i.snd--)
            if ((int)myfact.size() == k) myfact[(int)myfact.size()-1] *= i.fst;
            else myfact.pb(i.fst);
    }

    if ((int)myfact.size() < k) cout << -1;
    else for (auto &i : myfact) cout << i << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!

