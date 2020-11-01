#include "BinarySearchTree.h"
#include <iostream>
#include <string>

class TransferWindowManager
{
	//friend class BinarySearchTree;
private:
	int m_budget;

	BinarySearchTree fwBST;
	BinarySearchTree mfBST;
	BinarySearchTree dfBST;
	BinarySearchTree gkBST;
	int fw_c;
	int mf_c;
	int df_c;
	int gk_c;
	BinarySearchTree  fw_arr[20];
	BinarySearchTree  mf_arr[20];
	BinarySearchTree  df_arr[20];
	BinarySearchTree  gk_arr[20];

public:

	struct SoccerTeam //struct
	{
		SoccerPlayerData fw;
		SoccerPlayerData mf;
		SoccerPlayerData df;
		SoccerPlayerData gk;

		int sum_transfer_fee;  //sum fee is int
		int sum_ability;

		SoccerTeam(); // function declaer
		SoccerTeam(SoccerPlayerData fw, SoccerPlayerData mf, SoccerPlayerData df, SoccerPlayerData gk);// function declaer
		friend std::ostream& operator<<(std::ostream& os, const SoccerTeam& team);// function declaer
	};

	TransferWindowManager(std::string file_dir, int budget);// function declaer

	
	friend std::ostream& operator<<(std::ostream& os, const TransferWindowManager& manager);// print by position

	const SoccerTeam getBestTeam();// function declaer

};


