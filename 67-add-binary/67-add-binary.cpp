class Solution {
public:
    string addBinary(string a, string b) {
        stack<char> st;
        int n1 = a.size();
        int n2 = b.size();
        int carry = 0;
        int i = n1-1;
        int j = n2-1;
        while(i>=0 || j>=0){
            char cur_a = (i>=0)?a[i]:'0';
            char cur_b = (j>=0)?b[j]:'0';
            //cout<<" char a :"<<cur_a<<" char b : "<<cur_b<<" carry: "<<carry <<" result: "<<" ";
            if(carry==0){ 
                if(cur_a == '1' && cur_b=='1'){
                    //cout<<0<<"\n";
                    st.push('0');
                    carry=1;
                }
                else if(cur_a == '0' && cur_b=='0'){
                    st.push('0');
                }
                else{
                    //cout<<1<<"\n";
                    st.push('1');
                }
            }
            else{
                if(cur_a == '1' && cur_b=='1'){
                    //cout<<1<<"\n";
                    st.push('1');
                }
                else if(cur_a == '1' || cur_b=='1'){
                    //cout<<0<<"\n";
                    st.push('0');
                }
                else{
                    //cout<<1<<"\n";
                    st.push('1');
                    carry=0;
                }
            }
            i--;
            j--;
        }
        if(carry==1){
            st.push('1');
        }
        //cout<<st.size();
        string temp = "";
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        return temp;
    }
};