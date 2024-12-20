#include <iostream>
#include "BST.hpp"

int main()
{
    int vAdd[] = {8, 2, 10, 6, 5, 15, 7, 3, 20, 11};

    int tAdd = sizeof(vAdd) / sizeof(int);

    int vCnt[] = {1, 2, 0, 3, 4, 5, 21, 6, 22, 7, 23,
                  8, 9, 10, 24, 11, 12, 15, 16, 20, 25};

    int tCnt = sizeof(vCnt) / sizeof(int);

    BST<int> *bst = new BST<int>();

    for (int i = 0; i < tAdd; ++i)
        bst->add(vAdd[i]);

    cout << bst->strGraphViz();

    for (int i = 0; i < tCnt; ++i)
        if ((i % 2 == 0) == bst->contains(vCnt[i]))
            cout << " ERROR " << endl;

    delete bst;

    return 0;
}
