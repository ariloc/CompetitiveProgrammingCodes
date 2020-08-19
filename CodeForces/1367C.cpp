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

int main() {
    FAST_IO;

    int t; cin >> t;
    forn (i,t) {
        int k,N; cin >> N >> k;
        string s; cin >> s;

        int one = 0;
        forn (j,s.size()) if (s[j] == '1') one++;

        int cnt = 0, rta = 0, lastO = -1, primCnt = -1;
        forn (j,N) {
            if (s[j] == '1') {
                int val = cnt/(k+1);

                if (lastO == -1) {primCnt = cnt; goto LAST;}

                if (val*(k+1)+k > cnt) val--;
                //cerr << val*(k+1)+k << ' ' << cnt << endl;
                rta += max(val,0);

                LAST:
                cnt = 0; lastO = j;
            } else cnt++;
        }

        if (primCnt == -1) {
            rta += cnt/(k+1);
            if (!(cnt/(k+1))) rta++;
            else if (rta*(k+1) < N) rta++;
        }
        else {
            rta += primCnt/(k+1);
            rta += cnt/(k+1);
        }

        cout << rta << '\n';
    }

    return 0;
}