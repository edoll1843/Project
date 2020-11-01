#include <string>
#include <iostream>
class SoccerPlayerData
{
	friend class TreeNode; //friend class
	friend class BinarySearchTree;
	friend class TransferWindowManager;
private:
	std::string m_name; //name
	std::string m_position;//position
	int m_transfer_fee;// fee
	int m_ability;//ability

public:
	SoccerPlayerData() { } //function declaer
	SoccerPlayerData(std::string name, std::string position, int transfer_fee, int ability) // function declaer
		:
		m_name(name),
		m_position(position),
		m_transfer_fee(transfer_fee),
		m_ability(ability)
	{
	}
	friend std::ostream& operator<<(std::ostream& os, const SoccerPlayerData& node) {//visit
		os << "(node.m_name: " << node.m_name << "), " //print
			<< "(node.m_position: " << node.m_position << "), "
			<< "(node.m_transfer_fee: " << node.m_transfer_fee << "), "
			<< "(node.m_ability: " << node.m_ability << ")";
		return os;
	}
};

