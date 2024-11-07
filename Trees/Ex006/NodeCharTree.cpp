#include <iostream>
#include <sstream>
#include "NodeCharTree.hpp"

using namespace std;

NodeCharTree::NodeCharTree(T i)
{
    parent = nullptr;
    info = i;
}

NodeCharTree::~NodeCharTree()
{
    for (int i = 0; i < childs.size(); ++i)
        delete childs[i];
}

T NodeCharTree::getInfo() const
{
    return this->info;
}

void NodeCharTree::setInfo(char i)
{
    this->info = i;
}

NodeCharTree *NodeCharTree::getParent() const
{
    return this->parent;
}

NodeCharTree *NodeCharTree::getChild(int index) const
{
    if (index < 0 || index > childs.size())
        return nullptr;
    return childs[index];
}

bool NodeCharTree::isRoot() const
{
    return this->parent == nullptr;
}

bool NodeCharTree::isInternal() const
{
    if (this->parent != nullptr)
    {
        if (childs.size() != 0)
            return true;
    }
    return false;
}

bool NodeCharTree::isExternal() const
{
    return childs.size() == 0;
}

int NodeCharTree::degree() const
{
    return childs.size();
}

int NodeCharTree::depth() const
{
    int res = 0;
    NodeCharTree *pai = this->parent;
    while (pai != nullptr)
    {
        res++;
        pai = pai->parent;
    }
    return res;
}

int NodeCharTree::height() const
{
    int altura = 0;
    for (int i = 0; i < childs.size(); i++)
    {
        int altura_filhos = 1 + childs[i]->height();
        if (altura_filhos > altura)
            altura = altura_filhos;
    }
    return altura;
}

int NodeCharTree::size() const
{
    if (childs.size() == 0)
        return 0;
    int res = 1;
    for (int i = 0; i < childs.size(); i++)
        res += childs.size();
    return res;
}

void NodeCharTree::addSubtree(NodeCharTree *subtree)
{
    if (subtree == nullptr)
        return childs.push_back(subtree);
    subtree->parent = this;
}

bool NodeCharTree::removeSubtree(NodeCharTree *subtree)
{
    for (int i = 0; i < childs.size(); ++i)
        if (childs[i] == subtree)
        {
            childs.erase(childs.begin() + i);
            return true;
        }
    return false;
}

bool NodeCharTree::contains(char i) const
{
    if (info == i)
        return true;
    for (int j = 0; j < childs.size(); ++j)
        if (childs[j]->contains(i))
            return true;

    return false;
}

NodeCharTree* const NodeCharTree::find(char i) const
{
    if (this->info == i) return this;
    for (int j = 0; j < childs.size(); ++j)
    {
        NodeCharTree *child = childs[j]->find(i);
        if (child != nullptr) return child;
    }
    return nullptr;
}

string NodeCharTree::strGraphViz() const
{
    stringstream ss;
    ss << " graph \" Arvore Generica \" {" << endl
       << " Node [ shape = circle ]" << endl
       << "}" << endl;
    return ss.str();
}
string NodeCharTree::strGraphVizNode(NodeCharTree const *node) const
{
    stringstream ss;
    for (int i = 0; i < node->childs.size(); i++)
    {
        ss << " " << node->info << " -- " << node->childs[i]->info << endl
           << strGraphVizNode(node->childs[i]);
    }
    return ss.str();
}