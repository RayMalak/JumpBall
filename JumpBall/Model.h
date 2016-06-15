#pragma once

#include "osglib.h"

class Model
{
public:
	Model();
	~Model();

	osg::ref_ptr<osg::Node> GetNode(){ return _root; }

protected:
	osg::ref_ptr<osg::MatrixTransform> _root;
};

