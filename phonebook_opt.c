#include <stdlib.h>

#include "phonebook_opt.h"


/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *pHead)
{
    /* TODO: implement */
    entry *pNode = pHead;
    while (pNode != NULL) {
        int k = strcasecmp(lastName, pNode->lastName);

        if(k > 0)
            pNode = pNode->pRight;
        else if(k < 0)
            pNode = pNode->pLeft;
        else
            return pNode;
    }
    return NULL;
}

entry *append(char lastName[], entry *root)
{
    if(root == NULL) {
        root = (entry*)malloc(sizeof(entry));
        strcpy(root->lastName, lastName);
        root->pLeft = root->pRight = NULL;
        root->parent = NULL;
        root->color = BLACK;
        return root;
    }

    entry *e = root;
    int k;

    while( e!= NULL) {
        k = strcasecmp(lastName, e->lastName);

        if(k > 0) {
            if(e->pRight != NULL)
                e = e->pRight;
            else {
                e->pRight = (entry *) malloc(sizeof(entry));
                e->pRight->parent = e;
                e = e->pRight;
                break;
            }
        } else if (k < 0) {
            if(e->pLeft != NULL)
                e = e->pLeft;
            else {
                e->pLeft = (entry *) malloc(sizeof(entry));
                e->pLeft->parent = e;
                e = e->pLeft;
                break;
            }
        } else
            return root;
    }
    strcpy(e->lastName, lastName);
    e->pLeft = e->pRight = NULL;
    e->color = RED;
    check(e);
    return root;
}

void check(entry *node)
{
    entry *father, *grandfather, *uncle;
    int cmp1, cmp2;
    father = node->parent;

    if(father->color == BLACK)
        return;

    grandfather = father->parent;
    if(father == grandfather->pLeft) {
        uncle = grandfather->pRight;
        cmp1 = 0;
    } else {
        uncle = grandfather->pLeft;
        cmp1 = 1;
    }

    if(node == father->pLeft)
        cmp2 = 0;
    else
        cmp2 = 1;

    if(uncle != NULL && uncle->color == RED) {
        father->color = BLACK;
        uncle->color = BLACK;
        grandfather->color = RED;
        check(grandfather);
    } else if(cmp1 == cmp2) {
        if(cmp1 == 0)
            right_rotate(father);
        else
            left_rotate(father);
        father->color = BLACK;
        grandfather->color = RED;
    } else {
        if(cmp1 == 0) {
            left_rotate(node);
            right_rotate(node);
        } else {
            right_rotate(node);
            left_rotate(node);
        }
        node->color = BLACK;
        grandfather->color = RED;
    }

}

void left_rotate(entry *e)
{
    entry *pivot = e->parent;

    if(e->pLeft != NULL) {
        e->pLeft->parent = pivot;
        pivot->pRight = e->pLeft;
    } else
        pivot->pRight = NULL;
    if(pivot->parent != NULL) {
        if(strcasecmp(pivot->lastName, pivot->parent->lastName) > 0) {
            pivot->parent->pRight = e;
            e->parent = pivot->parent;
        } else {
            pivot->parent->pLeft = e;
            e->parent = pivot->parent;
        }
    }
    pivot->parent = e;
    e->pLeft = pivot;
}
void right_rotate(entry *e)
{
    entry *pivot = e->parent;
    if(e->pRight != NULL) {
        e->pRight->parent = pivot;
        pivot->pLeft = e->pRight;
    } else
        pivot->pLeft = NULL;
    if(pivot->parent != NULL) {
        if(strcasecmp(pivot->lastName, pivot->parent->lastName) > 0) {
            pivot->parent->pRight = e;
            e->parent = pivot->parent;
        } else {
            pivot->parent->pLeft = e;
            e->parent = pivot->parent;
        }
    }
    pivot->parent = e;
    e->pRight = pivot;
}

entry *traceRoot(entry *node)
{
    if(node->parent != NULL)
        node = node->parent;

    return node;
}

















