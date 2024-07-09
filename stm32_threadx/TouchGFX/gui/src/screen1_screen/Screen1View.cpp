#include <gui/screen1_screen/Screen1View.hpp>
#include <stdio.h>

Screen1View::Screen1View() : tickCounter(0)
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
    presenter->setCurrentScreenIndex(0);
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::handleTickEvent()
{
	touchgfx::Unicode::snprintf(volumeTextAreaBuffer, VOLUMETEXTAREA_SIZE, "%d", presenter->getSystemVolume());
	touchgfx::Unicode::snprintf(cpuTextAreaBuffer, CPUTEXTAREA_SIZE, "%d", presenter->getCpuUsage());
	touchgfx::Unicode::snprintf(memoryTextAreaBuffer, MEMORYTEXTAREA_SIZE, "%d", presenter->getMemoryUsage());
	touchgfx::Unicode::snprintf(gpuTextAreaBuffer, GPUTEXTAREA_SIZE, "%d", presenter->getGpuUsage());

	volumeTextArea.invalidate();
	cpuTextArea.invalidate();
	memoryTextArea.invalidate();
	gpuTextArea.invalidate();

	if (presenter->getBackLightState()) {
		int rest = BackLightOffTick - tickCounter;

		if (rest > 0) {
			int displayProgressValue = rest / IndicatorDivider;
			displayProgress.setValue(displayProgressValue);
			tickCounter++;
		} else {
			presenter->setBackLightState(false);
		}
	} else {
		displayProgress.setValue(100);
		tickCounter = 0;
	}
}

void Screen1View::play()
{
	printf("play\n");
	presenter->play();
	tickCounter = 0;
}

void Screen1View::nextMusic()
{
	printf("next\n");
	presenter->nextMusic();
	tickCounter = 0;
}

void Screen1View::prevMusic()
{
	printf("prev\n");
	presenter->prevMusic();
	tickCounter = 0;
}

void Screen1View::volumeUp()
{
	printf("volumeUp\n");
	presenter->volumeUp();
	tickCounter = 0;
}

void Screen1View::volumeDown()
{
	printf("volumeDown\n");
	presenter->volumeDown();
	tickCounter = 0;
}

void Screen1View::displayPort()
{
	printf("displayPort\n");
	presenter->displayPort();
	tickCounter = 0;
}

void Screen1View::hdmi1()
{
	printf("hdmi1\n");
	presenter->hdmi1();
	tickCounter = 0;
}

void Screen1View::hdmi2()
{
	printf("hdmi2\n");
	presenter->hdmi2();
	tickCounter = 0;
}

void Screen1View::typec()
{
	printf("typec\n");
	presenter->typec();
	tickCounter = 0;
}

void Screen1View::backgroundTouched()
{
	printf("background\n");
	tickCounter = 0;
}
