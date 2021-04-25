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

void fastscan(int &num)
{
    register int c;
    c=getchar_unlocked();
    for (; (c>47 && c<58); c=getchar_unlocked())
        {num = num*10 + c - 48;}
}

const int MAXN = 2e5;

int arr[MAXN];
priority_queue<ii> low; // max queue tiene los primeros n/2 menores
priority_queue<ii,vector<ii>,greater<ii>> high; // min queue tiene los ultimos n/2 mayores

int main() {
    int n=0,k=0; fastscan(n); fastscan(k);
    forn(i,n) fastscan(arr[i]);

    if (k == 1) {forn(i,n) printf("%d ",arr[i]); return 0;} // caso 1

    forn(i,k) low.push({arr[i],i});
    while(low.size() > (k+1)/2) {high.push(low.top()); low.pop();} // balance
    printf("%d ",low.top().fst);

    forsn(i,k,n) {
        int myLow = low.top().fst;
        while (!low.empty() and low.top().snd <= i-k) low.pop();
        while (!high.empty() and high.top().snd <= i-k) high.pop();

        if (arr[i] <= low.top().fst) {
            low.push({arr[i],i});
            if (arr[i-k] > myLow) {high.push(low.top()); low.pop();}
        }
        else if (arr[i] >= high.top().fst) {
            high.push({arr[i],i});
            if (arr[i-k] <= myLow) {low.push(high.top()); high.pop();}
        }
        else if (arr[i-k] <= myLow) low.push({arr[i],i});
        else high.push({arr[i],i});

        while (!low.empty() and low.top().snd <= i-k) low.pop();
        while (!high.empty() and high.top().snd <= i-k) high.pop();

        printf("%d ",low.top().fst);
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
