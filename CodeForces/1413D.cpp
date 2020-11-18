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

const int MAXN = 1e5+5;

pair<char,int> orders[2*MAXN];
int r[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    bool posib = true;
    forn(i,2*n) {
        char op; int x = -1; cin >> op;
        if (op == '-') cin >> x;
        orders[i] = {op,x};
    }

    priority_queue<int,vi,greater<int>> Q;
    int ind = n-1;
    dforn(i,2*n) {
        if (orders[i].fst == '-') Q.push(orders[i].snd);
        else {
            if (ind < 0 || Q.empty()) {posib = false; break;}
            r[ind--] = Q.top(); Q.pop();
        }
    }

    // check si está bien
    if (posib) {
        priority_queue<int,vi,greater<int>> Qaux;
        ind = 0;
        forn(i,2*n) {
            if (orders[i].fst == '+') Qaux.push(r[ind++]);
            else {
                if (Qaux.top() != orders[i].snd) {posib = false; break;}
                Qaux.pop();
            }
        }
    }

    if (posib) {cout << "YES\n"; forn(i,n) cout << r[i] << ' ';}
    else cout << "NO";

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
