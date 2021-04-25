class BST {
	// Complete this class
    BinaryTreeNode<int> * root=NULL;
    public :
    BST()
    {
        root=NULL;
    }
    ~BST()
    {
        delete root->left;
        delete root->right;
        delete root;
    }