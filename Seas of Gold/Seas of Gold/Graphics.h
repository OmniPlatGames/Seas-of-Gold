#pragma once
#include "Common.h"

enum eRot {Pitch,Yaw,Roll};

class Graphics
{
public:
	Graphics();

	/*virtual v3d GetPosition();
	virtual v3d GetScale();
	virtual v3d GetRotation();

	virtual void SetPosition(v3d position);
	virtual void SetPosition(float x, float y, float z);
	virtual void SetScale(v3d scale);
	virtual void SetScale(float x, float y, float z);
	virtual void SetScale(float Uscale);
	virtual void SetRotation(v3d rotation);
	virtual void SetRotation(float Pitch, float Yaw, float Roll);*/

	virtual void Draw(irr::video::IVideoDriver* driver);
protected:
	/*v3d m_Position;
	v3d m_Scale;
	v3d m_Rotation;*/
};

class Graphics2D : public Graphics
{
public:
	Graphics2D();

	virtual v2d GetPosition();
	virtual irr::video::SColor GetColor();

	virtual void SetPosition(v2d Position);
	virtual void SetPosition(float x, float y);

	virtual void SetColor(irr::video::SColor Color);
	virtual void SetColor(int R, float G, float B, float A);
	virtual void SetColor(int R, float G, float B);
protected:
	v2d m_Position;
	irr::video::SColor m_Color;
};

class GraphicsRect : public Graphics2D
{
public:
	GraphicsRect();
	GraphicsRect(float x1, float y1, float x2, float y2);
	GraphicsRect(v2d Position, float width, float height);

	float GetWidth();
	float GetHeight();

	void SetWidth(float Width);
	void SetHeight(float Height);

	virtual void Draw(irr::video::IVideoDriver* driver) override;

protected:

	float m_Width;
	float m_Height;
};

class GraphicsImage : public GraphicsRect
{
public:
	GraphicsImage();
	GraphicsImage(float x1, float y1, float x2, float y2);
	GraphicsImage(v2d Position, float width, float height);

	virtual void SetTexture(irrstring texture, irr::video::IVideoDriver* driver);

	virtual void Draw(irr::video::IVideoDriver* driver) override;

protected:
	irr::video::ITexture* Texture;
	irr::core::dimension2d<int> Dimensions;
};

// Sprite doesn't function as expected so it won't draw anything right now.
class GraphicsSprite : public GraphicsImage
{
public:
	GraphicsSprite();
	GraphicsSprite(float x1, float y1, float x2, float y2);
	GraphicsSprite(v2d Position, float width, float height);

	virtual void SetTexture(irrstring texture, irr::video::IVideoDriver* driver) override;

	virtual void Draw(irr::video::IVideoDriver* driver) override;
protected:

};

// Not fully implemented.
class GraphicsCircle : public Graphics2D
{
public:
	GraphicsCircle();
	GraphicsCircle(float x, float y, float radius);
	GraphicsCircle(v2d Position, float radius);

	float GetRadius();
	virtual void SetRadius(float radius);

	void Draw(irr::video::IVideoDriver* driver) override;
protected:
	float m_Radius;
};

class Graphics3D : public Graphics
{
public:
	Graphics3D();

	virtual v3d GetPosition();
	virtual v3d GetScale();
	virtual v3d GetRotation();
	virtual irr::video::SColor GetColor();

	virtual void SetPosition(v3d Position);
	virtual void SetPosition(float x, float y, float z);
	virtual void SetScale(v3d scale);
	virtual void SetScale(float x, float y, float z);
	virtual void SetScale(float Uscale);
	virtual void SetRotation(v3d rotation);
	virtual void SetRotation(float Pitch, float Yaw, float Roll);
	virtual void SetColor(irr::video::SColor Color);
	virtual void SetColor(int R, float G, float B, float A);
	virtual void SetColor(int R, float G, float B);

	virtual void Draw(irr::video::IVideoDriver* driver);
protected:
	v3d m_Position;
	v3d m_Scale;
	v3d m_Rotation;

	irr::video::SColor m_Color;
};

class GraphicsModel : public Graphics3D
{
public:
	GraphicsModel();

	virtual void setMesh(irrstring mesh, irrstring texture,
		irr::scene::ISceneManager* smgr,
		irr::video::IVideoDriver* driver);

	virtual void Draw(irr::video::IVideoDriver* driver);

protected:
	irr::scene::IMesh* m_Mesh;
	irr::scene::IMeshSceneNode* m_Node;
	irr::video::ITexture* m_Texture;
};