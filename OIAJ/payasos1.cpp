#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int n;

bool is_valid(vi &A) {
    vi histo(n,0);
    forn(i,n) histo[A[i]]++;
    forn(i,n) if (histo[i] > 1) return false;
    return true;
}

bool is_boring(vi &A) {
    if (!is_valid(A)) return false;
    forn(i,n) if (A[A[i]] != i) return false;
    return true;
}

void apply(vi &A, vi &P, int k) {
    forn(_,k) {
        vi auxi(n);
        forn(i,n) auxi[P[i]] = A[i];
        swap(auxi,A);
    }
}

int payasos1(vector<int> &A, vector<int> &B, vector<int> &C) {
    n = A.size();
    if (!is_boring(A)) return 1;
    if (!is_boring(B)) return 2;
    if (!is_valid(C)) return 3;
    
    bool posib = false;
    forn(k1,2) forn(k2,2) {
        vi auxi(n);
        forn(i,n) auxi[i] = i;
        apply(auxi,A,k1);
        apply(auxi,B,k2);
        bool ok = true;
        forn(i,n) if (auxi[C[i]] != i) ok = false;
        posib |= ok;
    }

    return posib ? 0 : 4;
}
