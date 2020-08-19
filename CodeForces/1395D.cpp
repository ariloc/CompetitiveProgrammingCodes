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

const int MAXN = 1e5+5;

int arr[MAXN];
int control[MAXN], exceed[MAXN], a = 0, b = 0;

int main() {
    FAST_IO;

    int n,d,m; cin >> n >> d >> m;
    forn(i,n) cin >> arr[i];
    sort(arr,arr+n);
    /*forn (i,n) cout << arr[i] << ' ';
    cout << endl;*/
    forn (i,n) if (arr[i] <= m) control[a++] = arr[i]; else exceed[b++] = arr[i];

    ll maxi = 0; int tmpN = n, ind = b; bool pass = false;
    dforn (i,b) {
        if (tmpN <= 0) break;
        maxi += exceed[i]; pass = true;
        tmpN--; ind = i;
        tmpN -= d;
    }
    if (pass) tmpN += d;

    int indA = a-1;
    while (tmpN > 0 and indA >= 0) {maxi += control[indA--]; tmpN--;}

    //cerr << tmpN << ' ' << maxi << endl;

    ll rta = maxi; int del = tmpN;
    while (indA >= 0 and ind <= b) {
        if (!del) {maxi -= exceed[ind]; ind++; del = d;}
        else del--;
        maxi += control[indA--];
        rta = max(rta,maxi);
    }

    cout << rta;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!