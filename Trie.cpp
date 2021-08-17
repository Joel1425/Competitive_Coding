#include <bits/stdc++.h>
using namespace std;
struct Trie{
    bool isEnd;
    int count;
    unordered_map<char,Trie*> mp;
    Trie()
    {
        this->isEnd=false;
        this->count=0;
        mp.clear();
    }
};
void insert(Trie* root, string &str)
{
    Trie* temp=root;
    int n=str.size();
    for (int i=0;i<n;i++)
    {
        if (temp->mp.find(str[i])==temp->mp.end())
        {
            Trie* newNode=new Trie();
            temp->mp[str[i]]=newNode;
        }
        temp=temp->mp[str[i]];
        temp->count++;
    }
    temp->isEnd=true;
}

bool search(Trie* root, string &str)
{
    Trie* temp=root;
    int n=str.size();
    for (int i=0;i<n;i++)
    {
        if (temp->mp.find(str[i])==temp->mp.end())
        {
            return false;
        }
        temp=temp->mp[str[i]];
    }
    return (temp->isEnd==true);
}

void dfs(Trie* root, string str, string temp, vector<string> &res)
{
    if (!root) return;
    if (root->isEnd)
    {
        res.push_back(str+temp);
    }
    for (auto i:root->mp)
    {
        char c=i.first;
        temp.push_back(c);
        dfs(root->mp[c],str,temp,res);
        temp.pop_back();
    }
    
}
vector<string> suggestions(Trie* root, string &str)
{
    vector<string> res;
    Trie* temp=root;
    int n=str.size();
    for (int i=0;i<n;i++)
    {
        if (temp->mp.find(str[i])==temp->mp.end())
        {
            return res;
        }
        temp=temp->mp[str[i]];   
    }
    dfs(temp,str,"",res);
    return res;
}
int main() 
{
    Trie* trie=new Trie();
    int n;
    cin>>n;
    vector<string> arr(n);
    for (int i=0;i<n;i++) 
    {
        cin>>arr[i];
        insert(trie,arr[i]);
    }
    int q;
    cin>>q;
    vector<string> res;
    cout<<"Checking Validity:\n";
    while(q--)
    {
        string s;
        cin>>s;
        if (search(trie,s))
        {
            res.push_back(s+" is present.");
        }
        else
        {
            res.push_back(s+" is not present.");
        }
    }
    for (auto i:res) cout<<i<<"\n";
    
    int Q;
    cin>>Q;
    cout<<"Showing Suggestions:\n";
    while(Q--)
    {
        res.clear();
        string s;
        cin>>s;
        
        res=suggestions(trie,s);
        cout<<"From "<<s<<" there are "<<res.size()<<" words:\n";
        for (auto i:res) cout<<i<<"\n";
    }
    return 0;
}
