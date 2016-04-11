#ifndef BIN_TREE_H
#define BIN_TREE_H

template <class keyType, class dataType>
class binaryTree
{
public:
	// CREATE AN EMPTY TREE
	binaryTree();

	// INSERT AN ELEMENT INTO THE TREE
	bool insert(const keyType &, const dataType &);

	// CHECK IF THE TREE IS EMPTY
	bool empty() const;

	// SEARCH FOR A KEY IN THE TREE
	bool search(const keyType &) const;

	// RETRIEVE DATA FOR A GIVEN KEY
	bool retrieve(const keyType &, dataType &) const;

	bool editdata(const keyType &, dataType &);

	bool remove(const keyType &);

	bool getallnodes(dataType[100],int) const;
	

private:
	// Node Class
	class treeNode
	{
	public:
		keyType key; 		// key 
		dataType data;		// Data
		treeNode *left;		// left subtree	       
		treeNode *right;	// right subtree
	}; // end of class treeNode declaration

	typedef treeNode * NodePointer;

	NodePointer root;

	// Inserts an item in a subtree
	bool insert2(NodePointer &, const keyType &, const dataType &);
	// Searches a subtree for a key
	bool search2(NodePointer, const keyType &) const;

	// Searches a subtree for a key and retrieves data
	bool retrieve2(NodePointer, const keyType &, dataType &) const;

	bool editdata2(NodePointer, const keyType &, dataType &) ;

	


};
#endif // BIN_TREE_H
#include "binaryTree.cpp"
