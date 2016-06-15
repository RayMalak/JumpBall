#include "StairsModel.h"


int main()
{
	std::auto_ptr<StairsModel> sm(new StairsModel(5));

	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;

	viewer->setSceneData(sm->GetNode());

	viewer->run();

	return 0;
}