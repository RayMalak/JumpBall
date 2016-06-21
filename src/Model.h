#pragma once

#include "osglib.h"

#define MN_STAIRS        "stairs_name"
#define MN_BALL          "ball_name"
#define MN_BOX           "box_name"
#define BALL_RADIUS      (2)


class Model : public osg::MatrixTransform
{
public:
	Model();
	~Model();

	// change the node position, use relative position
	void changePostion(osg::Vec3d&);
	
	
	void toPosition(osg::Vec3& vcPos);

};

