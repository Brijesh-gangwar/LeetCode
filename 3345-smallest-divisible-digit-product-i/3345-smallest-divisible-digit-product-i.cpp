class Solution {
public:
    int smallestNumber(int n, int t) {
        int i = n;

        while(true){
            int num = i;
            int prod = 1;

            while(num){
                int dig = num % 10;
                num = num / 10;

                prod = prod * dig;

                if(prod % t == 0) return i;
            }

            i++;
        }
    }
};