/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* cloneGraph(Node* node) {
        //cout<<"hello";
        map<Node*,Node*> mp;
        queue<Node*> q;
        q.push(node);
        Node* mera;
        if(node==NULL){
            return NULL;
        }
        mera = new Node(node->val) ;
        mp[node]=mera;
        
        while(!q.empty()){
            
            Node* cur = q.front();
            q.pop();
            
            vector<Node*> v = cur->neighbors;
            
            int n = v.size();
            
            for(int i=0;i<n;i++){
                if(mp[v[i]]==NULL){
                    Node* naya;
                    naya = new Node(v[i]->val) ;
                    mp[v[i]]=naya;
                    q.push(v[i]);
                }
                mp[cur]->neighbors.push_back(mp[v[i]]);
            }
        }
        
        return mp[node];
    }
};