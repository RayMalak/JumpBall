
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
		osg::ref_ptr<osg::Vec3d> vcStart = new osg::Vec3d(this->getBound()._center);
		osg::ref_ptr<osg::Vec3d> vcEnd = new osg::Vec3d(vcPosIn);
		osg::ref_ptr<osgUtil::LineSegmentIntersector> lsi = new osgUtil::LineSegmentIntersector(vcStart, vcEnd);

		osgUtil::in
		
	}
	

	// 2. ���м��

	// 3. �õ������

	// 4. ���ݼ����������λ��

}


