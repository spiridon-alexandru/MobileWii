/*
 * SplashScreen.h
 *
 *  Created on: Mar 9, 2012
 *      Author: Cipri
 */

#ifndef SPLASHSCREEN_H_
#define SPLASHSCREEN_H_

#include <NativeUI/Screen.h>
#include <NativeUI/Image.h>
#include <NativeUI/VerticalLayout.h>

namespace PongClientUI
{
	class SplashScreen : public NativeUI::Screen
	{
		public:
			SplashScreen();
			~SplashScreen();

			void createMainLayout(const int& screenWidth, const int& screenHeight);
		private:
			//The main layout
			NativeUI::VerticalLayout*  _m_mainLayout;

			//The background image
			NativeUI::Image* _m_backgroundImage;
	};
}//end PinBallClientUI
#endif /* SPLASHSCREEN_H_ */
