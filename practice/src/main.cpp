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
    map<string, int> M;
    int n;
    cin >> n;
    rep(i,0,n) {
        int l, d;
        string s;
        cin >> l;
        rep(j,0,l) {
            cin >> s;
            M[s] = M[s] + 1;
        }
        cin >> d;
        rep(j,0,d) {
            cin >> s;
            M[s] = M[s] - 1;
        }
    }

    vector<string> ingrd;
    for (auto pair : M) {
        if (pair.second >= 0) ingrd.push_back(pair.first);
    }

    cout << ingrd.size() << " ";
    for (string s : ingrd) {
        cout << s << " ";
    }
    cout << endl;
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
