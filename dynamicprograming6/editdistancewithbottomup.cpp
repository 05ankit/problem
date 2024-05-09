class Solution {
private:
    int minimumdistance(string word1, string word2,int i,int j)
    {
        int dp[i+1][j+1];
        for(int a=0;a<=i;a++)
        {
            for(int b=0;b<=j;b++)
            {
                if(a==0)
                {
                    dp[a][b]=b;
                }
                else if(b==0)
                {
                    dp[a][b]=a;
                }
                else if(word1[a-1]==word2[b-1])
                {
                    dp[a][b]=dp[a-1][b-1];
                }
                else
                {
                    dp[a][b]=1+min(min(dp[a-1][b],dp[a-1][b-1]),dp[a][b-1]);
                }
            }
        }
        return dp[i][j];
        
    }
public:
    int minDistance(string word1, string word2) {

        int i=word1.length();
        int j=word2.length();

        return minimumdistance(word1,word2,i,j);
    }
};
