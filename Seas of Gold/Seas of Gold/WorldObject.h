#pragma once

#include "vector3d.h"
#include "irrString.h"

typedef irr::core::vector3d<float> v3d;
typedef irr::core::string<char> irrString;

class WorldObject{
	v3d m_v3Loc;
	v3d m_v3Rot;
	v3d m_v3Scale;
	long m_lGUID;
	irrString m_isName;
	int m_iModelID;
	bool m_bClipping;
	bool m_bVisible;
	long m_lOwner;

	void generateGUID(long* GUIDList[], int len);

public:
	inline v3d* getLocation() { return &m_v3Loc; };
	inline void setLocation(v3d newLoc) { m_v3Loc = v3d(newLoc); };
	inline void setLocation(float x, float y, float z){ m_v3Loc = v3d(x, y, z); };
	inline v3d* getRotation() { return &m_v3Rot; };
	inline void setRotation(v3d newRot){ m_v3Rot = v3d(newRot); };
	inline void setRotation(float x, float y, float z){ m_v3Rot = v3d(x, y, z); };
	inline v3d* getScale() { return &m_v3Scale; };
	inline void setScale(v3d newScale){ m_v3Scale = v3d(newScale); };
	inline void setScale(float x, float y, float z){ m_v3Scale = v3d(x, y, z); };
	inline long getGUID(){ return m_lGUID; };
	inline irrString getName(){ return m_isName; };
	inline int getModelById(){ return m_iModelID; };
	inline bool hasClipping(){ return m_bClipping; };
	inline bool isVisible(){ return m_bVisible; };
	inline long getOwner(){ return m_lOwner; };
	inline void setOwner(long ownGUID){ m_lOwner = ownGUID; };

	WorldObject(v3d* l, v3d* r, v3d* s, irrString n, int m, bool c, bool v, long* GUIDList[], int len);
	WorldObject();
};