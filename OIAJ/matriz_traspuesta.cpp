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

const int MAXN = 100;

int tabla[MAXN][MAXN];

int main() {
    FAST_IO;

    int N,M;
    cin >> N >> M;

    forn (i,N)
        forn (j,M) {
            int x;
            cin >> x;
            tabla[i][j] = x;
        }

    forn (i,M) {
        forn (j,N)
            cout << tabla[j][i] << ' ';
        cout << '\n';
    }

    return 0;
}