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

bool palindromo (string pal, int L) {
    int sizeNew = (pal.size()+L);
    pal.resize(sizeNew);
    forn (i,(sizeNew/2)) {
        if (L-- > 0)
            pal[pal.size()-i-1] = pal[i];
        if (pal[i] != pal[pal.size()-i-1]) return false;
    }
    return true;
}

int dictado( string palabra ) {
    forn (i,palabra.size())
        if (palindromo(palabra,i)) return i;
}
