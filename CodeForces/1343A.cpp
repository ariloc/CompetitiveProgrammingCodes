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

const int MAXP = 31;

int pot[MAXP];

void gen() {
    int sum = 0, x = 1;
    forn (i,MAXP-1) {
        sum += x;
        pot[i+1] = sum;
        x <<= 1;
    }
}

int main() {
    FAST_IO;

    gen();
    int t; cin >> t;

    forn (i,t) {
        int x; cin >> x;

        int val = -1;
        forsn (j,2,MAXP)
            if (!(x%pot[j]))
                {val = x/pot[j]; break;}

        cout << val << '\n';
    }

    return 0;
}