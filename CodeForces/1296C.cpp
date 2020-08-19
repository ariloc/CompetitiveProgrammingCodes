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

const int INF = 1000000;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    forn (i,t) {
        int n;
        string s;
        cin >> n;
        cin >> s;

        int L,R,U,D;
        L = R = U = D = 0;
        ii toDelete = {1,INF};
        int difToDel = INF-1;
        map <ii,int> num;
        num[{0,0}] = -1;
        ii pos = {0,0};
        forn (j,s.size()) {
            switch (s[j]) {
                case 'L': L++; pos.fst--; break;
                case 'D': D++; pos.snd--; break;
                case 'U': U++; pos.snd++; break;
                case 'R': R++; pos.fst++; break;
            }
            if (num.count(pos)) {
                if ((j - num[pos]) < difToDel) {
                        //cerr << difToDel << ' ' << j-num[pos] <<  endl;
                    toDelete = {num[pos]+2,j+1};
                    difToDel = j-num[pos];
                }
            }
            num[pos] = j;

            if (j) {
                int prev = s[j-1], act = s[j];
                if (prev > act) swap(prev,act);
                if ((prev == 'D' and act == 'U') or (prev == 'L' and act == 'R')) {
                    difToDel = 2;
                    toDelete = {j,j+1};
                }
            }
        }
        if (difToDel == INF-1) {
            if (L == R and U == D) cout << 1 << ' ' << n;
            else cout << -1;
        }
        else cout << toDelete.fst << ' ' << toDelete.snd;
        cout << '\n';
    }

    return 0;
}