#include "StairsModel.h"
#include "BallManipulator.h"
#include "ShapeModel.h"
#include <osgViewer/ViewerEventHandlers>

int main()
{
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	osg::ref_ptr<osg::Group> root = new osg::Group;
	osg::ref_ptr<StairsModel> sm = new StairsModel(5);
	osg::ref_ptr<ShapeModel> ball = new ShapeModel(ShapeModel::Sphere);
	
	root->addChild(sm);
	root->addChild(ball);

	// 移动到合适位置
	sm->changePostion(osg::Vec3(2, 0, 0));

	viewer->setSceneData(root);

	viewer->addEventHandler(new BallManipulator(*(ball)));

	viewer->addEventHandler(new osgViewer::WindowSizeHandler());

	viewer->run();

	return 0;
}