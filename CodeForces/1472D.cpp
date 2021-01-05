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
        priority_queue<int> A,B;
        forn(j,n) {int x; cin >> x; if (x&1) B.push(x); else A.push(x);}
        ll sA = 0, sB = 0;
        bool turn = 0;
        while (!A.empty() || !B.empty()) {
            if (!turn) {
                if (!A.empty()) {
                    if (B.empty() || A.top() > B.top()) sA += A.top(), A.pop();
                    else B.pop();
                } else B.pop();
            }
            else {
                if (!B.empty()) {
                    if (A.empty() || B.top() > A.top()) sB += B.top(), B.pop();
                    else A.pop();
                } else A.pop();
            }
            turn = !turn;
        }
        cout << (sA == sB ? "Tie" : sA > sB ? "Alice" : "Bob") << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
