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

vi arr;

int main() {
    FAST_IO;

    int N,r=0;
    cin >> N;

    forn (i,N) {
        int x; cin >> x;
        arr.push_back(x);
    }

    forn(i,N)
        forsn (j,i+1,N)
            if (!((arr[i]+arr[j]) % 10)) r++;

    cout << r;

    return 0;
}