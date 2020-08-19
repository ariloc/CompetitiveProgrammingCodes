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

int main() {
    FAST_IO;

    int N,even = 0,odd = 0, prevE = -1, prevO = -1;
    cin >> N;

    forn(i,N) {
        int x;
        cin >> x;
        if (x % 2) {
            odd++;
            prevO = i+1;
        } else {even++; prevE = i+1;}
    }

    if (even < odd) cout << prevE;
    else cout << prevO;

    return 0;
}