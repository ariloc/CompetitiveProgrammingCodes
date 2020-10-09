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

string s;

int solve (int pos, ll mask, int cnt) {
    int sum = 0;
    bool a = false, b = false, c = false, d = false;

    mask |= (1LL<<pos);
    if (pos == 42) if (mask == ((1LL<<49LL)-1)) sum++; else return 0;

    int tend = pos+7;
    if (tend > 0 && tend < 49 && !(mask & (1LL<<tend))) a = true;

    tend = pos-7;
    if (tend > 0 && tend < 49 && !(mask & (1LL<<tend))) b = true;

    tend = pos+1;
    if (tend > 0 && tend < 49 && !(mask & (1LL<<tend)) && (int(pos/7) == int(tend/7))) c = true;

    tend = pos-1;
    if (tend > 0 && tend < 49 && !(mask & (1LL<<tend)) && (int(pos/7) == int(tend/7))) d = true;

    if ((a && b && !c && !d) || (!a && !b && c && d)) return 0;
    if (a && (s[cnt] == '?' || s[cnt] == 'D')) sum += solve(pos+7,mask,cnt+1);
    if (b && (s[cnt] == '?' || s[cnt] == 'U')) sum += solve(pos-7,mask,cnt+1);
    if (c && (s[cnt] == '?' || s[cnt] == 'R')) sum += solve(pos+1,mask,cnt+1);
    if (d && (s[cnt] == '?' || s[cnt] == 'L')) sum += solve(pos-1,mask,cnt+1);

    return sum;
}

int main() {
    FAST_IO;
    cin >> s;
    cout << solve(0,1,0);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
