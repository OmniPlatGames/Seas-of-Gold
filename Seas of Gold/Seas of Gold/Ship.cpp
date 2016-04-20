#include "Ship.h"

Ship::Ship()
{
	Supplies = 100;
	SupplyCost = 10;
	SupplyMax = 100;
	CrewMax = 10;
	Crew = 2;
}

void Ship::SetSupplyCost(int sc)
{
	SupplyCost = sc;
}

void Ship::SetSupplies(int s)
{
	Supplies = s;
}

void Ship::SetSupplyMax(int sm)
{
	SupplyMax = sm;
}

void Ship::SetCrewMax(int cm)
{
	CrewMax = cm;
}

void Ship::SetCrew(int c)
{
	Crew = c;
}

int Ship::GetSupplyCost()
{
	return SupplyCost;
}

int Ship::GetSupplies()
{
	return Supplies;
}

int Ship::GetSupplyMax()
{
	return SupplyMax;
}

int Ship::GetCrewMax()
{
	return CrewMax;
}

int Ship::GetCrew()
{
	return Crew;
}

void Ship::RemoveSupplies(int amnt)
{
	Supplies -= amnt;
	if (Supplies < 0)
		Supplies = 0;
}

void Ship::RemoveCrew(int amnt)
{
	Crew -= amnt;
	if (Crew < 0)
		Crew = 0;
}

void Ship::AddSupplies(int amnt)
{
	Supplies += amnt;
	if (Supplies > SupplyMax)
		Supplies = SupplyMax;
}

void Ship::AddCrew(int amnt)
{
	Crew += amnt;
	if (Crew > CrewMax)
		Crew = CrewMax;
}