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

const int MAXN = 1002;

bitset<MAXN> done;
vi primes;

void criba (int N) {
    for (int i = 2; i*i <= N; i++)
        if (!done[i])
            for (int j = i+i; j <= N; j+=i)
                done[j] = true;

    forsn (i,2,N) if (!done[i]) primes.pb(i);
}

int main() {
    FAST_IO;

    criba(MAXN-1);

    int N,k; cin >> N >> k;

    int cnt = 0;
    forsn (i,1,primes.size()) {
        if (primes[i]+primes[i-1]+1 > N) break;
        if (!done[primes[i]+primes[i-1]+1]) cnt++;
    }

    cout << (cnt >= k ? "YES" : "NO");


    return 0;
}