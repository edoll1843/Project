#include "AVLTree.h"
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <stack>

AVLTree::AVLTree(ofstream * flog)
{
	this->flog=flog; //get flog
}

AVLTree::~AVLTree()
{
}

AVLNode * AVLTree::Getroot()
{
	return root; //return root
}

void AVLTree::Setroot(AVLNode * node)
{
	root = node; //root is node
}

bool AVLTree::Insert(CityData * node)
{ //insert
	
	if (root == NULL)
	{ //if root is NULL
		root = new AVLNode; //make new node
		root->SetCityData(node);
	
	}
	else
	{ //else
		while(1) //while
		{//already exist root
			//Locate insertion point for id
			AVLNode *a = root,
				*pa = NULL, //pa is null
				*p = this->root, // p is this root
				*pp = NULL, // pp get NULL
				*rootSub = NULL; //root sub
			while(p!=NULL) //while p is not null
			{
				if(p->GetmBF() != 0){a =p;pa =pp;} // get bf of p is not 0 a is p  , pa is pp
				if (strncmp(node->Getname(), p->GetCityData()->Getname(),sizeof(node->Getname())) < 0)
				{ // if node name is smaller than p's name
					pp = p; // pp is p
					p = p->GetLeft(); // p go left
				}
				else if (strncmp(node->Getname(), p->GetCityData()->Getname(),sizeof(node->Getname()))> 0)
				{ // if node name is bigger than p's name
					pp = p; //pp is p
					p = p->GetRight(); // p get right
				}
				else
				{ // else
					delete node; //delete node
					return false; // return false
				}	
			}
			AVLNode * y = new AVLNode; //make new node
			y->SetCityData(node); //set citydata
			y->SetLeft(NULL);
			y->SetRight(NULL);
			if (strncmp(node->Getname(), pp->GetCityData()->Getname(),sizeof(node->Getname())) < 0) //if node name is smaller than pp'sname
			pp->SetLeft(y); //pp go left
			else //else
			pp->SetRight(y); //pp set y
			int d;
			AVLNode *b,*c;
			if (strncmp(node->Getname(), a->GetCityData()->Getname(),sizeof(node->Getname())) > 0)
			{ // if node's name is bigger than a's name
				p = a->GetRight(); //p is a's left
				b = p; // b is p
				d = -1; // d is -1
			}
			else
			{ //
				p = a->GetLeft(); //p is a's left
				b = p; //b is p
				d =1; // diff is 1
			}
			while(p!=y)
			{ //while until p is not y
				if(strncmp(node->Getname(),p->GetCityData()->Getname(),sizeof(node->Getname()))>0)
				{ //if nod's name is bigger than p's name
					p->SetmBF(-1); //p's bf is -1
					p=p->GetRight(); //p is p's right
				}
				else
				{//else
					p->SetmBF(1); //p 's bf is 1
					p=p->GetLeft(); //p is p's left
				}
			}
			if(a->GetmBF()==0|| a->GetmBF()+d==0)
			{ // id a's bf is 0 or a's bf+d is 0
				a->SetmBF(a->GetmBF()+d); //a's bf is a's left's bf+d
				break;
			}
			if(d ==1 )
			{ //if d ==1
				if(b->GetmBF()==1)
				{ //b's bf is 1 type ll
					a->SetLeft(b->GetRight()); //a left is b's right
					b->SetRight(a); //b set right a
					a->SetmBF(0); //set a's bf 0
					b->SetmBF(0); //set b mf
					rootSub = b; //roootxub is b
				}
				else
				{ //else  typr lr
					c = b->GetRight(); // c is b's right
					b->SetRight(c->GetLeft()); //set b right is c's left
					a->SetLeft(c->GetRight()); //set a left is c's right
					c->SetLeft(b); //c set left b
					c->SetRight(a);
					switch (c->GetmBF())
					{
					case 0:
						b->SetmBF(0); a->SetmBF(0);
						break;
					case 1:
						a->SetmBF(-1); b->SetmBF(0);
						break;
					case -1:
						b->SetmBF(1); a->SetmBF(0);
						break;
					}
					c->SetmBF(0); rootSub =c;
				}
			}
			else
			{
				if (b->GetmBF() == -1)
				{//rotation type RR
					a->SetRight(b->GetLeft());
					b->SetLeft(a);
					a->SetmBF(0);
					b->SetmBF(0);
					rootSub = b;//b is the new root of the subtree
				}
				else
				{//rotation type RL
					c = b->GetLeft();
					b->SetLeft(c->GetRight());
					a->SetRight(c->GetLeft());
					c->SetRight(b);
					c->SetLeft(a);
					switch (c->GetmBF())
					{
					case 0:
						b->SetmBF(0); a->SetmBF(0);
						break;
					case 1:
						b->SetmBF(-1); a->SetmBF(0);
						break;
					case -1:
						a->SetmBF(1); b->SetmBF(0);
						break;
					}
					c->SetmBF(0); rootSub = c;//c is the new root of the subtree
				}//end of RL
			}
			if (pa == NULL) root = rootSub; //finish while and if pa is nULL root ;s rootsub
			else if (a == pa->GetLeft()) pa->SetLeft(rootSub); //else id a is pa'sleft pa left is rootsub
			else pa->SetRight(rootSub); //else pa set right is root sub
			break;
		}
			
	}
	return true;
}

CityData * AVLTree::Delete(int num)
{
	AVLNode * del = new AVLNode();
	//Setroot(del);
	del = root;
	num2 = num;
	AVLNode * num_node = new AVLNode();
	num_node = inorder_tree(del);
	if (num_node == NULL)
		return NULL;
	AVLNode * prev = NULL;
	AVLNode * pw = NULL;
	AVLNode * prev_w = NULL;
	AVLNode * wa = NULL;
	if (Getroot() == NULL)
	{ //if root is NULL
		return 0; //return 0;
	}
	while (del)
	{ //while del is exist
		if (strncmp(num_node->GetCityData()->Getname(),del->GetCityData()->Getname(),sizeof(num_node->GetCityData()->Getname()))==0)
			break;//if num_node's name is del's name is same
		prev = del; 
		if (strncmp(num_node->GetCityData()->Getname(),del->GetCityData()->Getname(),sizeof(num_node->GetCityData()->Getname()))>0)
			del = del->GetRight();//or bigger
		else
			del = del->GetLeft();
	}
	
	//only root node
	if (del == Getroot() && del->GetLeft() == NULL && del->GetRight() == NULL)
	{ 
		Setroot(NULL); //root is null
		delete prev; //delete prev
	}
	else if (del->GetLeft() == 0 && del->GetRight() == 0)
	{//no child
		if (prev == NULL)
			return 0;
		if (prev->GetLeft() == del)
		{ //if prev left is del
			prev->SetLeft(NULL); //set prev's left is null
			delete del; //delete del
		}
		else
		{ //else
			prev->SetRight(NULL); //prev set right is null
			delete del; //delete del
		}
	}
	else if(del->GetLeft() == NULL || del->GetRight() == NULL) //else if del go lfet is NULL or del right is null
	{// 1child
		if (del->GetLeft() == NULL && del->GetRight() != NULL)
		{//(right)
			if (prev == NULL) //if prev is null
				Setroot(del->GetRight()); //set root del get right
			else if (prev->GetLeft() == del) //else if prev get left is del
				prev->SetLeft(del->GetRight()); //prev set left is del's right
			else //else
				prev->SetRight(del->GetRight()); //prev right is del's right
			delete del; //delete del
		}
		else if (del->GetLeft() != NULL && del->GetRight() == NULL)
		{//left
			if (prev == NULL) //if prev is null
				Setroot(del->GetLeft()); //set root
			else if (prev->GetLeft() == del) //else if prev left is del
				prev->SetLeft(del->GetLeft()); //prev set left is del's left
			else 
				prev->SetRight(del->GetLeft()); //prev set right is del's left
			delete del; //delete del
		}
	}
	else
	{ //else if del node has two child
		AVLNode *prevprev = del;
		AVLNode * prev = prevprev->GetLeft();
		while (prev->GetRight() != NULL)
		{//while prev 's right is not null
			prevprev = prev; //pp is p
			prev = prev->GetRight(); //p is p'sright
		}
		if (prev->GetLeft() != NULL)
		{//if prev get left is not null
			if (prevprev->GetLeft() == prev) //if pp left is prev
				prevprev->SetLeft(prev->GetLeft()); //pp left is p's left
			else //else
				prevprev->SetRight(prev->GetLeft()); //pp set right is p's left
		}
		else
		{ //else
			if (prevprev->GetLeft() == prev)
				prevprev->SetLeft(NULL); //pp's left is null
			else
				prevprev->SetRight(NULL); //pp's right is null
		}
		if (del == Getroot())
		{//if dell is root
			Setroot(prev);
			//root = prev;
		}
		del->SetCityData(prev->GetCityData());//del get data is prev's data
		del = prev; //del is prev
		delete del; //delete del
		del = NULL;
	}
	AVLNode * p = Getroot();
	p->SetmBF(diff(Getroot()));
	if (p->GetmBF() > 1)
	{//ll, lr
		if (diff(Getroot()->GetLeft()) > 0)
		{//ll
			Setroot(ll(p));
		}
		else
		{//lr
			Setroot(lr(p));
		}
	}
	else if (p->GetmBF() < -1)
	{//rr, rl
		if (diff(Getroot()->GetRight()) > 0)
		{//rl
			Setroot(rl(p));
		}
		else
		{//rr
			Setroot(rr(p));
		}
	}
}

bool AVLTree::Print(AVLNode * root)
{
	stack<AVLNode*> T = *new stack<AVLNode*>;
   AVLNode* a = root;//make stack
   if (a == NULL) return false; //if a is null return false

   while (1) 
   { 
      while (a) 
	  { //while a is not null
         T.push(a); //stack insert a
         a = a->GetLeft(); //a is a'sleft
      }
      if (T.empty()) break; //if t is empty than break
      a = T.top(); //a is top of stack
      T.pop(); //delete
      *flog << "(" << a->GetCityData()->GetLocationId() << ", " << a->GetCityData()->Getname() << ", " << a->GetCityData()->Getcountry() << ")" << endl;
      a = a->GetRight();//a is a's right
   }
   return true;
}

int AVLTree::height(AVLNode * temp)
{
	int h = 0;
	if (temp != NULL)
	{ //reculsivly call fucntion
		int left = height(temp->GetLeft()); //go left
		int right = height(temp->GetRight()); //go right
		int max_h = max(left, right); //max left or right
		h = max_h + 1; //h is max+1
	}
	return h;
}

int AVLTree::diff(AVLNode * temp)
{ //make diff 
	int left = height(temp->GetLeft());
	int right = height(temp->GetRight());
	int factor = left - right;
	return factor;
}

AVLNode * AVLTree::rr(AVLNode * parent)
{ //rr fuction
	AVLNode * temp;
	temp = parent->GetRight();
	parent->SetRight(temp->GetLeft());
	temp->SetLeft(parent);
	return temp;
}

AVLNode * AVLTree::ll(AVLNode * parent)
{ //ll type
	AVLNode * temp;
	temp = parent->GetLeft();
	parent->SetLeft(temp->GetRight());
	temp->SetRight(parent);
	return temp;
}

AVLNode * AVLTree::lr(AVLNode * parent)
{ // lr type
	AVLNode * temp;
	temp = parent->GetLeft();
	parent->SetLeft(rr(temp));
	return ll(parent);
}

AVLNode * AVLTree::rl(AVLNode * parent)
{ //rl type
	AVLNode * temp;
	temp = parent->GetRight();
	parent->SetRight(ll(temp));
	return rr(parent);
}
AVLNode * AVLTree::inorder_tree(AVLNode * tree)
{ //inorder tree
	if (tree)
	{
		inorder_tree(tree->GetLeft());
		if (tree->GetCityData()->GetLocationId() == num2)
		{
			sa = tree;
		}
		inorder_tree(tree->GetRight());

	}
	return sa;
}


