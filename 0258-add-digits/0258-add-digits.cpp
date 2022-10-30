class Solution {
public:
    int solve(int num){
        if(num<=9){
            return num;
        }
        int sum=0;
        int temp =num;
        while(temp!=0){
            int x = temp%10;
            sum=sum+x;
            temp=temp/10;
        }
        return solve(sum);
    }
    int addDigits(int num) {
        return solve(num);
    }
};