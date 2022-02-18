#include <bits/stdc++.h>

using namespace std;

int check(string input, string output) {
    ifstream in(input);
    ifstream out(output);
    int c; in>>c;
    set <string> l[c];
    set <string> d[c];

    for (int i=0; i<c; i++) {
        int L; in>>L;
        for (int j=0; j<L; j++) {
            string s; in>>s;
            l[i].insert(s);
        }
        int D; in>>D;
        for (int j=0; j<D; j++) {
            string s; in>>s;
            d[i].insert(s);
        }
    }

    set <string> ing;
    int count; out>>count;
    for (int i=0; i<count; i++) {
        string s; out>>s; ing.insert(s);
    }
    int score = 0;
    for (int i=0; i<c; i++) {
        bool ok = true;
        for (string s : l[i]) {
            ok &= ing.count(s) > 0;
        }
        for (string s : d[i]) {
            ok &= ing.count(s) == 0;
        }
        if (ok)
            score++;
    }
    return score;
}

signed main(int argc, char *argv[]) {
    cout << "Score:\t" << check(argv[1], argv[2])<<endl;
}