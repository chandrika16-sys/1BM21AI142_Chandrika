#include<iostream>

using namespace std;

class great{
public:

   int gcd(int a, int b){

if (b !=0 )
    return gcd(b,a%b);
else
    return a;
}
};

int main(){
 int a,b;

cout<<"Enter the two numbers:";
cin>>a>>b;
great GCD;
cout<< "The GCD of "<<a << " and " <<b << " is " << GCD.gcd(a,b);
return 0;

}
