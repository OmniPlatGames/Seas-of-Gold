#pragma once
#include "Unit.h"
#include <irrString.h>
struct mission { irrString missionName; bool isComplete; };

class Vendor : public Unit
{
public:
	Vendor();
	~Vendor();

	int getVendorType();
	bool vendorHasMissions();
	bool vendorMissionComplete(int missionIndex);
	mission vendorMissionAccept(int missionIndex);

private:
	int vendorType;
	bool hasMissions;
	mission* missionTable[];
};

