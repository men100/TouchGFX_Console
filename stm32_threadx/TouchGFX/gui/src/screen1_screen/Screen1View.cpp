#include <gui/screen1_screen/Screen1View.hpp>
#include <stdio.h>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::play()
{
	printf("play\n");
	presenter->play();
}

void Screen1View::nextMusic()
{
	printf("next\n");
	presenter->nextMusic();
}

void Screen1View::prevMusic()
{
	printf("prev\n");
	presenter->prevMusic();
}

void Screen1View::volumeUp()
{
	printf("volumeUp\n");
	presenter->volumeUp();
}

void Screen1View::volumeDown()
{
	printf("volumeDown\n");
	presenter->volumeDown();
}

void Screen1View::displayPort()
{
	printf("displayPort\n");
	presenter->displayPort();
}

void Screen1View::hdmi1()
{
	printf("hdmi1\n");
	presenter->hdmi1();
}

void Screen1View::hdmi2()
{
	printf("hdmi2\n");
	presenter->hdmi2();
}

void Screen1View::typec()
{
	printf("typec\n");
	presenter->typec();
}
