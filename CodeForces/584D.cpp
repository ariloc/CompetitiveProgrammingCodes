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

bool checkPrime (int N) {
    int i;
    for (i = 2; (N%i) and i*i <= N; i++);
    if (i*i > N) return true;
    return false;
}

void print(vi &x) {cout << x.size() << '\n'; for (auto &i : x) cout << i << ' ';}

int main() {
    FAST_IO;

    int N; cin >> N;

    vi nums;
    dforsn (i,2,N+1)
        // hasta aprox 300 iteraciones, pues diferencia entre primos es hasta alrededor de 300
        if (checkPrime(i)) // O(sqrt(N))
            {nums.pb(i); break;}

    if (nums.back() == N) {print(nums); return 0;}

    forsn (i,2,N)
        if (checkPrime(i) and checkPrime(N-nums.back()-i)) {
            if (N-nums.back()-i) nums.pb(N-nums.back()-i);
            if (i) nums.pb(i);
            print(nums);
            return 0;
        }

    return 0;
}