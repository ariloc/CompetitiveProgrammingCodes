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

const int MAXR = 1e9;
const int MINR = MAXR/2;
const int INF = 2e9+5;
const ii posib[] = {{-MINR,-MINR},{MAXR-MINR,-MINR},{MAXR-MINR,MAXR-MINR},{-MINR,MAXR-MINR},{0,0}};

ii findSpot() {
    forn (i,5) {
        string response;
        cout << posib[i].fst << ' ' << posib[i].snd << endl;
        cin >> response;

        if (response == "CENTER") return {-1,-1};
        if (response == "HIT") return posib[i];
    }
}

int binSrch (int lowF, int highF, ii p, bool x, bool mini) {
    int low = lowF, high = highF;

    while (high-low>1) {
        int mid = low + (high-low)/2;
        if (x) p.fst = mid; else p.snd = mid;
        cout << p.fst << ' ' << p.snd << endl;

        string response;
        cin >> response;
        if (response == "CENTER") return INF;
        if (response == "HIT")
            if (mini) high = mid; else low = mid;
        else if (mini) low = mid; else high = mid;
    }

    string resp;
    if (x) cout << high << ' ' << p.snd << endl;
    else cout << p.fst << ' ' << high << endl;
    cin >> resp; if (resp == "HIT") return high;
    return low;
}

int main() {
    FAST_IO;

    int t,a,b; cin >> t >> a >> b;

    forn (i,t) {
        ii point = findSpot();
        if (point.fst == -1) continue; // por si de suerte le pego al centro

        int l = binSrch(-MAXR, point.fst, point, true, true); if (l == -INF) return 0;
        int r = binSrch(point.fst, MAXR, point, true, false); if (r == -INF) return 0;
        int u = binSrch(point.snd, MAXR, point, false, false); if (u == -INF) return 0;
        int d = binSrch(-MAXR, point.snd, point, false, true); if (d == -INF) return 0;

        string response;
        cout << (l+r)/2 << ' ' << (d+u)/2 << endl;
        cin >> response;
        if (response == "CENTER") continue;
        return 0;
    }

    return 0;
}
