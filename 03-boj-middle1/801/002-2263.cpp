#include <iostream>

using namespace std;

int inorder[100000]={0};
int postorder[100000]={0};

void preorder(int l, int r, int rc)
{
    if(l>r) return;
    int a,b;
    a=l;
    b=r;
    while(true)
    {
        if(postorder[r-rc]==inorder[a])
        {
            cout<<postorder[r-rc]<<" ";
            preorder(l,a-1,rc);
            preorder(a+1,r,rc+1);
            return;
        }
        a++;
        if(postorder[r-rc]==inorder[b])
        {
            cout<<postorder[r-rc]<<" ";
            preorder(l,b-1,rc);
            preorder(b+1,r,rc+1);
            return;
        }
        b--;
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>inorder[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>postorder[i];
    }
    preorder(0,n-1,0);
}