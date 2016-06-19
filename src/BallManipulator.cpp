
#include <iostream>
#include <osg/Matrix>
#include "BallManipulator.h"
#include "Model.h"

osg::Vec3f	BallManipulator::s_vcLeft(-0.2, 0, 0);
osg::Vec3f	BallManipulator::s_vcRight(0.2, 0, 0);
osg::Vec3f	BallManipulator::s_vcUp(0, 0, 0.2);
osg::Vec3f	BallManipulator::s_vcDown(0, 0, -0.2);
osg::Vec3f	BallManipulator::s_vcFront(0, -0.2, 0);
osg::Vec3f	BallManipulator::s_vcBack(0, 0.2, 0);;

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

	// 检测是否有碰撞， 得到有效位移

	// 1. 构造检测线段

	// X 
	{
		osg::Vec3f vcStart(_ball.getBound()._center);
		osg::Vec3f vcEnd(vcStart.x() - 0.2, vcStart.y(), vcStart.z());
		
		std::cout << "start pos: " << vcStart.x() << ", " << vcStart.y() << ", " << vcStart.z() << std::endl;
		std::cout << "end pos: " << vcEnd.x() << ", " << vcEnd.y() << ", " << vcEnd.z() << std::endl;

		osg::ref_ptr<osgUtil::LineSegmentIntersector> lsi = new osgUtil::LineSegmentIntersector(vcStart, vcEnd);

		// 2. 进行检测
		osg::ref_ptr<osgUtil::IntersectionVisitor> iv = new osgUtil::IntersectionVisitor(lsi);
		(dynamic_cast<osgViewer::Viewer*>(aa.asView()))->getSceneData()->accept(*iv);

		// 3. 得到检测结果
		if (lsi->containsIntersections())
		{
			osgUtil::LineSegmentIntersector::Intersections & iss = lsi->getIntersections();

			std::cout << "there are " << iss.size() << " intersections!" << std::endl;
			std::cout << (*(iss.begin()->nodePath.begin()))->getName() << std::endl;
			
			
			// 			osgUtil::LineSegmentIntersector::Intersections::iterator iter = iss.begin();
// 			for (; iter != iss.end(); iter++)
// 			{
// 				const osg::NodePath &np = iter->nodePath;
// 				for (osg::NodePath::iterator iterNode = np.begin(); iterNode != np.end(); iterNode++)
// 				{
// 					std::cout << "node name" << iterNode->getName() << std::endl;
// 				}
// 			}
		}

		// 4. 根据检测结果设置新位移
		

		
	}


	

	
	_ball.changePostion(s_vcLeft);

	return true;
}

bool BallManipulator::handleKeyRight( const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa )
{
	std::cout << "Right" << std::endl;
	
	_ball.changePostion(s_vcRight);

	return true;
}


