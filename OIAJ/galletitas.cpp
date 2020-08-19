#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXN = 200010;
const int INF = 1e9+2;

void parte(int tam, int i);

struct estado {
    int sum,I,O,gallet; // I, O son remanentes de separar galletita
};

struct padre {
    int ind,typ;
};

estado dp[MAXN][3]; // val, galletitas accum
padre P[MAXN][3];
// 1 -> pego directamente galletita | 2 -> tipo 1 | 3 -> tipo 2

int galletitas(string cadena, int G, int D, int T)
{
    forn (i,MAXN) forn (j,3) dp[i][j] = {INF,0,0,0};

    dp[0][0] = dp[0][1] = dp[0][2] = {0,0,0,0};
    P[0][0] = P[0][1] = P[0][2] = {-1,-1};
    forn (i,cadena.size()) {
        forn(j,3) {
            if (i+1 < (int)cadena.size() and max(cadena[i],cadena[i+1]) == 'O' and
                min(cadena[i],cadena[i+1]) == 'I') {
                    int I = dp[i][j].I, O = dp[i][j].O;
                    I += 1;
                    int calc = dp[i][j].sum+G+D;
                    if (calc < dp[i+2][1].sum) {
                        dp[i+2][1] = {calc,I,O,dp[i][j].gallet+1};
                        P[i+2][1] = {i,j};
                    }
                }
            if (i+1 < (int)cadena.size() and i+2 < (int)cadena.size() and cadena[i+1] == 'O' and
                cadena[i] == 'I' and cadena[i] == cadena[i+2]) {
                    int I = dp[i][j].I, O = dp[i][j].O;
                    int calc = dp[i][j].sum+G;
                    if (calc < dp[i+3][0].sum) {
                        dp[i+3][0] = {calc,I,O,dp[i][j].gallet+1};
                        P[i+3][0] = {i,j};
                    }
                }

            int I = dp[i][j].I - (cadena[i] == 'I'), O = dp[i][j].O - (cadena[i] == 'O');
            bool nuevaG = false;
            if (I < 0 or O < 0) {nuevaG = true; I += 2; O += 1;}
            int calc = dp[i][j].sum+(nuevaG ? G+T : 0);
            if (calc < dp[i+1][2].sum) {
                dp[i+1][2] = {calc,I,O,dp[i][j].gallet+nuevaG};
                P[i+1][2] = {i,j};
            }
        }
    }

    int mini = min({dp[cadena.size()][0].sum,dp[cadena.size()][1].sum,dp[cadena.size()][2].sum});
    forn (i,cadena.size()+5) cerr << dp[i][0].sum << ' ' << dp[i][1].sum << ' ' << dp[i][2].sum << endl;
    int typ = -1;
    if (mini == dp[cadena.size()][0].sum) typ = 0;
    else if (mini == dp[cadena.size()][1].sum) typ = 1;
    else typ = 2;

    /*vector<ii> toDivide;
    for (ii i = {cadena.size(),typ}; i.fst != -1; i = P[i.fst][i.snd])
        toDivide.pb({i.fst,i.snd});

    int last = 0;
    dforn (i,toDivide.size()-1) {
        parte(toDivide[i].fst-last,dp[toDivide[i].fst][toDivide[i].snd].gallet)
    }*/

    return mini;
}

// ***************** EVALUADOR LOCAL *******************

#ifndef EVAL

    #include <iostream>
    #include <vector>
    #include <string>
    #include <cassert>

    using namespace std;

    int galletitas(string cadena, int G, int D, int T);

    vector<int> _EVALUADOR__evaluadorGlobalVtam;
    vector<int> _EVALUADOR__evaluadorGlobalVi;

    void parte(int tam, int i)
    {
        _EVALUADOR__evaluadorGlobalVtam.push_back(tam);
        _EVALUADOR__evaluadorGlobalVi.push_back(i);
    }

    using namespace std;

    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        string s; cin >> s;
        int G,D,T; cin >> G >> D >> T;
        cout << galletitas(s, G,D,T) << "\n";
        assert(_EVALUADOR__evaluadorGlobalVi.size() == _EVALUADOR__evaluadorGlobalVtam.size());
        cout << _EVALUADOR__evaluadorGlobalVi.size() << "\n";
        for (int i=0;i<int(_EVALUADOR__evaluadorGlobalVi.size());i++)
            cout << _EVALUADOR__evaluadorGlobalVtam[i] << " " << _EVALUADOR__evaluadorGlobalVi[i] << "\n";
        return 0;
    }
#endif
