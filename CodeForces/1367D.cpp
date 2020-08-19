#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= s; i++)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 55;
const int MAXV = 1260;
const int MAXL = 30;

int arr[MAXN], let[MAXN], typ[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn (i,t) {
        map<int,char> equiv;
        forn (j,MAXN) {let[j] = 0; typ[j] = -1;}

        string s; cin >> s;
        int N, prox_libre = 0; cin >> N;
        forn (j,N) cin >> arr[j];

        forn (j,s.size()) let[s[j]-'a']++;

        vi priorityVal;

        int mark = 0;
        while (mark < N) {
            int actD = 0, cnt = 0;
            vi vals(MAXN);

            forn (j,N) {
                actD += cnt;
                if (typ[j] != -1) cnt++;
                vals[j] += actD;
            }

            actD = 0, cnt = 0;
            dforn (j,N) {
                actD += cnt;
                if (typ[j] != -1) cnt++;
                vals[j] += actD;
            }

            int meLvl = 0;
            forn (j,N) if (arr[j] == vals[j]) {
                if (typ[j] != -1) continue;
                typ[j] = prox_libre; meLvl++;
            }

            mark += meLvl; prox_libre++;
            priorityVal.pb(meLvl);
        }

        int ind = 0;
        dforn (j,MAXL)
            if (let[j] >= priorityVal[ind])
                {equiv[ind] = (j+'a'); ind++;}

        forn (j,N) cout << equiv[typ[j]];
        cout << '\n';
    }

    return 0;
}