
class Solution {
public:
    int hammingWeight(int n) {

        //method1----o(log n) base 2 time & o(1) space
        int HammingWeight=0;
        while(n)
        {
            int rem = n%2;
            if(rem==1)
            HammingW+=rem;
            n/=2;
        }
        return HammingW;

    //method2 ----o(1) time and o(1) space
    //built-in function (hardware optimised)
      return __builtin_popcount(n);


    //method3---o(32bits)=o(1) time and o(1) space 
    if(n==0)
    return 0;
    int res=0;
    while(n>0)
    {
        res+=n&1;
        n=n>>1;
    }
    return res;

    
    //method4----o(number of 1 bits) time and o(1) space
    int count=0;
    while(n)
    {
        count++;
        n=n&(n-1); //every time removes 1 set bit
    }
    return count;
    }
};