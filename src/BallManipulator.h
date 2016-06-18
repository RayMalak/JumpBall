
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

private:
	Model& _ball;

	static osg::Vec3	s_vcLeft;
	static osg::Vec3	s_vcRight;
	static osg::Vec3	s_vcUp;
	static osg::Vec3	s_vcDown;
	static osg::Vec3	s_vcFront;
	static osg::Vec3	s_vcBack;

};
