#include <iostream>
#include <iomanip>
using namespace std;

// constructor - create an empty tree
template <class keyType, class dataType>
binaryTree<keyType, dataType>::binaryTree()
{
	root = NULL;
}

//____________ Public insert __________________
// If there is a node with the same key value as k, returns false.
template <class keyType, class dataType>
bool binaryTree<keyType, dataType>::insert(const keyType &k, const dataType &d)
{
	return insert2(root, k, d);
} // end of public insert

  //____________ Private insert __________________
template <class keyType, class dataType>
bool binaryTree<keyType, dataType>::insert2(NodePointer &aRoot, const keyType &k, const dataType &d)
{
	if (aRoot == NULL) {
		aRoot = new treeNode();
		aRoot->left = NULL;
		aRoot->right= NULL;
		aRoot->key  = k;
		aRoot->data = d;
		return true;
	}
	else if (k == aRoot->key)
		return false;
	else if (k < aRoot->key)
		insert2(aRoot->left, k, d);
	else
		insert2(aRoot->right, k, d);
	
	/* if empty tree (base case #1 insert a new key)
	Create new node
	Set the left and right pointers (NULL)
	Set the key and data values
	return true

	else if key found (already exist) at the current node then return false (Base case #2 duplicate key)
	else if key less than the current root key then call insert2 with left subtree  (general case moving left)
	else call insert2 with right subtree  (general case moving right)
	*/
} // end of private insert

  //____________ Public search __________________
  // Searches for the item with same key as k
template <class keyType, class dataType>
bool binaryTree<keyType, dataType>::search(const keyType &k) const
{
	return search2(root, k);
} // end of public search   

template <class keyType, class dataType>
bool binaryTree<keyType, dataType>::search2(NodePointer aRoot, const keyType &k)	const
{
	if (aRoot == NULL)
		return false;
	else if (aRoot->key == k)
		return true;
	else if (k < aRoot->key)
		return search2(aRoot->left, k);
	else
		return search2(aRoot->right, k);

	/* if empty tree then return false (base case #1 does not exist)
	else if found then return true  (base case #2 key found)
	else if k is less than current key then call search2 with left subtree
	else call search2 with right subtree
	*/
} // end of private search

  //____________ Public retrieve __________________
  // Searches for the item with same key as k and retrieves data part if found
template <class keyType, class dataType>
bool binaryTree<keyType, dataType>::retrieve(const keyType &k, dataType &d) const
{
	return retrieve2(root, k, d);
} // end of public retrieve   


template <class keyType, class dataType>
bool binaryTree<keyType, dataType>::editdata(const keyType &k, dataType &d) const
{
	return editdata2(root, k, d);
}   

template <class keyType, class dataType>
bool binaryTree<keyType, dataType>::editdata2(NodePointer aRoot, const keyType &k, dataType &d)	const
{
	if (aRoot == NULL)
		return false;
	else if (aRoot->key == k) {
		d = aRoot->data;
		return true;
	}
	else if (k < aRoot->k)
	{
		return editdata2(aRoot->left, k, d);
		d=aRoot->data;
	}
	else
	{
		return editdata2(aRoot->right, k, d);
		d=aRoot->data;
	}
	/* if empty tree then return false   (base case#1 not found)
	else if found then get data  and return true (base case#2 found)
	else if k is less than current key then call retrieve2 with left subtree
	else call retrieve2 with right subtree
	*/
} // end of private retrieve


template <class keyType, class dataType>
bool binaryTree<keyType, dataType>::retrieve2(NodePointer aRoot, const keyType &k, dataType &d)	const
{
	if (aRoot == NULL)
		return false;
	else if (aRoot->key == k) {
		d = aRoot->data;
		return true;
	}
	else if (k < aRoot->k)
		return retrieve2(aRoot->left, k, d);
	else
		return retrieve2(aRoot->right, k, d);

	/* if empty tree then return false   (base case#1 not found)
	else if found then get data  and return true (base case#2 found)
	else if k is less than current key then call retrieve2 with left subtree
	else call retrieve2 with right subtree
	*/
} // end of private retrieve

  //____________ Public empty __________________ 
  // Check if tree is empty
template <class keyType, class dataType>
bool binaryTree<keyType, dataType>::empty() const
{
	return(root == NULL);
} // end of empty


/*template <class keyType, class dataType>
bool binaryTree<keyType, dataType>::editdata(const keyType &k, dataType &d)
{
	NodePointer t=root;
	
	if (t == NULL)
		return false;	
	else if (t->key == k) 
	{
		d = t->data;
		return true;
	}
	else
	{
		while (t != NULL)
		{
			if (k < t->key)
				t = t->left;

			if (k > t->key)
				t = t->right;

			if (t->key == k)
			{
				return true;
				t->data = d;
			}
			else 
				return false;
		}

	}

}*/