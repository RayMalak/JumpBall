#include "StairsModel.h"
#include "ShapeModel.h"
#include <osg/Matrix>

StairsModel::StairsModel()
{
	setName(MN_STAIRS);
	GenStairs(2);
}

StairsModel::StairsModel(unsigned int stairsNum)
{
	setName(MN_STAIRS);
	GenStairs(stairsNum);
}

StairsModel::~StairsModel()
{
}


void StairsModel::GenStairs(const unsigned int stairsNum)
{
	osg::ref_ptr<ShapeModel> shape = new ShapeModel(ShapeModel::Box);
	
	for (unsigned int n = 0; n < stairsNum; n++)
	{
		osg::ref_ptr<osg::MatrixTransform> mtPos = new osg::MatrixTransform;
		osg::ref_ptr<osg::MatrixTransform> mtScale = new osg::MatrixTransform;
		mtPos->setName("mtPos");
		mtScale->setName("mtScale");
		
		mtScale->addChild(shape);
		mtPos->addChild(mtScale);

		if (n > 0)
		{
			// Z轴放大 n + 1 倍
			mtScale->setMatrix(osg::Matrix::scale(osg::Vec3(1.0, 1.0, 1.0 + n)));
			
			// X轴向右移动 n 倍的边长，
			// 放大后需要向上移动 n*0.5
			mtPos->setMatrix(osg::Matrix::translate(osg::Vec3(shape->getRaidius()*n*2.0, 0.0, shape->getRaidius()*n)));
		}

		addChild(mtPos);

	}
}
