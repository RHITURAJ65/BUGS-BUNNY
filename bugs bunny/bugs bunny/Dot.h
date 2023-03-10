#ifndef DOT_H
#define DOT_H

struct Dot
{
    //public:
		//The dimensions of the dot
		static const int DOT_WIDTH =20;
		static const int DOT_HEIGHT =20;

		//Maximum axis velocity of the dot
		static const int DOT_VEL = 40;

		//Initializes the variables
		Dot();

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e );

		//Moves the dot
		void move();

		//Shows the dot on the screen
		void render();
void cowrender();
    //private:
		//The X and Y offsets of the dot
		int mPosX, mPosY;

		//The velocity of the dot
		int mVelX, mVelY;
};

#endif
