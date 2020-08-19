#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

const int MAXD = 998244353;

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int main() {
    FAST_IO;

    int N;
    cin >> N;

    forn (i,N) {
        int x,times;
        string r;
        cin >> x;
        
        times = x/2;
        forn (j,times) r+='1';
        if (x % 2) r[0] = '7';
        
        cout << r << '\n';
    }

    return 0;
}