#include "screen.hpp"
Button::Button(const char *imagepath, Vector2 imagePosition, int p_w, int p_h)
{
 Image img = LoadImage(imagepath);
 ImageResize(&img,p_w,p_h);
 UnloadImage(img);
 Position = imagePosition;
}
Button::~Button(){
 UnloadTexture(Texture);
}
// void Button::drawbutton(){
//  DrawTexture(Texture,Pos,WHITE);
// }