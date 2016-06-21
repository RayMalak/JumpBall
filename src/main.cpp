#include "StairsModel.h"
#include "BallManipulator.h"
#include "ShapeModel.h"
#include <osgViewer/ViewerEventHandlers>
#include "GeomeryModel.h"
#include <iostream>

int main()
{
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	osg::ref_ptr<osg::Group> root = new osg::Group;
	osg::ref_ptr<StairsModel> stairs = new StairsModel(5);
	osg::ref_ptr<ShapeModel> ball = new ShapeModel(ShapeModel::Sphere);
	osg::ref_ptr<BallManipulator> bm = new BallManipulator(*ball);
	
	bm->SetHitSceneNode(stairs);

	root->addChild(stairs);
	root->addChild(ball);

	
	// 移动到合适位置
	stairs->changePostion(osg::Vec3d(2, 0, 0));

	stairs->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);

	viewer->setSceneData(root);

	viewer->addEventHandler(bm);

	viewer->addEventHandler(new osgViewer::WindowSizeHandler());

	viewer->run();

	return 0;
}