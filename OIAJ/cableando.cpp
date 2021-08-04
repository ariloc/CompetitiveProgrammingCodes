#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= s; i++)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1e9+5;

int main() {
    FAST_IO;

    int N,K; cin >> N >> K;
    int mini = INF, maxi = -1;
    forn (i,N) {
        int x; cin >> x;
        maxi = max(maxi,x);
        mini = min(mini,x);
    }
    if (mini > K) mini = K;
    if (maxi < K) maxi = K;

    cout << abs(maxi-mini);

    return 0;
}