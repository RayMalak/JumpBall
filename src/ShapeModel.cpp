#include "ShapeModel.h"
#include <osg/ShapeDrawable>

ShapeModel::ShapeModel()
	:m_radius(1)
{
	GenShape(Box);
}

ShapeModel::ShapeModel(Type typeShape)
	: m_radius(1)
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
		shape = new osg::Sphere(vecPos, BALL_RADIUS);
		setName(MN_BALL);
	}
	break;
	default:
		shape = new osg::Box(vecPos, 2 * m_radius);
		setName(MN_BOX);
		break;
	}

	osg::ref_ptr<osg::ShapeDrawable> shapeDrawable = new osg::ShapeDrawable(shape);
	geode->addDrawable(shapeDrawable);

	addChild(geode);

	shapeDrawable->setColor(osg::Vec4(0.5, 0.8, 0.8, 0.5));
	
}
