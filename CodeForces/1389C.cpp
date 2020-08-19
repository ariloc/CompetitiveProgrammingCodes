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

const int MAXD = 10;

int main() {
    FAST_IO;

    int t; cin >> t;

    forn(i,t) {
        string s; cin >> s;

        int toDel = s.size()-2;
        forn(j,MAXD) {
            forn(k,MAXD) {
                int turn = 0, cnt = 0;
                forn(w,s.size()) {
                    if (!turn and (s[w]-'0') == j) {cnt++; turn = 1;}
                    else if (turn and (s[w]-'0') == k) {cnt++; turn = 0;}
                }
                if (cnt & 1 and j != k) cnt--;
                toDel = min(toDel,(int)s.size()-cnt);
                cnt = 0; turn = 1;
                forn(w,s.size()) {
                    if (!turn and (s[w]-'0') == j) {cnt++; turn = 1;}
                    else if (turn and (s[w]-'0') == k) {cnt++; turn = 0;}
                }
                if (cnt & 1 and j != k) cnt--;
                toDel = min(toDel,(int)s.size()-cnt);
            }
        }

        cout << toDel << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!