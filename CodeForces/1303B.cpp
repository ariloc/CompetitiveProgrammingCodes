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

    int t;
    cin >> t;

    forn (i,t) {
        int n,g,b;
        ll days = 0;
        cin >> n >> g >> b;
        
        ll half = ceil((double)n/2);
        ll times = ((half+g-1)/g)-1;
        days = times*(g+b);
        days += half-(g*times);
        ll rest = (n-half)-(times*b);
        if (rest < 0) rest = 0;
        days += rest;
        
        
        cout << days << '\n';
    }
    return 0;
}