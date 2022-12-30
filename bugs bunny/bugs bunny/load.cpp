#include "header.h"
// #include<SDL2/SDL.h>
// #include<SDL2/SDL_image.h>
// #include<SDL2/SDL_ttf.h>
// #include<SDL2/SDL_mixer.h>
// #include<stdio.h>
// #include<sstream>


// #include "global.h"
// #include "ltexture.h"
// #include "Dot.h"
//int flags=0;
SDL_Window* gWindow = NULL;
int keyflag=1;
	int c9=0;
SDL_Renderer* gRenderer = NULL;
TTF_Font *gFont=NULL;
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 760;

//int soundflag=0;//this is for sound control
//	if(soundflag){
Mix_Music *bg = NULL;
Mix_Chunk *j = NULL;
Mix_Chunk *f = NULL;
Mix_Chunk *d = NULL;
Mix_Chunk *g = NULL;
Mix_Chunk *sg = NULL;//stone collision
Mix_Chunk *eg = NULL;//eagle collision
//}

//LTexture gBackgroundTexture;
LTexture gBGTexture;
LTexture coinTexture;
LTexture stoneTexture;
LTexture hangTexture;

LTexture crushTexture;
LTexture ncrushTexture;
LTexture sunTexture;
LTexture lifeTexture;
LTexture score1Texture;
LTexture mouseTexture;
LTexture scoreflagTexture;
LTexture meritTexture;
LTexture gTimeTextTexture;
LTexture gTimeTextTexturea;
LTexture hunterTexture;
LTexture newgameTexture;
LTexture ctpTexture;
LTexture exitTexture;
LTexture insTexture;
LTexture backTexture;
bool init();

bool loadMedia();


void close();




const int WALKING_ANIMATION_FRAMES = 4;
SDL_Rect gSpriteClips[ WALKING_ANIMATION_FRAMES ];
SDL_Rect fgSpriteClips[ WALKING_ANIMATION_FRAMES ];
SDL_Rect hgSpriteClips[ WALKING_ANIMATION_FRAMES ];
SDL_Rect eagleSpriteClips[ WALKING_ANIMATION_FRAMES ];
LTexture gSpriteSheetTexture;
LTexture fgSpriteSheetTexture;
LTexture hgSpriteSheetTexture;
LTexture eagleSpriteSheetTexture;


// Dot dot;


bool init()
{

	bool success = true;


	if( SDL_Init( SDL_INIT_VIDEO  | SDL_INIT_AUDIO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{

		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}


		gWindow = SDL_CreateWindow( "RUN BUNNY", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{

			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{

				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );


				int imgFlags = IMG_INIT_PNG;
				
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
					if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
					success = false;
				}
			}
		}
	}
TTF_Init();
	return success;
}

bool loadMedia()
{      gFont=TTF_OpenFont("font.otf",60);
	SDL_Color textColor={0,0,255,255};

	bool success = true;
gBGTexture.loadFromFile( "map.png" );
coinTexture.loadFromFile("carrot2.png");
stoneTexture.loadFromFile("realstone.png");
newgameTexture.loadFromFile("newgame.png");
ctpTexture.loadFromFile("ctp.png");
exitTexture.loadFromFile("exit.png");
insTexture.loadFromFile("ins.png");
backTexture.loadFromFile("back.png");
hangTexture.loadFromFile("hang2.png");

//crushTexture.loadFromFile("crush.png");
sunTexture.loadFromFile("dot.png");
lifeTexture.loadFromFile("love.jpg");
score1Texture.loadFromFile("score.jpg");
ncrushTexture.loadFromFile("ncrush.png");
mouseTexture.loadFromFile("frontbunny1.png");
scoreflagTexture.loadFromFile("scorelast.jpg");
//hunterTexture.loadFromFile("hunter3.png");
meritTexture.loadFromFile("merit2.png");
eagleSpriteSheetTexture.loadFromFile( "color.png" );
fgSpriteSheetTexture.loadFromFile("flam4.png");

hgSpriteSheetTexture.loadFromFile( "edit.png" );

// hgSpriteSheetTexture.loadFromFile( "hunteranimate.png" );
//  hgSpriteSheetTexture.loadFromFile( "no.png" );

	if( !gSpriteSheetTexture.loadFromFile( "hunter8.png" ) )
	{
		printf( "Failed to load walking animation texture!\n" );
		success = false;
	}
	else
	{
			for (int i = 0; i < 4; i++)
		{
			gSpriteClips[i].x = 212 * i;
			gSpriteClips[i].y = 0;
			gSpriteClips[i].w = 212;
			gSpriteClips[i].h = 293;
		}
			for (int j = 0; j < 4; j++)
		{
			fgSpriteClips[j].x = 125* j;
			fgSpriteClips[j].y = 0;
			fgSpriteClips[j].w = 90;
			fgSpriteClips[j].h = 196;
		}
		
		// for edit.png mohish

				
			for (int j1 = 0; j1 < 3; j1++)
		{
			hgSpriteClips[j1].x = 320* j1;
			hgSpriteClips[j1].y = 0;
			hgSpriteClips[j1].w = 310;
			hgSpriteClips[j1].h = 665;
		}
		
		// for (int j1 = 0; j1 < 4; j1++)
		// {
		// 	hgSpriteClips[j1].x = 252* j1;
		// 	hgSpriteClips[j1].y = 0;
		// 	hgSpriteClips[j1].w = 242;
		// 	hgSpriteClips[j1].h = 256;
		// }

		// 	for(int i=0;i<4;i++){
		// hgSpriteClips[ i ].x =   62*i;
		// hgSpriteClips[ i ].y =   0;
		// hgSpriteClips[ i ].w =  62;
		// hgSpriteClips[ i ].h = 81;
		// }

		// for cowboy


		// 	for(int i=0;i<4;i++){
		// hgSpriteClips[ i ].x =   144*i;
		// hgSpriteClips[ i ].y =   0;
		// hgSpriteClips[ i ].w = 145;
		// hgSpriteClips[ i ].h = 160;
		// }





			for (int k = 0; k < 4; k++)
		{
			eagleSpriteClips[k].x = 227* k;
			eagleSpriteClips[k].y = 0;
			eagleSpriteClips[k].w = 230;
			eagleSpriteClips[k].h = 309;
		}
		
		
		
				
	}	
	
//	if(soundflag){
		bg = Mix_LoadMUS( "jaz.mp3" );
	if( bg == NULL )
	{
		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}

		j = Mix_LoadWAV( "jump.wav" );
	if( j == NULL )
	{
		printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}
		f = Mix_LoadWAV( "eat.mp3" );
	if( f == NULL )
	{
		printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}
		d = Mix_LoadWAV( "oo.mp3" );
	if( d == NULL )
	{
		printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}	
	
			
	sg = Mix_LoadWAV( "stone.mp3" );	
	// if( sg == NULL )
	// {
	// 	printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
	// 	success = false;
	// }	//}

	eg = Mix_LoadWAV( "opp.mp3" );	
	// if( eg == NULL )
	// {
	// 	printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
	// 	success = false;
	// }	//}
	
	g = Mix_LoadWAV( "low.mp3" );
	if( g == NULL )
	{
		printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}	//}	
	return success;
}
#if defined(SDL_TTF_MAJOR_VERSION)
void LTexture::loadFromRenderedText(std::string textureText,SDL_Color textColor)
{
	free();
	SDL_Surface* textSurface=TTF_RenderText_Solid(gFont,textureText.c_str(),textColor);
	mTexture=SDL_CreateTextureFromSurface(gRenderer,textSurface);
	mWidth=textSurface->w;
	mHeight=textSurface->h;
	SDL_FreeSurface(textSurface);
		
}
#endif



void close()
{
gBGTexture.free();

	//if(soundflag){
	Mix_FreeChunk( j );
	Mix_FreeChunk( f );
	Mix_FreeChunk( d );
	Mix_FreeChunk( g );
		Mix_FreeChunk( sg );	Mix_FreeChunk( eg );
	j = NULL;
	f = NULL;
	d = NULL;
	g = NULL;
sg = NULL;eg = NULL;
	Mix_FreeMusic( bg );
	bg = NULL;//}
 coinTexture.free();
 newgameTexture.free();
 stoneTexture.free();
  insTexture.free();
  backTexture.free();
  
   exitTexture.free();
 hangTexture.free();
 crushTexture.free();
ncrushTexture.free();
 sunTexture.free();
lifeTexture.free();
score1Texture.free();
mouseTexture.free();
meritTexture.free();
gTimeTextTexture.free();
gTimeTextTexturea.free();

meritTexture.free();

	//Free global font
	TTF_CloseFont( gFont );
	gFont = NULL;

	gSpriteSheetTexture.free();
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	IMG_Quit();
	SDL_Quit();
}
