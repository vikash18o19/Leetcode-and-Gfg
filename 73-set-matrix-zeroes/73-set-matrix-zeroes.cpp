class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int first_row=false, first_col=false;  // storing the status of first row and collumn then use first column and row for hashing to store the status for column and rows respectively
        int r=matrix.size(), c=matrix[0].size();
        for(int i=0;i<r;i++)
            if(matrix[i][0]==0)
                first_row=true;
        for(int i=0;i<c;i++)
            if(matrix[0][i]==0)
                first_col=true;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0, matrix[0][j]=0;
                }
            }
        }
        
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if(matrix[0][j]==0 || matrix[i][0]==0)
                    matrix[i][j]=0;
            }
        }
        
        if(first_row)
        {
            for(int i=0;i<r;i++)
                matrix[i][0]=0;
        }
        
        if(first_col)
        {
            for(int i=0;i<c;i++)
                matrix[0][i]=0;
        }
    }
};