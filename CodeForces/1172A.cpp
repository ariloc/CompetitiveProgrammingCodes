#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define snd second
#define fst first
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int const MAXN = 2e5+5;
int const INF = 2e9;

int hand[MAXN], pile[MAXN];
int n;

int cnt[MAXN];
queue<int> p;

bool simul(int take, int start) {
    int zero = 0;

    forn(i,n) cnt[i]=0;
    while (!p.empty()) p.pop();

    forn(i,n) p.push(pile[i]);
    forn(i,n) if (hand[i]) cnt[hand[i]]++; else zero++;

    while (take--) {
        if (!zero) break;
        p.push(0);
        zero--;
        if (p.front())
            cnt[p.front()]++;
        else zero++;
        p.pop();
    }

    while (start <= n) {
        if (!cnt[start]) return false;
        p.push(start);
        cnt[start]--;
        if (p.front())
            cnt[p.front()]++;
        else zero++;
        p.pop();
        start++;
    }

    return true;
}

int main() {
    FAST_IO;
    
    cin >> n;

    forn(i,n) cin >> hand[i];
    forn(i,n) cin >> pile[i];

    int mini = INF;
    int last = pile[n-1];
    if (last) {
        dforn(i,n) {
            if (!last) break;
            if (last != pile[i]) break;
            --last;
        }
        if (!last && (simul(0,pile[n-1]+1)))
            mini = min(mini, n-pile[n-1]);
    }

    int lo = -1, hi = n;
    while (hi-lo > 1) {
        int mid = (hi+lo)/2;
        if (simul(mid,1)) hi = mid;
        else lo = mid;
    }

    mini = min(mini, hi+n);

    cout << mini << '\n';

    return 0;
}
