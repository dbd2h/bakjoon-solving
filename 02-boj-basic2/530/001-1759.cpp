#include <iostream>

char vowel[5]={'a','e','i','o','u'};

using namespace std;

void insert_sort(char *arr, int len);
void print(char *arr, char *cArr, int l, int c, int count, int now);

int main()
{
    int l,c;
    cin>>l>>c;
    char arr[c];
    char cArr[c];
    for(int i=0;i<c;i++)
    {
        cin>>cArr[i];
    }
    insert_sort(cArr, c);
    print(arr,cArr,l,c,0,0);
}

void insert_sort(char *arr, int len)
{
    for(int i=0;i<len;i++)
    {
        char min=arr[i];
        int minI=i;
        for(int j=i+1;j<len;j++)
        {
            if(min>arr[j])
            {
                min=arr[j];
                minI=j;
            }
        }
        char c=arr[i];
        arr[i]=min;
        arr[minI]=c;
    }
}

void print(char *arr, char *cArr, int l, int c, int count, int now)
{
    if(count!=l&&now>=c)
    {
        return;
    }
    if(count==l)
    {
        int vCount=0;
        for(int i=0;i<l;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(vowel[j]==arr[i])
                {
                    vCount++;
                    break;
                }
            }
        }
        if(vCount==0||l-vCount<2)
        {
            return;
        }
        for(int i=0;i<l;i++)
        {
            cout<<arr[i];
        }
        cout<<"\n";
        return;
    }
    for(int i=now;i<c;i++)
    {
        arr[count]=cArr[i];
        print(arr, cArr, l, c, count+1, i+1);
    }
}