  // Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


float binaryExponentiation(float &base,int &exp){
    
    if(base==0 && exp==0){
        cout<<"Undefined behavior!"<<endl;
        return -404;
    }
    if(base==1 || exp==0) return 1;
    
    float res=1;
    while(exp>0){
        
        if(exp%2==1){
            res*=base;
            exp--;
        }
        
        base=base*base;
        exp=exp>>1;
    }
    return res;
}

int main() {
  
  float base;
  int exp;
  
  
  cout<<"Enter base and exponent for base^exp: "<<endl;
  cin>>base>>exp;
    float b_cpy=base;
  int e_cpy=exp;
  float ans = binaryExponentiation(base,exp);
  cout<<b_cpy<<"^"<<e_cpy<<" = "<<ans<<endl;
  

    return 0;
}
