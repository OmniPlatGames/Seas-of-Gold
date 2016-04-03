#include "Graphics.h"

Graphics::Graphics()
{
	/*m_Position = v3d(0, 0, 0);
	m_Scale = v3d(1, 1, 1);
	m_Rotation = v3d(0, 0, 0);*/
}

/*v3d Graphics::GetPosition()
{
	return m_Position;
}

v3d Graphics::GetScale()
{
	return m_Scale;
}

v3d Graphics::GetRotation()
{
	return m_Rotation;
}

void Graphics::SetPosition(v3d position)
{
	m_Position = position;
}

void Graphics::SetPosition(float x, float y, float z)
{
	m_Position = v3d(x, y, z);
}

void Graphics::SetScale(v3d scale)
{
	m_Scale = scale;
}

void Graphics::SetScale(float x, float y, float z)
{
	m_Scale = v3d(x, y, z);
}

void Graphics::SetScale(float Uscale)
{
	m_Scale = v3d(Uscale, Uscale, Uscale);
}

void Graphics::SetRotation(v3d rotation)
{
	m_Rotation = rotation;
}

void Graphics::SetRotation(float Pitch, float Yaw, float Roll)
{
	m_Rotation = v3d(Pitch, Yaw, Roll);
}*/

void Graphics::Draw(irr::video::IVideoDriver* driver)
{

}



///////////////////////////////////////////////////////////////////////////

Graphics2D::Graphics2D()
{
	m_Position = v2d(0, 0);
	m_Color = irr::video::SColor(255, 255, 255, 255);
}

v2d Graphics2D::GetPosition()
{
	return m_Position;
}

irr::video::SColor Graphics2D::GetColor()
{
	return m_Color;
}

void Graphics2D::SetPosition(v2d Position)
{
	m_Position = Position;
}

void Graphics2D::SetPosition(float x, float y)
{
	m_Position = v2d(x, y);
}

void Graphics2D::SetColor(irr::video::SColor Color)
{
	m_Color = Color;
}

void Graphics2D::SetColor(int R, float G, float B, float A)
{
	m_Color = irr::video::SColor(A, R, G, B);
}

void Graphics2D::SetColor(int R, float G, float B)
{
	m_Color = irr::video::SColor(255, R, G, B);
}

///////////////////////////////////////////////////////////////////////////

GraphicsRect::GraphicsRect()
{
	m_Width = 0;
	m_Height = 0;
	m_Position = v2d(0, 0);
	m_Color = irr::video::SColor(255, 255, 255, 255);
}

GraphicsRect::GraphicsRect(float x1, float y1, float x2, float y2)
{
	m_Position = v2d(x1, y1);
	m_Width = x2 - x1;
	m_Height = y2 - y1;
	m_Color = irr::video::SColor(255, 255, 255, 255);
}

GraphicsRect::GraphicsRect(v2d Position, float width, float height)
{
	m_Position = Position;
	m_Width = width;
	m_Height = height;
	m_Color = irr::video::SColor(255, 255, 255, 255);
}

float GraphicsRect::GetWidth()
{
	return m_Width;
}

float GraphicsRect::GetHeight()
{
	return m_Height;
}



void GraphicsRect::SetWidth(float Width)
{
	m_Width = Width;
}

void GraphicsRect::SetHeight(float Height)
{
	m_Height = Height;
}

void GraphicsRect::Draw(irr::video::IVideoDriver* driver)
{
	driver->draw2DRectangle(m_Color,
		irr::core::rect<irr::s32>(m_Position.X, m_Position.Y,
			m_Position.X + m_Width, m_Position.Y + m_Height));
}



/////////////////////////////////////////////////////////////////////////

GraphicsImage::GraphicsImage()
{
	m_Width = 0;
	m_Height = 0;
	m_Position = v2d(0, 0);
	m_Color = irr::video::SColor(255, 255, 255, 255);
}

GraphicsImage::GraphicsImage(float x1, float y1, float x2, float y2)
{
	m_Position = v2d(x1, y1);
	m_Width = x2 - x1;
	m_Height = y2 - y1;
	m_Color = irr::video::SColor(255, 255, 255, 255);
}

GraphicsImage::GraphicsImage(v2d Position, float width, float height)
{
	m_Position = Position;
	m_Width = width;
	m_Height = height;
	m_Color = irr::video::SColor(255, 255, 255, 255);
}

void GraphicsImage::SetTexture(irrstring texture, irr::video::IVideoDriver* driver)
{
	Texture = driver->getTexture(texture.c_str());
	Dimensions = Texture->getSize();
	driver->makeColorKeyTexture(Texture, irr::core::position2d<irr::s32>(0, 0));
}

void GraphicsImage::Draw(irr::video::IVideoDriver* driver)
{
	irr::core::rect<irr::s32> src(0, 0, Dimensions.Width, Dimensions.Height);
	irr::core::rect<irr::s32> dest(m_Position.X, m_Position.Y,
		m_Position.X + m_Width, 
		m_Position.Y + m_Height);

	driver->enableMaterial2D();
	driver->draw2DImage(Texture, dest, src);
	driver->enableMaterial2D(false);
}



///////////////////////////////////////////////////////////////////////////

GraphicsSprite::GraphicsSprite()
{
	m_Width = 0;
	m_Height = 0;
	m_Position = v2d(0, 0);
	m_Color = irr::video::SColor(255, 255, 255, 255);
}

GraphicsSprite::GraphicsSprite(float x1, float y1, float x2, float y2)
{
	m_Position = v2d(x1, y1);
	m_Width = x2 - x1;
	m_Height = y2 - y1;
	m_Color = irr::video::SColor(255, 255, 255, 255);
}

GraphicsSprite::GraphicsSprite(v2d Position, float width, float height)
{
	m_Position = Position;
	m_Width = width;
	m_Height = height;
	m_Color = irr::video::SColor(255, 255, 255, 255);
}

void GraphicsSprite::SetTexture(irrstring texture, irr::video::IVideoDriver* driver)
{
	Texture = driver->getTexture(texture.c_str());
	Dimensions = Texture->getSize();
	//driver->makeColorKeyTexture(Texture, irr::core::position2d<irr::s32>(0, 0));
}

void GraphicsSprite::Draw(irr::video::IVideoDriver* driver)
{
	irr::core::rect<irr::s32> src(0, 0, Dimensions.Width, Dimensions.Height);
	irr::core::rect<irr::s32> dest(m_Position.X, m_Position.Y,
		m_Position.X + m_Width,
		m_Position.Y + m_Height);

	driver->enableMaterial2D();
	//driver->draw2DImage(Texture, dest, src, 0, &m_Color, true);
	driver->enableMaterial2D(false);
}



////////////////////////////////////////////////////////////////////////////

GraphicsCircle::GraphicsCircle()
{
	m_Radius = 0;
}

GraphicsCircle::GraphicsCircle(float x, float y, float radius)
{
	m_Position = v2d(x, y);
	m_Radius = radius;
}

GraphicsCircle::GraphicsCircle(v2d Position, float radius)
{
	m_Position = Position;
	m_Radius = radius;
}

float GraphicsCircle::GetRadius()
{
	return m_Radius;
}

void GraphicsCircle::SetRadius(float radius)
{
	m_Radius = radius;
}

void GraphicsCircle::Draw(irr::video::IVideoDriver* driver)
{
	driver->draw2DPolygon(irr::core::vector2di(m_Position.X, m_Position.Y),
		m_Radius, m_Color, 60);
	//driver->drawIndexedTriangleFan()
}



/////////////////////////////////////////////////////////////////////////////////

Graphics3D::Graphics3D()
{
	m_Position = v3d(0, 0, 0);
	m_Scale = v3d(1, 1, 1);
	m_Rotation = v3d(0, 0, 0);
	m_Color = irr::video::SColor(255, 255, 255, 255);
}

v3d Graphics3D::GetPosition()
{
	return m_Position;
}

v3d Graphics3D::GetScale()
{
	return m_Scale;
}

v3d Graphics3D::GetRotation()
{
	return m_Rotation;
}

irr::video::SColor Graphics3D::GetColor()
{
	return m_Color;
}

void Graphics3D::SetPosition(v3d Position)
{
	m_Position = Position;
}

void Graphics3D::SetPosition(float x, float y, float z)
{
	m_Position = v3d(x, y, z);
}

void Graphics3D::SetScale(v3d scale)
{
	m_Scale = scale;
}

void Graphics3D::SetScale(float x, float y, float z)
{
	m_Scale = v3d(x, y, z);
}

void Graphics3D::SetScale(float Uscale)
{
	m_Scale = v3d(Uscale, Uscale, Uscale);
}

void Graphics3D::SetRotation(v3d rotation)
{
	m_Rotation = rotation;
}

void Graphics3D::SetRotation(float Pitch, float Yaw, float Roll)
{
	m_Rotation = v3d(Pitch, Yaw, Roll);
}

void Graphics3D::SetColor(irr::video::SColor Color)
{
	m_Color = Color;
}

void Graphics3D::SetColor(int R, float G, float B, float A)
{
	m_Color = irr::video::SColor(A, R, G, B);
}

void Graphics3D::SetColor(int R, float G, float B)
{
	m_Color = irr::video::SColor(255, R, G, B);
}

void Graphics3D::Draw(irr::video::IVideoDriver* driver)
{

}



////////////////////////////////////////////////////////////////////////////

GraphicsModel::GraphicsModel()
{

}

void GraphicsModel::setMesh(irrstring mesh, irrstring texture,
	irr::scene::ISceneManager* smgr,
	irr::video::IVideoDriver* driver)
{
	m_Mesh = smgr->getMesh(mesh);
	m_Node = smgr->addMeshSceneNode(m_Mesh);
	m_Texture = driver->getTexture(texture);
}

void GraphicsModel::Draw(irr::video::IVideoDriver* driver)
{
	m_Node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	m_Node->setMaterialTexture(0, m_Texture);
	m_Node->setScale(m_Scale);
	m_Node->setPosition(m_Position);
	m_Node->setRotation(m_Rotation);
}