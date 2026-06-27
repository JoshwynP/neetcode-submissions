class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int res = 0;

        for (int i = 0; i < 32; i++)
        {
            int a_bit = a & 1;
            int b_bit = b & 1;

            if (a_bit == b_bit && a_bit == 1) // both equal 1
            {
                if (carry)
                {
                    res = res + (1 << i);
                }
                carry = 1;
            }
            else if (a_bit != b_bit) // one equals 1
            {
                if (!carry)
                {
                    res = res + (1 << i);
                }
            }
            else
            {
                if (carry)
                {
                    res = res + (1 << i);
                    carry = 0;
                }
            }

            a = a >> 1;
            b = b >> 1;
        }

        return res;
    }
};
