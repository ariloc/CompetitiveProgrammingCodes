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

const int MAXN = 501;

int main() {
    FAST_IO;

    ll k,N; cin >> N >> k;

    queue<int> Q;

    forn (i,N) {
        int x; cin >> x;
        Q.push(x);
    }

    int bst = -1;
    int roundsP = 0;
    while (true) {
        int act = Q.front(); Q.pop();

        while (Q.front() < act and roundsP < min(N,k)) {
            Q.push(Q.front()); Q.pop();
            roundsP++;
        }

        if (roundsP == min(N,k)) {bst = act; break;}
        else {roundsP = 1; Q.push(act);}
    }

    cout << bst;

    return 0;
}