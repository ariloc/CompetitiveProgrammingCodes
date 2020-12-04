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

    int n; cin >> n;
    priority_queue<ii,vector<ii>,greater<ii>> Q1;
    priority_queue<ii> Q2;
    forn(i,n) {
        int x; cin >> x; Q1.push({x,i});
    }
    string s; cin >> s;
    forn(i,s.size()) {
        if (s[i] == '1') {
            cout << Q2.top().snd+1 << ' '; Q2.pop();
        }
        else {
            cout << Q1.top().snd+1 << ' ';
            Q2.push(Q1.top()); Q1.pop();
        }
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
