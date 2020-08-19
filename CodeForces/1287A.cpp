#include <bits/stdc++.h>

#define forn(i,n) for(ll i = 0; i < ll(n); i++)
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

    forn (i,N) {
        int T;
        cin >> T;

        bool contar = false;
        int consecutive = 0,best = 0;

        forn (k,T) {
            char x;
            cin >> x;
            if (x == 'A') {
                contar = true;
                best = max(best,consecutive);
                consecutive = 0;
            }
            if (x == 'P' and contar)
                consecutive++;
        }
        cout << max(best,consecutive) << '\n';
    }

    return 0;
}