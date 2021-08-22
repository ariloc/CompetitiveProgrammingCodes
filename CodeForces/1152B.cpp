#include <bits/stdc++.h>

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

vi rta;
bitset<32> states;

int main() {
    FAST_IO;

    int x; cin >> x;
    states = x;

    int msb = 32-__builtin_clz(x);

    int op = 0;
    while (true) {
        bool flag = false;
        //cerr << states << endl;
        dforn (i,msb) {
            if (!states[i]) {
                states ^= ((1<<(i+1))-1);
                op++;
                rta.pb(i+1);
                flag = true;
                break;
            }
        }
        //cerr << states << endl;

        if (!states[0]) {
            bool tmpF = false;
            dforsn (i,1,msb) if (!states[i]) {tmpF = true; break;}
            //cerr << tmpF << "OK" << endl;
            if (!tmpF) {op++; break;}
        } else {
            bool tmpF = false;
            dforn (i,msb) if (!states[i]) {tmpF = true; break;}
            if (!tmpF) break;
        }
        states = states.to_ulong()+1; op++;
    }

    cout << op << '\n';
    for (auto &i : rta) cout << i << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!