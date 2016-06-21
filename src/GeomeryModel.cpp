
#include <osg/LineWidth>
#include "GeomeryModel.h"



osg::ref_ptr<osg::Node> GeomeryModel::CreateLine( osg::Vec3& s, osg::Vec3& e )
{
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

	geode->addDrawable(geom.get());

	//申请一些顶点 
	osg::ref_ptr<osg::Vec3Array> coords = new osg::Vec3Array;
	
	//设置顶点
	geom->setVertexArray(coords.get());

	osg::ref_ptr<osg::LineWidth> lw = new osg::LineWidth(5);
	geode->getOrCreateStateSet()->setAttributeAndModes(lw, osg::StateAttribute::ON);

	//设置顶点 
	coords->push_back(s);
	coords->push_back(e);

	//设置顶点的关联方式
	geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::Mode::LINES, 0, coords->size()));

	return geode;
}

