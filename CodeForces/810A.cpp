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

map<string,string> asoc;

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;

    int sum = 0, cnt = 0;
    forn (i,n) {int x; cin >> x; sum += x;}

    while (round(sum/(double)n) < k) {
        n++; sum+=k; cnt++;
    }

    cout << cnt;

    return 0;
}