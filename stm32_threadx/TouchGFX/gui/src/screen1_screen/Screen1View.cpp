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
