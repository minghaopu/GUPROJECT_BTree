# GUPROJECT_BTree
This project is used for practicing and comparing the search effeciency between B-tree and link list.

The basic structure of B-tree node. M is the number of children nodes. DEGREE is the degree for each node.
    
    #define M 4;
    #define DEGREE 2;
    
    
    struct BTNode {

        int num;

        bool isLeaf;

        vector<pair<string, int> > keys;        // store the word and its frequency

        vector<BTNode*> children;

        BTNode(int nodeSize, int childSize) : num(0), isLeaf(true), keys(nodeSize, pair<string, int> ("", 0)) , children(childSize, NULL)  {}

    };
