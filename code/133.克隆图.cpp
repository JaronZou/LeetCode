/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
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
    // BFS
    // Node* cloneGraph(Node* node) {
    //     if(node == nullptr) {
    //         return node;
    //     }
    //     queue<Node*> nodeQue;
    //     unordered_map<Node*, Node*> nodeMap;
    //     nodeQue.push(node);
    //     nodeMap[node] = new Node(node->val);
    //     while(!nodeQue.empty()) {
    //         Node *curNode = nodeQue.front();
    //         nodeQue.pop();
    //         Node *newNode = nodeMap[curNode];
    //         for(auto &n : curNode->neighbors) {
    //             // 没入过队的结点入队并新建结点
    //             if(nodeMap.count(n) == 0) {
    //                 nodeQue.push(n);
    //                 nodeMap[n] = new Node(n->val);
    //             }
    //             newNode->neighbors.push_back(nodeMap[n]);
    //         }
    //     }
    //     return nodeMap[node];
    // }


    // DFS
    unordered_map<Node*, Node*> nodeMap;
    Node* cloneGraph(Node* node) {
        if(node == nullptr) {
            return nullptr;
        }
        if(nodeMap.count(node) != 0) {
            return nodeMap[node];
        }
        nodeMap[node] = new Node(node->val);
        Node *newNode = nodeMap[node];
        for(auto &n : node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(n));
        }
        return nodeMap[node];
    }
};
// @lc code=end

