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

const int MAXN = 5000;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    forn (i,t) {
        int n; cin >> n;

        int done[MAXN];
        bool posib = false;
        memset(done,-1,sizeof(done));

        forn (j,n) {
            int x; cin >> x;
            if (done[x-1] != -1 and done[x-1] != j-1)
                posib = true;
            if (done[x-1] == -1) done[x-1] = j;
        }
        if (posib) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}