#include <iostream>
#include <string>

bool isLeftBig(std::string string1,std::string string2)
{
    if(string1.length()>string2.length())
    {
        return true;
    }
    else if(string1.length()<string2.length())
    {
        return false;
    }

    for(int i=0;i<string1.length();i++)
    {
        if((int)string1[i]>(int)string2[i])
        {
            return true;
        }
        else if((int)string1[i]<(int)string2[i])
        {
            return false;
        }
    }
    return false;
}

void change(std::string *arr,int index1,int index2)
{
    std::string change=arr[index1];
    arr[index1]=arr[index2];
    arr[index2]=change;
}


int main()
{
    int inputNum;
    std::cin>>inputNum;
    std::string strArr[inputNum];

    for(int i=0;i<inputNum;i++)
    {
        std::string str;
        std::cin>>str;
        strArr[i]=str;
        int cur=i+1;
        while(cur-1)
        {
            if(isLeftBig(strArr[cur-1],strArr[cur/2-1]))
            {
                change(strArr,cur-1,cur/2-1);
            }
            else
            {
                break;
            }
            cur/=2;
        }
    }
    change(strArr,0,inputNum-1);

    for(int len=inputNum-1;len>0;len--)
    {
        int tree=1;
        while(tree<=len/2)
        {
            if(isLeftBig(strArr[tree*2-1],strArr[tree*2])||len==tree*2)
            {
                if(isLeftBig(strArr[tree*2-1],strArr[tree-1]))
                {
                    change(strArr,tree*2-1,tree-1);
                }
                else
                {
                    break;
                }
                tree=tree*2;
            }
            else
            {
                if(isLeftBig(strArr[tree*2],strArr[tree-1]))
                {
                    change(strArr,tree*2,tree-1);
                }
                else
                {
                    break;
                }
                tree=tree*2+1;
            }
        }
        change(strArr,0,len-1);
    }
    std::string backStr=strArr[0];
    for(int i=1;i<inputNum;i++)
    {
        if(strArr[i]==backStr)
        {
            strArr[i]="";
        }
        else
        {
            backStr=strArr[i];
        }
    }
    for(int i=0;i<inputNum;i++)
    {
        if(strArr[i]!="")
        {
            std::cout<<strArr[i]<<"\n";
        }
    }
}