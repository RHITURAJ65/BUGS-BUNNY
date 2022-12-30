#ifndef LTEXTURE_H
#define LTEXTURE_H

struct LTexture
{
	//public:
		LTexture();
		~LTexture();
		bool loadFromFile( std::string path );
		#if defined(SDL_TTF_MAJOR_VERSION)
	void  loadFromRenderedText(std::string textureText,SDL_Color textColor);
	#endif 
	void scorerender(int x,int y,SDL_Rect* clip=NULL,double angle=0.0,SDL_Point* center=NULL,SDL_RendererFlip flip=SDL_FLIP_NONE);
		void free();
		void setColor( Uint8 red, Uint8 green, Uint8 blue );
		void setBlendMode( SDL_BlendMode blending );
		void setAlpha( Uint8 alpha );
		void render( int x, int y, SDL_Rect* clip = NULL );
		void cowrender( int x, int y, SDL_Rect* clip = NULL );
		void frender( int x, int y, SDL_Rect* fclip = NULL );
		void brender(int x,int y);
		int getWidth();
				void efrender( int x, int y, SDL_Rect* fclip = NULL );
		void sunrender(int x, int y);
		void score1render(int x, int y);
		void liferender(int x, int y);
		void hunterrender(int x,int y);
		int getHeight();
		void ncrushrender(int x, int y);
		void coinrender(int x,int y);
			void stonerender(int x,int y);
				void hangrender(int x,int y);
		void crushrender(int x, int y);
		void newgamerender(int x, int y);
			void ctprender(int x, int y);
		
		void exitrender(int x, int y);void insrender(int x, int y);
		void mouserender(int x,int y);
				void bbrender( int x, int y);// SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
	//private:

		SDL_Texture* mTexture;


		int mWidth;
		int mHeight;
};

#endif
