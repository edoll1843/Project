#define _CRT_SECURE_NO_WARNINGS
#include "TransferWindowManager.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
TransferWindowManager::SoccerTeam::SoccerTeam()
{
}

TransferWindowManager::SoccerTeam::SoccerTeam(SoccerPlayerData fw, SoccerPlayerData mf, SoccerPlayerData df, SoccerPlayerData gk)
{ //this point best team's position and sum fee,ablility
	this->fw = fw;
	this->mf = mf;
	this->df = df;
	this->gk = gk;

	this->sum_transfer_fee = fw.m_transfer_fee + mf.m_transfer_fee + df.m_transfer_fee + gk.m_transfer_fee;
	this->sum_ability = fw.m_ability + mf.m_ability + df.m_ability + gk.m_ability;
}

std::ostream& operator<<(std::ostream& os, const TransferWindowManager::SoccerTeam& team)
{ // prnt best team
	os << team.fw << std::endl;
	os << team.mf << std::endl;
	os << team.df << std::endl;
	os << team.gk << std::endl;

	os << "sum_transfer_fee " << team.sum_transfer_fee << std::endl;
	os << "sum_ability " << team.sum_ability << std::endl;

	return os;
}


TransferWindowManager::TransferWindowManager(std::string file_dir, int budget)
{
	fw_c = 0;//declear count 
	gk_c = 0;
	mf_c = 0;
	df_c = 0;

	m_budget = budget;
	std::ifstream in(file_dir); //read file
	std::string line; //get line by string
	char str_buf[100];
	string str_name;
	string str_position;
	while (std::getline(in, line)) //read while text is end
	{
		strcpy(str_buf, line.c_str());
		char * name_ = strtok(str_buf,",");//tok by name
		char * position_ = strtok(NULL ,","); //position
		char * pay_ = strtok(NULL, ","); //fee
	    char * abli_ = strtok(NULL, "\t"); //ablility
		str_name = string(name_); //change name to string
		str_position = string(position_); //change position to position
		int int_pay = atoi(pay_); //change char fee
		int int_abli = atoi(abli_); //change ablility to char
		SoccerPlayerData * player_data = new SoccerPlayerData(str_name, str_position, int_pay, int_abli);// make player node
		TreeNode * player = new TreeNode(*player_data, NULL, NULL);//insert


		if (str_position == " Forward") //if fw
		{
			fwBST.insert(*player_data); //insert
			fw_arr[fw_c].insert_arr(*player_data);
			fw_c++;
		}
		else if (str_position == " Goalkeeper") //if gk
		{
			gkBST.insert(*player_data); //insert
			gk_arr[gk_c].insert_arr(*player_data);
			gk_c++;
		}
		else if (str_position == " Midfielder")//if mf
		{
			mfBST.insert(*player_data); //insert
			mf_arr[mf_c].insert_arr(*player_data);
			mf_c++;
		}
		else if (str_position == " Defender") //if df
		{
			dfBST.insert(*player_data); //insert
			df_arr[df_c].insert_arr(*player_data);
			df_c++;
		}
			
	}
}

std::ostream& operator<<(std::ostream& os, const TransferWindowManager& manager)//print all player by position
{
	os << "********Forward List********" << std::endl;
	os << manager.fwBST;//print bst
	os << "****************************" << std::endl;

	os << "********Midflder List********" << std::endl;
	os << manager.mfBST;
	os << "*****************************" << std::endl;

	os << "********Defender List********" << std::endl;
	os << manager.dfBST;
	os << "*****************************" << std::endl;

	os << "********Goalkeeper List********" << std::endl;
	os << manager.gkBST;
	os << "*******************************" << std::endl;

	return os;
}


const TransferWindowManager::SoccerTeam TransferWindowManager:: getBestTeam()
{//make bestteam

	SoccerTeam  best_team;//make team
	best_team.sum_ability = 0;//reset
	best_team.sum_transfer_fee = 0;
	best_team.fw.m_ability = 0;
	best_team.mf.m_ability = 0;
	best_team.df.m_ability = 0;
	best_team.gk.m_ability = 0;

	for (int z = 0; z < fw_c; z++) //for all fw's player 
	{
		for (int x = 0; x < mf_c; x++) //for all mf's player 
		{
			for (int y = 0; y < df_c; y++) //for all df's player 
			{
				for (int w = 0; w < gk_c; w++) //for all gk's player 
				{ 
					if (fw_arr[z].m_root->m_data.m_transfer_fee 
						+ mf_arr[x].m_root->m_data.m_transfer_fee 
						+ df_arr[y].m_root->m_data.m_transfer_fee
						+ gk_arr[w].m_root->m_data.m_transfer_fee <= m_budget)
					{// if team's sum fee is rower or same with budget
						if (best_team.fw.m_ability == 0 && best_team.mf.m_ability == 0 && best_team.df.m_ability == 0 && best_team.gk.m_ability == 0)
						{//reset
							best_team.fw = fw_arr[z].m_root->m_data;
							best_team.mf = mf_arr[x].m_root->m_data;
							best_team.df = df_arr[y].m_root->m_data;
							best_team.gk = gk_arr[w].m_root->m_data;
							best_team.sum_ability = best_team.df.m_ability + best_team.fw.m_ability + best_team.gk.m_ability + best_team.mf.m_ability;
						}
						if (best_team.sum_ability <=
							fw_arr[z].m_root->m_data.m_ability 
							+ mf_arr[x].m_root->m_data.m_ability 
							+ df_arr[y].m_root->m_data.m_ability 
							+ gk_arr[w].m_root->m_data.m_ability)
						{ //if sum abli is rower than team's sum abli
							if (best_team.sum_ability ==
								fw_arr[z].m_root->m_data.m_ability
								+ mf_arr[x].m_root->m_data.m_ability
								+ df_arr[y].m_root->m_data.m_ability
								+ gk_arr[w].m_root->m_data.m_ability)
							{//is sum abli and team sum abli is same
								if (fw_arr[z].m_root->m_data.m_transfer_fee
									+ mf_arr[x].m_root->m_data.m_transfer_fee
									+ df_arr[y].m_root->m_data.m_transfer_fee
									+ gk_arr[w].m_root->m_data.m_transfer_fee
									< best_team.fw.m_transfer_fee + best_team.df.m_transfer_fee
									+ best_team.mf.m_transfer_fee + best_team.gk.m_transfer_fee)
								{ //sum fee is cheper than best_team 
									best_team.fw = fw_arr[z].m_root->m_data;
									best_team.mf = mf_arr[x].m_root->m_data;
									best_team.df = df_arr[y].m_root->m_data;
									best_team.gk = gk_arr[w].m_root->m_data;
									best_team.sum_ability = best_team.df.m_ability + best_team.fw.m_ability + best_team.gk.m_ability + best_team.mf.m_ability;
									//insert data.
								}

							}
							else
							{ // insert data
								best_team.fw = fw_arr[z].m_root->m_data;
								best_team.mf = mf_arr[x].m_root->m_data;
								best_team.df = df_arr[y].m_root->m_data;
								best_team.gk = gk_arr[w].m_root->m_data;
								best_team.sum_ability = best_team.df.m_ability + best_team.fw.m_ability + best_team.gk.m_ability + best_team.mf.m_ability;
							}
						}
					}
				}
			}
		}
	}	
	best_team.sum_transfer_fee = best_team.df.m_transfer_fee + best_team.fw.m_transfer_fee + best_team.gk.m_transfer_fee + best_team.mf.m_transfer_fee;

	fwBST.deletion(best_team.fw.m_ability);// delete player
	mfBST.deletion(best_team.mf.m_ability);// delete player
	dfBST.deletion(best_team.df.m_ability);// delete player
	gkBST.deletion(best_team.gk.m_ability);// delete player
	
	return best_team; //return
}


























#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// ��� ����ü�� �����մϴ�.
struct nodeAVL
{
	int data;
	struct nodeAVL *left;
	struct nodeAVL *right;
} *root;

// Ŭ������ �����մϴ�.
class classAVL
{
public:
	// ����� ���̸� ��ȯ�մϴ�. 
	int height(nodeAVL *);
	// �����μ�(������ ����)�� ��ȯ�մϴ�. 
	int diff(nodeAVL *);
	// RR ȸ�� �Լ��Դϴ�. 
	nodeAVL *rr(nodeAVL *);
	// LL ȸ�� �Լ��Դϴ�. 
	nodeAVL *ll(nodeAVL *);
	// LR ȸ�� �Լ��Դϴ�. 
	nodeAVL *lr(nodeAVL *);
	// RL ȸ�� �Լ��Դϴ�. 
	nodeAVL *rl(nodeAVL *);
	// Ʈ���� ������ ���ߴ� �Լ��Դϴ�. 
	nodeAVL *balance(nodeAVL *);
	// AVL Ʈ���� ���ο� ���Ҹ� �����մϴ�. 
	nodeAVL *insert(nodeAVL *, int);
	// ������ AVL Ʈ�� ������ �����ִ� �Լ��Դϴ�. 
	void display(nodeAVL *, int);
	// AVL Ʈ���� ���� ��ȸ�մϴ�. 
	void inorder(nodeAVL *);
	// AVL Ʈ���� ���� ��ȸ�մϴ�. 
	void preorder(nodeAVL *);
	// AVL Ʈ���� ���� ��ȸ�մϴ�. 
	void postorder(nodeAVL *);
	// classAVL�� �������Դϴ�.
	classAVL()
	{
		root = NULL;
	}
};

int main(void)
{
	int choice, item;
	classAVL AVL;
	while (1)
	{
		cout << "\n----------------------------" << endl;
		cout << "    C++�� ������ AVL Ʈ��" << endl;
		cout << "----------------------------" << endl;
		cout << "1. ���Ҹ� �����ҷ���." << endl;
		cout << "2. AVL Ʈ���� �����ּ���." << endl;
		cout << "3. ���� ��ȸ�� �ϰ�;��." << endl;
		cout << "4. ���� ��ȸ�� �ϰ�;��." << endl;
		cout << "5. ���� ��ȸ�� �ϰ�;��." << endl;
		cout << "6. ���α׷��� �����ҷ���." << endl;
		cout << "����� ������ �Է��ϼ��� : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "������ ������ �Է��ϼ��� : ";
			cin >> item;
			root = AVL.insert(root, item);
		case 2:
			if (root == NULL)
			{
				cout << "���� Ʈ���� ������ϴ�." << endl;
				continue;
			}
			cout << "[ AVL Ʈ�� ��� ]" << endl;
			AVL.display(root, 1);
			break;
		case 3:
			cout << "[ ���� ��ȸ ]" << endl;
			AVL.inorder(root);
			cout << endl;
			break;
		case 4:
			cout << "[ ���� ��ȸ ]" << endl;
			AVL.preorder(root);
			cout << endl;
			break;
		case 5:
			cout << "[ ���� ��ȸ ]" << endl;
			AVL.postorder(root);
			cout << endl;
			break;
		case 6:
			exit(1);
			break;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
	}
	return 0;
}

// AVL Ʈ���� ���̸� ����մϴ�.
int classAVL::height(nodeAVL* temp)
{
	int h = 0;
	if (temp != NULL)
	{
		// ��������� ���� Ȥ�� ���������� �˻��մϴ�. 
		int left = height(temp->left);
		int right = height(temp->right);
		int maxHeight = max(left, right);
		h = maxHeight + 1;
	}
	return h;
}

// �����μ�(������ ����)�� ��ȯ�մϴ�.
int classAVL::diff(nodeAVL* temp)
{
	// ���� �ڽ��� ���̿� ������ �ڽ��� ���� ���̸� ��ȯ�մϴ�. 
	int left = height(temp->left);
	int right = height(temp->right);
	int factor = left - right;
	return factor;
}

// RR ȸ�� �Լ��Դϴ�.
nodeAVL *classAVL::rr(nodeAVL* parent)
{
	// ���� ȸ������ �׳� �θ� ����� ������ �ڽĳ��� �����͸� ��ȯ�ϴ� ���Դϴ�. 
	nodeAVL *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

// ll ȸ�� �Լ��Դϴ�.
nodeAVL *classAVL::ll(nodeAVL* parent)
{
	// RR ȸ���� �ݴ��Դϴ�. 
	nodeAVL *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

// LR ȸ�� �Լ��Դϴ�. 
nodeAVL *classAVL::lr(nodeAVL* parent)
{
	// LR ȸ���� ���� �ڽ��� �������� RR, ������ �������� LLȸ���մϴ�. 
	nodeAVL * temp;
	temp = parent->left;
	parent->left = rr(temp);
	return ll(parent);
}

// RL ȸ�� �Լ��Դϴ�.
nodeAVL *classAVL::rl(nodeAVL* parent)
{
	// LR ȸ���� �ݴ��Դϴ�.
	nodeAVL * temp;
	temp = parent->right;
	parent->right = ll(temp);
	return rr(parent);
}

// AVL Ʈ���� ������ ���ߴ� �Լ��Դϴ�.
nodeAVL *classAVL::balance(nodeAVL *temp)
{
	int factor = diff(temp);
	// ���� ����Ʈ�������� ������ �Ǿ� ������ ���� ����Դϴ�. 
	if (factor > 1)
	{
		// �� ���� �ڽĳ�忡 ������ �߻��߽��ϴ�. 
		if (diff(temp->left) > 0)
		{
			temp = ll(temp);
		}
		// �� ������ �ڽ� ��忡 ������ �߻��߽��ϴ�. 
		else
		{
			temp = lr(temp);
		}
	}
	else if (factor < -1)
	{
		if (diff(temp->right) > 0)
		{
			temp = rl(temp);
		}
		else
		{
			temp = rr(temp);
		}
	}
	return temp;
}

// Ʈ���� ���Ҹ� �����ϴ� �Լ��Դϴ�.
nodeAVL * classAVL::insert(nodeAVL *root, int value)
{
	// ���� Ʈ���� ����� �� 
	if (root == NULL)
	{
		root = new nodeAVL;
		root->data = value;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if (value < root->data)
	{
		root->left = insert(root->left, value);
		root = balance(root);
	}
	// ũ�ų� ���� ��� ������ ����Ʈ���� �����մϴ�. 
	else if (value >= root->data)
	{
		root->right = insert(root->right, value);
		root = balance(root);
	}
	return root;
}

void classAVL::display(nodeAVL * ptr, int level)
{
	int i;
	// ���� Ʈ���� ������� ���� ����Դϴ�. 
	if (ptr != NULL)
	{
		display(ptr->right, level + 1);
		printf("\n");
		// ���� ��Ʈ ����� ����Դϴ�. 
		if (ptr == root)
		{
			cout << "Root -> ";
		}
		// i�� ���������� ���� ��Ʈ�� �ƴ� ����� ������ �Դϴ�. 
		for (i = 0; i < level && ptr != root; i++)
		{
			cout << "        ";
		}
		// �ڽ��� ��ġ�� �����͸� ����մϴ�. 
		cout << ptr->data;
		// ���� ��嵵 ������ݴϴ�.
		display(ptr->left, level + 1);
	}
}

/* Ʈ���� ��ȸ�ϴ� �� ���� �Լ��Դϴ�. */
void classAVL::inorder(nodeAVL *tree)
{
	if (tree == NULL)
		return;
	inorder(tree->left);
	cout << tree->data << "  ";
	inorder(tree->right);
}
void classAVL::preorder(nodeAVL *tree)
{
	if (tree == NULL)
		return;
	cout << tree->data << "  ";
	inorder(tree->left);
	inorder(tree->right);
}
void classAVL::postorder(nodeAVL *tree)
{
	if (tree == NULL)
		return;
	inorder(tree->left);
	inorder(tree->right);
	cout << tree->data << "  ";
}