#ifndef PETTREE_H_
#define PETTREE_H_

#include <stdbool.h>

#define STRLEN 30


typedef struct pet
{
    char type[STRLEN];
    char name[STRLEN];
    struct pet * next;
} Pet;

typedef Pet * List;

typedef struct node
{
    char name[STRLEN];
    List head;
    struct node * left;
    struct node * right;
} Node;

typedef Node * Tree;

Tree * InitializeTree(Tree * ptree);


bool TreeIsEmpty(const Tree * ptree);

bool TreeIsFull(const Tree * ptree);

bool AddPet(Pet * ppet, Tree * ptree);

bool DeletePet(Pet * ppet, Tree * ptree);

bool InTree(Pet * ppet, const Tree * ptree);

int TreeItemCount(Tree tree);

void TraverseTree(const Tree * ptree, void (*fn)(Pet));

void ApplyToNode(Pet * ppet, const Tree * ptree, void (*fn)(Pet));

void DeleteAll(Tree * ptree);

#endif
