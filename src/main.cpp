#include "StairsModel.h"
#include "BallManipulator.h"
#include "ShapeModel.h"


int main()
{
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	osg::ref_ptr<osg::Group> root = new osg::Group;
	osg::ref_ptr<StairsModel> sm = new StairsModel(5);
	osg::ref_ptr<ShapeModel> ball = new ShapeModel(ShapeModel::Sphere);
	
	root->addChild(sm);
	root->addChild(ball);


	viewer->setSceneData(root);

	viewer->addEventHandler(new BallManipulator(*(ball)));

	viewer->run();

	return 0;
}