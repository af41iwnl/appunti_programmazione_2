#ifndef TREE_H
#define TREE_H

#include "type.h"

struct node {
    tipo_inf inf;
    node* parent;
    node* first_child;
    node* next_sibling;
};

typedef node* tree;

/**
 * @brief create a new node with inf as information field and return it
 * 
 * @param inf information field of the new node
 * @return node* freshly built node
 */
node* new_node(const tipo_inf inf);

/**
 * @brief add t subtree to p as the first child
 * 
 * @param p parent tree
 * @param c child tree
 */
void insert_child(tree p, tree c);

/**
 * @brief add a sibling to n node
 * 
 * @param n node where the function inserts t
 * @param t subtree to be added
 */
void insert_sibling(node* n, tree t);

#endif  // TREE_H