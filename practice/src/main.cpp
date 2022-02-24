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

// graph w/edges between incompatible ingredients - find subset of disconnected
// nodes (nodes with no edges between them) of least degree

template <typename T1, typename T2>
struct less_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second > b.second;
    }
};

void solve() {
    // first - like, second - dislike
    //map<string, pair<vector<int>,vector<int>>> M;
    map<string, int> F;
    int n;
    cin >> n;
    vector<vector<string>> likes(n, vector<string>());
    vector<vector<string>> dislikes(n, vector<string>());
    rep(i,0,n) {
        int l, d;
        string s;
        cin >> l;
        rep(j,0,l) {
            cin >> s;
            likes[i].push_back(s);
            //if (M.count(s) == 0) M[s] = pair<vector<int>,vector<int>>(vector<int>({i}),vector<int>());
            //else M[s].first.push_back(i);
            F[s] = F[s] + 1;
        }
        cin >> d;
        rep(j,0,d) {
            cin >> s;
            dislikes[i].push_back(s);
            //if (M.count(s) == 0) M[s] = pair<vector<int>,vector<int>>(vector<int>(),vector<int>({i}));
            //else M[s].second.push_back(i);
            F[s] = F[s] - 1;
        }
    }

    vector<pair<string, int>> A(F.begin(), F.end());
    sort(A.begin(), A.end(), less_second<string, int>());

    /*
    for (auto kv : A) {
        cout << kv.first << ":" << kv.second << endl;
    }*/

    vector<string> ingrd;
    set<int> rejected_customers; // use this for a search speedup later
    set<int> accepted_customers;
    set<int> left_customers;
    int max_score = 0;
    int max_idx = 0;
    int idx = 0;
    
    for (int i=0; i<n; i++) {
        left_customers.insert(i);
    }
    cout << A.size() << endl;
    for (auto kv : A) {
        cout << idx << endl;
        if (kv.second < 0) break;
        int curr_score = 0;
        // check and update how adding this ingredient influences current score
        //for (int i=0; i<accepted_customers.size(); i++) {
         //   if (dislikes[c].find(kv.first) != dislikes[c].end()) accepted_customers.erase(accepted_customers.begin()+i);
        //}

        // if accepted customer has a reject ingredient, then remove him from acc list
        // don't check reject customers
        // check if the non-rejected, non-accepted customers have all ingredients in their list

        //cout << "checking key " << kv.first << endl;
        ingrd.push_back(kv.first);

        for (auto it = accepted_customers.begin(); it != accepted_customers.end(); ) {
            if (find(dislikes[*it].begin(), dislikes[*it].end(), kv.first) != dislikes[*it].end()) {
                //cout << "removing " << *it << " from accepted customers" << endl;
                rejected_customers.insert(*it);
                it = accepted_customers.erase(it);
                //cout << "removed from accepted customers" << endl;
            }
            else {++it;}
        }
        
        //cout << "Checking other elements to be included" << endl;

        for (auto it = left_customers.begin(); it != left_customers.end();) {
            int i = *it;

            bool all_in_likes = true;
            for (string l : likes[i]) {
                if (find(ingrd.begin(), ingrd.end(), l) == ingrd.end()) {
                    all_in_likes = false;
                    break;
                }
            }
            if (!all_in_likes) {++it; continue;}

            bool none_in_dislikes = true;
            for (string l : ingrd) {
                if (find(dislikes[i].begin(), dislikes[i].end(), l) != dislikes[i].end()) {
                    none_in_dislikes = false;
                    break;
                }
            }
            if (!none_in_dislikes) {++it; continue;}
            //cout << "adding " << i << " to accepted customers" << endl;
            accepted_customers.insert(i);
            it = left_customers.erase(it);
        }

        curr_score = accepted_customers.size();
        if (curr_score > max_score) { //cout << curr_score << endl; 
        max_score = curr_score; max_idx = idx;}
        idx++;
    }

    //cout << "constructed customer list" << endl;

    cout << max_idx+1 << " ";
    for (int i=0; i<=max_idx; i++) {
        cout << ingrd[i] << " ";
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
