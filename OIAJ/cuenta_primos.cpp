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

const int MAXN = 200;
set<int> primos;

bitset<MAXN+1> done;

void criba(int N = MAXN) { //hasta MAXN
    for (int i = 2; i*i <= N; i++) {
        if (done[i]) continue;
        for (int j = i+i; j <= N; j+=i)
            done[j] = true;
    }

    forsn (i,2,N) if (!done[i]) primos.insert(i);
}

vi arr;

int main() {
    FAST_IO;

    criba();

    int N,r=0;
    cin >> N;

    forn (i,N) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    forn (i,N)
        forsn(j,i+1,N)
            if (primos.count(arr[j]+arr[i])) r++;

    cout << r;

    return 0;
}