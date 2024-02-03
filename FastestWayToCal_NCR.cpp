
#include <iostream>
using namespace std;


long long nCr(int &n,int &r){
        
        long long ans=1;
        // for will run till (n-r-1) so that (n-r)! and (n-r)! in denominator cancell out
        for(int i=0;i<r;i++){
            ans*=(n-i);
            ans/=(i+1);
        }
        return ans;
}


int main() {
   
   int n,r;
   cout<<"For nCr enter n: ";
   cin>>n;
   cout<<"For nCr enter r: ";
   cin>>r;
   long long ans=nCr(n,r);
   cout<<n<<"C"<<r<<"="<<ans<<endl;
   
   

    return 0;
}
