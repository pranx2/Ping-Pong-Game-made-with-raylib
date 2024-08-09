#include "pong.hpp"
#define Width 720
#define Height 480
int Player_Score = 0;
int AI_score = 0;

/*
  @author->Pranx2
  *Main Working cpp
  *clear background;
  *Ball Physics;
  *Player Score;
  *Paddle Physics;
  *Score Reset;
  *Screen Limitation;
 */
pong::pong(){
}

pong::~pong(){
  ClearBackground(BLACK);
}

void pong::ball(int x, int y, int r){//Ball texture;
// Image img = LoadImage("res/ball.png");
// ImageResize(&img,300,50);
// Texture = LoadTextureFromImage(img);
// DrawTexture(Texture,x,y,WHITE);
// UnloadTexture(Texture);
DrawCircle(x,y,r,PURPLE);
}

void pong::ScoreAudio(){
  Sound scoreSfx = LoadSound("res/sfx/score.wav");
  PlaySound(scoreSfx);
}
void pong::ballMovement()
{ // Ball Physics;
  x += speed_x;
  y += speed_y;
  if (x + r >= GetScreenWidth() || x - r <= 0)
  {
    speed_x = -speed_x;
  }

  if (x + r >= GetScreenWidth())
  {
    AI_score++; // AI SCORE;
    ScoreAudio();
    Reset();
 }

 if( x - r  <= 0 || x <=0  ){
  Player_Score++; //PLAYER SCORE;
  ScoreAudio();
  Reset();
 }


 if(y + r >= GetScreenHeight() || y - r <= 0){
  speed_y = - speed_y;
 }
}

int pong::AIscore(){
  return AI_score;
}

int pong::PLAYERscore()
{
 return Player_Score;
}

void pong::Reset(){
  x = GetScreenWidth()/2;
  y = GetScreenHeight()/2;

  int Speed_Choice[2] = {1, -1};
  speed_x *= Speed_Choice[GetRandomValue(0,1)];
  speed_y *= Speed_Choice[GetRandomValue(0,1)];
}

//Paddle MoveMent;

void paddleMovement::limitMovement(){
 if( y <= 0) y = 0;
 if( y + height >= GetScreenHeight()){
  y = GetScreenHeight() - height;
 }
}

void paddleMovement::paddle(float x, float y, float width, float height)
{
 DrawRectangleRounded(Rectangle{x,y,width,height},0,2,SKYBLUE);
}

void paddleMovement::update(){
 if(IsKeyDown(KEY_UP )){
  y -= speed;
 }
 if(IsKeyDown(KEY_DOWN)){
  y += speed;
 }
 limitMovement();
}

void CpuPuddle::update(int ball_y){
 if( y + height/2 > ball_y){
  y -= speed;
 }
 if(y + height/2 <= ball_y){
  y += speed;
 }
 limitMovement();
}

