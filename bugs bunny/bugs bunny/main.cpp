#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>

#define WINDOW_WIDTH (1280)
#define WINDOW_HEIGHT (960)
#define SCROLL_SPEED (300)


int main(int agr, char* args[]){

	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER)>0){
		printf("video and timer: %s\n",SDL_GetError());
	}
	if (!(IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG)))
		printf("image: %s\n",SDL_GetError());

	printf("Initialization Complete\n");

	SDL_Window* win = SDL_CreateWindow("SDL Demonstration",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

 	if (!win){
 		printf("window: %s\n",SDL_GetError());
 		SDL_Quit();
		return 1;
 	}

 	Uint32 render_flags = SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC;
 	SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);

 	if (!rend){
 		printf("renderer: %s\n",SDL_GetError());
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return 1;
 	}

 	SDL_Surface* surface = IMG_Load("dot.png");
 	if (!surface){
 		printf("Redbar Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return 1;
 	}

 
 	SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
 	SDL_FreeSurface(surface);
 	if(!tex){
 		printf("Redbar Texture %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return 1;
 	}

 	SDL_Rect dest;
 	SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);

 	dest.w = (int) dest.w * 0.1;
 	dest.h = (int) dest.h * 0.1;
 	dest.x = 0;
 	dest.y = (int)(WINDOW_HEIGHT*0.1);
 	float x_pos = 0;

 	SDL_RenderClear(rend);
 	SDL_RenderCopy(rend, tex, NULL, &dest);
 	SDL_RenderPresent(rend);

 	while(dest.x<=WINDOW_WIDTH){
 		SDL_RenderClear(rend);
 		dest.x = (int) x_pos;
 		SDL_RenderCopy(rend, tex, NULL, &dest);
 		SDL_RenderPresent(rend);
 		x_pos += (float) SCROLL_SPEED/60;
 		SDL_Delay(1000/60);

 	}



 	SDL_Delay(2000);
 	SDL_DestroyRenderer(rend);
 	SDL_DestroyWindow(win);
 	//SDL_DestroyWindow(win);

	SDL_Quit();
	return 0;
}
