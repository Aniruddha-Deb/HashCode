#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a);)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
}
map<string, map<string, int>> skills; // skills[name][skill] = level

map<string, int> days;  // days[project] = days needed
map<string, int> score; // scores[project] = score gained
map<string, int> bbefore;
map<string, vector<pair<string, int>>> roles;

vector<string> assigned;

bool fulfill(string skill, int level)
{
    for (auto i : skills)
    {
        if (find(assigned.begin(), assigned.end(), i.first) != assigned.end())
        {
            if (i.second[skill] >= level)
            {
                return true;
            }
        }
    }
    return false;
}

vector<string> check(string project)
{
    assigned.clear();
    map<string, bool> completed;
    vector<pair<int, string>> opened;
    for (auto i : roles[project])
    {
        opened.clear();
        for (auto j : skills)
        {
            if (find(assigned.begin(), assigned.end(), j.first) != assigned.end())
            {
                continue;
            }
            if (j.second[i.first] >= i.second)
            {
                int cnt = 0;
                completed[i.first] = true;
                for (auto k : roles[project])
                {
                    if (completed.find(k.first) == completed.end() && j.second[k.first] >= k.second)
                    {
                        cnt++;
                    }
                }
                opened.emplace_back(make_pair(cnt, j.first));
            }
        }
        if (opened.empty())
        {
            return {};
        }
        else
        {
            sort(opened.begin(), opened.end());
            string curr = opened[opened.size() - 1].second;
            assigned.emplace_back(curr);
            for (auto k : roles[project])
            {
                if (completed.find(k.first) == completed.end() && skills[curr][k.first] >= k.second)
                {
                    k.second -= 1;
                    completed[k.first] = true;
                }
            }
        }
    }
    return assigned;
}

void solve()
{
    int c;
    cin >> c;
    int p;
    cin >> p;

    for (int i = 0; i < c; i++)
    {
        string name;
        cin >> name;
        int n;
        cin >> n;
        map<string, int> m;
        for (int j = 0; j < n; j++)
        {
            string skill;
            cin >> skill;
            int l;
            cin >> l;
            m[skill] = l;
        }
        skills[name] = m;
    }

    for (int i = 0; i < p; i++)
    {
        string name;
        cin >> name;
        int d;
        cin >> d;
        days[name] = d;
        int s;
        cin >> s;
        score[name] = s;
        int b;
        cin >> b;
        bbefore[name] = b;
        int r;
        cin >> r;
        vector<pair<string, int>> m;
        for (int j = 0; j < r; j++)
        {
            string x;
            cin >> x;
            int l;
            cin >> l;
            m.emplace_back(make_pair(x, l));
        }
        roles[name] = m;
    }
    vector<vector<string>> ans;
    map<string, bool> finished;
    bool flag = true;
    int cnt = 0;
    while (flag && cnt < 1000)
    {
        cnt++;
        flag = false;
        for (auto proj : bbefore)
        {
            if (finished[proj.first])
            {
                continue;
            }
            vector<string> ass = check(proj.first);
            if (!ass.empty())
            {
                flag = true;
                ans.push_back({proj.first});
                for (auto u : ass)
                {
                    ans[ans.size() - 1].push_back(u);
                }
                finished[proj.first] = true;
                break;
            }
        }
    }
    cout << ans.size() << "\n";
    for (auto u : ans)
    {
        cout << u[0] << "\n";
        for (int i = 1; i < u.size(); i++)
        {
            cout << u[i] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    init();
    int t = 1;
    // cin >> t;
    while (t-- > 0)
    {
        solve();
    }
    return 0;
}
