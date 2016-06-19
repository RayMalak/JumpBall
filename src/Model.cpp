
#include <osgUtil/LineSegmentIntersector>
#include "Model.h"


Model::Model()
{
}

Model::~Model()
{
}

void Model::changePostion( osg::Vec3& vcPos)
{
	osg::Vec3 vcPosUse;
	
	GetValidChangePos(vcPos, vcPosUse);

	setMatrix(getMatrix()*osg::Matrix::translate(vcPosUse));
}

void Model::GetValidChangePos(osg::Vec3&vcPosIn, osg::Vec3&vcPosOut)
{
	// 检测是否有碰撞， 得到有效位移

	// 1. 构造检测线段
	
	// X 
	{
// 		osg::Vec3d vcStart(this->getBound()._center);
// 		osg::Vec3d vcEnd(vcPosIn);
// 		osg::ref_ptr<osgUtil::LineSegmentIntersector> lsi = new osgUtil::LineSegmentIntersector(vcStart, vcEnd);

	}
	

	// 2. 进行检测

	// 3. 得到检测结果

	// 4. 根据检测结果设置新位移

	vcPosOut = vcPosIn;

}


