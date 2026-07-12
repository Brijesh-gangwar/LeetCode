class Solution {
public:

double power(double a , int b){
    if(b==-1) return 1/a;

    if(b == 0) return 1;
    
    if( b == 1) return a;
    
    double ans = power(a , b/2);
        
    if(b%2 == 0)
        return ans * ans;
        
    else{
ans =   b <  0 ?  ans * ans * (1 / a) :  ans * ans * a;
return ans;
    }
      
  
    
}
    double myPow(double x, int n) {
        return power(x , n);
    }
};