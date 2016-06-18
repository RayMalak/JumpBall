#include "KeyboardHandler.h"


KeyboardHandler::KeyboardHandler(void)
{
}


KeyboardHandler::~KeyboardHandler(void)
{
}

bool KeyboardHandler::handle( const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
	bool bReturn = false;
	switch(ea.getEventType())
	{
	case osgGA::GUIEventAdapter::KEYDOWN:
		{
			if(ea.getKey() == osgGA::GUIEventAdapter::KEY_Up)
				bReturn = handleKeyUp(ea, aa);
			else if(ea.getKey() == osgGA::GUIEventAdapter::KEY_Down)
				bReturn = handleKeyDown(ea, aa);
			else if(ea.getKey() == osgGA::GUIEventAdapter::KEY_Left)
				bReturn = handleKeyLeft(ea, aa);
			else if(ea.getKey() == osgGA::GUIEventAdapter::KEY_Right)
				bReturn = handleKeyRight(ea, aa);
			
		}break;
	}

	return bReturn;
}
