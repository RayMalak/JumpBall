#pragma once
#include "model.h"

class GeomeryModel :
	public Model
{
public:
	GeomeryModel(void){}
	~GeomeryModel(void){}

	enum Type
	{
		Line = 0,
		
	};

	static osg::ref_ptr<osg::Node> CreateLine(osg::Vec3& s, osg::Vec3& e);

};

