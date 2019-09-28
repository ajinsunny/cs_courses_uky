/**** CS 216 - 002 Programming Assingment ****  
 * File:   parsetree.h
 * Author: Ajin Sunny
 *
 * Created on April 18, 2015, 10:10 PM
 *
 *
 */

#ifndef PARSETREE_H
#define	PARSETREE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TreeNode
{
    private:
        string key;
        TreeNode *leftChild, *rightChild;
    public:
        TreeNode(string k) {key = k; leftChild = rightChild = NULL;}
        friend class ParseTree;
};

const string PLUS = "+";
const string MINUS = "-";
const string MULTIPLY = "*";
const string DIVIDE = "/";
const string OPENBRACE = "(";
const string CLOSEBRACE = ")";
const int FORMAT_WIDTH = 3;  // It is for the display of a tree structure: the width of each operand

class ParseTree
{
    private:
        TreeNode* root;	        // points to the root of the tree
        vector<string> vect;
        string postExp;

    public:
        ParseTree();			//constructor
        ParseTree(string key);
        ~ParseTree();			//destructor
        void buildTree(string E);
        TreeNode* build(vector<string> E, int left, int right);
        int getHeight();
        void prefix (TreeNode* localRoot);
        void infix (TreeNode* localRoot);
        void postfix (TreeNode* localRoot);
        void tree_traverse(int traversetype); 
        string  getEval();
        string getPostExp();
        void resetPostExp();

        // ------------------------------------------
        void destroy(TreeNode* T);
        int height(TreeNode* T);
};


#endif	/* PARSETREE_H */

