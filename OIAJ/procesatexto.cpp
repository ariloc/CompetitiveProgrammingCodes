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

vector<string> tokenize(string s) {
    string act = "";
    vector<string> ret;
    forn(i,s.size()) {
        if (s[i] == '-') ret.pb(act), act = "";
        else act.pb(s[i]);
    }
    if (!act.empty()) ret.pb(act);
    return ret;
}

string procesatexto(string &texto, vector<string> &comandos) {
    for (auto &c : comandos) {
        if (c == "INTERCAMBIA") {
            for (auto &j : texto) if (isupper(j)) j = tolower(j); else j = toupper(j);
        }
        else if (c == "BORRAULTI") {
            if (!texto.empty()) texto.pop_back();
        }
        else if (c == "BORRAPRI") {
            if (!texto.empty()) texto.erase(0,1);
        }
        else if (c == "DUP") {
            texto += texto;
        }
        else if (c == "ROTA") {
            if (!texto.empty()) {
                char prim = texto[0];
                texto.erase(0,1);
                texto.pb(prim);
            }
        }
        else if (c == "INVERTIR") {
            reverse(all(texto));
        }
        else if (c == "CHAUAGUS") {
            forn(i,texto.size()-3) {
                if (tolower(texto[i]) == 'a' && tolower(texto[i+1]) == 'g' && tolower(texto[i+2]) == 'u' && tolower(texto[i+3]) == 's') {
                    texto.erase(i,4);
                    break;
                }
            }
        }
        else {
            vector<string> tokens = tokenize(c);
            if (tokens[0] == "AGREGA") {
                texto += tokens[1];
            }
            else if (tokens[0] == "DUP") {
                size_t pos1{}, pos2{};
                int l = stoi(tokens[1],&pos1), r = stoi(tokens[2],&pos2);
                --l, --r;
                string aux = texto.substr(l,r-l+1);
                texto.insert(r+1,aux);
            }
            else if (tokens[0] == "INVERTIR") {
                size_t pos1{}, pos2{};
                int l = stoi(tokens[1],&pos1), r = stoi(tokens[2],&pos2);
                --l, --r;
                reverse(texto.begin()+l,texto.begin()+r+1);
            }
            else if (tokens[0] == "BORRA") {
                size_t pos{};
                int ind = stoi(tokens[1],&pos);
                --ind;
                texto.erase(ind,1);
            }
            else if (tokens[0] == "CHAU") {
                string aux = tokens[1];
                forn(i,(int)texto.size()-(int)aux.size()+1) {
                    bool yes = true;
                    forn(j,aux.size()) {
                        if (texto[i+j] != aux[j]) {
                            yes = false; break;
                        }
                    }
                    if (yes) {
                        texto.erase(i,(int)aux.size());
                        break;
                    }
                }
            }
        }

        if ((int)texto.size() > 1000) return "MemoryLimitExceeded";
    }
    return texto;
}
