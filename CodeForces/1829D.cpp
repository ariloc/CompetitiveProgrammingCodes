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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXP = 32;

int cdiv (int x, int p) {
    int cnt = 0;
    while (x > 1 && !(x%p)) ++cnt, x /= p;
    return cnt;
}

int pot2[MAXP], pot3[MAXP];

bool cond (int n, int m) {
    int a = n / pot2[cdiv(n,2)] / pot3[cdiv(n,3)];
    int b = m / pot2[cdiv(m,2)] / pot3[cdiv(m,3)];
    return a == b;
}

int main() {
    FAST_IO;

    pot2[0] = 1, pot3[0] = 1;
    forsn(i,1,MAXP) pot2[i] = pot2[i-1] * 2, pot3[i] = pot3[i-1] * 3;

    int t; cin >> t;
    forn(_,t) {
        int n,m; cin >> n >> m;

        if ((cdiv(n,3)-cdiv(m,3)) >= (cdiv(m,2)-cdiv(n,2)) && cond(n,m) && cdiv(n,2) <= cdiv(m,2)) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}
