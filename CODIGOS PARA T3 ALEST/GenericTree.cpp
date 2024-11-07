#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <typename T>
class Tree
{
private:
    T info;
    Tree *parent;
    vector<Tree *> children;
    string strGraphVizNode(Tree const *nodo) const;

public:
    Tree(T &data);
    ~Tree();
    T getInfo() const;
    void setInfo(T &data);
    Tree *getParent() const;
    Tree *getChild(int index) const;
    bool isRoot() const;
    bool isInternal() const;
    bool isExternal() const;
    int degree() const;
    int depth() const;
    int height() const;
    int size() const;
    void addSubtree(Tree *subtree);
    bool removeSubtree(Tree *subtree);
    bool contains(T &data) const;
    Tree const *find(T const &data) const;
    string strGraphViz() const;
    string preorder() const;
    string postorder() const;
    string levelorder() const;
};

template <typename T>
Tree<T>::Tree(T &data)
{
    info = data;
    parent = nullptr;
}

template <typename T>
Tree<T>::~Tree()
{
    for (int i = 0; i < children.size(); ++i)
        delete children[i];
}

template <typename T>
T Tree<T>::getInfo() const
{
    return info;
}

template <typename T>
void Tree<T>::setInfo(T &data)
{
    info = data;
}

template <typename T>
Tree<T> *Tree<T>::getParent() const
{
    return parent;
}

template <typename T>
Tree<T> *Tree<T>::getChild(int index) const
{
    if (index < 0 || index >= children.size())
        return nullptr;
    return children[index];
}

template <typename T>
bool Tree<T>::isRoot() const
{
    return parent == nullptr;
}

template <typename T>
bool Tree<T>::isInternal() const
{
    if (parent != nullptr && children.size() != 0)
        return true;
    return false;
}

template <typename T>
bool Tree<T>::isExternal() const
{
    return children.size() == 0;
}

template <typename T>
int Tree<T>::degree() const
{
    return children.size();
}

template <typename T>
int Tree<T>::depth() const
{
    int count = 0;
    Tree *aux = parent;
    while (aux != nullptr)
    {
        aux = aux->parent;
        count++;
    }
    return count;
}

template <typename T>
int Tree<T>::height() const
{
    int count = 0;
    for (int i = 0; i < children.size(); ++i)
    {
        int altura = 1 + children[i]->height();
        if (altura > count)
            count = altura;
    }
    return count;
}

template <typename T>
int Tree<T>::size() const
{
    int count = 1;
    for (int i = 0; i < children.size(); ++i)
    {
        count += children[i]->size();
    }
    return count;
}

template <typename T>
void Tree<T>::addSubtree(Tree *subtree)
{
    if (subtree == nullptr)
        return;
    children.push_back(subtree);
    subtree->parent = this;
}

template <typename T>
bool Tree<T>::removeSubtree(Tree *subtree)
{
    for (int i = 0; i < children.size(); ++i)
    {
        if (children[i] == subtree)
        {
            children.erase(children.begin() + i);
            return true;
        }
    }
    return false;
}

template <typename T>
bool Tree<T>::contains(T &data) const
{
    if (info == data)
        return true;
    for (int i = 0; i < children.size(); ++i)
    {
        if (children[i]->contains(i))
            return true;
    }
    return false;
}

template <typename T>
Tree<T> const *Tree<T>::find(T const &data) const
{
    if (info == data)
        return this;
    for (int i = 0; i < children.size(); ++i)
    {
        Tree const *child = children[i]->find(i);
        if (child != nullptr)
            return child;
    }
    return nullptr;
}

template <typename T>
string Tree<T>::strGraphVizNode(Tree const *node) const
{
    stringstream ss;
    for (int i = 0; i < node->children.size(); ++i)
    {
        ss << " " << node->info << " -- " << node->children[i]->info << endl;
        ss << strGraphVizNode(node->children[i]);
    }
    return ss.str();
}

template <typename T>
string Tree<T>::strGraphViz() const
{
    stringstream ss;
    ss << " Arvore {" << endl
       << " nodo [ shape = circle ]" << endl;
    ss << strGraphVizNode(this) << "}" << endl;
    return ss.str();
}

template <typename T>
string Tree<T>::preorder() const
{
    stringstream ss;
    ss << info << endl;
    for (int i = 0; i < children.size(); ++i)
    {
        ss << children[i]->preorder();
    }
    return ss.str();
}

template <typename T>
string Tree<T>::postorder() const
{
    stringstream ss;
    for (int i = 0; i < children.size(); ++i)
    {
        ss << children[i]->postorder();
    }
    ss << info << endl;
    return ss.str();
}

template <typename T>
string Tree<T>::levelorder() const
{
    stringstream ss;
    vector<const Tree *> queue; // cria um vector do tipo ponteiro para arvore (classe)
   
    queue.push_back(this);      // coloca a raiz no vector

    while (!queue.empty())
    { // enquanto tiver algum elemento

        const Tree *aux = queue[0];   // ponetiro para primeiro elemento (raiz)
        ss << aux->getInfo() << endl; // coloca a informacao na string

        queue.erase(queue.begin()); // retira o primeiro elemento

        for (int i = 0; i < aux->degree(); ++i) // loop para a quantidade de filhos
        {
            queue.push_back(aux->getChild(i)); // coloca na fila o filho na fila
        }
    }
    return ss.str();
}
