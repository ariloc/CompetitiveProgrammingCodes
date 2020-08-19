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

const int MAXN = 2e5+2;

vector<ii> B;

int main() {
    FAST_IO;

    int N;
    cin >> N;

    forn (i,N) {
        int x;
        cin >> x;
        B.push_back({i+1-x,x});
    }

    sort(all(B));
    ll best;
    ll sum = best = B[0].snd;
    forsn (i,1,B.size()) {
        if (B[i].fst != B[i-1].fst) {best = max(best,sum); sum = 0;}
        sum += B[i].snd;
    }
    best = max(best,sum);

    cout << best;

    return 0;
}