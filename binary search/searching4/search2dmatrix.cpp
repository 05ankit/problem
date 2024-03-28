class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int key) {
     int s=0,e=matrix.size()-1;
       int low=0,high=matrix[0].size()-1;
     while(s<e)
     {
        int mid=(s+e)/2;
        if(matrix[mid][0]==key)
        return true;
        else if(key>matrix[mid][0])
        {
           if(key<=matrix[mid][high])
           {
            s=mid;
            e=mid;
           }
           else
           s=mid+1;
        }
     
        else
        e=mid-1;
     }
   
     while(low<=high)
     {
        int mid=low+(high-low)/2;
        if(matrix[s][mid]==key)
        {
        return true;
        }
        else if(matrix[s][mid]>key)
        {
        high=mid-1;
        }
        else
        {
        low=mid+1;
        }
     }
return false;    
    }
};
