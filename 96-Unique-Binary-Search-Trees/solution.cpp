class Solution {
public:
    unsigned long catalan(int n)
    {
        unsigned long save[n+1];
        save[0] = save[1] = 1;
        for (int i = 2; i <= n; i++)  
        {
            save[i] = 0;
            for (int j=0; j <= i-1; j++)
            {
                save[i] += save[j] * save[i-1-j];
            }
         }
         return save[n];
    }

    int numTrees(int n) {
        return catalan(n);

    }
};