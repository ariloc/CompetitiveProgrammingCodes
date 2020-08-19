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

int main() {
    FAST_IO;

    int N;
    cin >> N;

    forn(i,N) {
        int n,c[3];
        cin >> c[0] >> c[1] >> c[2] >> n;

        sort(c,c+3);
        n -= c[2]-c[1];
        n -= c[2]-c[0];
        if (n < 0) cout << "NO" << '\n';
        else if (!n) cout << "YES" << '\n';
        else if (n % 3) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }

    return 0;
}