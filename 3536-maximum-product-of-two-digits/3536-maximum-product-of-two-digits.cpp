class Solution {
public:
    int maxProduct(int n) {

        string s = to_string(n);

        int largest = -1;;
        int secondlargest = -1;

        for(char i : s){
            int dig = i - '0';

            if(dig > largest){
                secondlargest = largest ;
                largest = dig;
            }else if( dig > secondlargest){
                secondlargest = dig;   
            }
        }

        return largest * secondlargest;
    }
};