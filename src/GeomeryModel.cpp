
#include <osg/LineWidth>
#include "GeomeryModel.h"



osg::ref_ptr<osg::Node> GeomeryModel::CreateLine( osg::Vec3& s, osg::Vec3& e )
{
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

	geode->addDrawable(geom.get());

	//����һЩ���� 
	osg::ref_ptr<osg::Vec3Array> coords = new osg::Vec3Array;
	
	//���ö���
	geom->setVertexArray(coords.get());

	osg::ref_ptr<osg::LineWidth> lw = new osg::LineWidth(5);
	geode->getOrCreateStateSet()->setAttributeAndModes(lw, osg::StateAttribute::ON);

	//���ö��� 
	coords->push_back(s);
	coords->push_back(e);

	//���ö���Ĺ�����ʽ
	geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::Mode::LINES, 0, coords->size()));

	return geode;
}

