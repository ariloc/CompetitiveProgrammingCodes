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

const int INF = 1000000005;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    forn(i,t) {
        int n,x;
        int r = INF;
        cin >> n >> x;

        forn (i,n) {
            int f;
            cin >> f;

            if (f == x) r = 1;
            else if (f > x) r = min(r,2);
            else if (f < x) {
                int div = (x+f-1)/f;
                r = min(r,div);
            }
        }

        cout << r << '\n';
    }

    return 0;
}