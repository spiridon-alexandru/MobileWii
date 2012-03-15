/*
 * MenuScreen.h
 *
 *  Created on: Mar 9, 2012
 *      Author: Cipri
 */

#ifndef MENUSCREEN_H_
#define MENUSCREEN_H_

#include <NativeUI/Screen.h>
#include <NativeUI/ImageButton.h>
#include <NativeUI/VerticalLayout.h>
#include <NativeUI/ButtonListener.h>
#include <NativeUI/StackScreen.h>

#include "PlayScreen.h"

namespace PongClientUI
{
	class MenuScreen : public NativeUI::Screen, public NativeUI::ButtonListener
	{
		public:
			MenuScreen();
			~MenuScreen();
			void createMainLayout(const int& screenWidth, const int& screenHeight);
			void buttonClicked(NativeUI::Widget* button);
			void setParentScreen(const NativeUI::StackScreen& screen);
		private:
			NativeUI::VerticalLayout* _m_mainLayout;
			NativeUI::ImageButton* _m_playButton;
			NativeUI::ImageButton* _m_settingsButton;
			NativeUI::ImageButton* _m_aboutButton;
			NativeUI::StackScreen _m_parent;
			PlayScreen* _a_playScreen;
	};
}

#endif /* MENUSCREEN_H_ */
