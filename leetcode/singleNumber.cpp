class Solution {
    public:
        int singleNumber(int A[], int n) {
            int once = 0;
            int twice = 0;
            int three = 0;

            for(int i = 0; i < n; i ++){
                twice = twice | (once & A[i]);
                once = once ^ A[i];
                three = once & twice;
                once = once ^ three;
                twice = twice ^ three;
            }

            return once;
        }
};
