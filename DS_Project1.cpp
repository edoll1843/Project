#include <iostream>
#include "TransferWindowManager.h"

using namespace std;

int main(int argc, char** argv)
{
	TransferWindowManager transfer_window_manager(argv[1], atoi(argv[2]));//read argv[1](text) set budget(argv[2]) insert player's by position 
	cout << transfer_window_manager << endl; //and print
	TransferWindowManager::SoccerTeam team = transfer_window_manager.getBestTeam(); // make best team
	cout << "Best Players" << endl;
	cout << team << endl; //print best team and delete best team
	cout << "-----" << endl;
	cout << "The Transfer window close" << endl;
	cout << transfer_window_manager << endl; // print all team
	return 0;
}

