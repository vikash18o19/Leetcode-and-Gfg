class Solution {
public:
    int bin(int l, int h, vector<vector<int>>& matrix, int target,
           int flag){
        if(flag==-1){
            
            int n  =matrix[0].size()-1;
            while(l<=h){
               
                int mid = l+(h-l)/2;
                
                if(matrix[mid][n]<=target){
                    
                    l=mid+1;
                }
                else{
                    
                    h=mid-1;
                }
            }
            if(h==-1) return h+1;
            if(matrix[h][n]<target) return h+1;
            
            return h;
        }
        else{
            while(l<=h){
                int mid = l+(h-l)/2;
                if(matrix[flag][mid]==target){
                    return mid;
                }
                else if(matrix[flag][mid]<target){
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }
            return -1;
        }
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //cout<<matrix[0][3];
        int ind = bin(0,matrix.size()-1,matrix,target,-1);
        if(ind==matrix.size()) return false;
        int ind1 = bin(0,matrix[0].size()-1,matrix,target,ind);
        if(ind1==-1){
            return false;
        }
        else{
            return true;
        }
    }
};