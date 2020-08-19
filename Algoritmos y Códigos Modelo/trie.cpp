#include <iostream>
#include <string>
#include <map>
using namespace std;

struct trie{
    map<char, trie> edges;
    int count = 0;
    void insert(const string &s, int i=0){
        if( s.length() == i ) count++;
        else edges[s[i]].insert(s, i+1);
    }
    void print(const string &&s=""){
        if( count > 0 ) cout << s << endl;
        for(auto &e: edges)
            e.second.print(s+e.first);
    }
};

int main(){

    trie t;

    t.insert("hola");
    t.insert("horno");
    t.insert("holas");

    t.print();

    return 0;
}
