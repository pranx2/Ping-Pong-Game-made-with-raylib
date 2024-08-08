#include "screen.hpp"
#include<raylib.h>
Button::Button(const char *imagepath, Vector2 imagePosition, int p_w, int p_h)
{
 Image image = LoadImage(imagepath);
 ImageResize(&image,p_w,p_h);

 UnloadImage(image);//to Free up memory;
 Position = imagePosition;
}
Button::~Button(){
 UnloadTexture(Texture);
}

void Button::drawbutton(){
 //Taken A vector x,y coordinates Texture;
 DrawTextureV(Texture,Position,WHITE);
}

bool Button::IsPressed(Vector2 mousePosition, bool MousePressed){

 return false;
}
