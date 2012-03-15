/*
 * ParentScreen.h
 *
 *  Created on: Mar 9, 2012
 *      Author: Cipri
 */

#ifndef PARENTSCREEN_H_
#define PARENTSCREEN_H_

#include "PlayScreen.h"
#include "MenuScreen.h"
#include <NativeUI/StackScreen.h>

namespace PongClientUI
{
	class ParentScreen : public NativeUI::StackScreen
	{
		public:
			ParentScreen();
			~ParentScreen();
		private:
			MenuScreen* _m_menuScreen;
	};
}


#endif /* PARENTSCREEN_H_ */
