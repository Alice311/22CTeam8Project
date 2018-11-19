// Binary Search Tree ADT
//  Programmer Isaac Li
 
#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryNode.h"
#include "Queue.h"

template<class ItemType>
class BinarySearchTree
{   
private:
    BinaryNode<ItemType>* rootPtr;        // ptr to root node
    int count;                            // number of nodes in tree
    //function that helps printIndentedList
    void _printIndentedList(BinaryNode<ItemType>*, int);

    void _preorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
    void _inorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
    void _postorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;


	// internal insert node: insert newNode in nodePtr subtree
	BinaryNode<ItemType>* _insert(BinaryNode<ItemType>* nodePtr, BinaryNode<ItemType>* newNode, int compare(ItemType&, ItemType&));

   
	// internal remove node: locate and delete target node under nodePtr subtree
	BinaryNode<ItemType>* _remove(BinaryNode<ItemType>* nodePtr, const ItemType target, bool & success);
   
	// delete target node from tree, called by internal remove node
	BinaryNode<ItemType>* deleteNode(BinaryNode<ItemType>* targetNodePtr);
   
	// remove the leftmost node in the left subtree of nodePtr
	BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* nodePtr, ItemType & successor);
   
	// search for target node
	BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, const ItemType & target) const;
   
public:
    BinarySearchTree() {rootPtr = 0; count = 0;}
    BinarySearchTree(const BinarySearchTree<ItemType> & tree){rootPtr = copyTree(tree.rootPtr); count = tree.count;}
    ~BinarySearchTree() {}

    // delete all nodes from the tree
    void destroyTree(BinaryNode<ItemType>* nodePtr);

    // copy from the tree rooted at nodePtr and returns a pointer to the copy
    BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* nodePtr);

	// insert a node at the correct location
    bool insert(const ItemType & newEntry, int compare( ItemType&,  ItemType&));

	// remove a node if found
	bool remove(const ItemType & anEntry);
	// find a target node
	bool getEntry(const ItemType & target, ItemType & returnedItem) const;

    //  prints the BST as a indented list
    void printIndentedList();

    BinaryNode<ItemType>* findSmallestKey();     //Find smallest key in the BST
    BinaryNode<ItemType>* findLargestKey();      //Find largest key in the BST

    BinarySearchTree & operator = (const BinarySearchTree & sourceTree);

    // common functions for all binary trees
    bool isEmpty() const    {return count == 0;}
    int size() const        {return count;}
    void clear()            {destroyTree(rootPtr); rootPtr = 0; count = 0;}
    void preOrder(void visit(ItemType &)) const {_preorder(visit, rootPtr);}
    void inOrder(void visit(ItemType &)) const  {_inorder(visit, rootPtr);}
    void postOrder(void visit(ItemType &)) const{_postorder(visit, rootPtr);}
    void breadthOrder(void visit(ItemType &)){
        Queue<BinaryNode<ItemType>*> tempQ;
        BinaryNode<ItemType>* tempNode = rootPtr;
        do{
            ItemType tempItem = tempNode->getItem();
            visit(tempItem);
            if(tempNode->getLeftPtr()!=0)
                tempQ.enqueue(tempNode->getLeftPtr());
            if(tempNode->getRightPtr()!=0)
                tempQ.enqueue(tempNode->getRightPtr());
            tempQ.dequeue(tempNode);
        }while(tempNode != 0 && !tempQ.isEmpty());
        ItemType tempItem = tempNode->getItem();
        visit(tempItem);        //Dont forget the last node : )
    }

    int maxHeight(BinaryNode<ItemType>* node){
        if(node == 0)
            return 0;
        else{
            int lHeight = maxHeight(node->getLeftPtr());
            int rHeight = maxHeight(node->getRightPtr());

            if(lHeight > rHeight)
                return (lHeight+1);
            else return (rHeight+1);
        }
    }
 
};


///////////////////////// public function definitions ///////////////////////////

template<class ItemType>
void BinarySearchTree<ItemType>::printIndentedList(){

    BinaryNode<ItemType> *nodePtr = this->rootPtr;
    _printIndentedList(nodePtr, 1);

}


template<class ItemType>
bool BinarySearchTree<ItemType>::insert(const ItemType & newEntry, int compare( ItemType&,  ItemType&))
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
	this->rootPtr = _insert(this->rootPtr, newNodePtr, compare);
    (this->count)++;
	return true;
}  

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType & target)
{
	bool isSuccessful = false;
	this->rootPtr = _remove(this->rootPtr, target, isSuccessful);
    if(isSuccessful)
        (this->count)--;
	return isSuccessful; 
}  

template<class ItemType>
bool BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry, ItemType & returnedItem) const
{
    BinaryNode<ItemType>*  temp;
    temp = findNode(this->rootPtr, anEntry);
    if(!temp)
        return false;

    returnedItem = temp->getItem();
    return true;

    
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findSmallestKey()
{
    BinaryNode<ItemType>* temp = this->rootPtr;
    while(temp->getLeftPtr()!=0)
        temp = temp->getLeftPtr();

    return temp;

}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findLargestKey()
{
    BinaryNode<ItemType>* temp = this->rootPtr;
    while(temp->getRightPtr()!=0)
        temp = temp->getRightPtr();

    return temp;

}



//////////////////////////// private functions ////////////////////////////////////////////


template<class ItemType>
void BinarySearchTree<ItemType>::_printIndentedList(BinaryNode<ItemType>* nodePtr, int level){
    if(nodePtr->getRightPtr()!=0){
        _printIndentedList(nodePtr->getRightPtr(), level+1);
        if(nodePtr->getLeftPtr()!= 0)
            cout << endl;   //leave one space for empty node
    }

    for(int i = 0; i < level; i++)
        cout << "\t\t";
    cout << level << "." <<*(nodePtr->getItem()) << endl;;
    if(nodePtr->getLeftPtr()!=0){
        if(nodePtr->getRightPtr()!=0)
            cout << endl;
        _printIndentedList(nodePtr->getLeftPtr(), level+1);
    }


}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_insert(BinaryNode<ItemType>* nodePtr,
                                BinaryNode<ItemType>* newNodePtr, int compare( ItemType&,  ItemType&))
{
    BinaryNode<ItemType> *temp = nodePtr;
    if(temp == 0){
        nodePtr = newNodePtr;
    }
    while(temp != 0){
        ItemType newItem = newNodePtr ->getItem();
        ItemType tempItem = temp->getItem();
        if(compare(newItem, tempItem)>=0 && temp->getRightPtr()!=0)
            temp = temp->getRightPtr();
        else if(compare(newItem, tempItem)>=0 && temp->getRightPtr()==0){
            temp->setRightPtr(newNodePtr);
            return nodePtr;
        }
        else if(compare(newItem, tempItem)<0 && temp->getLeftPtr()!=0)
            temp = temp->getLeftPtr();
        else if(compare(newItem, tempItem)<0 && temp->getLeftPtr()==0){
            temp->setLeftPtr(newNodePtr);
            return nodePtr;
        }
    }
    return nodePtr;
}


template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_remove(BinaryNode<ItemType>* nodePtr,
                                                          const ItemType target,
                                                          bool & success)

{
	if (nodePtr == 0)                   
	{
		success = false;
		return 0;
	}
	if (nodePtr->getItem() > target)		 
		nodePtr->setLeftPtr(_remove(nodePtr->getLeftPtr(), target, success));
	else if (nodePtr->getItem() < target)	 
		nodePtr->setRightPtr(_remove(nodePtr->getRightPtr(), target, success));
	else		
	{
		nodePtr = deleteNode(nodePtr);
		success = true;
	}      
	return nodePtr;   
}  

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::deleteNode(BinaryNode<ItemType>* nodePtr)
{
	if (nodePtr->isLeaf())				
	{
		delete nodePtr;
		nodePtr = 0;
		return nodePtr;
	}
	else if (nodePtr->getLeftPtr() == 0)  
	{
		BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getRightPtr();
		delete nodePtr;
		nodePtr = 0;
		return nodeToConnectPtr;
	}
	else if (nodePtr->getRightPtr() == 0) 
	{
		BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getLeftPtr();
		delete nodePtr;
		nodePtr = 0;
		return nodeToConnectPtr;      
	}
	else                                  
	{
		ItemType newNodeValue;
		nodePtr->setRightPtr(removeLeftmostNode(nodePtr->getRightPtr(), newNodeValue));
		nodePtr->setItem(newNodeValue);
		return nodePtr;
	}  
}  

template<class ItemType> 
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* nodePtr,
                                                                     ItemType & successor)
{
	if (nodePtr->getLeftPtr() == 0)
	{
		successor = nodePtr->getItem();
		return deleteNode(nodePtr);
	}
	else 
	{
		nodePtr->setLeftPtr(removeLeftmostNode(nodePtr->getLeftPtr(), successor));
		return nodePtr;
	}       
}


template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* nodePtr,
                                                           const ItemType & target) const 
{
    BinaryNode<ItemType>* temp = nodePtr;
    if(temp == 0)
        return nullptr;
    while(true){
        if(temp->getLeftPtr() == 0 && temp->getRightPtr() == 0 && temp->getItem() != target)
            return nullptr;
        else if(target == temp->getItem())
            return temp;
        else if(temp -> getLeftPtr() != 0)
            if(target < temp->getItem()){
                temp = temp->getLeftPtr();
                continue;
            }
        else if(temp -> getRightPtr() != 0)
            if(target > temp->getItem()){
                temp = temp->getRightPtr();
                continue;
            }

        return nullptr;
    }
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::copyTree(const BinaryNode<ItemType>* nodePtr)
{
    BinaryNode<ItemType>* newNodePtr = 0;
    if(nodePtr != 0){
        newNodePtr = new BinaryNode<ItemType>(nodePtr->getItem());
        if(nodePtr->getLeftPtr() != 0)
            newNodePtr->setLeftPtr(copyTree(nodePtr->getLeftPtr()));
        if(nodePtr->getRightPtr() != 0)
            newNodePtr->setRightPtr( copyTree(nodePtr->getRightPtr()));
    }

    return newNodePtr;
}

template<class ItemType>
void BinarySearchTree<ItemType>::destroyTree(BinaryNode<ItemType>* nodePtr)
{
    if(nodePtr == 0)
        return;
    if(nodePtr->getLeftPtr()!= 0)
        destroyTree(nodePtr->getLeftPtr());
    if(nodePtr->getRightPtr()!=0)
        destroyTree(nodePtr->getRightPtr());
    cout << "deleting node " << nodePtr->getItem() << endl;
    delete nodePtr;
}

template<class ItemType>
void BinarySearchTree<ItemType>::_preorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
    if (nodePtr != 0)
    {
        ItemType item = nodePtr->getItem();
        visit(item);
        _preorder(visit, nodePtr->getLeftPtr());
        _preorder(visit, nodePtr->getRightPtr());
    }
}

template<class ItemType>
void BinarySearchTree<ItemType>::_inorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
    if (nodePtr != 0)
    {
        ItemType item = nodePtr->getItem();
        _inorder(visit, nodePtr->getLeftPtr());
        visit(item);
        _inorder(visit, nodePtr->getRightPtr());
    }
}

template<class ItemType>
void BinarySearchTree<ItemType>::_postorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
    if (nodePtr != 0)
    {
        ItemType item = nodePtr->getItem();
        _postorder(visit, nodePtr->getLeftPtr());
        _postorder(visit, nodePtr->getRightPtr());
        visit(item);
    }
}

template<class ItemType>
BinarySearchTree<ItemType> & BinarySearchTree<ItemType>::operator=(const BinarySearchTree<ItemType> & sourceTree)
{
    rootPtr = copyTree(sourceTree.rootPtr);
    count = sourceTree.count;
    return *this;

}


#endif
