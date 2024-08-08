#pragma once
#include<raylib.h>

class Button{
 private:
 Vector2 Position;//x,y position;
 public:
 Texture2D Texture;
 Button(const char* imagepath, Vector2 imagePosition,int p_w, int p_h);
 ~Button();
 void drawbutton();
 bool IsPressed(Vector2 mousePosition, bool MousePressed);
};