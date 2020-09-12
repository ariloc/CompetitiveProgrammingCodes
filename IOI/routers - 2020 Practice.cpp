#include "routers.h"
#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >=s; i++)
#define fst first
#define snd second
#define all(c) ((c).begin(),(c).end())
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXN = 1e5+5;

int street[MAXN];

// el grader cuando es igual, devuelve left

void get_routers(int l, int r) {
    int mid = (l+r)/2; //bool goOut = false;
    //if (!(mid & 1)) if (mid+1 <= r) mid++; else if (mid-1 >= l) mid--; else goOut = true;
    //cerr << l << ' ' << l << ' ' << r << endl;
    int fnd = (!street[mid] ? use_detector(mid) : street[mid]-1); fnd++;
    street[mid] = fnd; if (r-l <= 1) return;
    //if (goOut) return;
    if (fnd != street[r] and l != mid) get_routers(mid,r);
    if (fnd != street[l] and r != mid) get_routers(l,mid);

}

std::vector<int> find_routers(int l, int n, int q) {
    street[0] = 1; street[l] = n; vi rta(n);
    get_routers(0,l);
    int act = 1;
    forn(i,l+1) {
        if (street[i]) act = street[i];
        street[i] = act; //cerr << street[i] << ' ';
    } //cerr << endl;
    int lastP = 1, cnt = 0; rta[0] = 0;
    forsn(i,1,l+1) {
        if (lastP == n) break; cnt++;
        if (street[i] != street[i+1]) {rta[lastP++] = i+cnt; i += cnt; cnt = 0;}
    }
    //for (auto &i : rta) cerr << i << ' ';
    return rta;
}
