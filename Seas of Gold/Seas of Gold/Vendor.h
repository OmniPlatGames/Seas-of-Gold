#pragma once
#include "Unit.h"
#include <irrString.h>
struct mission { irrString missionName; bool isComplete; };

class Vendor : public Unit
{
	int ivendorType;
	bool bHasMissions;
	mission* missionTable[];
public:
	Vendor();
	~Vendor();

	inline int getVendorType() { return ivendorType; };
	inline bool vendorHasMissions(){ return bHasMissions; };
	inline bool vendorMissionComplete(int missionIndex) {
		return missionTable[missionIndex]->isComplete;
	};
	inline mission vendorMissionAccept(int missionIndex){
		return *missionTable[missionIndex];
	};
};

