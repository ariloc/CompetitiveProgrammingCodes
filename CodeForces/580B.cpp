#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1e5+2;
const ll INF = 2e18;

ii people[MAXN];

int main() {
    FAST_IO;

    int n,d; cin >> n >> d;
    ll r = -INF;

    forn (i,n) cin >> people[i].fst >> people[i].snd;

    sort(people,people+n);

    int j = 0; ll sum = 0;
    forn (i,n) {
        while (j < n and people[j].fst-people[i].fst < d) {
            sum += people[j].snd;
            j++;
        }
        r = max(r,sum);
        sum -= people[i].snd;
    }

    cout << r;

    return 0;
}