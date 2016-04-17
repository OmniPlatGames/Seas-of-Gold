#include "Mission.h"

Mission::Mission()
{
	m_loID = 0;
	irrstring m_isDisplayName = "Default Mission";
	irrstring m_isGoalText = "Default Mission Goal Text!";
	// m_itRequired = ?
	// m_itReward = ?
	m_iGoldReward = 0;
	m_loTurnInGUID = 0;
	m_bCompleted = false;
}

/*
Mission::Mission(long ID,  irrstring DispName, irrstring GoalText, Items* isReq, Items* isRew, int GoldRew);
{
	m_1ID = ID;
	irrstring m_isDisplayName = DispName;
	irrstring m_isGoalText = GoalText;
	// m_itRequired = isReq;
	// m_itReward = isRew;
	m_iGoldReward = GoldRew;
	m_1TurnInGUID = ? // However we generate this
	m_Completed = false;
}
*/

/*
Item* Mission::getRequiredItems()
{
	return m_itRequired;
}
*/

/*
Item* Mission::getRewardItems()
{
	return m_itReward;
}
*/

void Mission::completeMission()
{
	m_bCompleted = true;
}