#include <iostream>
#include <string>

typedef struct _cursor
{
    int cursorPos;
    int strSize;
    std::string str;
} Cursor;

void iniCursor(Cursor &cursor)
{
    cursor.strSize=cursor.str.size();
    cursor.cursorPos=cursor.strSize;
    return;
}

void lCursor(Cursor &cursor)
{
    if(cursor.cursorPos==0)
    {
        return;
    }
    cursor.cursorPos--;
    return;
}

void rCursor(Cursor &cursor)
{
    if(cursor.cursorPos==cursor.strSize)
    {
        return;
    }
    cursor.cursorPos++;
}

void bCursor(Cursor &cursor)
{
    if(cursor.cursorPos==0)
    {
        return;
    }
    std::string copyS=cursor.str;
    if(cursor.cursorPos-1==cursor.strSize)
    {
        cursor.str=copyS.substr(0,cursor.cursorPos-1);
    }
    else
    {
        cursor.str=copyS.substr(0,cursor.cursorPos-1)+copyS.substr(cursor.cursorPos,cursor.strSize-cursor.cursorPos);
    }
    
    cursor.strSize--;
    cursor.cursorPos--;
}

void pCursor(Cursor &cursor, char pWord)
{
    std::string copyS=cursor.str;
    if(cursor.cursorPos-1==cursor.strSize)
    {
        cursor.str=copyS.substr(0,cursor.cursorPos)+pWord;
    }
    else
    {
        cursor.str=copyS.substr(0,cursor.cursorPos)+pWord+copyS.substr(cursor.cursorPos,cursor.strSize-cursor.cursorPos);
    }
    cursor.strSize++;
    cursor.cursorPos++;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    Cursor cursor;
    std::cin>>cursor.str;
    iniCursor(cursor);
    int count;
    std::cin>>count;
    for(int i=0;i<count;i++)
    {
        char s;
        std::cin>>s;
        if(s=='P')
        {
            char pWord;
            std::cin>>pWord;
            pCursor(cursor, pWord);
        }
        else if(s=='L')
        {
            lCursor(cursor);
        }
        else if(s=='D')
        {
            rCursor(cursor);
        }
        else if(s=='B')
        {
            bCursor(cursor);
        }
    }
    std::cout<<cursor.str<<"\n";
}