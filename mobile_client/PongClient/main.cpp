#include <ma.h>
#include <mavsprintf.h>
#include <MAUtil/Moblet.h>
#include <NativeUI/Widgets.h>
#include <NativeUI/WidgetUtil.h>

#include "ParentScreen.h"
#include "SplashScreen.h"

/**
 * Moblet to be used as a template for a Native UI application.
 */
class NativeUIMoblet : public MAUtil::Moblet
{
public:
	/**
	 * The constructor creates the user interface.
	 */
	NativeUIMoblet()
	{
		createUI();
	}

	/**
	 * Destructor.
	 */
	virtual ~NativeUIMoblet()
	{
	}

	/**
	 * Create the user interface.
	 */
	void createUI()
	{
		_m_splashScreen = new PongClientUI::SplashScreen();
		_m_Screen = new PongClientUI::ParentScreen();
		_m_splashScreen->show();
		_m_splashIsOn = true;
	}

	void pointerPressEvent(MAPoint2d p)
	{
		if(_m_splashIsOn)
		{
			_m_splashIsOn = false;
			_m_Screen->show();
		}
	}
private:
	bool _m_splashIsOn;
	PongClientUI::SplashScreen* _m_splashScreen;
	PongClientUI::ParentScreen* _m_Screen;
};

/**
 * Main function that is called when the program starts.
 */
extern "C" int MAMain()
{
	MAUtil::Moblet::run(new NativeUIMoblet());
	return 0;
}
