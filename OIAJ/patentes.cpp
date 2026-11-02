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

int proclet(char &c, int v) {
    int ind = c-'A';
    ind += v;
    c = (ind%26)+'A';
    return ind / 26;
}

int procdig(char &c, int v) {
    int ind = c-'0';
    ind += v;
    c = (ind%10)+'0';
    return ind / 10;
}

string siguiente(string patente, int K) {
    int volt = K;
    if (sz(patente) == 6) {
        dforsn(i,3,6) volt = procdig(patente[i],volt);
        dforn(i,3) volt = proclet(patente[i],volt);
    }
    else {
        dforsn(i,5,7) volt = proclet(patente[i],volt);
        dforsn(i,2,5) volt = procdig(patente[i],volt);
        dforn(i,2) volt = proclet(patente[i],volt);
    }
    return patente;
}


#ifndef EVAL
    #include <iostream>

    int main()
    {
        string patente; int K;
        cin >> patente >> K;
        cout << siguiente(patente,K) << endl;
        return 0;
    }
#endif
