#include <stdlib.h>

#include "phonebook_opt.h"

#define BLACK 1
#define RED 0

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastname[], entry *pHead)
{
    /* TODO: implement */
    entry *pNode = pHead;
    while (pNode != NULL) {
    int case = strcasecmp(lastName, pNode->lastName);

    if(case > 0)
                pNode = pNode->pRight;
    else if(case < 0)
                pNode = pNode->pLeft;
        else
            return pNode;
    }
    return NULL;
}

entry *append(char lastName[], entry *root)
{
    if(root = NULL) {
        root = (entry*)malloc(sizeof(entry));
        strcpy(root->lastName, lastName);
        root->pLeft = root->pRight = NULL;
        root->color = BLACK;
        return root;
    }

    entry *e = root;
    while( e!= NULL) {
    int case = strcasecmp(lastName, e->lastName);

    if(case > 0) {
                if(e->pRight != NULL)
                    e = e->pRignt;
                else {
                    e->pRight = (entry *) malloc(sizeof(entry));
                    e = e->pRight;
                    strcpy(e->lastName, lastName);
                    e->pRight = e->pLeft = NULL;
                    e->color = RED;
                }
            }
    else if (case < 0) {
                if(e->pLeft != NULL)
                    e = e->pLeft;
                else {
                    e->pLeft = (entry *) malloc(sizeof(entry));
                    e = e->pLeft;
                    stycpy(e->lastName, lastName);
                    e->pRight = e->pLeft = NULL;
                    e->color = RED;
                }
            }
        else
            return root;
    }
    return NULL;
}
