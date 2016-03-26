#include "Vendor.h"

Vendor::Vendor()
{
}

Vendor::~Vendor()
{
}

int Vendor::getVendorType()
{
	return vendorType;
}

bool Vendor::vendorHasMissions()
{
	return hasMissions;
}

bool Vendor::vendorMissionComplete(int missionIndex)
{
	return missionTable[missionIndex]->isComplete;
}

mission Vendor::vendorMissionAccept(int missionIndex)
{
	return *missionTable[missionIndex];
}
