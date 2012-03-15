/*
 * PlayScreen.cpp
 *
 *  Created on: Mar 9, 2012
 *      Author: Cipri
 */
#include "PlayScreen.h"
#include <NativeUI/Button.h>

namespace PongClientUI
{
	#define LABEL_FONT_COLOR_RELEASED 0x5efd2d
	#define LABEL_FONT_COLOR_PRESSED 0
	#define LABEL_FONT_SIZE_SMALL 16
	#define LABEL_FONT_SIZE_LARGE 32
	#define BUFFER_SIZE 1024
	#define SENSOR_INTERVAL 100
	#define URL "http://192.168.1.103:8888/update"

	PlayScreen::PlayScreen() : NativeUI::Screen()
	{
		MAUtil::Environment::getEnvironment().addSensorListener(this);
		MAUtil::Environment::getEnvironment().addPointerListener(this);

		_m_mainLayout = new NativeUI::VerticalLayout();

		_m_mainLayout->fillSpaceHorizontally();
		_m_mainLayout->fillSpaceVertically();

		_m_infoLabel = new NativeUI::Label();
		_m_infoLabel->setFontColor(LABEL_FONT_COLOR_RELEASED);
		_m_infoLabel->fillSpaceHorizontally();
		_m_infoLabel->setTextHorizontalAlignment(MAW_ALIGNMENT_CENTER);

		MAExtent scrSize = maGetScrSize();
		if(EXTENT_Y(scrSize) <= 640)
		{
			_m_infoLabel->setFontSize(LABEL_FONT_SIZE_SMALL);
		}
		else
		{
			_m_infoLabel->setFontSize(LABEL_FONT_SIZE_LARGE);
		}

		_m_mainLayout->addChild(_m_infoLabel);
		_m_buffer = new char[BUFFER_SIZE];

		_m_connected = false;
		_m_readyForWrite = false;
		_m_Http = new MAUtil::HttpConnection(this);

		initHttpConnection();

		setMainWidget(_m_mainLayout);
	}

	PlayScreen::~PlayScreen()
	{
		MAUtil::Environment::getEnvironment().removeSensorListener(this);
		MAUtil::Environment::getEnvironment().removePointerListener(this);

		_m_Http->close();

		delete _m_buffer;
		delete _m_Http;
	}

	void PlayScreen::sensorEvent(MASensor a)
	{
		if(_m_connected && _m_readyForWrite)
		{
			sprintf(_m_buffer, "%lf\015\012", a.values[1]);
			_m_infoLabel->setText(_m_buffer);
			_m_readyForWrite = false;
			_m_Http->write(_m_buffer, strlen(_m_buffer));
		}
	}

	void PlayScreen::pointerReleaseEvent(MAPoint2d p)
	{
		_m_mainLayout->setBackgroundColor(0, 0, 0);
		_m_infoLabel->setFontColor(LABEL_FONT_COLOR_RELEASED);
		if(_m_connected) maSensorStop(SENSOR_TYPE_ACCELEROMETER);
	}

	void PlayScreen::pointerPressEvent(MAPoint2d p)
	{
		_m_mainLayout->setBackgroundColor(94, 253, 45);
		_m_infoLabel->setFontColor(LABEL_FONT_COLOR_PRESSED);
		if(_m_connected) maSensorStart(SENSOR_TYPE_ACCELEROMETER, SENSOR_INTERVAL);
	}

	void PlayScreen::initHttpConnection()
	{
		int res = _m_Http->create(URL, HTTP_POST);

		if(res < 0)
			_m_infoLabel->setText("Unable to connect.");
		else
		{
			if(strcmp(_m_infoLabel->getText().c_str(), "") == 0)
				_m_infoLabel->setText("Connected to server");
			_m_connected = true;
			_m_readyForWrite = true;
		}
	}

	void PlayScreen::httpFinished(MAUtil::HttpConnection* http, int result)
	{
		//_m_infoLabel->setText("httpFinished");

		initHttpConnection();
	}
	void PlayScreen::connRecvFinished(MAUtil::Connection *conn, int result){}
	void PlayScreen::connReadFinished(MAUtil::Connection *conn, int result){}
	void PlayScreen::connWriteFinished(MAUtil::Connection *conn, int result)
	{
		//_m_infoLabel->setText("connWriteFinished");

		_m_Http->finish();
		_m_Http->close();
		initHttpConnection();
	}
}
