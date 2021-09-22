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

ll nEnds[10],mEnds[10];

int main() {
    FAST_IO;

    ll n,m;
    ll r = 0;
    cin >> n >> m;

    forsn (i,1,10) {
        nEnds[i] = ll(n/10);
        mEnds[i] = ll(m/10);
        if (n%10 >= i) nEnds[i]++;
        if (m%10 >= i) mEnds[i]++;
    }
    nEnds[0] = ll(n/10); mEnds[0] = ll(m/10);

    forsn (i,1,10)
        r += nEnds[i]*mEnds[10-i];

    forsn (i,1,5)
        r += nEnds[i]*mEnds[5-i];

    r += nEnds[0]*mEnds[5]; r += nEnds[5]*mEnds[0];
    r += nEnds[0]*mEnds[0];
    r += nEnds[9]*mEnds[6]; r += nEnds[6]*mEnds[9];
    r += nEnds[7]*mEnds[8]; r += nEnds[8]*mEnds[7];

    cout << r;

    return 0;
}