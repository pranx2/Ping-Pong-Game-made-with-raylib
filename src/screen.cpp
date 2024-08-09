#include "screen.hpp"
#include<raylib.h>
Button::Button(const char *imagepath, Vector2 imagePosition, int p_w, int p_h){
 Image image = LoadImage(imagepath);
 ImageResize(&image,p_w,p_h);
 Texture = LoadTextureFromImage(image);

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
  Rectangle rect = {Position.x, Position.y,static_cast<float>(Texture.width),static_cast<float>(Texture.height)};
  if(CheckCollisionPointRec(mousePosition,rect) && MousePressed){
    return true;
  }
 return false;
}
