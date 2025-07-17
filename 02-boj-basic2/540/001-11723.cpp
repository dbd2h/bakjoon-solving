#include <iostream>
#include <string>

using namespace std;

void add(int *set, int num);
void remove(int *set, int num);
void check(int *set, int num);
void toggle(int *set, int num);
void all(int *set);
void empty(int *set);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int set[21]={0};
    string s;
    int num;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        if(s=="add")
        {
            cin>>num;
            add(set,num);
        }
        else if(s=="remove")
        {
            cin>>num;
            remove(set,num);
        }
        else if(s=="check")
        {
            cin>>num;
            check(set,num);
        }
        else if(s=="toggle")
        {
            cin>>num;
            toggle(set,num);
        }
        else if(s=="all")
        {
            all(set);
        }
        else if(s=="empty")
        {
            empty(set);
        }
    }
}

void add(int *set, int num)
{
    set[num]=1;
}
void remove(int *set, int num)
{
    set[num]=0;
}
void check(int *set, int num)
{
    if(set[num]==1)
    {
        cout<<1<<"\n";
    }
    else
    {
        cout<<0<<"\n";
    }
}
void toggle(int *set, int num)
{
    if(set[num]==1)
    {
        set[num]=0;
    }
    else
    {
        set[num]=1;
    }
}
void all(int *set)
{
    for(int i=1;i<=20;i++)
    {
        set[i]=1;
    }
}
void empty(int *set)
{
    for(int i=1;i<=20;i++)
    {
        set[i]=0;
    }
}