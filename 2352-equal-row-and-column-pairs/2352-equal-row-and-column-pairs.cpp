class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> r;
        unordered_map<string,int> c;
        string row;
        string col;
        for(int i=0;i<grid.size();i++){
            row="*";
            col="*";
            for(int j =0;j<grid[0].size();j++){
                
                row+=to_string(grid[i][j])+"*";
                col+=to_string(grid[j][i])+"*";
                
            }
            cout<<"row: "<<row<<"\n";
            cout<<"col: "<<col<<"\n";
            r[row]++;
            c[col]++;
        }
        cout<<"\n\n";
        cout<<r.size()<<"\n";
        int count=0;
        for(auto i = r.begin();i!=r.end();i++){
            cout<<"to find: "<<i->first<<"\n";
            if(c.find(i->first)!=c.end()){
                cout<<"got it "<<"\n";
                int temp = i->second*c.find(i->first)->second;
                count=count+temp;
            }
        }
        return count;
    }
};