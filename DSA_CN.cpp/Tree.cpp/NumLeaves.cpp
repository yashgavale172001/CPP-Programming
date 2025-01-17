#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

//#include "solution.h"

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}
int getLeafNodeCount(TreeNode<int>* root) 
{
    // Write your code here
    if(root==NULL)
    {
        return 0;
    }
    queue<TreeNode<int>*>queue;
    queue.push(root);
    int leaf=0;
    while(queue.size()!=0)
    {
        TreeNode<int>*front=queue.front();
        queue.pop();
        if(front->children.size()==0)
        {
           leaf++;
        }
        for(int i=0;i<front->children.size();i++)
        {
            queue.push(front->children[i]);
        }
    }
    return leaf;

}
int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout << getLeafNodeCount(root);
}