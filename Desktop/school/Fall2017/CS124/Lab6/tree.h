#ifndef _TREE_H_
#define _TREE_H_

struct TREENODE {
    SOMETYPE data;
    TREENODE *left;
    TREENODE *right;
};

void Destroy(TREENODE *root);
//TREENODE *Find(TREENODE *root, const SOMETYPE data);
//STATUS Insert(TREENODE &root, const SOMETYPE data);
//STATUS Remove(TREENODE &root, const SOMETYPE data);

extern int Compare(const SOMETYPE data1, const SOMETYPE data2);
extern void Copy(const SOMETYPE data1, SOMETYPE data2);

#endif
