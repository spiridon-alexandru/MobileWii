/*
 * MenuScreen.cpp
 *
 *  Created on: Mar 9, 2012
 *      Author: Cipri
 */

#include "MenuScreen.h"
#include "MAHeaders.h"
#include "PlayScreen.h"

namespace PongClientUI
{
	MenuScreen::MenuScreen() : NativeUI::Screen()
	{
		_m_mainLayout = new NativeUI::VerticalLayout();
		_m_playButton = new NativeUI::ImageButton();
		_m_settingsButton = new NativeUI::ImageButton();
		_m_aboutButton = new NativeUI::ImageButton();

		_m_playButton->addButtonListener(this);
		_m_settingsButton->addButtonListener(this);
		_m_aboutButton->addButtonListener(this);

		MAExtent scrSize = maGetScrSize();

		createMainLayout(EXTENT_X(scrSize), EXTENT_Y(scrSize));
	}

	MenuScreen::~MenuScreen()
	{
	}

	void MenuScreen::createMainLayout(const int& screenWidth, const int& screenHeight)
	{
		_m_mainLayout->setBackgroundColor(0, 0, 0);
		_m_mainLayout->fillSpaceHorizontally();
		_m_mainLayout->fillSpaceVertically();

		if(screenWidth <= 320 && screenHeight <= 480)
		{
			_m_playButton->setImage(RES_PLAY_BTN_IMAGE_SMALL);
			_m_settingsButton->setImage(RES_SETTINGS_BTN_IMAGE_SMALL);
			_m_aboutButton->setImage(RES_ABOUT_BTN_IMAGE_SMALL);
		}
		else if(screenWidth <= 480 && screenHeight <= 640)
		{
			_m_playButton->setImage(RES_PLAY_BTN_IMAGE_MEDIUM);
			_m_settingsButton->setImage(RES_SETTINGS_BTN_IMAGE_MEDIUM);
			_m_aboutButton->setImage(RES_ABOUT_BTN_IMAGE_MEDIUM);
		}
		else
		{
			_m_playButton->setImage(RES_PLAY_BTN_IMAGE_LARGE);
			_m_settingsButton->setImage(RES_SETTINGS_BTN_IMAGE_LARGE);
			_m_aboutButton->setImage(RES_ABOUT_BTN_IMAGE_LARGE);
		}

		_m_mainLayout->addChild(_m_playButton);
		_m_mainLayout->addChild(_m_settingsButton);
		_m_mainLayout->addChild(_m_aboutButton);

		_m_mainLayout->setChildVerticalAlignment(MAW_ALIGNMENT_CENTER);
		_m_mainLayout->setChildHorizontalAlignment(MAW_ALIGNMENT_CENTER);

		setMainWidget(_m_mainLayout);
	}

	void MenuScreen::setParentScreen(const NativeUI::StackScreen& screen)
	{
		_m_parent = screen;
	}

	void MenuScreen::buttonClicked(NativeUI::Widget* button)
	{
		if(button == _m_playButton)
		{
			_a_playScreen = new PlayScreen();
			_m_parent.push(_a_playScreen);
		}
	}
}

