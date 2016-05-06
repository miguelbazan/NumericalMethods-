





#include <iostream>
#include <math.h>
using namespace std;

double bisect(double es,int imax)
{
    int iter=0;
    double xl = 1;
    double xu = 1.5;
    
    cout<<"epsilon: ";
    cin>> es;
    cout<<"iteracion: ";
    cin>> imax;
    
    double fl,fr,xrold,xr,ea = 0.0,test;
    fl = (exp(-1*xl)-log(xl));
    do{
        xrold = xr;
        xr = (xl+xu)/2;
        fr = (exp(-1*xr)-log(xr));
        iter++;
        if(xr != 0)
        {
            ea= ((xr-xrold)/xr)*100;
            if(ea<0)
            {
                ea=ea*(-1);
            }
        }
        test = fl*fr;
        if(test < 0)
        {
            xu=xr;
        }else if(test > 0)
        {
            xl=xr;
            fl=fr;
        }else{
            
            ea=0;
        }
        
    }while(ea >es || iter < imax);
    return xr;
}

int main() {
    double bisec;
    
    bisec = bisect(.01, 5);
    cout<<bisec<<endl;
    return 0;
}