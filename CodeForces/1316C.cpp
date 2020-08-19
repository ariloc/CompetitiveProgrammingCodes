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

    int n,m,p;
    cin >> n >> m >> p;

    int a = -1, b = -1;
    forn(i,n) {
        int x; cin >> x;
        if (a == -1 and x%p) a = i;
    }
    forn(i,m) {
        int x; cin >> x;
        if (b == -1 and x%p) b = i;
    }
    cout << a+b;

    return 0;
}