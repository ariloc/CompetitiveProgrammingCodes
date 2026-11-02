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

int const MAXD = 61;
int const MAXT = 44;
int const MAXB = 6;
int const MINUT[] = {0,15,30,45};

bitset<MAXT> turns[MAXD][MAXB];

string date(int i) {
    char d[3];
    string m;
    if (i <= 29) {
        sprintf(d,"%02d",i+1);
        m = "11";
    }
    else {
        sprintf(d,"%02d",i-29);
        m = "12";
    }
    return string(d) + "/" + m;
}

string time(int s) {
    int h = s/4;
    int min = s%4;
    char tim[6];
    sprintf(tim,"%02d:%02d",8+h,MINUT[min]);
    return string(tim);
}

vector<string> turnos(string pacientes, vector<int> &boxes, vector<string> &feriados) {
    vi box(sz(boxes)+sz(feriados),-1);
    for (auto &i : feriados) {
        string mo = i.substr(3,2);
        int day = atoi(i.substr(0,2).c_str());
        --day;
        if (mo == "12") day += 30;
        // check when holiday is out of range
        if(day < sz(box)) box[day] = 0;
    }
    int curind = 0;
    forn(i,sz(boxes)) {
        while (box[curind] != -1) ++curind;
        box[curind] = boxes[i];
    }

    vector<string> r;
    forn(i,sz(pacientes)) {
        bool ok = false;
        forn(j,min(sz(box),MAXD)) {
            forn(s,MAXT) {
                forn(k,box[j]) {
                    if (pacientes[i] == 'P' && k >= 2) continue;
                    if (pacientes[i] == 'N' && k == 1) continue;
                    if (!turns[j][k][s] && (pacientes[i] == 'N' || (s+1 < MAXT && !turns[j][k][s+1]))) {
                        turns[j][k][s] = true;
                        if (pacientes[i] == 'P') turns[j][k][s+1] = true;
                        r.pb(date(j)+"|"+time(s)+"|Box:"+string(1,k+'A'));
                        ok = true;
                        break;
                    }
                    if (ok) break;
                }
                if (ok) break;
            }
            if (ok) break;
        }
    }

    return r;
}
