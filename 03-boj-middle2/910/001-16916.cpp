#include <stdio.h>
#include <cstring>

int main()
{
    char s[1000001],p[1000001];
    scanf("%s %s", s,p);
    char * result = strstr(s,p);
    if(!result) printf("0");
    else printf("1");
}