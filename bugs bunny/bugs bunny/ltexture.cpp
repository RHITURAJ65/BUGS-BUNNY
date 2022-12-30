#include "header.h"
// #include<SDL2/SDL.h>
// #include<SDL2/SDL_image.h>
// #include<SDL2/SDL_ttf.h>
// #include<SDL2/SDL_mixer.h>
// #include<stdio.h>
// #include<sstream>


// #include "global.h"
// #include "ltexture.h"

LTexture::LTexture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile( std::string path )
{
	
	free();

	SDL_Texture* newTexture = NULL;


	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{

		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{

			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}


		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void LTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}//this bbrender is for background scrolling
void LTexture::bbrender( int x, int y)//, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, 1280, 760 };

	//Set clip rendering dimensions
	//if( clip != NULL )
	
	//renderQuad.w = clip->w;
		//renderQuad.h = clip->h;
	

	//Render to screen
	//SDL_RenderCopyEx( gRenderer, mTexture,clip, &renderQuad, angle, center, flip );
	//SDL_RenderCopyEx(gRenderer,mTexture,clip,&renderQuad,angle,center,flip);
SDL_RenderCopy(gRenderer,mTexture,NULL,&renderQuad);
	
}
void LTexture::sunrender(int x,int y){
	SDL_Rect renderQuad={x,y,SCREEN_WIDTH,SCREEN_HEIGHT};
	SDL_RenderCopy(gRenderer,mTexture,NULL,&renderQuad);}
	
	void LTexture::liferender(int x,int y){
	SDL_Rect renderQuad={x,y,40,40};
	SDL_RenderCopy(gRenderer,mTexture,NULL,&renderQuad);}
	
	void LTexture::score1render(int x,int y){
	SDL_Rect renderQuad={x,y,100,50};
	SDL_RenderCopy(gRenderer,mTexture,NULL,&renderQuad);}
	
void LTexture::coinrender(int x,int y){

	SDL_Rect renderQuad={x,y,70,70};
	SDL_RenderCopy(gRenderer,mTexture,NULL,&renderQuad);
	
}
void LTexture::crushrender(int x,int y){
	SDL_Rect renderQuad={x,y,160,160};
	SDL_RenderCopy(gRenderer,mTexture,NULL,&renderQuad);
}
void LTexture::stonerender(int x,int y){
	SDL_Rect renderQuad={x,y,90,100};
	SDL_RenderCopy(gRenderer,mTexture,NULL,&renderQuad);
}void LTexture::newgamerender(int x,int y){
	SDL_Rect renderQuad={x,y,450,80};
	SDL_RenderCopy(gRenderer,mTexture,NULL,&renderQuad);
}
void LTexture::exitrender(int x,int y){
	SDL_Rect renderQuad={x,y,450,80};
	SDL_RenderCopy(gRenderer,mTexture,NULL,&renderQuad);
}

void LTexture::ctprender(int x,int y){
	SDL_Rect renderQuad={x,y,450,80};
	SDL_RenderCopy(gRenderer,mTexture,NULL,&renderQuad);
}
void LTexture::insrender(int x,int y){
	SDL_Rect renderQuad={x,y,450,80};
	SDL_RenderCopy(gRenderer,mTexture,NULL,&renderQuad);
}
void LTexture::hangrender(int x,int y){
	SDL_Rect renderQuad={x,y,190,180};
	SDL_RenderCopy(gRenderer,mTexture,NULL,&renderQuad);
}


//rendering for bunny
void LTexture::mouserender(int x,int y){
	SDL_Rect renderQuad={x,y,SCREEN_WIDTH ,SCREEN_HEIGHT};
	SDL_RenderCopy(gRenderer,mTexture,NULL,&renderQuad);
}
void LTexture::hunterrender(int x,int y){
	SDL_Rect renderQuad={x,y,60 ,100};
	SDL_RenderCopy(gRenderer,mTexture,NULL,&renderQuad);
}
void LTexture::ncrushrender(int x,int y){//for negative crash;
	SDL_Rect renderQuad={x,y,80,80};
	SDL_RenderCopy(gRenderer,mTexture,NULL,&renderQuad);
}
void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{

	SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{

	SDL_SetTextureBlendMode( mTexture, blending );
}
		
void LTexture::setAlpha( Uint8 alpha )
{

	SDL_SetTextureAlphaMod( mTexture, alpha );
}
//render for bunny
void LTexture::render( int x, int y, SDL_Rect* clip )
{

	SDL_Rect renderQuad = { x, y, 120, 220 };


	

	//Render to screen
	SDL_RenderCopy( gRenderer, mTexture, clip, &renderQuad );
}

void LTexture::cowrender( int x, int y, SDL_Rect* clip )
{

	SDL_Rect renderQuad = { x, y, 320, 300 };


	

	//Render to screen
	SDL_RenderCopy( gRenderer, mTexture, clip, &renderQuad );
}


//RENDERING FOR FIRE
void LTexture::frender( int x, int y, SDL_Rect* fclip )
{

	SDL_Rect renderQuad = { x, y, 80, 70 };



	//Render to screen
	SDL_RenderCopy( gRenderer, mTexture, fclip, &renderQuad );
}
//rendering for eagle
void LTexture::efrender( int x, int y, SDL_Rect* fclip )
{

	SDL_Rect renderQuad = { x, y, 190, 180 };



	//Render to screen
	SDL_RenderCopy( gRenderer, mTexture, fclip, &renderQuad );
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}
void LTexture::scorerender(int x,int y,SDL_Rect* clip,double angle,SDL_Point* center,SDL_RendererFlip flip)
{
	SDL_Rect renderQuad={x,y,mWidth,mHeight};
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}




void LTexture::brender(int x,int y){
	SDL_Rect brenderQuad={x,y,1280,760};
	SDL_RenderCopy(gRenderer,mTexture,NULL,&brenderQuad);
}
