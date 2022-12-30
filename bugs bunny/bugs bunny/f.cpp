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

int main( int argc, char* args[] )
{
char s[12];
scanf("%s",s);



bool quit = false;

	while(!quit){
		// Dot dot;

	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	

					Dot dot;


		int soundflag=1;
	int c2=4;
	int point=0;

	int c=1;
	int c1=1;
	int flags=0;int scoreflag=0;
dot.mPosX=600;
dot.mPosY=500;
				SDL_Event e;
	SDL_Color textColor={0,0,255};
	std::stringstream timeText;
	std::stringstream timeTexta;
				int frame = 0;
	int scrollingOffset = 0;
	int x=1280;
	int sx=1280;
	int sy=630;
int correctflag=1;
int hsx,hsy;
	int hsxx,hsyy;
	int hangflag=0;
	int a[]={100,700,300,600,150,360,630,230,200,500,410,310,210,590,405,237,455,167,189,378,520,437,278,620,550,120,490,310,410,40,190,690,390};
	int i=0;int fi1=0;
//	int firea[]={1200,1200,1160,1169,1180,1820,1800,200,1380,1400,220,405,1200,240,1790,260,1360,280,415,1780,300,425,1340,320,1180,340,440,1320,360,1760,1160,380,460,1300,1740,1140,480,1280,1720,1120,500,1700,520,1680,1100,1640,540,1080,560,1060,580,1620,1040,600,1600,1020,620,1580,1000,1560,640,980,1540,660,960,1520,1500,680,1480,920,1460,700,1440,900,720,1420,880,1400,740,860,760,840,780,840,800};
	int firea[]={50,1230,100,1200,150,1150,200,1100,250,1050,300,1000,350,950,400,900,450,850,500,800,550,750,600,30,700,80,650,130};
	int hunterx=0,huntery=480;
	 //fi1=sizeof(firea)/sizeof(firea[0]);
	int cb=0;
	int x1=400,y1=0;
	int eaglex=1280,eagley=280;
	int result=0;
			int y=400;
			Mix_PlayMusic( bg, -1 );
			while( !quit )
			{

				while( SDL_PollEvent( &e ) != 0 )
				{

					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					dot.handleEvent( e );
				}



dot.move();

//mouseTexture.mouserender(0,0);
	//dot.move();			//Scroll background
				scrollingOffset=scrollingOffset-2*c;
				
				//if(c>=5) scrollingOffset=scrollingOffset-1*(c+);
				if( scrollingOffset < -gBGTexture.getWidth() )
				{
					scrollingOffset = 0;
				}
				
				timeText.str("");
	timeText<<point;
	
	gTimeTextTexture.loadFromRenderedText(timeText.str().c_str(),textColor);
	
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );
					mouseTexture.mouserender(0,0);	
					
					int mousex;int mousey;
				int buttons=SDL_GetMouseState(&mousex,&mousey);
				if(mousex>=430&&mousex<=800&&mousey>=370&&mousey<=400){
			//flags=1;
			newgameTexture.newgamerender(410,330);
					}
					
					
					if(mousex>=578&&mousex<=715&&mousey>=520&&mousey<=570){
			//quit=true;
			exitTexture.exitrender(578,520);
			
					}
					
					if(mousex>=420&&mousex<=800&&mousey>=450&&mousey<=480){
						//scoreflag=1;
							insTexture.insrender(420,450);
					}
		
				if(buttons&SDL_BUTTON(SDL_BUTTON_LEFT)){
							if(mousex>=430&&mousex<=800&&mousey>=370&&mousey<=400){
			flags=1;//newgameTexture.newgamerender(200,200);
					}
					if(mousex>=578&&mousex<=715&&mousey>=520&&mousey<=570){
			quit=true;
			
					}
					
					if(mousex>=420&&mousex<=800&&mousey>=450&&mousey<=480){
						scoreflag=1;
					}
					if(mousex>=1015&&mousex<=1280&&mousey>=30&&mousey<=130){
						scoreflag=0;
					}
				}
					
				if(scoreflag){
					scoreflagTexture.mouserender(0,0);			if(mousex>=1015&&mousex<=1280&&mousey>=30&&mousey<=130){backTexture.exitrender(985,20);}
				}			
	if(flags){gBGTexture.bbrender( scrollingOffset, 0 );
				gBGTexture.bbrender( scrollingOffset + gBGTexture.getWidth(), 0 );	}		
				/*
				//srand((unsigned)time(0));
			//for(int i=0;i<100;i++){
				//int x,y;
				//int c=rand()%5;
					switch(c)
					{case 0:
						{
						x=420;y=430;
						break;
						}
						case 1:
						
						{
						x=20;y=30;
						break;
						}
						case 2:
						{
						x=140;y=240;
						break;
						}
						case 3:
						{
						x=860;y=860;
						break;
						}case 4:
						{
						x=580;y=780;
						break;
						}}
					/*	
					//for(int j=0;j<2;j++){
					
					
				//x=x+100;
				//y=y+10;
				int x=400;
			int y=300;	
			*	int x=400;
			int y=300;
			SDL_Rect coin1={x,y,40,40};
			while(x<1200){		//coinTexture.coinrender(400,400);
				//SDL_RenderPresent( gRenderer );
				//SDL_Rect coin1={x,y,40,40};
	SDL_RenderCopy(gRenderer,coinTexture.mTexture,NULL,&coin1);
	x=x+35;
			}	
			*/	//}
			
			
			if(e.key.keysym.sym!=SDLK_UP){keyflag=1;}
			
		//y=a[i];
 	if(keyflag){
 		if(dot.mPosY<500){dot.mPosY=dot.mPosY+17;}
 	}
				SDL_Rect* currentClip = &gSpriteClips[ frame / 4];
				//gSpriteSheetTexture.brender(45,78);
				if(flags){gSpriteSheetTexture.render(dot.mPosX , dot.mPosY, currentClip );
				coinTexture.coinrender(x,y);
				timeTexta.str("");
	timeTexta<<s<<"  is now playing...";
	
	gTimeTextTexturea.loadFromRenderedText(timeTexta.str().c_str(),textColor);
	
				gTimeTextTexturea.scorerender( 325, 9 );
	
				if(c>=2) stoneTexture.stonerender(sx,sy);
			
				SDL_Rect* fcurrentClip=&fgSpriteClips[frame/4];
				fgSpriteSheetTexture.frender(x1 , y1, fcurrentClip );
				
				SDL_Rect* eaglecurrentClip=&eagleSpriteClips[frame/4];
				if(c>=4)eagleSpriteSheetTexture.efrender(eaglex , eagley, eaglecurrentClip );

				
				
				
				//sunTexture.sunrender(600,50);
				score1Texture.score1render(10,10);
				SDL_Rect* hfcurrentClip=&hgSpriteClips[frame/4];
				if(c>=5){hgSpriteSheetTexture.cowrender(hunterx , huntery, hfcurrentClip );}
				if(c2>=3){
				lifeTexture.liferender(10,59);
				lifeTexture.liferender(65,59);
				lifeTexture.liferender(110,59);
				
				}
				if(c2==2){
				lifeTexture.liferender(10,59);
				lifeTexture.liferender(65,59);
				//lifeTexture.liferender(300,100);
				
				}
				if(c2==1){
				lifeTexture.liferender(10,59);
				//lifeTexture.liferender(250,100);
				//lifeTexture.liferender(300,100);
				
				}
				
				
				
				gTimeTextTexture.scorerender( 130, 0 );
				
				//ncrushTexture.ncrushrender(x1,y1);
				if(c>=1){
					//hunterTexture.hunterrender(hunterx,huntery);
				}
				
				
//dot.render();}
//dot.render();
//dot.render();			crushTexture.crushrender(dot.mPosX,dot.mPosY);	
//dot.render();
//gSpriteSheetTexture.brender(45,78);

				++frame;
				
				//i++;
				//if(i>7){i=0;}
				
	//	hangTexture.hangrender(500,500);		
				
		eaglex=eaglex-1*c;
		if(eaglex<1) eaglex=1260;		
	hunterx=hunterx+1*c;	
if(c>8){c=8;}
	if(hunterx>1800){
	hunterx=0;
	//huntery=a[i];
	//if(i>33){i=0;}
	//i++;
	}
	sx=sx-2*c;
	//if(sx<=600) sy=sy-10;
	if(sx>=1800||sx<=0){sx=1280;}			
	x=x-2*c;
	y1=y1+3*c;
	if(x<0 ){
	x=SCREEN_WIDTH;
	y=a[i];
	if(i>33){i=0;}
	i++;
	}
	if(y1>760){
	y1=0;
	x1=firea[fi1];
	fi1++;
		if(fi1>28){fi1=0;}
	}
	
	if(correctflag){
	//this is for carrot collisions
	if((dot.mPosX+90)>=x&&(dot.mPosX+90)<=(x+90)&&(dot.mPosY+100)>=y&&(dot.mPosY+100)<=(y+90)){
	//crushTexture.crushrender(dot.mPosX,dot.mPosY);
	//SDL_Delay(2000);
	Mix_PlayChannel( -1, f, 0 );
	point++;
	c=point;
	cb++;
	x=1550;
	//x=SCREEN_WIDTH;
	y=a[i];
	if(i>33){i=0;}
	i++;
	}
	if(c>=2){
	//this is for stone collisions
	if((dot.mPosX+90)>=sx&&(dot.mPosX+90)<=(sx+90)&&(dot.mPosY+200)>=sy&&(dot.mPosY+200)<=(sy+90)){
		
		Mix_PlayChannel( -1, sg, 0 );
		
		c1++;
		sx=1800;
		
	}}
	//this is for hunter collisions
	if(c>=5){
	if((hunterx+300)==(dot.mPosX+20)&&(huntery+100)>=dot.mPosY&&(huntery+100)<=(dot.mPosY+298)){
	//crushTexture.crushrender(dot.mPosX,dot.mPosY);
	//SDL_Delay(2000);
	Mix_PlayChannel( -1, d, 0 );
	c1++;


	hunterx=1300;

	if(hunterx>1800){
	hunterx=0;}
	//dot.mPosX=1550;
	//x=SCREEN_WIDTH;
	//huntery=a[i];
	//i/f(i>33){i=0;}
	//i++;
	}}
//x1 is for fire
//this is for fire collisions
	if((dot.mPosX+30)>=x1&&(dot.mPosX+30)<=(x1+80)&&(dot.mPosY+50)>=y1&&(dot.mPosY+50)<=(y1+70)){
	//crushTexture.crushrender(dot.mPosX,dot.mPosY);
	//SDL_Delay(2000);
	Mix_PlayChannel( -1, d, 0 );
	//Mix_PlayChannel( -1, g, 0 );
	c1++;
	y1=800;
	//x=SCREEN_WIDTH;
	x1=firea[fi1];
	if(fi1>28){fi1=0;}
	fi1++;
}
//this is for eagle collisions
if(c>=3){
if((dot.mPosX+90)>=eaglex&&(dot.mPosX)<=(eaglex)&&(dot.mPosY+100)>=(eagley)&&(dot.mPosY)<=(eagley-10)){
	//crushTexture.crushrender(dot.mPosX,dot.mPosY);
	//SDL_Delay(2000);
hangflag=1;
c1++;
	Mix_PlayChannel( -1, eg, 0 );

		//hangTexture.hangrender(hsx,hsy);
	//x=SCREEN_WIDTH;eaglex=1800;

		//hangTexture.hangrender(hsx,hsy);
		
}}
		if(hangflag){
	//Mix_PlayChannel( -1, d, 0 );
	//Mix_PlayChannel( -1, g, 0 );
	//c1++;
	if(dot.mPosX!=1300){ hsx=dot.mPosX;
	hsy=dot.mPosY;}

	hsy=hsy-3;
	hsx=hsy;
		eaglex=1800;
	dot.mPosX=1300;
	hangTexture.hangrender(hsx,hsy);
	if(hsy<1){ dot.mPosX=600;
	dot.mPosY=500;
	hangflag=0;}
	
}
	//this portion is for adding soung 
	//if(hangflag) {//Mix_HaltMusic();
//	Mix_PlayChannel( -1, g, 0 );}
	
	}
	
	}
int song;


	result=point-c1;
				if(!hangflag)c2=5-c1;
				
				
			if(flags){
			
			
				if(c2<=0){
			
				Mix_HaltMusic();
			if(dot.mPosX!=1600)	{Mix_PlayChannel( -1, g, 0 );}
						Mix_HaltMusic();
						dot.mPosX=1600;
						correctflag=0;	
						//hangflag=0;
				song=0;	meritTexture.sunrender(0,0);
								timeText.str("");
	timeText<<point;
	
	gTimeTextTexture.loadFromRenderedText(timeText.str().c_str(),textColor);
		gTimeTextTexture.scorerender( 607, 369 );
		timeTexta.str("");
	timeTexta<<s<<"'s     bunny's ";
	
	gTimeTextTexturea.loadFromRenderedText(timeTexta.str().c_str(),textColor);
	
				gTimeTextTexturea.scorerender( 325, 280 );
	if(mousex>=663&&mousex<=1220&&mousey>=670&&mousey<=740){ctpTexture.ctprender(740,620);}
		
		if(buttons&SDL_BUTTON(SDL_BUTTON_LEFT)){
							if(mousex>=663&&mousex<=1220&&mousey>=670&&mousey<=740){
							
							
							//SDL_RenderPresent( gRenderer );
							//gRenderer=0;
				//dot.mPosX=1800;	
				SDL_RenderPresent( gRenderer );
					//close();	
		break;
					}}
		
					
				}}


SDL_RenderPresent( gRenderer );
				if( frame / 4 >= WALKING_ANIMATION_FRAMES )
				{
					frame = 0;
				}
				
				
			}
		}
	}
}
	close();
	
	
	
	
	
	
	
	
	
	
	
	//LETS PLAY IT.....
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
//printf("result is %d",c9);
	return 0;
}
