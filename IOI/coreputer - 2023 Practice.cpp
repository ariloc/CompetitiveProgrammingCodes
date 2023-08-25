#include "coreputer.h"

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= 0; i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

std::vector<int> malfunctioning_cores(int N) {
    int low = -1, high = N-1;
    int winans = -2;
    while (high - low > 1) {
        int mid = (high+low) / 2;
        
        vi auxi;
        forn(i,mid+1) auxi.pb(i);
        
        int query = run_diagnostic(auxi);

        if (query >= 0) high = mid, winans = query;
        else low = mid;
    }

    vi ret = vi(N,0);
    ret[high] = 1;

    if (winans == -2) { // cores == 1, it's last one
        return ret;
    }

    int cntl = 1, missans = -2;
    forn(i,high) {
        vi aux;
        forn(j,high+1) if (i != j) aux.pb(j);
        int query = run_diagnostic(aux);
        if (query != winans) ret[i] = 1, cntl++, missans = query;
    }

    if (winans == 1) cntl--;

    forsn(i,high+1,N-1) {
        vi aux;
        forn(j,high) aux.pb(j);
        aux.pb(i);
        if (run_diagnostic(aux) >= 0) ret[i] = 1, cntl--;
    }
    if (cntl) ret[N-1] = 1;

    return ret;
}
