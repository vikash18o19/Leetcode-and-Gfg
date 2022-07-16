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
        map<Node*,Node*> mp;
        queue<Node*> q;
        q.push(node);
        Node* shuru_vala;
        
        if(node==NULL){
            return NULL;
        }
        
        shuru_vala = new Node(node->val) ;
        mp[node]=shuru_vala;
        
        while(!q.empty()){
            
            Node* abhi_vala = q.front();
            q.pop();
            
            vector<Node*> v = abhi_vala->neighbors;
            
            int n = v.size();
            
            for(int i=0;i<n;i++){
                if(mp[v[i]]==NULL){
                    Node* naya;
                    naya = new Node(v[i]->val) ;
                    mp[v[i]]=naya;
                    q.push(v[i]);
                }
                mp[abhi_vala]->neighbors.push_back(mp[v[i]]);
            }
        }
        
        return mp[node];
    }
};