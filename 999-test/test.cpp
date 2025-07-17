#include <iostream>
#include <cmath>

using namespace std;

long double dotToDot(int x, int y, int a, int b){
    return round(sqrt(pow(x-a, 2)+pow(y-b, 2))*10)/10;
}

long double findLen(int x1, int y1, int x2, int y2, int a, int b){
    long double min=dotToDot(x1,y1,a,b);
    min = min>dotToDot(x2,y2,a,b) ? dotToDot(x2,y2,a,b) : min;
    if(x1==x2){
        if(!((y1>=b && y2>=b)||(y1<=b && y2<=b))) return abs(x1-a);
    }
    else{
        if(!((x1>=a && x2>=a)||(x1<=a && x2<=a))) return abs(y1-b);
    }
    return min;
}

int main(){
    int x1,y1,x2,y2,a1,b1,a2,b2;
    cin>>x1>>y1>>x2>>y2>>a1>>b1>>a2>>b2;
    if(x1==x2 && b1==b2){
        if((y1<=b1 && y2>=b1)||(y1>=b1 && y2<=b1))
        {
            if((x1<=a1 && x1>=a2) || (x1>=a1 && x1<=a2)){
                cout<<0;
                return 0;
            }
        }
    }
    else if(y1==y2 && a1==a2){
        if((x1<=a1 && x2>=a1)||(x1>=a1 && x2<=a1))
        {
            if((y1<=b1 && y1>=b2) || (y1>=b1 && y1<=b2)){
                cout<<0;
                return 0;
            }
        }
    }
    long double min=findLen(x1,y1,x2,y2,a1,b1);
    min = min>findLen(x1,y1,x2,y2,a2,b2) ? findLen(x1,y1,x2,y2,a2,b2) : min;
    min = min>findLen(a1,b1,a2,b2,x2,y2) ? findLen(a1,b1,a2,b2,x2,y2) : min;
    min = min>findLen(a1,b1,a2,b2,x1,y1) ? findLen(a1,b1,a2,b2,x1,y1) : min;
    cout<<min;
}   
