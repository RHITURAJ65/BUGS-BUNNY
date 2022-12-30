#ifndef GLOBAL_H
#define GLOBAL_H


#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_mixer.h>
#include<stdio.h>
#include<sstream>

#include "ltexture.h"
#include "Dot.h"

extern SDL_Window* gWindow ;
extern int keyflag;
extern int c9;
extern SDL_Renderer* gRenderer ;
extern TTF_Font *gFont;
extern const int SCREEN_WIDTH ;
extern const int SCREEN_HEIGHT ;

//int soundflag=0;//this is for sound control
//	if(soundflag){
extern Mix_Music *bg;
extern Mix_Chunk *j ;
extern Mix_Chunk *f;
extern Mix_Chunk *d;
extern Mix_Chunk *g ;
extern Mix_Chunk *sg ;//stone collision
extern Mix_Chunk *eg ;//eagle collision
//}

//LTexture gBackgroundTexture;
extern LTexture gBGTexture;
extern LTexture coinTexture;
extern LTexture stoneTexture;
extern LTexture newgameTexture;
extern LTexture ctpTexture;
extern LTexture exitTexture;
extern LTexture insTexture;
extern LTexture backTexture;
extern LTexture hangTexture;

extern LTexture crushTexture;
extern LTexture ncrushTexture;
extern LTexture sunTexture;
extern LTexture lifeTexture;
extern LTexture score1Texture;
extern LTexture mouseTexture;
extern LTexture scoreflagTexture;
extern LTexture meritTexture;
extern LTexture gTimeTextTexture;
extern LTexture gTimeTextTexturea;
extern LTexture hunterTexture;
bool init();

bool loadMedia();


void close();




extern const int WALKING_ANIMATION_FRAMES ;
extern SDL_Rect gSpriteClips[ 4 ];
extern SDL_Rect fgSpriteClips[ 4 ];
extern SDL_Rect hgSpriteClips[ 4 ];
extern SDL_Rect eagleSpriteClips[ 4 ];
extern LTexture gSpriteSheetTexture;
extern LTexture fgSpriteSheetTexture;
extern LTexture hgSpriteSheetTexture;
extern LTexture eagleSpriteSheetTexture;


#endif
