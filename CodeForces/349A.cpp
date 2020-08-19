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

    int N; cin >> N;

    int b1 = 0, b2 = 0, b3 = 0;
    forn (i,N) {
        int x; cin >> x;
        if (x == 25) b1++;
        else if (x == 50) {b2++; b1--;}
        else if (x == 100) {b3++; if (!b2) b1-=3; else {b2--; b1--;}}

        if (b1 < 0 or b2 < 0 or b3 < 0) {cout << "NO"; return 0;}
    }
    cout << "YES";

    return 0;
}