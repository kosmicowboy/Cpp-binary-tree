//
// Created by kyle gray on 7/25/16.
//

#ifndef BINARYTREE_BTREE_H
#define BINARYTREE_BTREE_H

template<typename T>
class BTree {
public:
    BTree() { };
    virtual ~BTree() { };
    void insert(T);
private:
    template<typename T>
    class Node {
    public:
        Node(T s) : m_data(s) {}
        T m_data;
        Node<T>* pLeft = nullptr;
        Node<T>* pRight = nullptr;
    };
    Node<T>* pRoot = nullptr;
};

template<typename T>
inline void
BTree<T>::insert( T insertee ) {
    Node<T>* pLoc = nullptr;
    Node<T>* pParent = nullptr;
    Node<T>* pRoot = nullptr;
    bool found = false;

    // dive into tree
    // look to see if any node contains the insertee

    while ( !found && pLoc != nullptr ) {
        pParent = pLoc;
        if ( insertee < pLoc->m_data ) {
            pLoc = pLoc->pLeft;
        } else
        if ( insertee > pLoc->m_data) {
            pLoc = pLoc->pRight;
        }else {
            found = true;
        }
    }

    if (!found ) { //insert
        pLoc = new BTree<T>::Node(insertee);
        if (pParent == 0) {
            pRoot = pLoc;
        }
        else if (insertee < pParent->m_data) {
            pParent->pLeft = pLoc;
        }
    }
}





#endif //BINARYTREE_BTREE_H
