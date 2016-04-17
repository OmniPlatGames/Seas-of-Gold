// 
// Mission.h
//
// This is a header file that contains the following: Mission Class

// Includes
#include "Common.h"


// Mission Class
class Mission
{
	long m_loID; // Mission ID
	irrstring m_isDisplayName; // Visible name
	irrstring m_isGoalText; // Description Text for mission

	// The following are blocked out because there is no "Item" class yet

	// Item* m_itRequired; // Required item(s) for this mission
	// Item* m_itReward; // Rewarded item(s) for this mission

	int m_iGoldReward; // Gold reward for this mission
	long m_loTurnInGUID; // Generated GUID for quest turn in

	bool m_bCompleted; // Whether or not the mission is completed

	// Methods
public:
	// Returns m_1ID
	inline long getMissionID(){ return m_loID; };
	inline irrstring getDisplayName(){ return m_isDisplayName; }; // Returns m_isDisplayName
	inline irrstring getGoalText(){ return m_isGoalText; }; // Returns m_isGoalText

	// Item* getRequiredItems(); // Returns m_itRequired
	// Item* getRewardItems(); // Returns m_itReward

	inline int getRewardGold(){ return m_iGoldReward; }; // Returns m_iGoldReward
	inline long getTurnInGUID(){ return m_loTurnInGUID; }; // Return m_1TurnInGUID

	void completeMission(); // Sets the m_Completed flag to true.
	inline bool isCompleted(){ return m_bCompleted; }; // Returns m_Completed
	
	Mission();
	//Mission(long ID,  irrstring DispName, irrstring GoalText, Items* isReq, Items* isRew, int GoldRew);

	// Members 
};