#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int decada(int fecha) {
    char year[10];
    sprintf(year,"%d",fecha);
    return (year[2]-'0')*10 + (year[3]-'0');
}

bool esmayor(int edad) {
    return (edad >= 18);
}

string nombrecompleto(string nombre, string apellido) {
    return nombre + ' ' + apellido;
}

int cantidadmayores(vector<int> &edades) {
    int cnt = 0;
    for (auto &i : edades) cnt += (i >= 18);
    return cnt;
}
