
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
	// ����Ƿ�����ײ�� �õ���Чλ��

	// 1. �������߶�
	
	// X 
	{
// 		osg::Vec3d vcStart(this->getBound()._center);
// 		osg::Vec3d vcEnd(vcPosIn);
// 		osg::ref_ptr<osgUtil::LineSegmentIntersector> lsi = new osgUtil::LineSegmentIntersector(vcStart, vcEnd);

	}
	

	// 2. ���м��

	// 3. �õ������

	// 4. ���ݼ����������λ��

	vcPosOut = vcPosIn;

}


