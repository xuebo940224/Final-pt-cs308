#include <stdio.h>
#include <gb/gb.h>
#include <string.h>
#include "alpha.c"
#include "helloWorld.c"
#include "blankScreen.c"
#include "sprites.c"
#include "lineMap.c"
#include "X.c"
#include "O.c"
#include "bigX.c"
#include "bigO.c"
#include "welcome.c"



UINT8 GAME_BOARD[9];
void init();
void init2();
void checkInput();
void updateSwitches();
void checkPositionO();
void checkPosition();

// The player array will hold the player's position as X ([0]) and Y ([1])
UINT8 player[2];
UINT8 round[1];
UINT8 count[9];
UINT8 str[] = "X Win";
UINT8 str1[] = "O Win";
UINT8 str2[] = "No One Win";

enum chess
	{
	aa,
	bb,
	cc=10,
	dd,
	ee,
	ff,
	gg,
	hh,
	ii,
	jj,
	kk
	};



void main() {

	init();
	
	
	
	while(1) {
		
		checkInput();				// Check for user input (and act on it)
		updateSwitches();			// Make sure the SHOW_SPRITES and SHOW_BKG switches are on each loop
		wait_vbl_done();			// Wait until VBLANK to avoid corrupting memory
	}
	
}

void init() {
	
	DISPLAY_ON;						// Turn on the display
		
	set_bkg_data(0, 64, alpha);		// Load 47 tiles into background memory
	
	set_bkg_tiles(0,0,20,18,welcome);
		
		
		
	round[0] = 0;
	count[0] = kk;
	count[1] = cc;
	count[2] = dd;
	count[3] = ee;
	count[4] = ff;
	count[5] = gg;
	count[6] = hh;
	count[7] = ii;
	count[8] = jj;
	
	
	
	
	
}



void updateSwitches() {
	
	HIDE_WIN;
	SHOW_SPRITES;
	SHOW_BKG;
	
}

void checkInput() {

    if (joypad() & J_B) {
		
		if(round[0]==0)
		{
			set_bkg_tiles(0,0,20,18,lineMap);
			set_sprite_data(0, 1, X);
			set_sprite_tile(0,0);
			player[0] = 80;
			player[1] = 72;
			
		}
		
		
		checkPosition();
        delay(400);
    }
	
	// UP
	if (joypad() & J_UP) {
			
		player[1]--;
		
	}

	// DOWN
	if (joypad() & J_DOWN) {
			
		player[1]++;
		
	}

	// LEFT
	if (joypad() & J_LEFT) {
		
		player[0]--;
		
	}	
	
	// RIGHT
	if (joypad() & J_RIGHT) {
		
		player[0]++;
		
	}
	
	// Move the sprite in the first movable sprite list (0)
	//  the the position of X (player[0]) and y (player[1])
	move_sprite(0, player[0], player[1]);

}

void checkPosition() {

	
	if(player[0]<56 && player[1]<66)
		{
			if(count[0]!=0 && count[0]!=1)
				{
					if(round[0]==1 ||round[0]==3 ||round[0]==5 ||round[0]==7 ||round[0]==9)
					{
					set_bkg_tiles(1,2,4,4,bigX);
					count[0] = aa;
					}
					else if(round[0]==2 ||round[0]==4 ||round[0]==6 ||round[0]==8)
					{
					set_bkg_tiles(1,1,4,5,bigO);
					count[0] = bb;
					}
				}
			else
			{
				round[0]--;
			}
		}
	else if(player[0]>56 && player[0]<113 && player[1]<66)
		{
			if(count[1]!=0 && count[1]!=1)
				{
					if(round[0]==1 ||round[0]==3 ||round[0]==5 ||round[0]==7 ||round[0]==9)
					{
					set_bkg_tiles(8,2,4,4,bigX);
					count[1] = aa;
					}
					else if(round[0]==2 ||round[0]==4 ||round[0]==6 ||round[0]==8)
					{
					set_bkg_tiles(8,1,4,5,bigO);
					count[1] = bb;
					}
				}
				else
				{
					round[0]--;
				}
        
		}
	else if(player[0]>113 && player[1]<66)
		{
			if(count[2]!=0 && count[2]!=1)
				{
					if(round[0]==1 ||round[0]==3 ||round[0]==5 ||round[0]==7 ||round[0]==9)
					{
					set_bkg_tiles(15,2,4,4,bigX);
					count[2] = aa;
					}
					else if(round[0]==2 ||round[0]==4 ||round[0]==6 ||round[0]==8)
					{
					set_bkg_tiles(15,1,4,5,bigO);
					count[2] = bb;
					}
				}
			else
			{
				round[0]--;
			}
        
		}
	else if(player[0]<56 && player[1]>66 && player[1]<114)
		{
			if(count[3]!=0 && count[3]!=1)
				{
					if(round[0]==1 ||round[0]==3 ||round[0]==5 ||round[0]==7 ||round[0]==9)
					{
					set_bkg_tiles(1,7,4,4,bigX);
					count[3] = aa;
					}
					else if(round[0]==2 ||round[0]==4 ||round[0]==6 ||round[0]==8)
					{
					set_bkg_tiles(1,7,4,5,bigO);
					count[3] = bb;
					}
				}
			else
			{
				round[0]--;
			}
		}
	else if(player[0]>56 && player[0]<113 && player[1]>66 && player[1]<114)
		{
			if(count[4]!=0 && count[4]!=1)
				{
					if(round[0]==1 ||round[0]==3 ||round[0]==5 ||round[0]==7 ||round[0]==9)
					{
					set_bkg_tiles(8,7,4,4,bigX);
					count[4] = aa;
					}
					else if(round[0]==2 ||round[0]==4 ||round[0]==6 ||round[0]==8)
					{
					set_bkg_tiles(8,7,4,5,bigO);
					count[4] = bb;
					}
				}
			else
			{
				round[0]--;
			}
		}
	else if(player[0]>113 && player[1]>66 && player[1]<114)
		{
			if(count[5]!=0 && count[5]!=1)
				{
					if(round[0]==1 ||round[0]==3 ||round[0]==5 ||round[0]==7 ||round[0]==9)
					{
					set_bkg_tiles(15,7,4,4,bigX);
					count[5] = aa;
					}
					else if(round[0]==2 ||round[0]==4 ||round[0]==6 ||round[0]==8)
					{
					set_bkg_tiles(15,7,4,5,bigO);
					count[5] = bb;
					}
				}
			else
			{
				round[0]--;
			}     
		}
	else if(player[0]<56 && player[1]>114)
		{
			if(count[6]!=0 && count[6]!=1)
				{
					if(round[0]==1 ||round[0]==3 ||round[0]==5 ||round[0]==7 ||round[0]==9)
					{
					set_bkg_tiles(1,13,4,4,bigX);
					count[6] = aa;
					}
					else if(round[0]==2 ||round[0]==4 ||round[0]==6 ||round[0]==8)
					{
					set_bkg_tiles(1,13,4,5,bigO);
					count[6] = bb;
					}
				}
			else
			{
				round[0]--;
			}
        
		}
	else if(player[0]>56 && player[0]<113 && player[1]>114)
		{
			if(count[7]!=0 && count[7]!=1)
				{
					if(round[0]==1 ||round[0]==3 ||round[0]==5 ||round[0]==7 ||round[0]==9)
					{
					set_bkg_tiles(8,13,4,4,bigX);
					count[7] = aa;
					}
					else if(round[0]==2 ||round[0]==4 ||round[0]==6 ||round[0]==8)
					{
					set_bkg_tiles(8,13,4,5,bigO);
					count[7] = bb;
					}
				}
			else
			{
				round[0]--;
			}
        
		}
	else if(player[0]>113 && player[1]>114)
		{
			if(count[8]!=0 && count[8]!=1)
				{
					if(round[0]==1 ||round[0]==3 ||round[0]==5 ||round[0]==7 ||round[0]==9)
					{
					set_bkg_tiles(15,13,4,4,bigX);
					count[8] = aa;
					}
					else if(round[0]==2 ||round[0]==4 ||round[0]==6 ||round[0]==8)
					{
					set_bkg_tiles(15,13,4,5,bigO);
					count[8] = bb;
					}
				}
			else
			{
				round[0]--;
			}
        
		}
		
	if(round[0]==1 ||round[0]==3 ||round[0]==5 ||round[0]==7 ||round[0]==9)
		{
			set_sprite_data(0, 1, O);
		}
		else if(round[0]==2 ||round[0]==4 ||round[0]==6 ||round[0]==8)
		{
				set_sprite_data(0, 1, X);
		}
		
		
	round[0] = round[0]+1;
		
		
	if(
		   (count[0]==count[1] && count[1]==count[2] && count[0] == aa) ||
		   (count[3]==count[4] && count[4]==count[5] && count[3] == aa) ||
		   (count[6]==count[7] && count[7]==count[8] && count[6] == aa) ||
		   (count[0]==count[4] && count[4]==count[8] && count[0] == aa) ||
		   (count[2]==count[4] && count[4]==count[6] && count[2] == aa) ||
		   (count[0]==count[3] && count[3]==count[6] && count[0] == aa) ||
		   (count[1]==count[4] && count[4]==count[7] && count[1] == aa) ||
		   (count[2]==count[5] && count[5]==count[8] && count[2] == aa)
		  )
		  {
			 set_bkg_tiles(0,0,20,18,blankScreen);
			 printf("     %s\n",str);
			 delay(3000);
			 init();
		  }
	else if(
		   (count[0]==count[1] && count[1]==count[2] && count[0] == bb) ||
		   (count[3]==count[4] && count[4]==count[5] && count[3] == bb) ||
		   (count[6]==count[7] && count[7]==count[8] && count[6] == bb) ||
		   (count[0]==count[4] && count[4]==count[8] && count[0] == bb) ||
		   (count[2]==count[4] && count[4]==count[6] && count[2] == bb) ||
		   (count[0]==count[3] && count[3]==count[6] && count[0] == bb) ||
		   (count[1]==count[4] && count[4]==count[7] && count[1] == bb) ||
		   (count[2]==count[5] && count[5]==count[8] && count[2] == bb)
		  )
		  {
			 set_bkg_tiles(0,0,20,18,blankScreen);
			 printf("     %s\n",str1);
			 delay(3000);
			init();
		  }
	else if(round[0]==9)
		  {
			 printf("     %s\n",str2);
			 delay(3000);
			 init(); 
		  }
		  
	
}
		
	
	

	