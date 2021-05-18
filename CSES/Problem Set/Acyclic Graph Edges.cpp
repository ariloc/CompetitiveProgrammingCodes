#include <bits/stdc++.h>
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
 
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
 
void fastscan(int &x, char a[]) {
    register int c = 0; x = 0; int ind = 0;
    c=getchar_unlocked();
    if (c == '\n') c=getchar_unlocked();
    for(; c>47 && c<58; c=getchar_unlocked())
        {x = x*10 + c-48; a[ind++] = c;}
    a[ind] = '\0';
}
 
char num[11],num2[11];
 
void printMat (char a[]) {
    for(int j = 0; a[j]; j++) putchar_unlocked(a[j]); putchar_unlocked(' ');
}
 
int main() {
    int n,m; fastscan(n,num); fastscan(m,num);
 
    forn (i,m) {
        int a,b; fastscan(a,num); fastscan(b,num2);
 
        if (a > b) {printMat(num); printMat(num2); putchar_unlocked('\n');}
        else {printMat(num2); printMat(num); putchar_unlocked('\n');}
    }
 
    return 0;
}
 
/// ESCRIB� en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO B�SICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!