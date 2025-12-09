#include<bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

string frio(int N, int M, int K, int oi, int oj, int di, int dj) {
    int dif = abs(di-oi) + abs(dj-oj);
    if (dif > K || K%2 != dif%2)
        return "IMPOSIBLE";
    
    string r;
    if (oi < di) r += string(di-oi,'S');
    else r += string(oi-di,'N');

    if (oj < dj) r += string(dj-oj,'E');
    else r += string(oj-dj,'O');

    int rest = K-dif;
    if (di > 1) forn(_,rest/2) r += "NS";
    else forn(_,rest/2) r += "SN";

    return r;
}
