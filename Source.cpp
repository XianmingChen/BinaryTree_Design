#include "BinaryTree.h"

using namespace std;

void GenerateElem(ElemType input[],int length)
{
	int i;

	srand((unsigned)time(NULL));
	for(i=0;i<length;i++)
	{
		input[i]=rand()%100+1;
		cout<<input[i]<<endl;
	}
	cout<<endl;
}

int isInTree(NodePtr dest,NodePtr source)
{
	if((dest==NULL)||(source==NULL))
		return 0;

	if(dest==source)
		return 1;
	else
		return isInTree(dest,source->leftchild)+isInTree(dest,source->rightchild);
}

bool isInTreeNR(NodePtr dest,NodePtr source)
{
	queue<NodePtr> nodes;
	NodePtr tmp;

	if((dest==NULL)||(source==NULL))
		return false;

	nodes.push(source);
	while(!nodes.empty())
	{
		tmp=nodes.front();
		nodes.pop();

		if(dest==tmp)
			return true;

		if(tmp->leftchild!=NULL)
			nodes.push(tmp->leftchild);

		if(tmp->rightchild!=NULL)
			nodes.push(tmp->rightchild);
	}
	return false;
}

NodePtr NearestComParent(NodePtr root, NodePtr node1,NodePtr node2)
{
	NodePtr tmp=root;

	while(tmp!=NULL)
	{
		if((isInTreeNR(node1,tmp->leftchild)==true)&&(isInTreeNR(node2,tmp->leftchild)==true))
		{
			tmp=tmp->leftchild;
		}
		else if((isInTreeNR(node1,tmp->rightchild)==true)&&(isInTreeNR(node2,tmp->rightchild)==true))
		{
			tmp=tmp->rightchild;
		}
		else
		{
			break;
		}
	}
	return tmp;
}

int main()
{
	//ElemType input[SIZE];
	//GenerateElem(input,SIZE);

	ElemType input[15]={9,32,23,18,19,15,20,7,3,2,14,5,4,8,1};
	BinaryTree btree;
	btree.CreateAVLTree(input,15);
	btree.InTravel();
	//cout<<endl;

	//NodePtr node1,node2,node3;
	//node1=btree.find(2);
	//node2=btree.find(1);
	//node3=btree.find(15);

	//NodePtr result=NearestComParent(node3,node1,node2);

	system("pause");
	return 0;
}