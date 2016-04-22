#include "Unit.h"

Unit::Unit()
{
}


Unit::~Unit()
{
}

void Unit::update(v3d dir, float dt)
{
	
	v3d v3Direction = dir.normalize();
	v3d* v3CurrentLocation = getLocation();

	setLocation(*v3CurrentLocation + (v3Direction * fSpeed * dt));
}

int Unit::modifyGold(int i)
{
	if (i < iGold)
	{
		iGold += i;
		return 0;
	}
	else
	{
		return (iGold - i);
	}
}

void Unit::AddGold(int amnt)
{
	iGold += amnt;
}

void Unit::RemoveGold(int amnt)
{
	iGold -= amnt;

	if (iGold < 0)
		iGold == 0;
}