#include <bits/stdc++.h>

using namespace std;

int check(string input, string output) {
    ifstream in(input);
    ifstream out(output);
    int c; in>>c;
    int p; in>>p;
    map<string, map<string,int>> skills; //skills[name][skill] = level

    for (int i=0; i<c; i++) {
        string name; in>>name;
        int n; in>>n;
        map<string, int> m;
        for (int j=0; j<n; j++) {
            string skill; in>>skill;
            int l; in>>l;
            m[skill] = l;
        }
        skills[name] = m;
    }

    map<string, int> days; //days[project] = days needed
    map<string, int> score; //scores[project] = score gained
    map<string, int> bbefore;
    map<string, map<string, int>> roles;
    for (int i=0; i<p; i++) {
        string name; in>>name;
        int d; in>>d;
        days[name] = d;
        int s; in>>s;
        score[name] = s;
        int b; in>>b;
        bbefore[name] = b;
        int r; in>>r;
        map<string, int> m;
        for (int j=0; j<r; j++) {
            string x; in>>x;
            int l; in>>l;
            m[x] = l;
        }
        roles[name] = m;
    }

    int e; out>>e;
    map<string, vector<string>> ROLES;
    for (int i=0; i<e; i++) {
        string name; out>>name;
        vector<string> v;
        for (auto kv: roles[name]) {
            string r; out>>r;
            v.push_back(r);
        }
        // cout<<name<<endl;
        ROLES[name] = v;
    }
    
    int SCORE = 0;
    for (auto kv : ROLES) {
        SCORE += score[kv.first];
    }
    return SCORE;
}

signed main(int argc, char *argv[]) {
    cout << "Score:\t" << check(argv[1], argv[2])<<endl;
}