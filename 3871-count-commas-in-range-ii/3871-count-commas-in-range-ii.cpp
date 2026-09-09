
class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0;

        // 1 , 10^3 , 10^6 , 10^9 , 10^12 , 10^15
        long long range = 1000;
        int i = 1;

        while (range <= n && range <= 1000000000000000LL) {
            long long nextRange = range * 1000;

            if (nextRange > n) {
                count += i * (n - range + 1);
                break;
            }

            count += i * (nextRange - range);
            i++;
            range = nextRange;
        }

        return count;
    }
};

