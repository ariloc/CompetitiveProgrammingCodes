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

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int x; cin >> x;
        int N = x, sum = 1;

        int maxX = 1, actX = 1;
        cout << "Case #" << i+1 << ":\n";
        int a = 1;
        forn (j,5) {x -= a; a<<=1;}
        x = max(0,x);
        while (x) {
            if (x & 1) {
                if (sum + (1<<(maxX-1)) > N) {
                    while (sum <= N) {
                        cout << maxX++ << ' ' << actX << '\n';
                        if (actX != 1) actX++;
                        sum++;
                    }
                    goto OUT;
                }
                else {
                    if (actX == maxX) {actX++; while(actX > 1) cout << maxX << ' ' << --actX << '\n';}
                    else while(actX <= maxX) cout << maxX << ' ' << actX++ << '\n';
                    sum += (1<<(maxX-1));
                    cerr << (1<<(maxX-1)) << "OK" << ' ' << sum << endl;
                }
            }
            else {cout << maxX << ' ' << actX << '\n'; sum++;}
            maxX++; if (actX == maxX-1) actX++;
            x >>= 1;
        }
        OUT:
            while (sum <= N) {
                cout << maxX++ << ' ' << actX << '\n';
                if (actX != 1) actX++;
                sum++;
            }
            continue;
    }

    return 0;
}
