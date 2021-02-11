
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

const int MAXN = 1e6+5;
const int INF = 1e9+5;

bitset<MAXN> isNotPrime;
int TAdL[MAXN],minNeed[MAXN],minNeedRange[MAXN];

void criba(int N) {
    isNotPrime[1] = isNotPrime[0] = true;
    for (int i = 2; i*i <= N; i++)
        if (!isNotPrime[i])
            for (int j = i+i; j <= N; j+=i)
                isNotPrime[j] = true;
}

int main() {
    FAST_IO;

    criba(MAXN-1);
    int a,b,k; cin >> a >> b >> k;

    int cnt = 0;
    forsn (i,a,b+1) {
        if (!isNotPrime[i]) cnt++;
        TAdL[i] = cnt;
    }

    int j = a, primesOnWay = 0, maxi = 1;
    forsn (i,a,b+1) {
        if (j < i) j++; // por las dudas
        while (j <= b and primesOnWay < k) {
            primesOnWay += (!isNotPrime[j]);
            j++;
        }

        if (j <= b+1 and primesOnWay >= k) maxi = max(maxi,j-i);
        else maxi = INF;

        minNeed[i] = maxi;
        primesOnWay -= (!isNotPrime[i]);
    }

    int mini = -1;
    forsn (i,a,b+1) {
        mini = max(mini,minNeed[i]);
        minNeedRange[i] = mini;
    }

    //forsn(i,a,b+1) cout << minNeedRange[i] <<' ';

    int l = 1, rta = -1;
    dforsn(i,a,b+1) {
        if (minNeedRange[i] <= l) {rta = l; break;}
        l++;
    }

    cout << rta;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
