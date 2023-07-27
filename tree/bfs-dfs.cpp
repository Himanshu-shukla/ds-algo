#include <iostream>
#include <vector>
#include <queue>
#include <stack>

// Tree Node class to represent a node in the tree
class TreeNode {
public:
    int data;
    std::vector<TreeNode*> children;

    TreeNode(int value) : data(value) {}
};

// Tree class to represent a tree
class Tree {
private:
    TreeNode* root;

public:
    Tree(int value) {
        root = new TreeNode(value);
    }

    // Function to add a child to a node
    TreeNode* addChild(TreeNode* parent, int value) {
        TreeNode* newNode = new TreeNode(value);
        parent->children.push_back(newNode);
        return newNode;
    }

    // Function to get the root node
    TreeNode* getRoot() const {
        return root;
    }

    // Breadth-First Search
    void BFS() {
        if (root == nullptr)
            return;

        std::queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            TreeNode* currentNode = queue.front();
            queue.pop();

            std::cout << currentNode->data << " ";

            for (TreeNode* child : currentNode->children) {
                queue.push(child);
            }
        }

        std::cout << std::endl;
    }

    // Depth-First Search (Helper function for recursive DFS)
    void DFS(TreeNode* node, std::vector<bool>& visited) {
        if (node == nullptr)
            return;

        std::cout << node->data << " ";
        visited[node->data] = true;

        for (TreeNode* child : node->children) {
            if (!visited[child->data]) {
                DFS(child, visited);
            }
        }
    }

    // Depth-First Search (Wrapper function)
    void DFS() {
        if (root == nullptr)
            return;

        std::vector<bool> visited(100, false); // Assuming values in the tree are less than 100
        DFS(root, visited);

        std::cout << std::endl;
    }
};

int main() {
    Tree tree(1);

    TreeNode* node2 = tree.addChild(tree.getRoot(), 2);
    TreeNode* node3 = tree.addChild(tree.getRoot(), 3);
    TreeNode* node4 = tree.addChild(tree.getRoot(), 4);
    TreeNode* node5 = tree.addChild(node2, 5);
    TreeNode* node6 = tree.addChild(node2, 6);

    std::cout << "BFS Traversal: ";
    tree.BFS();

    std::cout << "DFS Traversal: ";
    tree.DFS();

    return 0;
}
