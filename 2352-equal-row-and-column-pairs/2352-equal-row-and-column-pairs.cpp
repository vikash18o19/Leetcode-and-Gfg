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
            r[row]++;
            c[col]++;
        }
        int count=0;
        for(auto i = r.begin();i!=r.end();i++){
            if(c.find(i->first)!=c.end()){
                int temp = i->second*c.find(i->first)->second;
                count=count+temp;
            }
        }
        return count;
    }
};