#include "WorldObject.h"

WorldObject::WorldObject(vector3d* l, vector3d* r, vector3d* s, string n, int m, bool c, bool v, long* GUIDList[], int len){
	m_v3Loc = vector3d(*l);
	m_v3Rot = vector3d(*r);
	m_v3Scale = vector3d(*s);
	m_isName = string(n);
	m_iModelID = m;
	m_bClipping = c;
	m_bVisible = v;
	generateGUID(GUIDList, len);
}