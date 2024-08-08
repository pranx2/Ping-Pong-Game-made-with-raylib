#pragma once
#include<raylib.h>

class Button{
 private:
 Texture2D Texture;
 public:
 Button(const char* imagepath, Vector2 imagePosition,int p_w, int p_h);
 ~Button();
 void drawbutton();
 Vector2 Position;
 bool IsPressed(Vector2 mousePosition, bool MousePressed);
};