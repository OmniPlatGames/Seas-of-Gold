// 
// Mission.h
//
// This is a header file that contains the following: Mission Class

// Includes
#include "Common.h"


// Mission Class
class Mission
{
	// Constructor
public:
	Mission();
	//Mission(long ID,  irrstring DispName, irrstring GoalText, Items* isReq, Items* isRew, int GoldRew);

	// Members 
public:

private:
	long m_1ID; // Mission ID
	irrstring m_isDisplayName; // Visible name
	irrstring m_isGoalText; // Description Text for mission

	// The following are blocked out because there is no "Item" class yet

	// Item* m_itRequired; // Required item(s) for this mission
	// Item* m_itReward; // Rewarded item(s) for this mission

	int m_iGoldReward; // Gold reward for this mission
	long m_1TurnInGUID; // Generated GUID for quest turn in

	bool m_Completed; // Whether or not the mission is completed

	// Methods
public:
	long getMissionID(); // Returns m_1ID
	irrstring getDisplayName(); // Returns m_isDisplayName
	irrstring getGoalText(); // Returns m_isGoalText

	// Item* getRequiredItems(); // Returns m_itRequired
	// Item* getRewardItems(); // Returns m_itReward

	int getRewardGold(); // Returns m_iGoldReward
	long getTurnInGUID(); // Return m_1TurnInGUID

	void completeMission(); // Sets the m_Completed flag to true.
	bool isCompleted(); // Returns m_Completed
private:

};