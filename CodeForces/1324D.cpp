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

int aux[MAXN], interes[MAXN];

int main() {
    FAST_IO;

    int N;
    ll r = 0;
    cin >> N;

    forn (i,N) {
        int x; cin >> x; aux[i] = x;
    }
    forn (i,N) {
        int x; cin >> x; interes[i] = aux[i]-x;
    }

    sort(interes,interes+N);

    int i = 0;
    dforn (j,N) {
        int suma = 0;
        while (i < j and (interes[i] + interes[j]) <= 0)
            i++;
        r += j-i;
        if (i == j) break;
    }

    cout << r;

    return 0;
}