/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen1ViewBase::Screen1ViewBase() :
    buttonCallback(this, &Screen1ViewBase::buttonCallbackHandler),
    flexButtonCallback(this, &Screen1ViewBase::flexButtonCallbackHandler)
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    backgroundButton.setBoxWithBorderPosition(0, 0, 800, 480);
    backgroundButton.setBorderSize(5);
    backgroundButton.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(0, 0, 0));
    backgroundButton.setAction(flexButtonCallback);
    backgroundButton.setPosition(0, 0, 800, 480);
    add(backgroundButton);

    volumeBox.setPosition(485, 19, 138, 138);
    volumeBox.setColor(touchgfx::Color::getColorFromRGB(28, 133, 28));
    add(volumeBox);

    cpuBox.setPosition(15, 18, 138, 138);
    cpuBox.setColor(touchgfx::Color::getColorFromRGB(28, 133, 28));
    add(cpuBox);

    volumeUpButton.setXY(485, 171);
    volumeUpButton.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MEDIUM_FILL_ACTION_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MEDIUM_FILL_PRESSED_ID));
    volumeUpButton.setLabelText(touchgfx::TypedText(T___SINGLEUSE_RHLM));
    volumeUpButton.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    volumeUpButton.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    volumeUpButton.setAction(buttonCallback);
    add(volumeUpButton);

    playButton.setXY(172, 322);
    playButton.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MEDIUM_FILL_ACTION_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MEDIUM_FILL_PRESSED_ID));
    playButton.setLabelText(touchgfx::TypedText(T___SINGLEUSE_DTVB));
    playButton.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    playButton.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    playButton.setAction(buttonCallback);
    add(playButton);

    nextButton.setXY(332, 322);
    nextButton.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MEDIUM_FILL_ACTION_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MEDIUM_FILL_PRESSED_ID));
    nextButton.setLabelText(touchgfx::TypedText(T___SINGLEUSE_YO9U));
    nextButton.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nextButton.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nextButton.setAction(buttonCallback);
    add(nextButton);

    prevButton.setXY(14, 322);
    prevButton.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MEDIUM_FILL_ACTION_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MEDIUM_FILL_PRESSED_ID));
    prevButton.setLabelText(touchgfx::TypedText(T___SINGLEUSE_LNUN));
    prevButton.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    prevButton.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    prevButton.setAction(buttonCallback);
    add(prevButton);

    displayportButton.setXY(15, 171);
    displayportButton.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MEDIUM_FILL_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MEDIUM_FILL_PRESSED_ID));
    displayportButton.setLabelText(touchgfx::TypedText(T___SINGLEUSE_EGPT));
    displayportButton.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    displayportButton.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    displayportButton.setAction(buttonCallback);
    add(displayportButton);

    hdmi1Button.setXY(173, 171);
    hdmi1Button.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MEDIUM_FILL_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MEDIUM_FILL_PRESSED_ID));
    hdmi1Button.setLabelText(touchgfx::TypedText(T___SINGLEUSE_JU3E));
    hdmi1Button.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    hdmi1Button.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    hdmi1Button.setAction(buttonCallback);
    add(hdmi1Button);

    volumeDownButton.setXY(485, 323);
    volumeDownButton.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MEDIUM_FILL_ACTION_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MEDIUM_FILL_PRESSED_ID));
    volumeDownButton.setLabelText(touchgfx::TypedText(T___SINGLEUSE_VPF3));
    volumeDownButton.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    volumeDownButton.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    volumeDownButton.setAction(buttonCallback);
    add(volumeDownButton);

    volumeLabelTextArea.setXY(517, 64);
    volumeLabelTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    volumeLabelTextArea.setLinespacing(0);
    volumeLabelTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_POGE));
    add(volumeLabelTextArea);

    cpuLabelTextArea.setXY(54, 39);
    cpuLabelTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    cpuLabelTextArea.setLinespacing(0);
    cpuLabelTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_BAJR));
    add(cpuLabelTextArea);

    volumeTextArea.setXY(524, 98);
    volumeTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    volumeTextArea.setLinespacing(0);
    Unicode::snprintf(volumeTextAreaBuffer, VOLUMETEXTAREA_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_QXAV).getText());
    volumeTextArea.setWildcard(volumeTextAreaBuffer);
    volumeTextArea.resizeToCurrentText();
    volumeTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_0VKQ));
    add(volumeTextArea);

    cpuTextArea.setXY(54, 109);
    cpuTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    cpuTextArea.setLinespacing(0);
    Unicode::snprintf(cpuTextAreaBuffer, CPUTEXTAREA_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_ZQHL).getText());
    cpuTextArea.setWildcard(cpuTextAreaBuffer);
    cpuTextArea.resizeToCurrentText();
    cpuTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_WR48));
    add(cpuTextArea);

    gpuBox.setPosition(332, 18, 138, 138);
    gpuBox.setColor(touchgfx::Color::getColorFromRGB(28, 133, 28));
    add(gpuBox);

    gpuLabelTextArea.setXY(370, 39);
    gpuLabelTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    gpuLabelTextArea.setLinespacing(0);
    gpuLabelTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_5BDZ));
    add(gpuLabelTextArea);

    gpuTextArea.setXY(370, 109);
    gpuTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    gpuTextArea.setLinespacing(0);
    Unicode::snprintf(gpuTextAreaBuffer, GPUTEXTAREA_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_C3ZQ).getText());
    gpuTextArea.setWildcard(gpuTextAreaBuffer);
    gpuTextArea.resizeToCurrentText();
    gpuTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_YMYI));
    add(gpuTextArea);

    memoryBox.setPosition(173, 18, 138, 138);
    memoryBox.setColor(touchgfx::Color::getColorFromRGB(28, 133, 28));
    add(memoryBox);

    memoryLabelTextArea.setXY(202, 39);
    memoryLabelTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    memoryLabelTextArea.setLinespacing(0);
    memoryLabelTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_RA6S));
    add(memoryLabelTextArea);

    memoryTextArea.setXY(212, 109);
    memoryTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    memoryTextArea.setLinespacing(0);
    Unicode::snprintf(memoryTextAreaBuffer, MEMORYTEXTAREA_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_X8D8).getText());
    memoryTextArea.setWildcard(memoryTextAreaBuffer);
    memoryTextArea.resizeToCurrentText();
    memoryTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_2NUH));
    add(memoryTextArea);

    displayProgress.setXY(0, 0);
    displayProgress.setProgressIndicatorPosition(0, 0, 800, 10);
    displayProgress.setRange(0, 100);
    displayProgress.setDirection(touchgfx::AbstractDirectionProgress::RIGHT);
    displayProgress.setBackground(touchgfx::Bitmap(BITMAP_PROGRESSBAR_ID));
    displayProgress.setColor(touchgfx::Color::getColorFromRGB(0, 240, 255));
    displayProgress.setValue(100);
    add(displayProgress);
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
    if (&src == &playButton)
    {
        //PlayButton_Interaction
        //When playButton clicked call virtual function
        //Call play
        play();
    }
    if (&src == &nextButton)
    {
        //NextButton_Interaction
        //When nextButton clicked call virtual function
        //Call nextMusic
        nextMusic();
    }
    if (&src == &prevButton)
    {
        //PrevButton_Interaction
        //When prevButton clicked call virtual function
        //Call prevMusic
        prevMusic();
    }
    if (&src == &displayportButton)
    {
        //DisplayPortButton_Interaction
        //When displayportButton clicked call virtual function
        //Call displayPort
        displayPort();
    }
    if (&src == &hdmi1Button)
    {
        //HDMI1Button_Interaction
        //When hdmi1Button clicked call virtual function
        //Call hdmi1
        hdmi1();
    }
}

void Screen1ViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &backgroundButton)
    {
        //BackgroundButton_Interaction
        //When backgroundButton clicked call virtual function
        //Call backgroundTouched
        backgroundTouched();
    }
}
