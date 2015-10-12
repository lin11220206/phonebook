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

		if(k > 0)
		{
			if(e->pRight != NULL)
				e = e->pRight;
			else
			{
				e->pRight = (entry *) malloc(sizeof(entry));
				e->pRight->parent = e;
				e = e->pRight;
				break;
			}
		}
	    else if (k < 0)
		{
			if(e->pLeft != NULL)
				e = e->pLeft;
			else
			{
				e->pLeft = (entry *) malloc(sizeof(entry));
				e->pLeft->parent = e;
				e = e->pLeft;
				break;
			}
		}
        else
            return root;
    }
	strcpy(e->lastName, lastName);
	e->pLeft = e->pRight = NULL;
	e->color = RED;
    return root;
}
