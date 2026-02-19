#include <bits/stdc++.h>
using namespace std;
int sumOfDigitsRec(int n){
    if(n == 0)
        return 0;
    return n % 10 + sumOfDigitsRec(n/10);
}

void rule6(){
    int divisor = 6, w = 6;
    cout << "\ti: "<<"\tSOD:" <<"\tDV: " << "\tRem" <<endl;
    for(int i=divisor;i<=100000;++i)
    {
        int sumOfdigits = sumOfDigitsRec(i);
        if(sumOfdigits%divisor == 0)
            cout <<setw(w)<<i << setw(w)<< sumOfdigits << setw(w)<< (sumOfdigits / divisor) << setw(w)<< (sumOfdigits%divisor) << endl;
    }
}

void rule9(){
    int divisor = 9, w = 6;
    cout << "\ti: "<<"\tSOD:" <<"\tDV: " << "\tRem" <<endl;
    for(int i=9;i<=100000;++i)
    {
        int sumOfdigits = sumOfDigitsRec(i);
        if(sumOfdigits%divisor == 0)
            cout <<setw(w)<<i << setw(w)<< sumOfdigits << setw(w)<< (sumOfdigits / divisor) << setw(w)<< (sumOfdigits%divisor) << endl;
    }

}

void rule(){
    int divisor = 6;
    for(int i=divisor;i<=1000000;++i){
        if(i%6 == 0)
            cout << "i: "<< i << " "<< i/6 << endl;
    }
}

int main()
{
    // rule9();
    // rule6();
    rule();
}