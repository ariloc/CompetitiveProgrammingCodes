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

int main() {
    FAST_IO;

    int rta = 0;
    char tmp = 'a',c = 'a',C='a';
    int n;
    while ((tmp = getchar()) != '\n') {if (tmp != '\n') {C = c; c = tmp;}}
    n = c-'0'+(C!='a'?(C-'0')*10:0);

    /*if (!n) {cout << 4; return 0;}

    if (!(n%2)) rta = 6; // por base 4
    else rta = 4;

    switch (n%4) { // por base 2
        case 0 : rta+=6; break;
        case 1 : rta+=2; break;
        case 2 : rta+=4; break;
        case 3 : rta+=8; break;
    }

    switch (n%4) { // por base 3
        case 0 : rta+=1; break;
        case 1 : rta+=3; break;
        case 2 : rta+=9; break;
        case 3 : rta+=7; break;
    }
    rta++;*/

    cout << (!(n%4) ? 4 : 0);

    return 0;
}