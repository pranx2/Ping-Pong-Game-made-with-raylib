#include<raylib.h>
#define Width 720
#define Height 480
#define BallSpeed 5           //Change The Ball Speed;    //Default 7;
#define PlayerPaddleSize 50   //Change The paddle Size;  //Default 50;
#define PlayerPaddleSpeed 8  //Change The paddle Speed;  //Default 8;
#define AI_Speed 6           //Change The Paddle Speed;  //Default 8;

#include "pong.hpp"
int main(){
  InitWindow(Width,Height,"Pong Game v1.0");
  SetTargetFPS(60);
    pong line;
    //Ball MoveMent;
    pong ball;
    ball.x = Width/2;
    ball.y = Height/2;
    ball.speed_x = BallSpeed;
    ball.speed_y = BallSpeed;
    ball.r = 10;
     
    //Paddle MoveMent Player;
    paddleMovement player;//Right Side;
    player.width = 10;//paddle width;
    player.height = PlayerPaddleSize;//paddle height;
    player.x = Width-20;//x postion;
    player.y = Height/2 - 30; // y position;
    player.speed = 8; // paddle movement Speed;

  //Paddle MoveMent AI;
    CpuPuddle Ai;
    Ai.width = 10;
    Ai.height = 50;
    Ai.x = 10;
    Ai.y = Height/2 - 20;
    Ai.speed = AI_Speed;

  while(WindowShouldClose() == false){
  BeginDrawing();
  ball.ballMovement();
  player.update();//player
  Ai.update(ball.y);//Ai

  //Check Collision;---->Player;
  if(CheckCollisionCircleRec( Vector2{ball.x, ball.y},ball.r,Rectangle{player.x, player.y, player.width, player.height})){
    ball.speed_x  = -ball.speed_x; //Reverse the Ball;
  }
  //Check Collision;---->AI;
  if(CheckCollisionCircleRec(Vector2{ball.x,ball.y},ball.r,Rectangle{Ai.x, Ai.y, Ai.width, Ai.height})){
    ball.speed_x = -ball.speed_x;
  }

  ball.~pong();
  ball.BG();
  line.line();//Middle Line;
  ball.ball(ball.x, ball.y, ball.r);//Ball postion;
  player.paddle(player.x, player.y, player.width, player.height);  //paddle player;
  Ai.paddle(Ai.x, Ai.y, Ai.width, Ai.height);//Paddle Ai;
  DrawText(TextFormat("AI: %i",ball.AIscore()),Width/2 - 200,10,20,WHITE);///Ai Score Board;
  DrawText(TextFormat("PLAYER: %i",ball.PLAYERscore()),Width/2 + 120,10,20,WHITE);//Player Score Board;
  EndDrawing();
  }
CloseWindow();
 return 0;
}