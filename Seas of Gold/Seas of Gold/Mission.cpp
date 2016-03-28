#include "Mission.h"

Mission::Mission()
{
	m_1ID = 0;
	irrstring m_isDisplayName = "Default Mission";
	irrstring m_isGoalText = "Default Mission Goal Text!";
	// m_itRequired = ?
	// m_itReward = ?
	m_iGoldReward = 0;
	m_1TurnInGUID = 0;
	m_Completed = false;
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

long Mission::getMissionID()
{
	return m_1ID;
}

irrstring Mission::getDisplayName()
{
	return m_isDisplayName;
}

irrstring Mission::getGoalText()
{
	return m_isGoalText;
}

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

int Mission::getRewardGold()
{
	return m_iGoldReward;
}

long Mission::getTurnInGUID()
{
	return m_1TurnInGUID;
}

void Mission::completeMission()
{
	m_Completed = true;
}

bool Mission::isCompleted()
{
	return m_Completed;
}