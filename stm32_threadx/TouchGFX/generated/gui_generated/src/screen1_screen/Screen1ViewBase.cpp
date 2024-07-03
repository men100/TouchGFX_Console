/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen1ViewBase::Screen1ViewBase() :
    buttonCallback(this, &Screen1ViewBase::buttonCallbackHandler)
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    volumeUpButton.setXY(187, 0);
    volumeUpButton.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MEDIUM_FILL_ACTION_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MEDIUM_FILL_PRESSED_ID));
    volumeUpButton.setLabelText(touchgfx::TypedText(T___SINGLEUSE_RHLM));
    volumeUpButton.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    volumeUpButton.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    volumeUpButton.setAction(buttonCallback);
    add(volumeUpButton);

    volumeDownButton.setXY(0, 0);
    volumeDownButton.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MEDIUM_FILL_ACTION_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MEDIUM_FILL_PRESSED_ID));
    volumeDownButton.setLabelText(touchgfx::TypedText(T___SINGLEUSE_VPF3));
    volumeDownButton.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    volumeDownButton.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    volumeDownButton.setAction(buttonCallback);
    add(volumeDownButton);
}

Screen1ViewBase::~Screen1ViewBase()
{

}

void Screen1ViewBase::setupScreen()
{

}

void Screen1ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &volumeUpButton)
    {
        //VolumeUp_Interaction
        //When volumeUpButton clicked call virtual function
        //Call volumeUp
        volumeUp();
    }
    if (&src == &volumeDownButton)
    {
        //VolumeDown_Interaction
        //When volumeDownButton clicked call virtual function
        //Call volumeDown
        volumeDown();
    }
}
