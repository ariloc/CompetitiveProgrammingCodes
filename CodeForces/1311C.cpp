#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 2e5+2;
const int MAXL = 26;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    forn(i,t) {
        int n,m;
        vi used;
        int aparic[MAXL];
        forn(j,MAXL) aparic[j] = 0;
        string s;

        cin >> n >> m;
        used.resize(n,0);
        cin >> s;

        forn(j,m) { // marco los intentos
            int x; cin >> x;
            used[x-1]++;
        }
        int cnt = 0;
        dforn(j,n) { // TAd 1D
            cnt += used[j];
            used[j] = cnt;
        }
        forn(j,n) // recuento los usados
            aparic[s[j]-'a'] += used[j]+1;

        forn(j,MAXL) cout << aparic[j] << ' ';
        cout << '\n';
    }

    return 0;
}