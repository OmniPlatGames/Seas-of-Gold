#include "vector3d.h"
#include "irrString.h"

typedef irr::core::vector3d<float> vector3d;
typedef irr::core::string<char> string;

class WorldObject{
	vector3d m_v3Loc;
	vector3d m_v3Rot;
	vector3d m_v3Scale;
	long m_lGUID;
	string m_isName;
	int m_iModelID;
	bool m_bClipping;
	bool m_bVisible;
	long m_lOwner;

	void generateGUID(long* GUIDList[], int len)
	{
		long tmp = abs(rand()*rand() - rand());
		bool test = true;
		while (1){
			for (int i = 0; i < len; i++)
			{
				if (*GUIDList[i] == tmp)
					test = false;
			}
			if (!test)
			{
				tmp = abs(rand()*rand() - rand());
				test = true;
			}
			else
				break;
		}
		m_lGUID = tmp;
	}

public:
	inline vector3d* getLocation() { return &m_v3Loc; };
	inline void setLocation(vector3d newLoc) { m_v3Loc = vector3d(newLoc); };
	inline void setLocation(float x, float y, float z){ m_v3Loc = vector3d(x, y, z); };
	inline vector3d* getRotation() { return &m_v3Rot; };
	inline void setRotation(vector3d newRot){ m_v3Rot = vector3d(newRot); };
	inline void setRotation(float x, float y, float z){ m_v3Rot = vector3d(x, y, z); };
	inline vector3d* getScale() { return &m_v3Scale; };
	inline void setScale(vector3d newScale){ m_v3Scale = vector3d(newScale); };
	inline void setScale(float x, float y, float z){ m_v3Scale = vector3d(x, y, z); };
	inline long getGUID(){ return m_lGUID; };
	inline string getName(){ return m_isName; };
	inline int getModelById(){ return m_iModelID; };
	inline bool hasClipping(){ return m_bClipping; };
	inline bool isVisible(){ return m_bVisible; };
	inline long getOwner(){ return m_lOwner; };
	inline void setOwner(long ownGUID){ m_lOwner = ownGUID; };

	WorldObject(vector3d* l, vector3d* r, vector3d* s, string n, int m, bool c, bool v, long* GUIDList[], int len);
};