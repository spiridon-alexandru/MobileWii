/*
 * ParentScreen.cpp
 *
 *  Created on: Mar 9, 2012
 *      Author: Cipri
 */

#include "ParentScreen.h"

namespace PongClientUI
{
	ParentScreen::ParentScreen() : NativeUI::StackScreen()
	{
		_m_menuScreen = new MenuScreen();
		_m_menuScreen->setParentScreen(*this);

		push(_m_menuScreen);
	}

	ParentScreen::~ParentScreen()
	{
	}
}


