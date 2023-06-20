#include<iostream>

using namespace std;

class fibbonaci{
public:
    int fib(int x){
    if(x==1)
        return 1;
      else if(x==2)
        return 1;
      else
        return fib(x-1)+fib(x-2);

    }
};


int main(){
int n;

cout<<"Enter the number:";
cin>>n;
fibbonaci f;
for(int i=1;i<=n;i++)
{
    cout<<f.fib(i)<<" ";
}
return 0;
}

