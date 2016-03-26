#include "Unit.h"

class Vendor : public Unit
{
private:
	int vendorType;
	bool hasMissions;
	//Missions* missionTable;

public:
	Vendor(){}
	~Vendor(){}

	int getVendorType();
	bool vendorHasMissions();
	bool vendorMissionComplete(int missionID);
	//Mission* vendorMissionAccept();
};