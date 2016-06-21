
#include "keyboardhandler.h"
class Model;

class BallManipulator : public KeyboardHandler
{
public:
	BallManipulator(Model&);
	~BallManipulator(void);

	virtual bool handleKeyUp( const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa);
	virtual bool handleKeyDown( const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa);
	virtual bool handleKeyLeft( const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa);
	virtual bool handleKeyRight( const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa);
	void SetHitSceneNode(osg::Node* hitNode){_hitSceneNode = hitNode;}
	
private:
	enum DIRECT{
		LEFT = 0,
		RIGHT,
		UP,
		DOWN,
		FRONT,
		BACK,
	};

	osg::Vec3d*  GetValidChangePos(DIRECT direct);

private:
	Model& _ball;
	osg::Node* _hitSceneNode;

	static osg::Vec3d	s_vcLeft;
	static osg::Vec3d	s_vcRight;
	static osg::Vec3d	s_vcUp;
	static osg::Vec3d	s_vcDown;
	static osg::Vec3d	s_vcFront;
	static osg::Vec3d	s_vcBack;

};
