/*!
	Author: Matthew Chrobak
	Contributors:
	
	Purpose: To provide a library-agnostic abstraction between the application and the graphics library it utilizes.
*/
#pragma once
#include "SurfaceContext.h"
#include "TextContext.h"
#include <string>

class GraphicsSystem
{
public:
	// Window-context events
	virtual void destroyContext() = 0;
	virtual void restartContext() = 0;
	virtual void drawContext() = 0;


	// Window-context mutators.
	virtual void setWindowTitle(std::string title) = 0;
	virtual void setWindowSize(unsigned int width, unsigned int height) = 0;
	virtual void setContextSize(unsigned int width, unsigned int height) = 0;

	virtual bool isDestroyed() const = 0;
	virtual void renderSurface(std::string surfacename, SurfaceContext& ctx) = 0;
	virtual void renderText(std::string text, TextContext& ctx) = 0;

private:
	virtual void createContext() = 0;
};