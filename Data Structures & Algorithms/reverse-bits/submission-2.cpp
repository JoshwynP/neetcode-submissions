class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        // takes in 32 bit number
        // returns n_rev
        // Loop through all 32 bits and bit shift n_rev left 
        // according to the bit shifted off of n

        int n_rev = 0;

        for (int i = 0; i < 32; i++)
        {
            int b = n & 1;
            n_rev = (n_rev << 1) + b;

            n = n >> 1;
        }

        return n_rev;
    }
};
