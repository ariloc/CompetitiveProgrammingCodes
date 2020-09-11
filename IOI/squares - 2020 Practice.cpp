#include "squares.h"
#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= s; i--)
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int myK = 10;
const string DEBRUIJN = "0100000000110000000101000000011100000010010000001011000000110100000011110000010001000001001100000101010000010111000001100100000110110000011101000001111100001000010001100001001010000100111000010100100001010110000101101000010111100001100010000110011000011010100001101110000111001000011101100001111010000111111000100010100010001110001001001000100101100010011010001001111000101001100010101010001010111000101100100010110110001011101000101111100011000110010100011001110001101001000110101100011011010001101111000111001100011101010001110111000111100100011110110001111101000111111100100100110010010101001001011100100110110010011101001001111100101001010011100101010110010101101001010111100101100110010110101001011011100101110110010111101001011111100110011010011001111001101010100110101110011011011001101110100110111110011100111010110011101101001110111100111101010011110111001111101100111111010011111111010101010111010101101101010111110101101011011110101110111010111101101011111110110110111011011111101110111110";

/*
string s;
vi way;
bitset<MAXN> done;

void dfs(int st) {
    forn(i,2) {
        int v = (st<<1)+i;
        if (done[v]) continue;
        done[v] = true; dfs(v & (~(1<<(myK-1))));
        way.pb(i);
    }
}

std::vector<int> paint(int n) {
    std::vector<int> labels(n + 1, 0);

    dfs(0);
    dforn(i,(1<<10)) s += way[i]+'0';
    s += string(myK-1,'0');
    forn(i,n) labels[i] = s[i]-'0';
    labels[n] = myK;

	return labels;
}*/

std::vector<int> paint(int n) {
    std::vector<int> labels(n + 1, 0);

    forn(i,n) labels[i] = DEBRUIJN[i]-'0';
    labels[n] = myK;

	return labels;
}

int find_location(int n, std::vector<int> c) {
    string b;
    int cnt = 0;
    forn(i,c.size()) {if (c[i] == -1) cnt++; else b += c[i]+'0';}
    if (cnt) return (n+cnt)-myK; // si se pasa de rango
    else return DEBRUIJN.find(b);
}
