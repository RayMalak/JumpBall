#pragma once

#include "osglib.h"

#include <osgGA/GUIEventAdapter>
#include <osgGA/GUIActionAdapter>
class KeyboardHandler : public osgGA::GUIEventHandler
{
public:
	KeyboardHandler(void);
	virtual ~KeyboardHandler(void);

public:
	/** Deprecated, Handle events, return true if handled, false otherwise. */
	virtual bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa);
 	virtual bool handleKeyUp( const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa){return false;}
	virtual bool handleKeyDown( const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa){return false;}
	virtual bool handleKeyLeft( const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa){return false;}
	virtual bool handleKeyRight( const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa){return false;}
};

