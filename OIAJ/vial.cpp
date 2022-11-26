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

const int MAXA = 26;
const int MAXN = 2e5+5;
const int MAXR = 1e6;

int op[MAXR][2]; // 0 -> remove, 1 -> put
int onboard[MAXA], pending[MAXA], cnt_pending[MAXA], cntPend = 0;

int vial(int K, int C, string &tipo, vector<int> &cuantos, vector<int> &pos, string &queHay) {
    int t = (int)tipo.size();
    forn(i,t) onboard[tipo[i]-'A'] = cuantos[i]; // no repeat

    int n = (int)pos.size();

    forn(i,MAXR) op[i][0] = op[i][1] = '-'; // nothing

    forn(i,n) {
        char c = queHay[i];
        bool put = (c >= 'A' && c <= 'Z');
        if (put) c -= 'A';
        else c -= 'a';
        
        op[pos[i]][put] = c;
    }

    forn(i,MAXA) pending[i] = MAXR;

    int rta = C * MAXR;
    forsn(i,1,MAXR) {
        if (op[i][0] == op[i][1]) continue;
        if (op[i][0] != '-') rta += K, onboard[op[i][0]]++;
        
        if (cntPend > 0) {
            bool canClear = 1;
            int mini = MAXR;
            forn(k,MAXA) {
                mini = min(mini, pending[k]);
                canClear &= (onboard[k] >= cnt_pending[k]);
            }

            if (canClear) {
                rta += K * cntPend + C * 2 * (i-mini);
                cntPend = 0;
                forn(k,MAXA) pending[k] = MAXR, onboard[k] -= cnt_pending[k], cnt_pending[k] = 0;
            }
        }

        if (op[i][1] != '-') {
            if (onboard[op[i][1]]) rta += K, onboard[op[i][1]]--;
            else {
                pending[op[i][1]] = min(pending[op[i][1]], i);
                cnt_pending[op[i][1]]++;
                cntPend++;
            }
        }
    }

    return rta;
}
