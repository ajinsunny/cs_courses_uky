/* CS 216 - 002 Programming Assignment 2 
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

string evaluation(string postfix);

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

/************ EMPTY STACK NOTIFICATION ****************
 *Empty stack notification is a funciton which is used to notify the
 * the user that the stack is currently empty and there is no information 
 * or data present to display. 
 * */


void EmptyStack_notification()
{
    cout<<"Expression from the user input is empty ! "<<endl;
}

void Error_print()
{
    cout<<"Error Try Again ! "<<endl;
        
}



/*************** BUILD FUNCTION ************ 
 *Build tree function is used build the tree by using the expression given from the user
 *The expression is input from the user and then passed as a vector into this function 
 *which then usees the Tree Node pointer to access the object and parse a tree from the 
 *input expression from the user. 
 * */
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

/********************* BUILD TREE FUNCTION******************
 *This function takes in a parameter which is the expression from the user
 *and use this expression from the user to push it into a vector. Which then builds
 *the tree.
 **/


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

/**************** TREE TRAVERSAL FUNCTION ***************
 *This function is used to traverse through the tree and then perform operations 
 *according to the integer values passed as a parameter into the traversal function. 
 *These integers are specified for each specific functions in the main function inside  
 *the case statement.
 * */


void ParseTree::tree_traverse(int type_of_traverse)
{
    if (type_of_traverse == 1)
    {
        this->prefix(root);       
    }    
    else if (type_of_traverse == 2)
    {
        this->infix(root);       
    }

    else if (type_of_traverse == 3)
    {
        this->postfix(root);       

    }


}

/**************** PREFIX FUNCTION ***************
 *The prefix function will convert the current expression present inside the 
 *tree into prefix notaiton and use the cout notation to print it. This is done 
 *by using recursive method. First the key is printed by using the localRoot 
 *pointer and then recursively the same process is done by using leftChild and 
 *right Child 
 * */

void ParseTree::prefix(TreeNode* localRoot)
{
    if(localRoot != NULL)
    {
        cout << localRoot->key << " ";
        prefix(localRoot->leftChild);
        prefix(localRoot->rightChild); 
    }    

}

/* ************** INFIX FUNCTION ***************
 *Infix function is just like the prefix function , it will print the input expression
 *in the form of infix notation. Infix function also uses recursive option to build the 
 *tree. first the key is printed and after which we will print leftChild and rightChild. 
 *
 * */

void ParseTree::infix(TreeNode* localRoot)
{
    if(localRoot != NULL)
    {
        if (localRoot->leftChild == NULL && localRoot->rightChild == NULL)        
        {
            cout << localRoot->key << " ";
        }

        else
        {
            cout<<" (";
            infix(localRoot->leftChild);
            cout<< localRoot->key << " ";
            infix(localRoot->rightChild);
            cout<<") ";
        }   
    }

}


/*************** POSTFIX FUNCTION **************
 *Post Expression is printed by using a variable which is a private data
 *member in the Parse Tree class. Postfix function is then recursively called  
 *on printing the key and the leftChild and rightChild.
 *
 *
 * */


void ParseTree::postfix(TreeNode* localRoot)
{
    if (localRoot != NULL)
    {
        postfix(localRoot->leftChild);
        postfix(localRoot->rightChild);
        postExp += localRoot->key;
        postExp += " ";
    }
}


string ParseTree::getEval()
{
    return evaluation(postExp);
}

string ParseTree::getPostExp()
{
    return postExp;
}

void ParseTree::resetPostExp()
{
    postExp = "";
}
















