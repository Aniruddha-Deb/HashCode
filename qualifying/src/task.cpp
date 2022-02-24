#include <bits/stdc++.h>
#define int long long
using namespace std;
#define pb push_back
#define vi vector<int>
const int INF=(int)1e18;
const int mod=1000000007;
#define sz(x) (x).size()
 
 
 
int exp(int k,int m){
    if (m==0){
        return 1;
    }
    int half=exp(k,m/2);
    if (m%2==1){
        return (((half*half)%mod)*k)%mod;
    }
    else{
        return (half*half)%mod;
    }
}
int inv(int x){
    return exp(x,mod-2);
}
int comb(int n,int r){
    int ans=1;
    for (int i=1;i<=r;i++){
        ans*=(n-i+1);
        ans%=mod;
        ans*=inv(i);
        ans%=mod;
    }
    return ans;
}

 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c;
    cin>>c;
    vector<set<string>> likes(c),dislikes(c);

    for (int i=0;i<c;i++){
        int l;
        cin>>l;
        for (int j=0;j<l;j++){
            string s;
            cin>>s;
            likes[i].insert(s);
        }
        int d;
        cin>>d;
        for (int j=0;j<d;j++){
            string s;
            cin>>s;
            dislikes[i].insert(s);
        }
    }
    vector<vector<int>> adj(c);
    for (int i=0;i<c;i++){
        for (int j=i+1;j<c;j++){
            for (string s:likes[i]){
                if (dislikes[j].count(s)!=0){
                    adj[i].pb(j);
                    adj[j].pb(i);
                    break;
                }
            }
        }
    }
    vector<bool> considering(c,1);
    vector<pair<int,int>> degnode;
    for (int i=0;i<c;i++){
        degnode.pb(make_pair(adj[i].size(),i));
    }
    vi final;
    sort(degnode.begin(),degnode.end());
    for (int i=0;i<c;i++){
        if (!considering[i]){
            continue;
        }
        final.pb(i);
        for (int j:adj[i]){
            considering[j]=0;
        }

        
    }
    set<string> ingredients;
    for (int x:final){
        for (string s:likes[x]){
            ingredients.insert(s);
        }
    }
    cout<<ingredients.size()<<" ";
    for (string s:ingredients){
        cout<<s<<" ";
    }





    
 
 
    
 
    return 0;
}