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

void startAlgo (int &a, int &b, int c1, int c2, vi &thisTira) {
    int ind = 0;
    int arr[2] = {a,b}, ch[2] = {c1,c2};
    while (arr[ind] > 0) {
        thisTira.pb(ch[ind]);
        arr[ind]--; ind = ((ind+1)&1);
    }
    a = arr[0]; b = arr[1];
}

int main() {
    FAST_IO;

    int a,b,c,d; cin >> a >> b >> c >> d;

    forn(i,(1<<5)) {
        vi tira;
        int a1 = a, b1 = b, c1 = c, d1 = d;
        if (i&1) startAlgo(a1,b1,0,1,tira);
        else startAlgo(b1,a1,1,0,tira);
        if (i&2) startAlgo(c1,b1,2,1,tira);
        else startAlgo(b1,c1,1,2,tira);
        if (i&4) startAlgo(d1,c1,3,2,tira);
        else startAlgo(c1,d1,2,3,tira);
        while (d1-- > 0) tira.pb(3);

        bool posib = true;
        forsn(i,1,tira.size()) if (abs(tira[i]-tira[i-1]) != 1) {posib = false; break;}
        if (tira.size() != a+b+c+d) posib = false;

        if (posib) {
            cout << "YES\n";
            for(auto &i : tira) cout << i << ' ';
            return 0;
        }
    }

    cout << "NO";

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
