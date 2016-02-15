#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include<iostream>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>

const int SIZE=10;

using namespace std;

enum OrderType{PreOrder,InOrder,PostOrder};
enum PosType{Left,Right};

typedef int ElemType;

typedef struct BinNode
{
	ElemType data;
	BinNode* leftchild;
	BinNode* rightchild;
}BinNode,*NodePtr;

typedef struct TreeLayerNode
{
	NodePtr treenode;
	int layer;
}TreeLayerNode;

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree(){clear();};

	void PreTravel();
	void PreTravel(NodePtr curr);
	void PreTravelNR();
	void PreTravelNR(NodePtr curr);
	void PostTravel();
	void PostTravel(NodePtr curr);
	void PostTravelNR();
	void PostTravelNR(NodePtr curr);
	void InTravel();
	void InTravel(NodePtr curr);
	void InTravelNR();
	void InTravelNR(NodePtr curr);
	void LayerTravel();

	void CreateTree();
	void CreateTree(NodePtr& start,int level);
	void CreateBST(ElemType input[],int length);
	void Insert_BST(ElemType value);
	void Insert2_BST(ElemType value);
	void Insert2_BST(NodePtr& target,ElemType value);
	void DeleteMinNode();
	void DeleteNode(ElemType value);
	void clear();
	void clear(NodePtr& start);
	void clearSQ();

	int TreeSize();
	int TreeSize(NodePtr start);
	int LeafSize();
	int LeafSize(NodePtr start);
	int TreeHeight();
	int TreeHeight(NodePtr start);
	int TreeHeightDS();
	NodePtr getroot();
	ElemType getrootvalue();
	ElemType min();
	ElemType max();

	void LRChildSwap();
	void LRChildSwap(NodePtr start);
	void LRChildSwapNR();
	void LRChildSwapNR(NodePtr start);

	void BST_Pos(ElemType value,NodePtr& pos,bool& isleft);
	NodePtr find(ElemType value);
	NodePtr find(NodePtr curr,ElemType value);
	NodePtr find(NodePtr& parent,bool& isleft,NodePtr curr,ElemType value);
	NodePtr FindMinNode(NodePtr start,NodePtr& parent);
	NodePtr FindMinNode();
	NodePtr FindMaxNode();
	bool isLeaf(NodePtr curr);

	int BalanceFactor(NodePtr CurrNode);
	void BST_Pos(ElemType value,NodePtr& pos,bool& isleft,stack<NodePtr>& NodePath);
	void CreateAVLTree(ElemType input[],int length);
	void InsertAVLTree(ElemType value);

	void LL_Rotate(NodePtr ParentNUBNode,NodePtr NearestUBNode);
	void LR_Rotate(NodePtr ParentNUBNode,NodePtr NearestUBNode,bool isleft);
	void RR_Rotate(NodePtr ParentNUBNode,NodePtr NearestUBNode);
	void RL_Rotate(NodePtr ParentNUBNode,NodePtr NearestUBNode,bool isleft);
private:
	NodePtr root;
};

#endif