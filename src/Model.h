#pragma once

#include "osglib.h"

#define MN_STAIRS        "stairs_name"
#define MN_BALL          "ball_name"
#define MN_BOX          "box_name"

class Model : public osg::MatrixTransform
{
public:
	Model();
	~Model();

	// change the node position, use relative position
	void changePostion(osg::Vec3&);

	// Get valid changed pos
	void GetValidChangePos(osg::Vec3&vcPosIn, osg::Vec3&vcPosOut);


};

