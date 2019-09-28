/* 
 * File:   parsetree.cpp
 * Author: Ajin Sunny
 *
 * Created on April 18, 2015, 10:14 PM
 */
#include <sstream>
#include <queue>
#include <cmath>
#include <iomanip>
#include "parsetree.h"
#include <vector>
#include <cctype>

using namespace std;

// default constructor
ParseTree::ParseTree()
{
    root = NULL;
}

// recursive function to delete(free) tree node
// starting from the node pointed by T
void ParseTree::destroy(TreeNode* T)
{
    if  (T != NULL)    
    {    
        destroy(T->leftChild) ;
        destroy(T->rightChild) ;

        delete  T ;
    }
}

// destructor
// by calling destory function to free each node of the tree
// starting from the root node
ParseTree::~ParseTree()
{
    destroy(root);
}

// calculate the height of tree (tree levels)
// an empty tree has zero height
// The height of the tree is the number of nodes at the longest path
// from the root node to the leaf node
int ParseTree::height(TreeNode* T) 
{
    int hh = 0;
    int lh, rh;
    if (T == NULL) return hh;
    if ((T->leftChild == NULL) && (T->rightChild == NULL)) return (hh++);
    lh = height(T->leftChild);
    rh = height(T->rightChild);
    if (lh >= rh)
        hh = lh + 1;
    else
        hh = rh + 1;
    return hh;
}

// return the height of the parse tree
int ParseTree::getHeight()
{
    if (root == NULL)
        return 0;
    else
        return (height(root));
}

int findMultDiv(vector<string> E, int left, int right)
{
    int parenCnt = 0;
    int loc = right;

    //traverse string vector backwards
    while (loc >= left)
    {
        if (E[loc] == ")")
        {
            parenCnt++;
        }
        else if (E[loc] == "(")
        {
            parenCnt--;
        }
        else if (E[loc] == "*" || E[loc] == "/")
        {
            if (parenCnt == 0) //must have balanced parenthesis
            {
                return loc;
            }
        }
        loc--; //move to next index
    }
    return -1; //no * or / found
}

int findPlusMinus(vector<string> E, int left, int right)
{
    int parenCnt = 0;
    int loc = right;

    //traverse string vector backwards
    while (loc >= left)
    {
        if (E[loc] == ")")
        {
            parenCnt++;
        }
        else if (E[loc] == "(")
        {
            parenCnt--;
        }
        else if (E[loc] == "+" || E[loc] == "-")
        {
            if (parenCnt == 0) //must have balanced parenthesis
            {
                return loc;
            }
        }
        loc--; //move to next index
    }
    return -1; //no + or - found
}




// to build the parse tree from an infix expression
TreeNode* ParseTree::build(vector<string> E, int left , int right)
{

    if (left == right)
    {
        TreeNode* T = new TreeNode(E[left]);
        return T;
    }

    TreeNode* T;
    int loc = findPlusMinus(E, left, right);
    if (loc != -1) //check for existence of + or - in string vector
    {
        if (E[loc] == "+")
        {
            T = new TreeNode("+");
        }
        else
        {
            T = new TreeNode("-");
        }

        T->leftChild = build(E, left, loc-1);
        T->rightChild = build(E, loc+1, right);
        return T;
    }
    loc = findMultDiv(E, left, right);
    if (loc != -1) //check for existence of * or / in string vector
    {
        if (E[loc] == "*")
        {
            T = new TreeNode("*");
        }
        else
        {
            T = new TreeNode("/");
        }

        T->leftChild = build(E, left, loc-1);
        T->rightChild = build(E, loc+1, right);
        return T;
    }
    return build(E, left+1, right-1); //call recursively
}


void ParseTree::buildTree(string E) //parameter takes original user input infix expression
{
    vector<string> vector;

    //cycle through entire string
    for (unsigned int i = 0; i < E.length(); i++)
    {
        if (E[i] == ' ') //don't need spaces
        {
            continue;
        }
        else if (E[i] == '+' || E[i] == '-' //check for operators and parenthesis
                || E[i] == '*' || E[i] == '/'
                || E[i] == '(' || E[i] == ')')
        {
            string tmp = ""; //temporary string is built to hold single operator character
            tmp += E[i];
            vector.push_back(tmp);
        }
        else if (isdigit(E[i])) //checks for numerical character in string
        {
            string tmp = ""; //temporary string is built to hold single number of multiple digits
            while (E[i] != ' ' && E[i] != '\0') //allow mult digit numbers in string, checking for seperator of space character
            {
                tmp += E[i];
                i++;
            }
            vector.push_back(tmp);
        }
    }    
    root = build(vector, 0, vector.size()-1); //call recursively
}

// display the parse tree strcture visually
void ParseTree::printTree() 
{
    queue<TreeNode*> nodes;
    queue<int> levelList;
    TreeNode* current = NULL;
    int printDepth = this->getHeight();
    int possibleNodes = static_cast<int>(pow(2.0, printDepth + 1));
    int countNodes = 0;

    nodes.push(root);
    int currentLevel = 0;
    int previousLevel = -1;
    levelList.push(currentLevel);

    while (countNodes < possibleNodes) 
    {
        countNodes = countNodes + 1;
        if (!nodes.empty())  
        {    
            current = nodes.front();
            nodes.pop();
        }
        if (!levelList.empty())
        {    
            currentLevel = levelList.front();
            levelList.pop();
        }
        if (currentLevel > previousLevel)
        {
            cout << endl << endl;
            previousLevel = currentLevel;
            for (int j = 0; j < int ((pow(2.0, (printDepth - currentLevel))) - 1); j++)
                cout << setw(FORMAT_WIDTH)<< " ";
        }
        else
        {
            for (int i = 0; i < int ((pow(2.0, (printDepth - currentLevel + 1)) - 1)) ; i++) 
            {
                cout << setw(FORMAT_WIDTH) <<" ";
            }
        }
        if (current != NULL)
        {
            cout << setw(FORMAT_WIDTH) << current->key;
            nodes.push(current->leftChild);
            levelList.push(currentLevel + 1);
            nodes.push(current->rightChild);
            levelList.push(currentLevel + 1);
        }
        else {
            nodes.push(NULL);
            levelList.push(currentLevel + 1);
            nodes.push(NULL);
            levelList.push(currentLevel + 1);
            cout << setw(FORMAT_WIDTH) << " ";
        }

    }
}



































