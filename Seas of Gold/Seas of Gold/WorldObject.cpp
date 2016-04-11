#include "WorldObject.h"

WorldObject::WorldObject(v3d* l, v3d* r, v3d* s, irrString n, int m, bool c, bool v, long* GUIDList[], int len)
{
	m_v3Loc = v3d(*l);
	m_v3Rot = v3d(*r);
	m_v3Scale = v3d(*s);
	m_isName = irrString(n);
	m_iModelID = m;
	m_bClipping = c;
	m_bVisible = v;
	generateGUID(GUIDList, len);
}

WorldObject::WorldObject(){
	m_v3Loc = v3d(0, 0, 0);
	m_v3Rot = v3d(0, 0, 0);
	m_v3Scale = v3d(0, 0, 0);
	m_isName = irrString("NONAME");
	m_iModelID = 0;
	m_bClipping = true;
	m_bVisible = false;
	generateGUID(nullptr, 0);
}

void WorldObject::generateGUID(long* GUIDList[], int len){
	if (len = 0)
	{
		m_lGUID = -1;
		return;
	}
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