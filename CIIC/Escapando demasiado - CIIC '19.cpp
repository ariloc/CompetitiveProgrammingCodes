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

const int INF = 1e9+5;

int main() {
    FAST_IO;

    string s;
    while (cin >> s) {
        s += 'E'; // dummy
        string lex[2];
        bool posib = true;

        int cnt = 0, mini = INF;
        forn (i,s.size()) {
            if (s[i] == 'x') cnt++;
            else {
                if (!cnt) continue;
                if (cnt & 1)
                    if (s[i] != 'p') {posib = false; break;} // si no puede ser
                    else {mini = 1; cnt = 0; continue;} // deal breaker

                int myDiv = 0;
                while (cnt and !(cnt & 1)) {myDiv++; cnt>>=1;}
                if (s[i] == 'p' and cnt) myDiv++;
                mini = min(mini,myDiv);
                cnt = 0;
            }
        }

        if (!posib) {cout << "0\nNOSTRING" << endl; continue;}

        if (mini == INF) mini = 1;
        cout << mini << endl;
        cnt = 0;
        forn(i,s.size()) {
            if (s[i] == 'x') cnt++;
            else {
                int orgCnt = cnt;
                forn(j,2) {
                    int myMini = (!j ? mini : 1);
                    int myDiv = 0; bool doP = false;
                    if (!cnt) {lex[j] += s[i]; continue;}

                    while (cnt and !(cnt & 1) and (myDiv+1) <= myMini) {myDiv++; cnt>>=1;}
                    if (s[i] == 'p' and cnt and (myDiv+1) <= myMini) {doP = true; cnt>>=1;}
                    lex[j] += string(cnt,'x'); lex[j] += string(doP,'$');
                    if (!doP) lex[j] += s[i];
                    cnt = orgCnt;
                }
                cnt = 0;
            }
        }
        lex[0].pop_back(); // quito dummy
        lex[1].pop_back(); // quito dummy
        cout << min(lex[0],lex[1]) << endl;
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
