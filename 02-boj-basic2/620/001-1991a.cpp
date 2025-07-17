#include <iostream>
#include <vector>

#define MAX_LEN 26

using namespace std;

void preOrder(vector<pair<int,int>> v[] ,int node)
{
    if(node==-1)
    {
        return;
    }
    char ch=node+'A';
    cout<<ch;
    pair<int,int> curTree;
    curTree=v[node][0];
    preOrder(v, curTree.first);
    preOrder(v, curTree.second);
}

void inOrder(vector<pair<int,int>> v[] ,int node)
{
    if(node==-1)
    {
        return;
    }
    pair<int,int> curTree;
    curTree=v[node][0];
    inOrder(v, curTree.first);
    char ch=node+'A';
    cout<<ch;
    
    
    inOrder(v, curTree.second);
}

void postOrder(vector<pair<int,int>> v[] ,int node)
{
    if(node==-1)
    {
        return;
    }
    pair<int,int> curTree;
    curTree=v[node][0];
    postOrder(v, curTree.first);
    postOrder(v, curTree.second);
    char ch=node+'A';
    cout<<ch;
    
}

int main()
{
    vector<pair<int,int>> v[MAX_LEN];
    int n;
    cin>>n;

    char parent, left, right;
    for(int i=0;i<n;i++)
    {
        cin>>parent>>left>>right;
        pair <int,int> node;
        node.first=-1;
        node.second=-1;
        if(left != '.')
            node.first=left-'A';
        if(right != '.')
            node.second=right-'A';
        v[parent-'A'].push_back(node);
    }
    preOrder(v,0);
    cout<<"\n";
    inOrder(v,0);
    cout<<"\n";
    postOrder(v,0);
}