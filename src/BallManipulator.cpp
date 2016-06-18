
#include <iostream>
#include <osg/Matrix>
#include "BallManipulator.h"
#include "Model.h"

osg::Vec3	BallManipulator::s_vcLeft(-0.2, 0, 0);
osg::Vec3	BallManipulator::s_vcRight(0.2, 0, 0);
osg::Vec3	BallManipulator::s_vcUp(0, 0, 0.2);
osg::Vec3	BallManipulator::s_vcDown(0, 0, -0.2);
osg::Vec3	BallManipulator::s_vcFront(0, -0.2, 0);
osg::Vec3	BallManipulator::s_vcBack(0, 0.2, 0);;

BallManipulator::BallManipulator(Model& ball)
	:_ball(ball)
{
}

BallManipulator::~BallManipulator(void)
{
}

bool BallManipulator::handleKeyUp( const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa )
{
	std::cout << "Up" << std::endl;

	_ball.changePostion(s_vcUp);

	return true;
}

bool BallManipulator::handleKeyDown( const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa )
{
	std::cout << "Down" << std::endl;

	_ball.changePostion(s_vcDown);

	return true;
}

bool BallManipulator::handleKeyLeft( const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa )
{
	std::cout << "Left" << std::endl;
	
	_ball.changePostion(s_vcLeft);

	return true;
}

bool BallManipulator::handleKeyRight( const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa )
{
	std::cout << "Right" << std::endl;
	
	_ball.changePostion(s_vcRight);

	return true;
}


