#include "ShapeModel.h"
#include <osg/ShapeDrawable>

ShapeModel::ShapeModel()
	:m_radius(1.0)
{
	GenShape(Box);
}

ShapeModel::ShapeModel(Type typeShape)
	: m_radius(1.0)
{
	GenShape(typeShape);
}

ShapeModel::~ShapeModel()
{
}

void ShapeModel::GenShape(Type typeShape)
{
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	osg::ref_ptr<osg::Shape> shape = NULL;
	osg::Vec3 vecPos(0.0, 0.0, 0.0);
	
	switch (typeShape)
	{
	case ShapeModel::Box:
	{
		shape = new osg::Box(vecPos, 2 * m_radius);
		setName(MN_BOX);
	}
	break;
	case ShapeModel::Sphere:
	{
		shape = new osg::Sphere(vecPos, m_radius);
		setName(MN_BALL);
	}
	break;
	default:
		shape = new osg::Box(vecPos, 2 * m_radius);
		setName(MN_BOX);
		break;
	}

	geode->addDrawable(new osg::ShapeDrawable(shape));
	addChild(geode);

}
