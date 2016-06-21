
#include <iostream>
#include <osg/Matrix>
#include <osg/LineSegment>
#include <osgUtil/IntersectVisitor>
#include "BallManipulator.h"
#include "Model.h"
#include "GeomeryModel.h"
#include "StairsModel.h"

const int g_stepLen = 2;
osg::Vec3d	BallManipulator::s_vcLeft(-g_stepLen, 0, 0);
osg::Vec3d	BallManipulator::s_vcRight(g_stepLen, 0, 0);
osg::Vec3d	BallManipulator::s_vcUp(0, 0, g_stepLen);
osg::Vec3d	BallManipulator::s_vcDown(0, 0, -g_stepLen);
osg::Vec3d	BallManipulator::s_vcFront(0, -g_stepLen, 0);
osg::Vec3d	BallManipulator::s_vcBack(0, g_stepLen, 0);;

BallManipulator::BallManipulator(Model& ball)
	:_ball(ball)
	, _hitSceneNode(0)
{
	osg::Vec3 vcSX(_ball.getBound().center().x() +BALL_RADIUS + g_stepLen, 0, 0);
	osg::Vec3 vcEX(_ball.getBound().center().x() -BALL_RADIUS - g_stepLen, 0, 0);
	osg::Vec3 vcSZ(0, 0, _ball.getBound().center().z() +BALL_RADIUS + g_stepLen);
	osg::Vec3 vcEZ(0, 0, _ball.getBound().center().z() -BALL_RADIUS - g_stepLen);
	
	_ball.addChild(GeomeryModel::CreateLine(vcSX, vcEX));
	_ball.addChild(GeomeryModel::CreateLine(vcSZ, vcEZ));
}

BallManipulator::~BallManipulator(void)
{
}

bool BallManipulator::handleKeyUp( const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa )
{
	std::cout << "Up" << std::endl;

	_ball.changePostion(*GetValidChangePos(UP));

	return true;
}

bool BallManipulator::handleKeyDown( const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa )
{
	std::cout << "Down" << std::endl;

	_ball.changePostion(*GetValidChangePos(DOWN));

	return true;
}


bool BallManipulator::handleKeyLeft( const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa )
{
	std::cout << "Left" << std::endl;

	_ball.changePostion(*GetValidChangePos(LEFT));

	return true;
}

bool BallManipulator::handleKeyRight( const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa )
{
	std::cout << "Right" << std::endl;
	
	_ball.changePostion(*GetValidChangePos(RIGHT));

	return true;
}

// Get valid changed pos
osg::Vec3d* BallManipulator::GetValidChangePos(DIRECT direct)
{
	// 检测是否有碰撞， 得到有效位移

	osg::Vec3d* vcNewPos = new osg::Vec3d;
	bool bHit = false;

	// 1. 构造检测线段
	osg::Vec3d vcLineStart(_ball.getBound()._center);
	osg::Vec3d vcLineEnd;
	
	switch(direct)
	{
	case LEFT:
		{
			vcNewPos->set((s_vcLeft));
			vcLineEnd.set(vcLineStart.x() - BALL_RADIUS - g_stepLen, vcLineStart.y(), vcLineStart.z());
		}
		break;
	case RIGHT:
		{
			vcNewPos->set((s_vcRight));
			vcLineEnd.set(vcLineStart.x()  + BALL_RADIUS + g_stepLen , vcLineStart.y(), vcLineStart.z());
		}
		break;
	case UP:
		{
			vcNewPos->set((s_vcUp));
			vcLineEnd.set(vcLineStart.x(), vcLineStart.y(), vcLineStart.z() + BALL_RADIUS + g_stepLen );
		}
		break;
	case DOWN:
		{
			vcNewPos->set((s_vcDown));
			vcLineEnd.set(vcLineStart.x(), vcLineStart.y(), vcLineStart.z()  - BALL_RADIUS - g_stepLen);
		}
		break;
	default:
		{

		}
		break;
	}

	osg::ref_ptr<osg::LineSegment> ls = new osg::LineSegment(vcLineStart, vcLineEnd);

	// 2. 进行检测
	osg::ref_ptr<osgUtil::IntersectVisitor> iv = new osgUtil::IntersectVisitor;
	iv->addLineSegment(ls);

	if(_hitSceneNode)
		_hitSceneNode->accept(*iv);
	else
		;// error


	// 3. 得到检测结果, 根据检测结果设置新位移
	if (iv->hits())
	{
		osgUtil::IntersectVisitor::HitList & hitList = iv->getHitList(ls);
		osgUtil::IntersectVisitor::HitList::iterator iterHit = hitList.begin();

		for (; iterHit != hitList.end(); iterHit++)
		{
			osg::NodePath &np = iterHit->getNodePath();
			
			for (osg::NodePath::iterator iterNode = np.begin(); iterNode != np.end(); iterNode++)
			{
				std::cout << "node name is " << (*iterNode)->getName() << std::endl;

				StairsModel* sm = dynamic_cast<StairsModel*>(*iterNode);

				if(sm)
				{
					osg::Vec3d vcDiff = iterHit->getWorldIntersectPoint() - vcLineStart;
					vcDiff._v[0] = fabsf(vcDiff._v[0]) - BALL_RADIUS;
					vcDiff._v[1] = fabsf(vcDiff._v[1]) - BALL_RADIUS;
					vcDiff._v[2] = fabsf(vcDiff._v[2]) - BALL_RADIUS;

					if(LEFT == direct && vcDiff.x() >= 0)
						vcNewPos->set(-vcDiff.x(), vcNewPos->y(), vcNewPos->z());
					else if(RIGHT == direct  && vcDiff.x() >= 0)
						vcNewPos->set(vcDiff.x(), vcNewPos->y(), vcNewPos->z());
					else if(UP == direct  && vcDiff.z() >= 0)
						vcNewPos->set(vcNewPos->x(), vcNewPos->y(), vcDiff.z());
					else if(DOWN == direct && vcDiff.z() >= 0)
						vcNewPos->set(vcNewPos->x(), vcNewPos->y(), -vcDiff.z());
					
					return vcNewPos;
				}
			}
		}
	}

	return vcNewPos;
}




