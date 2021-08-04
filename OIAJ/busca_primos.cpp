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

const int MAXN = 1005;

bitset<MAXN> done;

void criba(int N) {
    for (int i = 2; i*i <= N; i++)
        if (!done[i])
            for (int j = i+i; j <= N; j += i)
                done[j] = true;
}

int main() {
    FAST_IO;

    int N; cin >> N;
    criba(N);

    forsn(i,2,N+1) if (!done[i]) cout << i << '\n';

    return 0;
}