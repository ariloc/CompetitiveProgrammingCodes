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

const int MAXN = 1000000002;

vi solveCriba(int &n) {
    vi r;
    int x = n;
    for (int i = 2; i*i<=n and r.size() < 2; i++)
        if (!(x%i)) {x/=i; r.push_back(i);}
    if (r.size() == 2 and r[0] != x and r[1] != x) r.push_back(x);
    return r;
}

int main() {
    FAST_IO;

    int N,maxi = -1;
    cin >> N;

    forn(i,N) {
        int x;
        cin >> x;
        vi r = solveCriba(x);
        if (r.size() < 3) cout << "NO" << '\n';
        else {
            cout << "YES" << '\n';
            for (auto &i : r)
                cout << i << ' ';
            cout << '\n';
        }
    }

    return 0;
}