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

const int MAXN = 1e5+5;

bitset<MAXN> fined;
int cnt = 0;
int in[MAXN], out[MAXN];

int main() {
    FAST_IO;

    int N; cin >> N;

    forn (i,N) cin >> in[i];
    forn (i,N) cin >> out[i];

    int j = 0;
    forn (i,N) {
        if (fined[in[i]]) continue;
        while (j < N and out[j] != in[i]) {
            cnt++; fined[out[j]] = true; j++;
        }
        j++;
    }

    cout << cnt;

    return 0;
}