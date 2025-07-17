#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int numArr[100000]={0};

struct Node
{
    Node * left;
    Node * right;

    Node()
    {
        left=NULL;
        right=NULL;
    }

    void insert(string s)
    {
        if(s.empty())
        {
            return;
        }
        if(s[0]=='1')
        {
            if(left == NULL) left = new Node();
            left->insert(s.substr(1));
        }
        else if(s[0]=='0')
        {
            if(right == NULL) right = new Node();
            right->insert(s.substr(1));
        }
    }
};

int desc(int n1, int n2)
{
    if(n1>n2) return 1;
    else return 0;
}

string bitMaker(int num, int bitLen)
{
    string s;
    while(num!=0)
    {
        if(num%2==1)
        {
            num/=2;
            s='1'+s;
        }
        else if(num%2==0)
        {
            num/=2;
            s='0'+s;
        }
    }
    int ssize=s.size();
    for(int i=0;i<bitLen-ssize;i++)
    {
        s='0'+s;
    }
    return s;
}

int powF(int len)
{
    if(len==0)
    {
        return 1;
    }
    return 2*powF(len-1);
}


void xorF(Node * n1, Node * n2, int len, int *max, int sumV)
{
    if(len==0)
    {
        if(sumV>*max) *max=sumV;
        return;
    }
    int isF=0;
    if(n1->left!=NULL && n2->right!=NULL)
    {
        isF=1;
        xorF(n1->left,n2->right,len-1,max,sumV+powF(len-1));
    }
    if(n1->right!=NULL && n2->left!=NULL)
    {
        isF=1;
        xorF(n1->right,n2->left,len-1,max,sumV+powF(len-1));
    }
    if(isF==1) return;
    if(n1->left!=NULL && n2->left!=NULL)
    {
        xorF(n1->left,n2->left,len-1,max,sumV);
    }
    if(n1->right!=NULL && n2->right!=NULL)
    {
        xorF(n1->right,n2->right,len-1,max,sumV);
    }
}


int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>numArr[i];
    }
    sort(numArr,numArr+n,desc);
    Node * root = new Node();
    int len=0;
    int num=numArr[0];
    while(num!=0)
    {
        num/=2;
        len++;
    }
    for(int i=0;i<n;i++)
    {
        string s=bitMaker(numArr[i],len);
        root->insert(s);
    }
    Node * n1;
    Node * n2;
    int result=0;
    while(len!=0)
    {
        len--;
        if(root->left!=NULL && root->right!=NULL)
        {
            n1=root->left;
            n2=root->right;
            result+=powF(len);
            break;
        }
        if(root->left==NULL)
        {
            root=root->right;
        }
        else if(root->right==NULL)
        {
            root=root->left;
        }
    }
    if(len!=0)
    {
        xorF(n1,n2,len,&result,result);       
    }
    cout<<result;
}