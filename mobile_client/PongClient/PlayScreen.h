/*
 * PlayScreen.h
 *
 *  Created on: Mar 9, 2012
 *      Author: Cipri
 */

#ifndef PLAYSCREEN_H_
#define PLAYSCREEN_H_

#include <NativeUI/Screen.h>
#include <NativeUI/Label.h>
#include <NativeUI/VerticalLayout.h>
#include <MAUtil/Environment.h>
#include <MAUtil/Connection.h>

namespace PongClientUI
{
	class PlayScreen : public NativeUI::Screen, public MAUtil::SensorListener, public MAUtil::PointerListener, private MAUtil::HttpConnectionListener
	{
		public:
			PlayScreen();
			~PlayScreen();

			void pointerPressEvent(MAPoint2d p);
			void pointerReleaseEvent(MAPoint2d p);
			void sensorEvent(MASensor a);
			void pointerMoveEvent(MAPoint2d p) {}
			void httpFinished(MAUtil::HttpConnection* http, int result);
			void connRecvFinished(MAUtil::Connection *conn, int result);
			void connReadFinished(MAUtil::Connection *conn, int result);
			void connWriteFinished(MAUtil::Connection *conn, int result);
		private:
			void initHttpConnection();

			NativeUI::VerticalLayout* _m_mainLayout;
			NativeUI::Label* _m_infoLabel;
			MAUtil::HttpConnection* _m_Http;

			bool _m_connected;
			bool _m_readyForWrite;
			char* _m_buffer;
	};
}


#endif /* PLAYSCREEN_H_ */
