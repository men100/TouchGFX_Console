// 4.23.0 0xfcaa0dbd
// Generated by imageconverter. Please, do not edit!

#include <images/BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_alternate_theme_images_widgets_button_icon_rounded_medium_fill_action[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MEDIUM_FILL_ACTION_ID = 0, Size: 138x138 pixels
extern const unsigned char image_alternate_theme_images_widgets_button_icon_rounded_medium_fill_active[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MEDIUM_FILL_ACTIVE_ID = 1, Size: 138x138 pixels
extern const unsigned char image_alternate_theme_images_widgets_button_icon_rounded_medium_fill_pressed[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MEDIUM_FILL_PRESSED_ID = 2, Size: 138x138 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_alternate_theme_images_widgets_button_icon_rounded_medium_fill_action, 0, 138, 138, 2, 2, 134, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 134, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_alternate_theme_images_widgets_button_icon_rounded_medium_fill_active, 0, 138, 138, 2, 2, 134, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 134, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_alternate_theme_images_widgets_button_icon_rounded_medium_fill_pressed, 0, 138, 138, 2, 2, 134, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 134, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
} // namespace BitmapDatabase
