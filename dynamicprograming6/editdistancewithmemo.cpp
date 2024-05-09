class Solution {
private:
    int minimumdistance(string word1, string word2,int i,int j,vector<vector<int>> &memo)
    {
        if(j<0)
        {
            return i+1;
        }
        if(i<0)
        {
            return j+1;
        }
        if(memo[i][j]!=-1)
        {
            return memo[i][j];
        }
        if(word1[i]==word2[j])
        {
            return memo[i][j]=minimumdistance(word1,word2,i-1,j-1,memo);
        }
        else
        {
            int replace=minimumdistance(word1,word2,i-1,j-1,memo);
            int remove=minimumdistance(word1,word2,i-1,j,memo);
            int add=minimumdistance(word1,word2,i,j-1,memo);
            return memo[i][j]=1+min(min(replace,remove),add);
        }
       
    }
public:
    int minDistance(string word1, string word2) {

        int i=word1.length();
        int j=word2.length();
        vector<vector<int>> memo(i+1,vector<int>(j+1,-1));

        return minimumdistance(word1,word2,i,j,memo);
    }
};
