#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for (int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXM = 1505;
const int INF = 1e9+5;

struct sum {
    int cnt, cnt_ult, ult;
};

sum dp[MAXM];
map<int,int> vals;

int cajero(vector<int> &billetes, int M, int C, vector<int> &respuesta) {
    int n = (int)billetes.size();
    reverse(all(billetes)); // men to may

    dp[0] = {0,0,-1};
    forsn(i,1,MAXM) dp[i] = {-INF,0,-1};
    forn(i,n) {
        int act = billetes[i];
        forsn(j,act,M+1) {
            if ( ((dp[j-act].cnt) + 1 > dp[j].cnt) && (dp[j-act].ult != act || dp[j-act].cnt_ult < C)) {
                dp[j] = {dp[j-act].cnt + 1, (dp[j-act].ult == act ? dp[j-act].cnt_ult + 1 : 1), act};
            }
        }
    }

    vi aux(n,0);

    if (dp[M].cnt < 0) {respuesta = aux; return 0;}

    int pos = M;
    while (pos > 0)
        vals[dp[pos].ult]++, pos -= dp[pos].ult;

    reverse(all(billetes));
    forn(i,n) if (vals.count(billetes[i])) aux[i] = vals[billetes[i]];

    respuesta = aux;
    return dp[M].cnt;
}
