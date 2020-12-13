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

const int MAXN = 3e5+2;
const int INF = 1e9+5;

vi posic[MAXN];
int arr[MAXN], minL[MAXN], minR[MAXN], TAd[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        set<int> num; string s;
        forn(j,n) {int x; cin >> x; arr[j+1] = x; num.insert(x); posic[x].pb(j+1);}
        s += ((int)num.size() == n ? '1' : '0');
        s += string(n-1,'0');

        // primeros menores
        arr[0] = arr[n+1] = -INF; int k;
        dforsn(j,1,n+1) {for(k = j+1; arr[k] >= arr[j]; k = minL[k]); minL[j] = k;}
        forsn(j,1,n+1) {for(k = j-1; arr[k] >= arr[j]; k = minR[k]); minR[j] = k;}

        forsn(j,1,n+1) {
            if (posic[j].empty()) break;
            map<int,int> mark,fromNow;
            for (auto &o : posic[j])
                if (min(abs(minL[o]-o),abs(minR[o]-o)) > 1) mark[abs(minL[o]-minR[o])-1]++;
                else fromNow[max(abs(minL[o]-o),abs(minR[o]-o))]++;

            if (fromNow.empty()) for (auto &o : mark) TAd[o.fst]++, TAd[o.fst+1]--;
            else {
                int st = (fromNow.size() > 1 ? (*prev(fromNow.rbegin())).fst+1 : 1), nd = (*(fromNow.rbegin())).fst;
                TAd[st]++, TAd[nd+1]--;
                for (auto &o : mark) if (o.fst > nd && o.snd == 1) TAd[o.fst]++,TAd[o.fst+1]--;
            }
        }
        forsn(j,2,n+2) {
            TAd[j] += TAd[j-1];
            if (TAd[j] >= n-j+1) s[j-1] = '1';
        }

        forn(j,n+2) {TAd[j] = minL[j] = minR[j] = 0; posic[j].clear();}

        cout << s << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
s
