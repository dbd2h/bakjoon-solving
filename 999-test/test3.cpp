#include <iostream>

using namespace std;

int AtoH[8]={0};
int matrix[4][4]={0};
int isused[14]={0};
int mcount=0;

string sumF(string &s1, string &s2)
{
    string s;
    if(s1=="0" && s2=="0")
    {
        return "0";
    }
    int idx1=s1.size()-1;
    int idx2=s2.size()-1;
    bool isUp=0;
    while(idx1>-1 || idx2>-1)
    {
        int num1=0;
        if(idx1>-1)
        {
            num1=s1[idx1]-'0';
            idx1--;
        } 
        int num2=0;
        if(idx2>-1)
        {
            num2=s2[idx2]-'0';
            idx2--;
        }
        int sumV=num1+num2;
        if(isUp) sumV+=1;
        if(sumV/10==1)
        {
            isUp=1;
            sumV-=10;
        }
        else isUp=0;
        s+=to_string(sumV);
    }
    if(isUp) s+="1";
    reverse(s.begin(),s.end());
    return s;
}

void fill(int n)
{
    
    if(n==0)
    {
        for(int i=1;i<=13;i++)
        {
            int sum=AtoH[7];
            if(sum-i<=0 || sum-i>13) continue;
            if(isused[sum-i]==1 || isused[i]==1) continue;
            if(sum-i == i) continue;
            matrix[3][0]=i;
            matrix[3][1]=sum-i;
            isused[i]=1;
            isused[sum-i]=1;
            fill(n+2);
            matrix[3][0]=0;
            matrix[3][1]=0;
            isused[i]=0;
            isused[sum-i]=0;
        }
        return;
    }
    else if(n==2)
    {
        for(int i=1;i<=13;i++)
        {
            int sum=AtoH[3];
            if(sum-i<=0 || sum-i>13) continue;
            if(isused[sum-i]==1 || isused[i]==1) continue;
            if(sum-i == i) continue;
            matrix[0][3]=i;
            matrix[1][3]=sum-i;
            isused[i]=1;
            isused[sum-i]=1;
            fill(n+2);
            matrix[0][3]=0;
            matrix[1][3]=0;
            isused[i]=0;
            isused[sum-i]=0;
        }
        return;
    }
    else if(n==4)
    {
        for(int i=1;i<=13;i++)
        {
            if(isused[i]==1) continue;
            matrix[2][0]=i;
            isused[i]=1;
            fill(n+1);
            matrix[2][0]=0;
            isused[i]=0;
        }
        return;
    }
    else if(n==5)
    {
        for(int i=1;i<=13;i++)
        {
            int sum=AtoH[6]-matrix[2][0];
            if(sum-i<=0 || sum-i>13) continue;
            if(isused[sum-i]==1 || isused[i]==1) continue;
            if(sum-i == i) continue;
            matrix[2][1]=i;
            matrix[2][2]=sum-i;
            isused[i]=1;
            isused[sum-i]=1;
            fill(n+2);
            matrix[2][1]=0;
            matrix[2][2]=0;
            isused[i]=0;
            isused[sum-i]=0;
        }
        return;
    }
    else if(n==7)
    {
        for(int i=1;i<=13;i++)
        {
            int sum=AtoH[2]-matrix[2][2];
            if(sum-i<=0 || sum-i>13) continue;
            if(isused[sum-i]==1 || isused[i]==1) continue;
            if(sum-i == i) continue;
            matrix[0][2]=i;
            matrix[1][2]=sum-i;
            isused[i]=1;
            isused[sum-i]=1;
            fill(n+2);
            matrix[0][2]=0;
            matrix[1][2]=0;
            isused[i]=0;
            isused[sum-i]=0;
        }
        return;
    }
    else if(n==9)
    {
        for(int i=1;i<=13;i++)
        {
            int sum=AtoH[1]-matrix[2][1]-matrix[3][1];
            if(sum-i<=0 || sum-i>13) continue;
            if(isused[sum-i]==1 || isused[i]==1) continue;
            if(sum-i == i) continue;
            matrix[0][1]=i;
            matrix[1][1]=sum-i;
            isused[i]=1;
            isused[sum-i]=1;
            fill(n+2);
            matrix[0][1]=0;
            matrix[1][1]=0;
            isused[i]=0;
            isused[sum-i]=0;
        }
        return;
    }
    else if(n==11)
    {
        for(int i=1;i<=13;i++)
        {
            int sum=AtoH[0]-matrix[2][0]-matrix[3][0];
            if(sum-i<=0 || sum-i>13) continue;
            if(isused[sum-i]==1 || isused[i]==1) continue;
            if(sum-i == i) continue;
            matrix[0][0]=i;
            matrix[1][0]=sum-i;
            isused[i]=1;
            isused[sum-i]=1;
            fill(n+2);
            matrix[0][0]=0;
            matrix[1][0]=0;
            isused[i]=0;
            isused[sum-i]=0;
        }
        return;
    }
    else if(n==13)
    {
        if(!(AtoH[4]==(matrix[0][0]+matrix[0][1]+matrix[0][2]+matrix[0][3]) && AtoH[5]==(matrix[1][0]+matrix[1][1]+matrix[1][2]+matrix[1][3]))) return;
        mcount++;
        return;
    }
}

int main()
{
    for(int i=0;i<8;i++)
    {
        cin>>AtoH[i];
    }
    fill(0);
    cout<<mcount<<"\n";
}