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

const int MAXN = 1005;

ii arr[MAXN];

int main() {
    FAST_IO;

    int N; cin >> N;

    forn (i,N) cin >> arr[i].fst >> arr[i].snd;

    sort(arr,arr+N,[](const ii &a, const ii &b)
         {if (a.snd == b.snd) return a.fst > b.fst; return a.snd > b.snd;});

    int cnt = 1; ll acc = 0;
    forn (i,N) {
        if (cnt <= 0) break;
        acc += arr[i].fst; cnt--;
        cnt += arr[i].snd;
    }

    cout << acc;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!