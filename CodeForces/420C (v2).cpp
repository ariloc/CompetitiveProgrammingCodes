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

const int MAXN = 3e5+2;

int mention[MAXN], mentionUO[MAXN];
map<ii,int> common;

int main() {
    FAST_IO;

    int n,p; ll rta = 0; cin >> n >> p;

    forn (i,n) {
        int a,b; cin >> a >> b; a--; b--;
        mention[a]++; mention[b]++; mentionUO[a]++; mentionUO[b]++;
        if (b > a) swap(a,b);
        common[{a,b}]++;
    }

    sort(mention,mention+n);

    int k = 0;
    dforn (l,n) {
        while (k < l and mention[k]+mention[l] < p)
            k++;

        rta += l-k;
        if (k == l) break;
    }

    for (auto &i : common) {
        int calc = mentionUO[i.fst.fst]+mentionUO[i.fst.snd];
        if (calc >= p and (calc-i.snd) < p) rta--;
    }

    cout << rta;

    return 0;
}