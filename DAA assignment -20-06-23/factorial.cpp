#include<iostream>

using namespace std;

class factorial{
public:
    int fact( int n){
    if(n==0)
        return 1;
    else
        return fact(n-1)*n;

    }
};

int main(){
int n;

cout<<"Enter the number:";
cin>>n;

factorial f;
cout<<"The factorial of "<<n<<" is:"<<f.fact(n);
return 0;

}
