
#include <osgUtil/LineSegmentIntersector>
#include "Model.h"


Model::Model()
{
}

Model::~Model()
{
}

void Model::changePostion( osg::Vec3d& vcPos)
{
	setMatrix(getMatrix()*osg::Matrix::translate(vcPos));
}

void Model::toPosition(osg::Vec3& vcPos)
{
	osg::Vec3 vcReverse(-getBound().center().x(), -getBound().center().y(), -getBound().center().z());
	setMatrix(osg::Matrix::translate(vcReverse) * osg::Matrix::translate(vcPos));
}


