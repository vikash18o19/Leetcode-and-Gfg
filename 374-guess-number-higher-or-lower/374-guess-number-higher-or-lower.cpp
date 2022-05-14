/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int start=1,end=n;
        int ans;
        while(start<=end){
            int mid = start+(end-start)/2;
            int check=guess(mid);
            if(check==-1){
                end=mid-1;
            }
            else if(check==1){
                start=mid+1;
            }
            else if(check==0){
                ans=mid;
                break;
            }
        }
        return ans;
    }
};