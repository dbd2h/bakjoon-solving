#include <cstring>
#include <stdio.h>

int cnt;

int recursion(char* str, int l, int r)
{
    if(l>=r)
    {
        return 1;
    }
    else if(str[l]!=str[r])
    {
        return 0;
    }
    else
    {
        cnt++;
        return recursion(str, l+1,r-1);
    }
}

int isPalindrome(char* str)
{
    return recursion(str, 0, strlen(str)-1);
}

int main()
{
    int tCount;
    scanf("%d",&tCount);
    for(int i=0;i<tCount;i++)
    {
        char str[1001];
        scanf("%s", &str);
        cnt=1;
        int isTrue;
        isTrue=isPalindrome(str);
        printf("%d %d\n",isTrue, cnt);
    }
}