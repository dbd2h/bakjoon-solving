#include <iostream>

using namespace std;

int block[100]={0};

int block1(int c) // |
{
    int res=0;
    for(int i=0;i<c;i++)
    {
        res+=1;
    }
    for(int i=0;i<c-3;i++)
    {
        if(block[i]==block[i+1] && block[i+1]==block[i+2] && block[i+2]==block[i+3]) res+=1;
    }
    return res;
}
int block2(int c) // ㅁ
{
    int res=0;
    for(int i=0;i<c-1;i++)
    {
        if(block[i]==block[i+1]) res+=1;
    }
    return res;
}
int block3(int c) // 역 ㄹ
{
    int res=0;
    for(int i=0;i<c-2;i++) // 가로
    {
        if(block[i]==block[i+1] && block[i+1]+1==block[i+2]) res+=1;
    }
    for(int i=0;i<c-1;i++) //세로
    {
        if(block[i]==block[i+1]+1) res+=1;
    }
    return res;
}
int block4(int c) // ㄹ
{
    int res=0;
    for(int i=0;i<c-2;i++) // 가로
    {
        if(block[i]==block[i+1]+1 && block[i+1]==block[i+2]) res+=1;
    }
    for(int i=0;i<c-1;i++) //세로
    {
        if(block[i]+1==block[i+1]) res+=1;
    }
    return res;
}
int block5(int c) // ㅗ
{
    int res=0;
    for(int i=0;i<c-2;i++) // ㅗ,ㅜ
    {
        if(block[i]==block[i+1] && block[i+1]==block[i+2]) res+=1;
        if(block[i]==block[i+1]+1 && block[i+1]+1==block[i+2]) res+=1;
    }
    for(int i=0;i<c-1;i++) // ㅓ,ㅏ
    {
        if(block[i]==block[i+1]+1) res+=1;
        if(block[i]+1==block[i+1]) res+=1;
    }
    return res;
}
int block6(int c) // 역 ㄴ
{
    int res=0;
    for(int i=0;i<c-2;i++) // 역ㄴ, 역ㄱ
    {
        if(block[i]==block[i+1] && block[i+1]==block[i+2]) res+=1;
        if(block[i]+1==block[i+1] && block[i+1]==block[i+2]) res+=1;
    }
    for(int i=0;i<c-1;i++)
    {
        if(block[i]==block[i+1]) res+=1;
        if(block[i]==block[i+1]+2) res+=1;
    }
    return res;
}
int block7(int c) // ㄴ
{
    int res=0;
    for(int i=0;i<c-2;i++) // ㄴ,ㄱ
    {
        if(block[i]==block[i+1] && block[i+1]==block[i+2]) res+=1;
        if(block[i]==block[i+1] && block[i+1]==block[i+2]+1) res+=1;
    }
    for(int i=0;i<c-1;i++)
    {
        if(block[i]==block[i+1]) res+=1;
        if(block[i]+2==block[i+1]) res+=1;
    }
    return res;
}

int main()
{
    int c,p;
    cin>>c>>p;
    for(int i=0;i<c;i++)
    {
        cin>>block[i];
    }
    if(p==1) cout<<block1(c);
    if(p==2) cout<<block2(c);
    if(p==3) cout<<block3(c);
    if(p==4) cout<<block4(c);
    if(p==5) cout<<block5(c);
    if(p==6) cout<<block6(c);
    if(p==7) cout<<block7(c);

}