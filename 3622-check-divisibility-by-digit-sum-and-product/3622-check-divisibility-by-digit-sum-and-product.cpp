class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;

        int num = n;
        while(num){
            int dig = num % 10;

            sum += dig;
            prod*= dig;

            num/=10;
        }

        int total = sum + prod;

        if(n % total == 0) return true;
        return false;
    }
};