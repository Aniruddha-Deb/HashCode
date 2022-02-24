#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve() {
	int c; cin>>c;
    int p; cin>>p;
    map<string, map<string,int>> skills; //skills[name][skill] = level

    for (int i=0; i<c; i++) {
        string name; cin>>name;
        int n; cin>>n;
        map<string, int> m;
        for (int j=0; j<n; j++) {
            string skill; cin>>skill;
            int l; cin>>l;
            m[skill] = l;
        }
        skills[name] = m;
    }

    map<string, int> days; //days[project] = days needed
    map<string, int> score; //scores[project] = score gained
    map<string, int> bbefore;
    map<string, map<string, int>> roles;
    for (int i=0; i<p; i++) {
        string name; cin>>name;
        int d; cin>>d;
        days[name] = d;
        int s; cin>>s;
        score[name] = s;
        int b; cin>>b;
        bbefore[name] = b;
        int r; cin>>r;
        map<string, int> m;
        for (int j=0; j<r; j++) {
            string x; cin>>x;
            int l; cin>>l;
            m[x] = l;
        }
        roles[name] = m;
    }
}

int main() {
	init();
	int t = 1;
	// cin >> t;
	while (t-- > 0) {
		solve();
	}
	return 0;
}
