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
const int MAXL = 26;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    forn (i,t) {
        int a,b,x,y;
        cin >> x >> y >> a >> b;

        int bestSup = 0;
        if (a+1 <= x) bestSup = max(bestSup,y*(x-a-1));
        bestSup = max(bestSup,y*a);
        bestSup = max(bestSup,x*b);
        if (b+1 <= y) bestSup = max(bestSup,x*(y-b-1));

        cout << bestSup << '\n';
    }

    return 0;
}