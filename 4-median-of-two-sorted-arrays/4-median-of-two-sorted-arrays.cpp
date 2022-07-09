class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        
        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int l = 0;
        int h = n1;
        while(l<=h){
            int cut1 = (l+h)/2;
            int cut2 = (n1+n2+1)/2-cut1;
            
            //cout<<"cut1: "<<cut1<<" cut2: "<<cut2<<"\n";
            
            int left1=(cut1==0)?INT_MIN:nums1[cut1-1];
            //cout<<"left1: "<<left1<<" ";
            int left2=(cut2==0)?INT_MIN:nums2[cut2-1];
            
            int right1=(cut1==n1)?INT_MAX:nums1[cut1];
            //cout<<"righ1: "<<right1<<"\n";
            int right2=(cut2==n2)?INT_MAX:nums2[cut2];
            
            if(left1<=right2 && left2<=right1){
                if((n1+n2)%2==0){
                    int num1= max(left1,left2);
                    int num2= min(right1,right2);
                    return (double)(num1+num2)/2;
                }
                else{
                    return max(left1,left2);
                }
                
            }
            else if(left1>right2){
                h=cut1-1;
            }
            else{
                l=cut1+1;
            }
        }
        return 0.0;
    }
};