// https://www.hackerrank.com/contests/simulacro-4-n2-oia-2020/challenges/obra-en-la-vereda-joacru/problem
#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int MAXN = (1<<21);

int TAd[MAXN];

int divide (int l, int r) {
    int inR = TAd[r]-TAd[l];
    //cerr << l << ' ' << r << ' ' << inR << endl;
    if (!inR || inR == r-l || r-l <= 1) return 0;
    else {
        int mid = (l+r)/2;
    //cerr << "OKK" << ' ' << l  << ' ' << r << endl;
        return divide(l,mid)+divide(mid,r)+1;
    }
}

int obra(char A, string V){
    int cnt = 0;
    forn(i,V.size()) {cnt += (V[i] != A); TAd[i+1] = cnt;}
    return divide(0,(int)V.size())+1;
}

int main(){
    char A;
    string V;
    cin>>A>>V;
    cout<<obra(A, V)<<endl;
    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
