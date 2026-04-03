class Solution {
public:
    int countPrimes(int n) {
        // sieve of eratosthenes
        int count = 0;
        vector<bool> isPrime(n+1, true); // vector size: 0 to n
        for(int i=2; i<n; i++) {
            if(isPrime[i]) {
                count++;
                for(int j=i*2; j<n; j=j+i) {
                    isPrime[j] = false;
                }
            }
        }
        return count;
    }
};