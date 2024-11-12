#include <iostream>

using namespace std;

template <typename T>

class NodeBT
{
private:
    T info;
    NodeBT *parent, *left, *right;
    string strGraphVizNode(NodeBT const *node) const; // Imprime as conex ões de um nodo com seus filhos em GraphViz
public:
    NodeBT(T const &i);
    ~NodeBT();
    T getInfo() const;
    void setInfo(T &i);
    NodeBT *getParent() const;

    NodeBT *getLeft() const;
    NodeBT *getRight() const;
    void setLeft(NodeBT *subtree);
    void setRight(NodeBT *subtree);
    void removeLeft();
    void removeRight();
    bool isRoot() const;
    bool isInternal() const;
    bool isExternal() const;
    int degree() const;
    int depth() const;
    int height() const;
    int size() const;
    bool contains(T &i) const;
    NodeBT const *find(T const &i) const;
    string strGraphViz() const;
    string preorder() const;
    string postorder() const;
    string inorder() const;
    string levelorder() const;
};

template <typename T>
NodeBT<T>::NodeBT(T const &i)
{
    parent = left = right = nullptr;
    info = i;
} // Cria um nodo com a informal ção i, e sem pai
template <typename T>
NodeBT<T>::~NodeBT()
{

} // Destr ói o nodo atual e seus descendentes
template <typename T>
T NodeBT<T>::getInfo() const
{
    return info;
} // Retorna a informa ção armazenada no nodo atual
template <typename T>
void NodeBT<T>::setInfo(T &i)
{   
    info = i;
} // Altera a informa ção armazenada no nodo atual
template <typename T>
NodeBT<T> *NodeBT<T>::getParent() const
{
    return parent;
} // Retorna a refer ê ncia para o nodo - pai do nodo atual
template <typename T>
NodeBT<T> *NodeBT<T>::getLeft() const
{
    return left;
} // Retorna a refer ê ncia para o nodo - fiho / sub á rvore da esquerda
template <typename T>
NodeBT<T> *NodeBT<T>::getRight() const
{
    return right;
} // Retorna a refer ê ncia para o nodo - fiho / sub á rvore da direita

template <typename T>
void NodeBT<T>::setLeft(NodeBT *subtree)
{
    if (left != nullptr)
        delete left;
    left = subtree;

} // Adiciona uma sub á rvore como subá rvore da esquerda do nodo atual

template <typename T>
void NodeBT<T>::setRight(NodeBT *subtree)
{
    if (right != nullptr)
        delete left;
    right = subtree;
} // Adiciona uma subá rvore como subá rvore da direita do nodo atual

template <typename T>
void NodeBT<T>::removeLeft()
{

} // Remove a sub á rvore da esquerda ( desalocando -a, se necess á rio )

template <typename T>
void NodeBT<T>::removeRight()
{

} // Remove a sub á rvore da direita ( desalocando -a, se necess á rio )

template <typename T>
bool NodeBT<T>::isRoot() const
{
    return false;
} // Retorna true se o nodo for raiz

template <typename T>
bool NodeBT<T>::isInternal() const
{
    return false;
} // Retorna true se o nodo for interno

template <typename T>
bool NodeBT<T>::isExternal() const
{
    return false;
} // Retorna true se o nodo for externo

template <typename T>
int NodeBT<T>::degree() const
{
    int filhos = 0;
    if (left != nullptr)
        filhos++;
    if (left != nullptr)
        filhos++;
    return filhos;
} // Retorna o grau (nú mero de filhos ) do nodo atual

template <typename T>
int NodeBT<T>::depth() const
{
    return 0;
} // Retorna o ní vel do nodo atual

template <typename T>
int NodeBT<T>::height() const
{
    in alt = 0;
    while(parent != nullptr){
        ++alt;
        parent = parent->parent;
    }
    return ;
} // Retorna a altura da subá rvore /á rvore a partir do nodo atual

template <typename T>
int NodeBT<T>::size() const
{
    int res = 1;
    if (left != nullptr)
        res += left.size();
    if (right != nullptr)
        res += right.size();
    return res;
} // V

template <typename T>
bool NodeBT<T>::contains(T &i) const
{
    return false;
} // Retorna true se o nodo atual ou algum de seus descendentes contivere i

template <typename T>
NodeBT<T> const *NodeBT<T>::find(T const &i) const
{
    return nullptr;
} // Retorna a refer ê ncia para o nodo , a partir do atual , que cont ém i ou nullptr

template <typename T>
string NodeBT<T>::strGraphViz() const
{
    return "";
} // Gera uma representa ção da á rvore a partir do nodo atual no formato GraphViz

template <typename T>
string NodeBT<T>::preorder() const
{
    return "";
} // Gera uma cadeia de caracteres (um nodo por linha ) em pré-ordem

template <typename T>
string NodeBT<T>::postorder() const
{
    return "";
} // Gera uma cadeia de caracteres (um nodo por linha ) em pós- ordem

template <typename T>
string NodeBT<T>::inorder() const
{
    return "";
} // Gera uma cadeia de caracteres (um nodo por linha ) em in - ordem

template <typename T>
string NodeBT<T>::levelorder() const
{
    return "";
} // Gera uma cadeia de caracteres (um nodo por linha ) em largura
