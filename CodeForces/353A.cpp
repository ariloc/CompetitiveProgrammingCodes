#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int main() {
    FAST_IO;

    int N; cin >> N;
    int sumU = 0, sumD = 0;
    bool twoFace = false;
    forn (i,N) {
        int u,d; cin >> u >> d;
        if ((u&1) != (d&1)) twoFace = true;
        sumU += u; sumD += d;
    }

    if (!(sumU & 1) and !(sumD & 1)) cout << 0;
    else if ((sumU & 1) == (sumD & 1) and twoFace) cout << 1;
    else cout << -1;

    return 0;
}