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
    map<string, vector<pair<string, int>>> roles;
    for (int i=0; i<p; i++) {
        string name; cin>>name;
        int d; cin>>d;
        days[name] = d;
        int s; cin>>s;
        score[name] = s;
        int b; cin>>b;
        bbefore[name] = b;
        int r; cin>>r;
        vector<pair<string, int>> v;
        for (int j=0; j<r; j++) {
            string x; cin>>x;
            int l; cin>>l;
            v.push_back({x, l});
        }
        roles[name] = v;
    }

	//E
	vector<pair<float, string>> priority;
	for (auto kv: days) {
		string name = kv.first;
		float p = (score[name]*score[name]*score[name]*score[name])/(days[name]*days[name]*bbefore[name]*roles[name].size()*roles[name].size()*roles[name].size());
		priority.push_back({p, name});
	}
	sort(priority.rbegin(),priority.rend());

	vector<pair<string, vector<string>>> ROLES;

	map<string, int> booked;
	int currday = 0;
	for (int i = 0; i<priority.size(); i++) {
		string name = priority[i].second;
		vector<pair<string, int>> r = roles[name];
		vector<string> ans;
		for (int j=0; j<r.size(); j++) {
			string skill = r[j].first;
			for (auto kv:skills) {
				for (auto sl:kv.second) {
					string has = sl.first;
					if (has == skill && booked[kv.first] + days[name] + currday < bbefore[name]) {
						ans.push_back(kv.first);
						booked[kv.first] = booked[kv.first] + currday + days[name];
					}
				}
			}
		}
		if (ans.size() == r.size()) {
			ROLES.push_back({name, ans});
			currday += days[name];
		}
	}
	cout<<ROLES.size()<<endl;
	for (auto kv: ROLES) {
		cout<<kv.first<<endl;
		for (string r : kv.second)
			cout<<r<<' ';
		cout<<endl;
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
