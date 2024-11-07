#include <iostream>
#include <string>
#include <sstream>

using namespace std;
template <namespace T>

struct Node
{
    T info;
    Node *left, *right, *parent;

    Node(T vinfo)
    {
        info = vinfo; left = right = parent = nullptr;
    }

    ~Node()
    {
        if (this->left != nullptr)
            delete left;
        if (this->right != nullptr)
            delete right;
    }

    bool isInternal(Node *v)
    {
        if (parent != nullptr && left != nullptr || right != nullptr) return true;
        return false;
    }

    bool isExeternal(Node *v)
    {
        if (parent != nullptr && left != nullptr || right != nullptr) return false;
        return true;
    }

    bool isRoot(Node *v)
    {
        if (parent != nullptr) return true;
        return false;
    }
};

class Tree
{
private:
    int num;
    Node * root; 
public:
    Tree()
    {
        root = nullptr;
        num = 0;
    }

    Node getRoot() { return root; }

    int size(Node *subtree)
    {
        if(subtree == nullptr) return 0;
        int res = 1 + size(subtree->left) + size(subtree->right);
        return res;
    }

    bool isEmpty()
    {
        if (num != 0) return false;
        return true;
    }

    int degree(Node *subtree)
    {
        if(subtree == nullptr) return -1;
        int filhos = 0;
        if(left != nullptr) filhos++; 
        if(right != nullptr) filhos++; 
        return filhos;
    }

    int depth(Node *subtree)
    {
        if(subtree == nullptr) return -1;
        int res = 0;
        Node *pai = subtree->parent;
        while(pai != nullptr){
            res++;
            pai = pai->parent;
        } 
        return res;
    }

    int height(Node *subtree)
    {
        if(subtree == nullptr) return -1;
        if(subtree->left == nullptr && subtree->right == nullptr) return 0;
        int altdir = 0;
        int altesq = 0;
        if(subtree->left != nullptr) return 1 + height (subtree->left);
        
        if(subtree->right != nullptr) return 1 + height (subtree->right);

        if(altdir > altesq) return altdir;
        
        return altesq;
    }

    string strNode(Node *Node)
    {
        stringstream ss;
        if (Node->left != nullptr)
            ss << " " << Node->info << " -- " << Node->left->info << endl
               << strNode(Node->left);
        if (Node->right != nullptr)
            ss << " " << Node->info << " -- " << Node->right->info << endl
               << strNode(Node->right);
        return ss.str();
    }

    string strGraphViz(Node *root)
    {
        stringstream ss;
        ss << " graph \" Arvore Binaria \" {" << endl
           << " Node [ shape = circle ]" << endl
           << strNode(root) << "}" << endl;
        return ss.str();
    }
};
