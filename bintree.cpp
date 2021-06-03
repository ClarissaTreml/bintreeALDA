//
//  sort.cpp
//  ALDA_Exercise5v12021_Solution
//
//  Created by Michael Strommer on 17.05.21.
//

#include "bintree.hpp"


binTree *t_init(){
    binTree *tmp = (binTree *)malloc(sizeof(binTree));
    tmp->root = NULL;
    tmp->size = 0;
    return tmp;
}

node *insertNode(node *start, int key, const char *data){
    node * newNode;

    if (start == NULL){
        newNode = (node *) malloc(sizeof(node));
        if (newNode != NULL){
            newNode->data = (char *) data;
            newNode->key = key;
            newNode->right = newNode->left = NULL;
        }
        return newNode;
    }

    if (key < start->key){

        newNode = insertNode(start->left, key, data);
        if (start->left == NULL)
        {
            start->left = newNode;
        }
    }
    else{

        newNode = insertNode(start->right, key, data);
        if (start->right == NULL){
            start->right = newNode;
        }
    }
    return newNode;
}

node *insert(binTree *t, int key, const char *data){
    node * newNode;
    newNode = insertNode(t->root, key, data);

    if (t->root == NULL) t->root = newNode;
    if (newNode != NULL) t->size++;

    return newNode;
}

int evaluateExpression(node *start){



    switch (start->data[0]) {

        case '+':
            if (start->left == NULL){
                return evaluateExpression(start->right);
            }
            else return evaluateExpression(start->left) + evaluateExpression(start->right);

        case '-':
            if (start->left == NULL){
                return -(evaluateExpression(start->right));
            }
            /*else if(start->left < start->right){
                return evaluateExpression(start->right) - evaluateExpression(start->left);
            }*/
            else return evaluateExpression(start->left) - evaluateExpression(start->right);

        case '/':
            return evaluateExpression(start->left) / evaluateExpression(start->right);

        case '*':
            return evaluateExpression(start->left) * evaluateExpression(start->right);

        default:return atoi(start->data);
    }
}
