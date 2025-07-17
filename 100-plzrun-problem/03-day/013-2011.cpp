#include <iostream>
#include <string>

int main()
{
    std::string inputNum;
    std::cin>>inputNum;
    int len=inputNum.length();
    int dp[len];
    for(int i=0;i<len;i++)
    {
        if(i==0&&inputNum[i]-'0'==0)
        {
            dp[len-1]=0;
            break;
        }
        if(i==0)
        {
            dp[i]=1;
            continue;
        }
        else if(i==1)
        {
            if((inputNum[i-1]-'0'<2||(inputNum[i-1]-'0'==2&&inputNum[i]-'0'<=6))&&inputNum[i]-'0'!=0)
            {
                dp[i]=2;
            }
            else if((inputNum[i-1]-'0'!=1&&inputNum[i-1]-'0'!=2)&&inputNum[i]-'0'==0)
            {
                dp[len-1]=0;
                break;
            }
            else
            {
                dp[i]=1;
            }
            continue;
        }
        if((inputNum[i-1]-'0'!=1&&inputNum[i-1]-'0'!=2)&&inputNum[i]-'0'==0)
        {
            dp[len-1]=0;
            break;
        }
        else if(inputNum[i-1]-'0'==0)
        {
            dp[i]=dp[i-1];
        }
        else if((inputNum[i-1]-'0'<2||(inputNum[i-1]-'0'==2&&inputNum[i]-'0'<=6))&&inputNum[i]-'0'!=0)
        {
            dp[i]=(dp[i-2]+dp[i-1])%1000000;
        }
        else if(inputNum[i]-'0'==0)
        {
            dp[i]=dp[i-2];
        }
        else
        {
            dp[i]=dp[i-1];
        }
    }
    std::cout<<dp[len-1]<<"\n";
    return 0;
}