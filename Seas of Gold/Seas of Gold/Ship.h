#pragma once

#include "Common.h"

class Ship
{
public:
	Ship();

	void SetSupplyCost(int sc);
	void SetSupplies(int s);
	void SetSupplyMax(int sm);
	void SetCrewMax(int cm);
	void SetCrew(int c);

	int GetSupplyCost();
	int GetSupplies();
	int GetSupplyMax();
	int GetCrewMax();
	int GetCrew();

	void RemoveSupplies(int amnt);
	void RemoveCrew(int amnt);

	void AddSupplies(int amnt);
	void AddCrew(int amnt);
private:
	int Supplies;
	int SupplyCost;
	int SupplyMax;
	int CrewMax;
	int Crew;
};