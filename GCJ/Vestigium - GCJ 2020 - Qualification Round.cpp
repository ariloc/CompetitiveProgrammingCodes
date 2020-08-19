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

const int MAXN = 101;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn (i,t) {
        int mat[MAXN][MAXN];
        int N, repeatR = 0, repeatC = 0; cin >> N;
        forn (j,N) {
            bitset<MAXN> done; bool yes = false;
            forn (k,N) {
                cin >> mat[j][k];
                if (done[mat[j][k]]) yes = true;
                done[mat[j][k]] = true;
            }
            if (yes) repeatR++;
        }

        int trace = 0, ind = 0;
        while (ind < N) {trace += mat[ind][ind]; ind++;}

        forn (j,N) {
            bitset<MAXN> done; bool yes = false;
            forn (k,N) {
                if (done[mat[k][j]]) yes = true;
                done[mat[k][j]] = true;
            }
            if (yes) repeatC++;
        }

        cout << "Case #" << i+1 << ": " << trace << ' ' << repeatR << ' ' << repeatC << '\n';
    }

    return 0;
}
