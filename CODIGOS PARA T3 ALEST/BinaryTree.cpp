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
NodeBT::NodeBT(T const &i)
{

} // Cria um nodo com a informal ção i, e sem pai
template <typename T>
NodeBT::~NodeBT()
{

} // Destr ói o nodo atual e seus descendentes
template <typename T>
T NodeBT::getInfo() const
{
    return nullptr;
} // Retorna a informa ção armazenada no nodo atual
template <typename T>
void NodeBT::setInfo(T &i)
{

} // Altera a informa ção armazenada no nodo atual
template <typename T>
NodeBT *NodeBT::getParent() const
{
    return nullptr;
} // Retorna a refer ê ncia para o nodo - pai do nodo atual
template <typename T>
NodeBT *NodeBT::getLeft() const
{
    return nullptr;
} // Retorna a refer ê ncia para o nodo - fiho / sub á rvore da esquerda
template <typename T>
NodeBT *NodeBT::getRight() const
{
    return nullptr;
} // Retorna a refer ê ncia para o nodo - fiho / sub á rvore da direita

template <typename T>
void NodeBT::setLeft(NodeBT *subtree)
{

} // Adiciona uma sub á rvore como subá rvore da esquerda do nodo atual

template <typename T>
void NodeBT::setRight(NodeBT *subtree)
{

} // Adiciona uma subá rvore como subá rvore da direita do nodo atual

template <typename T>
void NodeBT::removeLeft()
{

} // Remove a sub á rvore da esquerda ( desalocando -a, se necess á rio )

template <typename T>
void NodeBT::removeRight()
{

} // Remove a sub á rvore da direita ( desalocando -a, se necess á rio )

template <typename T>
bool NodeBT::isRoot() const
{
    return false;
} // Retorna true se o nodo for raiz

template <typename T>
bool NodeBT::isInternal() const
{
    return false;
} // Retorna true se o nodo for interno

template <typename T>
bool NodeBT::isExternal() const
{
    return false;
} // Retorna true se o nodo for externo

template <typename T>
int NodeBT::degree() const
{
    return 0;
} // Retorna o grau (nú mero de filhos ) do nodo atual

template <typename T>
int NodeBT::depth() const
{
    return 0;
} // Retorna o ní vel do nodo atual

template <typename T>
int NodeBT::height() const
{
    return 0;
} // Retorna a altura da subá rvore /á rvore a partir do nodo atual

template <typename T>
int NodeBT::size() const
{
    return 0;
} // Retorna o nú mero de nodos a partir do nodo atual

template <typename T>
bool NodeBT::contains(T &i) const
{
    return false;
} // Retorna true se o nodo atual ou algum de seus descendentes contivere i

template <typename T>
NodeBT const *NodeBT::find(T const &i) const
{
    return nullptr;
} // Retorna a refer ê ncia para o nodo , a partir do atual , que cont ém i ou nullptr

template <typename T>
string NodeBT::strGraphViz() const
{
    return "";
} // Gera uma representa ção da á rvore a partir do nodo atual no formato GraphViz

template <typename T>
string NodeBT::preorder() const
{
    return "";
} // Gera uma cadeia de caracteres (um nodo por linha ) em pré-ordem

template <typename T>
string NodeBT::postorder() const
{
    return "";
} // Gera uma cadeia de caracteres (um nodo por linha ) em pós- ordem

template <typename T>
string NodeBT::inorder() const
{
    return "";
} // Gera uma cadeia de caracteres (um nodo por linha ) em in - ordem

template <typename T>
string NodeBT::levelorder() const
{
    return "";
} // Gera uma cadeia de caracteres (um nodo por linha ) em largura
