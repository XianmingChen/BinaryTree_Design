#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	root=NULL;
}

NodePtr BinaryTree::getroot()
{
	return root;
}

ElemType BinaryTree::getrootvalue()
{
	return root->data;
}

void BinaryTree::PreTravel()
{
	PreTravel(root);
}

void BinaryTree::PreTravel(NodePtr curr)
{
	if (curr!=NULL)
	{
		cout<<curr->data<<endl;
		PreTravel(curr->leftchild);
		PreTravel(curr->rightchild);
	}
}

void BinaryTree::PreTravelNR()
{
	PreTravelNR(root);
}

void BinaryTree::PreTravelNR(NodePtr curr)
{
	stack<NodePtr> record;
	NodePtr tmp;

	if (curr!=NULL)
	{
		record.push(curr);

		while(!record.empty())
		{
			tmp=record.top();
			cout<<tmp->data<<endl;
			record.pop();

			if(tmp->rightchild!=NULL)
				record.push(tmp->rightchild);

			if(tmp->leftchild!=NULL)
				record.push(tmp->leftchild);
		}
	}
}


void BinaryTree::PostTravel()
{
	PostTravel(root);
}

void BinaryTree::PostTravel(NodePtr curr)
{
	if (curr!=NULL)
	{
		PostTravel(curr->leftchild);
		PostTravel(curr->rightchild);
		cout<<curr->data<<endl;
	}
}

void BinaryTree::PostTravelNR()
{
	PostTravelNR(root);
}

void BinaryTree::PostTravelNR(NodePtr curr)
{
	stack<NodePtr> result;
	stack<NodePtr> record;
	NodePtr tmp;

	if (curr!=NULL)
	{
		record.push(curr);
		while(!record.empty())
		{
			tmp=record.top();
			record.pop();
			result.push(tmp);

			if(tmp->leftchild!=NULL)
				record.push(tmp->leftchild);

			if(tmp->rightchild!=NULL)
				record.push(tmp->rightchild);
		}

		while(!result.empty())
		{
			tmp=result.top();
			result.pop();
			cout<<tmp->data<<endl;
		}
	}
}

void BinaryTree::InTravel()
{
	InTravel(root);
}

void BinaryTree::InTravel(NodePtr curr)
{
	if (curr!=NULL)
	{
		InTravel(curr->leftchild);
		cout<<curr->data<<endl;
		InTravel(curr->rightchild);
	}
}

void BinaryTree::InTravelNR()
{
	InTravelNR(root);
}

void BinaryTree::InTravelNR(NodePtr curr)
{
	stack<NodePtr> record;
	NodePtr tmp=curr;

	if (curr!=NULL)
	{
		while(!record.empty()||(tmp!=NULL))
		{
			while(tmp!=NULL)
			{
				record.push(tmp);
				tmp=tmp->leftchild;
			}

			if(!record.empty())
			{
				tmp=record.top();
				record.pop();
				cout<<tmp->data<<endl;
				tmp=tmp->rightchild;
			}
		}
	}
}

void BinaryTree::LayerTravel()
{
	queue<NodePtr> queuetree;
	NodePtr tmp;

	if (root==NULL)
		return;

	queuetree.push(root);
	while(!queuetree.empty())
	{
		tmp=queuetree.front();
		queuetree.pop();
		cout<<tmp->data<<endl;

		if(tmp->leftchild!=NULL)
			queuetree.push(tmp->leftchild);

		if(tmp->rightchild!=NULL)
			queuetree.push(tmp->rightchild);
	}
}

void BinaryTree::CreateTree()
{
	CreateTree(root,0);
}

void BinaryTree::CreateTree(NodePtr& start,int level)
{
	char temp;

	cout<<"Please input the value for the node for level "<<level<<":"<<endl;
	cin>>temp;

	if (temp=='#')
		return;
	else
	{
		start=new BinNode;
		start->data=temp;
		start->leftchild=NULL;
		start->rightchild=NULL;

		cout<<"Left Node:"<<endl;
		CreateTree(start->leftchild,level+1);
		cout<<"Right Node:"<<endl;
		CreateTree(start->rightchild,level+1);
	}
}

void BinaryTree::BST_Pos(ElemType value,NodePtr& pos,bool& isleft)
{
	NodePtr tmp,curr=root;
	bool left;

	if(curr==NULL)
	{
		pos=NULL;
		isleft=false;
		return;
	}

	while(curr!=NULL)
	{
		tmp=curr;
		if(value<curr->data)
		{
			curr=curr->leftchild;
			left=true;
		}
		else
		{
			curr=curr->rightchild;
			left=false;
		}
	}
	pos=tmp;
	isleft=left;
}

void BinaryTree::Insert_BST(ElemType value)
{
	NodePtr temp,pos;
	bool isleft;

	temp=new BinNode;
	temp->data=value;
	temp->leftchild=NULL;
	temp->rightchild=NULL;

	if(root==NULL)
	{
		root=temp;
		return;
	}
	else
		BST_Pos(value,pos,isleft);
	
	if(isleft==true)
		pos->leftchild=temp;
	else
		pos->rightchild=temp;
}

void BinaryTree::Insert2_BST(NodePtr& target,ElemType value)
{
	if(target==NULL)
	{
		target=new BinNode;
		target->data=value;
		target->leftchild=NULL;
		target->rightchild=NULL;
	}
	else if(value<target->data)
		Insert2_BST(target->leftchild,value);
	else
		Insert2_BST(target->rightchild,value);
}

void BinaryTree::Insert2_BST(ElemType value)
{
	Insert2_BST(root,value);
}

void BinaryTree::CreateBST(ElemType input[],int length)
{
	int i;

	if(root!=NULL)
	{
		cout<<"The original tree should be empty!"<<endl;
		return;
	}

	for(i=0;i<length;i++)
	{
		//Insert_BST(input[i]);
		Insert2_BST(input[i]);
	}
}

int BinaryTree::TreeSize()
{
	return TreeSize(root);
}

int BinaryTree::TreeSize(NodePtr start)
{
	if (start==NULL)
		return 0;
	else
		return 1+TreeSize(start->leftchild)+TreeSize(start->rightchild);
}

int BinaryTree::LeafSize()
{
	return LeafSize(root);
}

int BinaryTree::LeafSize(NodePtr start)
{
	if (start==NULL)
		return 0;
	else if ((start->leftchild==NULL)&&(start->rightchild==NULL))
		return 1;
	else
		return LeafSize(start->leftchild)+LeafSize(start->rightchild);
}

int BinaryTree::TreeHeight()
{
	return TreeHeight(root);
}

int BinaryTree::TreeHeight(NodePtr start)
{
	int lheight,rheight;

	if (start==NULL)
		return 0;
	else 
	{
		lheight=TreeHeight(start->leftchild);
		rheight=TreeHeight(start->rightchild);
		return (lheight>rheight)?lheight+1:rheight+1;
	}
}

int BinaryTree::TreeHeightDS()
{
	queue<TreeLayerNode> queuetree;
	TreeLayerNode temp,curr;

	int layercount=0;
	if (root==NULL)
		return 0;

	temp.layer=1;
	temp.treenode=root;
	queuetree.push(temp);

	while(!queuetree.empty())
	{
		curr=queuetree.front();
		queuetree.pop();

		if (layercount<curr.layer)
			layercount=curr.layer;

		if(curr.treenode->leftchild!=NULL)
		{
			temp.treenode=curr.treenode->leftchild;
			temp.layer=curr.layer+1;
			queuetree.push(temp);
		}

		if(curr.treenode->rightchild!=NULL)
		{
			temp.treenode=curr.treenode->rightchild;
			temp.layer=curr.layer+1;
			queuetree.push(temp);
		}	
	}
	return layercount;
}

NodePtr BinaryTree::FindMinNode()
{
	if(root==NULL)
		return NULL;

	NodePtr temp=root;
	while(temp->leftchild!=NULL)
	{
		temp=temp->leftchild;
	}
	return temp;
}
NodePtr BinaryTree::FindMaxNode()
{
	if(root==NULL)
		return NULL;

	NodePtr temp=root;
	while(temp->rightchild!=NULL)
	{
		temp=temp->rightchild;
	}
	return temp;
}

NodePtr BinaryTree::FindMinNode(NodePtr start,NodePtr& parent)
{
	if(start==NULL)
		return NULL;

	while(start->leftchild!=NULL)
	{
		parent=start;
		start=start->leftchild;
	}
	return start;
}

void BinaryTree::DeleteMinNode()
{
	NodePtr prev=root,temp=root;

	while(temp->leftchild!=NULL)
	{
		prev=temp;
		temp=temp->leftchild;
	}

	if(temp==root)
		root=temp->rightchild;
	else
		prev->leftchild=temp->rightchild;

	delete temp;
}

NodePtr BinaryTree::find(NodePtr& parent,bool& isleft,NodePtr curr,ElemType value)
{
	while(curr!=NULL)
	{
		if(curr->data==value)
			return curr;
		else if(curr->data>value)
		{
			parent=curr;
			isleft=true;
			curr=curr->leftchild;
		}
		else
		{
			parent=curr;
			isleft=false;
			curr=curr->rightchild;
		}
	}
	return NULL;
}

NodePtr BinaryTree::find(NodePtr curr,ElemType value)
{
	while(curr!=NULL)
	{
		if(curr->data==value)
			return curr;
		else if(curr->data>value)
			curr=curr->leftchild;
		else
			curr=curr->rightchild;
	}
	return NULL;
}

NodePtr BinaryTree::find(ElemType value)
{
	if(root==NULL)
		return NULL;
	else
		return find(root,value);
}

void BinaryTree::DeleteNode(ElemType value)
{
	bool isleft;
	NodePtr tmp,parent=NULL;
	NodePtr LeastGreater,MinGreatParent=NULL;

	tmp=find(parent,isleft,root,value);

	if(tmp!=NULL)
	{
		if((tmp->leftchild==NULL)&&(tmp->rightchild==NULL))
		{
			if(tmp==root)
			{
				root=NULL;
			}
			else if(isleft==true)
				parent->leftchild=NULL;
			else
				parent->rightchild=NULL;

			delete tmp;
		}
		else if((tmp->leftchild!=NULL)&&(tmp->rightchild==NULL))
		{
			if(tmp==root)
			{
				root=tmp->leftchild;
			}
			else if(isleft==true)
				parent->leftchild=tmp->leftchild;
			else
				parent->rightchild=tmp->leftchild;

			delete tmp;
		}
		else if((tmp->leftchild==NULL)&&(tmp->rightchild!=NULL))
		{
			if(tmp==root)
			{
				root=tmp->rightchild;
			}
			else if(isleft==true)
				parent->leftchild=tmp->rightchild;
			else
				parent->rightchild=tmp->rightchild;

			delete tmp;
		}
		else
		{
			LeastGreater=FindMinNode(tmp->rightchild,MinGreatParent);
			tmp->data=LeastGreater->data;

			if(MinGreatParent==NULL)
				tmp->rightchild=LeastGreater->rightchild;
			else
				MinGreatParent->leftchild=LeastGreater->rightchild;

			delete LeastGreater;
		}
	}
	else
		cout<<value<<" not in the tree."<<endl;
}

ElemType BinaryTree::min()
{
	return FindMinNode()->data;
}

ElemType BinaryTree::max()
{
	return FindMaxNode()->data;
}

bool BinaryTree::isLeaf(NodePtr curr)
{
	if((curr->leftchild==NULL)&&(curr->rightchild==NULL))
		return true;
	else
		return false;
}

void BinaryTree::clear()
{
	clear(root);
	root=NULL;
}

void BinaryTree::clear(NodePtr& start)
{
	if(start!=NULL)
	{
		clear(start->leftchild);
		clear(start->rightchild);
		delete start;
	}
}

void BinaryTree::clearSQ()
{
	queue<NodePtr> Nodequeue;

	NodePtr tmp=root;

	if (root==NULL)
		return;

	Nodequeue.push(tmp);
	
	while(!Nodequeue.empty())
	{
		tmp=Nodequeue.front();

		if(tmp->leftchild!=NULL)
			Nodequeue.push(tmp->leftchild);

		if(tmp->rightchild!=NULL)
			Nodequeue.push(tmp->rightchild);

		Nodequeue.pop();
		delete tmp;
	}
	root=NULL;
}

void BinaryTree::LRChildSwap()
{
	LRChildSwap(root);
}

void BinaryTree::LRChildSwap(NodePtr start)
{
	NodePtr tmp;
	if(start==NULL)
		return;

	tmp=start->leftchild;
	start->leftchild=start->rightchild;
	start->rightchild=tmp;

	LRChildSwap(start->leftchild);
	LRChildSwap(start->rightchild);
}

void BinaryTree::LRChildSwapNR()
{
	LRChildSwapNR(root);
}

void BinaryTree::LRChildSwapNR(NodePtr start)
{
	queue<NodePtr> input;
	NodePtr tmp,curr;

	if(start!=NULL)
	{
		input.push(start);
	}

	while(!input.empty())
	{
		curr=input.front();
		input.pop();

		tmp=curr->leftchild;
		curr->leftchild=curr->rightchild;
		curr->rightchild=tmp;

		if(curr->leftchild!=NULL)
			input.push(curr->leftchild);
		if(curr->rightchild!=NULL)
			input.push(curr->rightchild);
	}
}

void BinaryTree::BST_Pos(ElemType value,NodePtr& pos,bool& isleft,stack<NodePtr>& NodePath)
{
	NodePtr tmp,curr=root;
	bool left;

	if(curr==NULL)
	{
		pos=NULL;
		isleft=false;
		return;
	}

	while(curr!=NULL)
	{
		tmp=curr;
		NodePath.push(curr);
		if(value<curr->data)
		{
			curr=curr->leftchild;
			left=true;
		}
		else
		{
			curr=curr->rightchild;
			left=false;
		}
	}
	pos=tmp;
	isleft=left;
}

int BinaryTree::BalanceFactor(NodePtr CurrNode)
{
	if(CurrNode==NULL)
		return 0;

	int LsonHeight=TreeHeight(CurrNode->leftchild);
	int RsonHeight=TreeHeight(CurrNode->rightchild);
	return LsonHeight-RsonHeight;
}

void BinaryTree::LL_Rotate(NodePtr ParentNUBNode,NodePtr NearestUBNode)
{
	NodePtr MidNode=NearestUBNode->leftchild;

	if (ParentNUBNode!=NULL)
	{
		if(ParentNUBNode->leftchild==NearestUBNode)
			ParentNUBNode->leftchild=MidNode;
		else
			ParentNUBNode->rightchild=MidNode;
	}
	else
		root=MidNode;

	NearestUBNode->leftchild=MidNode->rightchild;
	MidNode->rightchild=NearestUBNode;
}

void BinaryTree::LR_Rotate(NodePtr ParentNUBNode,NodePtr NearestUBNode,bool isleft)
{
	NodePtr MidNode=NearestUBNode->leftchild;
	NodePtr BtmNode=MidNode->rightchild;

	if(isleft==true)
	{
		//First rotate
		NearestUBNode->leftchild=BtmNode;
		MidNode->rightchild=BtmNode->leftchild;
		BtmNode->leftchild=MidNode;

		//Second rotate
		NearestUBNode->leftchild=NULL;
		BtmNode->rightchild=NearestUBNode;
	}
	else
	{
		//First rotate
		NearestUBNode->leftchild=BtmNode;
		MidNode->rightchild=NULL;
		BtmNode->leftchild=MidNode;

		//Second rotate
		NearestUBNode->leftchild=BtmNode->rightchild;
		BtmNode->rightchild=NearestUBNode;
	}

	if (ParentNUBNode!=NULL)
	{
		if(ParentNUBNode->leftchild==NearestUBNode)
			ParentNUBNode->leftchild=BtmNode;
		else
			ParentNUBNode->rightchild=BtmNode;
	}
	else
		root=BtmNode;
}

void BinaryTree::RR_Rotate(NodePtr ParentNUBNode,NodePtr NearestUBNode)
{
	NodePtr MidNode=NearestUBNode->rightchild;

	if (ParentNUBNode!=NULL)
	{
		if(ParentNUBNode->leftchild==NearestUBNode)
			ParentNUBNode->leftchild=MidNode;
		else
			ParentNUBNode->rightchild=MidNode;
	}
	else
		root=MidNode;
	
	NearestUBNode->rightchild=MidNode->leftchild;
	MidNode->leftchild=NearestUBNode;
}

void BinaryTree::RL_Rotate(NodePtr ParentNUBNode,NodePtr NearestUBNode,bool isleft)
{
	NodePtr MidNode=NearestUBNode->rightchild;
	NodePtr BtmNode=MidNode->leftchild;

	if(isleft==true)
	{
		//First rotate
		NearestUBNode->rightchild=BtmNode;
		MidNode->leftchild=NULL;
		BtmNode->rightchild=MidNode;

		//Second rotate
		NearestUBNode->rightchild=BtmNode->leftchild;
		BtmNode->leftchild=NearestUBNode;
	}
	else
	{
		//First rotate
		NearestUBNode->rightchild=BtmNode;
		MidNode->leftchild=BtmNode->rightchild;
		BtmNode->rightchild=MidNode;

		//Second rotate
		NearestUBNode->rightchild=NULL;
		BtmNode->leftchild=NearestUBNode;
	}

	if (ParentNUBNode!=NULL)
	{
		if(ParentNUBNode->leftchild==NearestUBNode)
			ParentNUBNode->leftchild=BtmNode;
		else
			ParentNUBNode->rightchild=BtmNode;
	}
	else
		root=BtmNode;
}

void BinaryTree::InsertAVLTree(ElemType value)
{
	NodePtr TmpParent,NewNode;
	NodePtr ParentNUBNode=NULL,NearestUBNode,MidNode,BtmNode;
	bool isleft;
	stack<NodePtr> NodePath;
	int BF;

	NewNode=new BinNode;
	NewNode->data=value;
	NewNode->leftchild=NULL;
	NewNode->rightchild=NULL;

	if(root==NULL)
	{
		root=NewNode;
		return;
	}
	else
		BST_Pos(value,TmpParent,isleft,NodePath);
	
	if(isleft==true)
		TmpParent->leftchild=NewNode;
	else
		TmpParent->rightchild=NewNode;

	if(NodePath.size()>2)
	{
		BtmNode=NodePath.top();
		NodePath.pop();

		MidNode=NodePath.top();
		NodePath.pop();

		NearestUBNode=NodePath.top();
		NodePath.pop();

		if(!NodePath.empty())
			ParentNUBNode=NearestUBNode=NodePath.top();

		BF=BalanceFactor(NearestUBNode);

		if((BF==2)&&(MidNode->leftchild==BtmNode)) //LL Rotate
			LL_Rotate(ParentNUBNode,NearestUBNode);
		else if((BF==2)&&(MidNode->rightchild==BtmNode)) //LR Rotate
			LR_Rotate(ParentNUBNode,NearestUBNode,isleft);
		else if((BF==-2)&&(MidNode->rightchild==BtmNode)) //RR Rotate
			RR_Rotate(ParentNUBNode,NearestUBNode);
		else if((BF==-2)&&(MidNode->leftchild==BtmNode)) //RL Rotate
			RL_Rotate(ParentNUBNode,NearestUBNode,isleft);
	}

	while(!NodePath.empty())
		NodePath.pop();
}

void BinaryTree::CreateAVLTree(ElemType input[],int length)
{
	int i;	

	if(root!=NULL)
	{
		cout<<"The original tree should be empty!"<<endl;
		return;
	}

	for(i=0;i<length;i++)
	{
		InsertAVLTree(input[i]);
	}
}