#include "aplusb.h"
#include <bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
 
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

int const MAX = 2e9;

bool posib (int N, vi &A, vi &B, int mid) {
    ll cnt = 0;
    forn(i,N) {
        int ind = upper_bound(all(B),mid-A[i])-B.begin();
        cnt += ind;
    }
    return cnt >= N;
}

std::vector<int> smallest_sums(int N, std::vector<int> A, std::vector<int> B) {
    int low = -1, high = MAX;
    while (high - low > 1) {
        int mid = (high-low)/2 + low;
        if (posib(N,A,B,mid)) high = mid;
        else low = mid;
    }

    vi rta;
    forn(i,N) forn(j,N) {
        if (A[i] + B[j] >= high) break;
        rta.pb(A[i] + B[j]);
    }

    sort(all(rta));
    
    while ((int)rta.size() < N) rta.pb(high);

    return rta;
}
