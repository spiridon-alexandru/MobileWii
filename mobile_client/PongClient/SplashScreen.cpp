/*
 * SplashScreen.cpp
 *
 *  Created on: Mar 9, 2012
 *      Author: Cipri
 */

#include "SplashScreen.h";
#include "MAHeaders.h"

namespace PongClientUI
{
	/*
	 * Constructor
	 */
	SplashScreen::SplashScreen() : NativeUI::Screen()
	{
		_m_mainLayout = new NativeUI::VerticalLayout();
		_m_backgroundImage = new NativeUI::Image();

		MAExtent scrSize = maGetScrSize();
		createMainLayout(EXTENT_X(scrSize), EXTENT_Y(scrSize));
	}
	/*
	 * Destructor
	 */
	SplashScreen::~SplashScreen()
	{
	}

	void SplashScreen::createMainLayout(const int& screenWidth, const int& screenHeight)
	{
		_m_mainLayout->setBackgroundColor(0, 0, 0);
		_m_mainLayout->fillSpaceHorizontally();
		_m_mainLayout->fillSpaceVertically();

		if(screenWidth <= 320 && screenHeight <= 480)
		{
			int result = _m_backgroundImage->setImage(RES_SPLASH_SCREEN_IMAGE_SMALL);
		}
		else if(screenWidth <= 480 && screenHeight <= 640)
		{
			int result = _m_backgroundImage->setImage(RES_SPLASH_SCREEN_IMAGE_MEDIUM);
		}
		else
		{
			int result = _m_backgroundImage->setImage(RES_SPLASH_SCREEN_IMAGE_LARGE);
		}

		_m_mainLayout->addChild(_m_backgroundImage);
		_m_mainLayout->setChildVerticalAlignment(MAW_ALIGNMENT_CENTER);
		_m_mainLayout->setChildHorizontalAlignment(MAW_ALIGNMENT_CENTER);

		this->setMainWidget(_m_mainLayout);
	}
}
