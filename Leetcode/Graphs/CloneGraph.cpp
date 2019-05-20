// ALGORITHM: BFS SEEMS NATURAL HERE
// DO A BFS ON THE NODES AND STORE A HASH OF ORIGINAL NODE TO THE THE CLONE NODES
// WHEN WE POP A NODE FROM THE NODE 
// WE, AT THE SAME TIME POPULATE THE NEIGHBOURS OF THE CLONED NODE
// WE USE A MAP JUST TO TAKE CARE OF NOT DUPLICATING THE NODES
// https://www.youtube.com/watch?v=vma9tCQUXk8
// try to make the code faster
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> mp; // for storing nodes for edge relationship later
        map<Node*, bool> seen; // for original graph
        queue<Node*> que; // for original graph

        seen[node] = true; // for original graph
        que.push(node); // for original graph
        
        Node* newNode = new Node(); // create a new clone node for start node
        newNode->val = node->val; // set the value
        mp[node] = newNode; // map original graph to clone 
        
        while(que.size() != 0){
            Node* curNode = que.front(); 
            que.pop();
                                    
            vector<Node*> curAdjacent = curNode->neighbors; // original neighbors
            vector<Node*> cloneAdjacent; // cloned neighbours
            
            for(int i = 0; i < curAdjacent.size(); i++) {
                // process current node
                if(seen.count(curAdjacent[i]) == 0){
                    que.push(curAdjacent[i]);
                    seen[curAdjacent[i]] = true;
                } 
                
                // Map relationships ie populate the neighbours
                // don't worry when the original node gets to be processed we can then 
                // process the neighbours
                if(mp.count(curAdjacent[i]) == 0){ //if we didnt store the initial node
                    Node* temp = new Node(); //create a new node and give it a val
                    mp[curAdjacent[i]] = temp; ///
                    temp->val = curAdjacent[i]->val;
                    cloneAdjacent.push_back(temp);
                }else{
                    Node* temp = mp[curAdjacent[i]];
                    cloneAdjacent.push_back(temp);
                }
                
            } ///end for loop
            ///map the neighbours of the colde
            mp[curNode]->neighbors = cloneAdjacent;
         }
        return mp[node];
    }
};