#include<iostream>
#include<stdlib.h>
#include <windows.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include "glut.h"

//create 3x3 two dimensional array for the tic tac toe board
int tictac[3][3];

/*
changeplayer alternates between the two players.
1 = 1st player's turn
2 = 2nd Player's turn
*/
int changeplayer;

/*
winner variable assigns number for who wins.
0 = Nobody wins.
1 = 1st player wins.
2 = 2nd player wins. 
*/
int winner; 
bool gameover; //gameover if it is 0 then its not game over else if it is 1 then its game over
int color =0;
int color2=0;
int counter = 1; 

char colorchoice1;
char colorchoice2;

//initialize the game
void initgame()
{
	//Player 1 goes first 
	changeplayer = 1;

	//clear tic tac toe board
	for(int i = 0; i <= 2; i++)
	{
		for(int j = 0; j <= 2; j++)
		{
			tictac[i][j] = 0;
		}
	}

}

//Responds to keyboard presses
void KeyPress(unsigned char key, int x, int y ){
	switch(key){
	case 'y':
		if(gameover == true)
		{
			gameover = false;
			initgame();
		}
		break;
	case 'n':
		if(gameover == true)
			exit(0);
		break;
		//one
	case 'b':
		colorchoice1='b';
		break;
	case 'r':
		colorchoice1 = 'r';
		break;
	case 'p':
		colorchoice2='p';
		break;
	case 'g':
		colorchoice2='g';
		break;
		//one
	case '1':
		if(tictac[2][0] == 0&&gameover==false){
			if(changeplayer == 1){
				tictac[2][0] = 1;
				changeplayer = 2;
			}else{
				tictac[2][0] = 2;
				changeplayer = 1;
			}
		}
		break;

		//two
	case '2':
		if(tictac[2][1] == 0&&gameover==false){
			if(changeplayer == 1){
				tictac[2][1] = 1;
				changeplayer = 2;
			}else{
				tictac[2][1] = 2;
				changeplayer = 1;
			}
		}
		break;

		//user presses three
	case '3':
		if(tictac[2][2] == 0&&gameover==false){
			if(changeplayer == 1){
				tictac[2][2] = 1;
				changeplayer = 2;
			}else{
				tictac[2][2] = 2;
				changeplayer = 1;
			}
		}
		break;

		//four
	case '4':
		if(tictac[1][0] == 0&&gameover==false){
			if(changeplayer == 1){
				tictac[1][0] = 1;
				changeplayer = 2;
			}else{
				tictac[1][0] = 2;
				changeplayer = 1;
			}
		}
		break;

		//five
	case '5':
		if(tictac[1][1] == 0&&gameover==false){
			if(changeplayer == 1){
				tictac[1][1] = 1;
				changeplayer = 2;
			}else{
				tictac[1][1] = 2;
				changeplayer = 1;
			}
		}
		break;

		//six
	case '6':
		if(tictac[1][2] == 0&&gameover==false){
			if(changeplayer == 1){
				tictac[1][2] = 1;
				changeplayer = 2;
			}else{
				tictac[1][2] = 2;
				changeplayer = 1;
			}
		}
		break;

		//seven
	case '7':
		if(tictac[0][0] == 0&&gameover==false){
			if(changeplayer == 1){
				tictac[0][0] = 1;
				changeplayer = 2;
			}else{
				tictac[0][0] = 2;
				changeplayer = 1;
			}}
		break;

		//eight
	case '8':
		if(tictac[0][1] == 0 &&gameover==false){
			if(changeplayer == 1){
				tictac[0][1] = 1;
				changeplayer = 2;
			}else{
				tictac[0][1] = 2;
				changeplayer = 1;
			}
		}
		break;

		//nine
	case '9':
		if(tictac[0][2] == 0&&gameover==false){
			if(changeplayer == 1){
				tictac[0][2] = 1;
				changeplayer = 2;
			}else{
				tictac[0][2] = 2;
				changeplayer = 1;
			}
		}
		break;
		exit(0);

	} 
}


//Used to write text in the opengl window
void drawString (void * font, char *s, float x, float y){
	unsigned int i;
	glRasterPos2f(x, y);
	for (i = 0; i < strlen (s); i++)
		glutBitmapCharacter (font, s[i]);
}



//Draw tic tac toe board
void setupboard()
{
	
	

	//create the board
	
	
	glBegin(GL_LINES);
	glVertex2f(200, 100);
	glVertex2f(200 , 680);
	glVertex2f(400, 680);
	glVertex2f(400 , 100);
	glVertex2f(0, 300);
	glVertex2f(600, 300);
	glVertex2f(0, 500);
	glVertex2f(600, 500);
	glEnd();
	



}


//This Function Draw the x and o's
void drawxo()
{
	
	for(int i = 0; i <= 2; i++)
	{
		for(int j = 0; j <= 2; j++)
		{
			if(tictac[i][j] == 1) //if it is 1 then draw x 
			{

				if(colorchoice1 == 'b'){
					glColor3f(0.0f, 0.0f, 1.0f);
				}
				else if (colorchoice1 == 'r'){
					glColor3f(1.0f, 0.0f, 0.0f);
				}else{
					glColor3f(1.0f, 1.0f, 1.0f);
				}

				glBegin(GL_LINES);

				glVertex2f((50 + j * 100 - 25)*2, (100 + i * 100 - 25)*2);
				glVertex2f((50 + j * 100 + 25)*2, (100 + i * 100 + 25)*2);
				glVertex2f((50 + j * 100 - 25)*2, (100 + i * 100 + 25)*2);
				glVertex2f((50 + j * 100 + 25)*2, (100 + i * 100 - 25)*2);
				glEnd();
			}
			else if(tictac[i][j] == 2) //if it is 2 then draw o
			{
				if(colorchoice2 == 'p'){
					glColor3f(1.0f, 0.0f, 1.0f);
				}
				else if (colorchoice2 == 'g'){
					glColor3f(0.0f,1.0f,0.0f);
				}else{
					glColor3f(1.0f, 1.0f, 1.0f);
				}
				glBegin(GL_LINE_LOOP);

				glVertex2f((50 + j * 100 - 25)*2, (100 + i * 100 - 25)*2);
				glVertex2f((50 + j * 100 - 25)*2, (100 + i * 100 + 25)*2);
				glVertex2f((50 + j * 100 + 25)*2, (100 + i * 100 + 25)*2);
				glVertex2f((50 + j * 100 + 25)*2, (100 + i * 100 - 25)*2);
				glEnd();
			}
			
			
		
		}
	}
}


//This function checks if there is any winner
bool checkifwin()
{
	
	for (int i=0; i<=2; i++)
 {
  if(tictac[i][0]==tictac[i][1] && tictac[i][1]==tictac[i][2] && tictac[i][0]!=0)
  {
  
    return true;
  }
  else {
	  
  }
 }

 // any of the columns is same
 for(int i=0; i<=2; i++)
 {
  if (tictac[0][i]==tictac[1][i] && tictac[1][i]==tictac[2][i] && tictac[0][i]!=0)
  {
    return true;
  }
  else {
	  
  }
 }

 // 1st diagonal is same
 if(tictac[0][0]==tictac[1][1] && tictac[1][1]==tictac[2][2] && tictac[0][0]!=0)
 {

  return true;
 }
 

 // 2nd diagonal is same
 if(tictac[0][2]==tictac[1][1] && tictac[1][1]==tictac[2][0] && tictac [0][2]!=0)
 {
  
  return true;
 }

return false;

}


//Checks if match is a draw
bool checkifdraw()
{
	int i, j;
	bool draw;

	for(i = 0; i <= 2; i++)
	{ 
		for(j = 0; j <= 2; j++)
		{ 
			if(tictac[i][j] == 0)
				return false;
		}
	}
	return true;	
}

//This is the idle call back function
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0,0,0,0);
	glColor3f(1, 1, 1);

	
		
		
		
	
	

	drawString(GLUT_BITMAP_HELVETICA_18, "Player 1 B = Blue, R = Red Player2 G=Green, P=Purple", 80, 80);	
	if(changeplayer == 1)
		drawString(GLUT_BITMAP_HELVETICA_18, "Player1 Turn", 250, 60);	
	else
		drawString(GLUT_BITMAP_HELVETICA_18, "Player2 Turn", 250, 60);	


	//setting up the tic tac toe board and drawing the x and square
	setupboard();
	drawxo();


	if(checkifwin() == true)
	{
		//the player who made the previous move is the winner
		if(changeplayer == 1)
		{
			gameover = true;
			winner = 2; //player2 wins
		}
		else
		{
			gameover = true;
			winner = 1; //player1 wins
		}
	}
	else if(checkifdraw() == true)
	{
		gameover = true;
		winner = 0; //it's a draw
	}


	if(gameover == true)
	{
		

		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 240, 320);

		if(winner == 0){
			drawString(GLUT_BITMAP_HELVETICA_18, "Its a draw", 240, 370);
			drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to continue? y=yes or n=no", 140, 390);
			
			//initgame();
		}
		if(winner == 1){
			//Grid animation
			
			//Color strobe
			
			for(int i = 0; i < 60; i++){
				glClear(GL_COLOR_BUFFER_BIT);
				glClearColor(0,0,0,0);
				glBegin(GL_LINES);

				if (counter ==1) {
					glColor3f(1,1,0);
				}
				else if (counter == 2){
					glColor3f(1,0 ,0);
				}
				else if (counter == 3){
					glColor3f(0,1,0);
				}
				else if (counter == 4){
					glColor3f(0, 0, 1);
					counter = 0;
				}else{
					glColor3f(1,1,1);
				}
				
                
				//'
				glVertex2f((0 + i * 5), (175)*2);
				glVertex2f((0 + i * 5), (185)*2);
				//X
                glVertex2f((10 + i * 5), (175)*2);
                glVertex2f((50 + i * 5), (225)*2);
                glVertex2f((50 + i * 5), (175)*2);
                glVertex2f((10 + i * 5), (225)*2);
		
				//'
				glVertex2f((60 + i * 5), (175)*2);
				glVertex2f((60 + i * 5), (185)*2);
				//W
				glVertex2f((60+15 + i * 5), (175)*2);
				glVertex2f((60+15 + i * 5), (225)*2);
               

 				glVertex2f((60+15 + i * 5), (225)*2);
                glVertex2f((85+15 + i * 5), (200)*2);

 				glVertex2f((85+15 + i * 5), (200)*2);
                glVertex2f((110+15 + i * 5), (225)*2);

				glVertex2f((110+15 + i * 5), (225)*2);
				glVertex2f((110+15 + i * 5), (175)*2);

				//I
				glVertex2f((120+15 + i * 5), (225)*2);
				glVertex2f((120+15 + i * 5), (175)*2);

				//N
				glVertex2f((130+15 + i * 5), (225)*2);
                glVertex2f((130+15 + i * 5), (175)*2);

				glVertex2f((130+15 + i * 5), (175)*2);
				glVertex2f((180+15 + i * 5), (225)*2);

                glVertex2f((180+15 + i * 5), (225)*2);
                glVertex2f((180+15 + i * 5), (175)*2);

				//S
				glVertex2f((240+15 + i * 5), (175)*2);
                glVertex2f((190+15 + i * 5), (175)*2);

				glVertex2f((190+15 + i * 5), (175)*2);
				glVertex2f((240+15 + i * 5), (225)*2);

                glVertex2f((240+15 + i * 5), (225)*2);
                glVertex2f((190+15 + i * 5), (225)*2);
				glEnd();
				Sleep(100);
				glutSwapBuffers();
				if(i == 59){
					
					gameover = false;
					initgame();
				}
				counter++;
			}
			
			
		}
		//Player 2 Wins
		if(winner == 2){

				
			//animation
			for(int i = 0; i < 60; i++){
				glClear(GL_COLOR_BUFFER_BIT);
				glClearColor(0,0,0,0);
				glBegin(GL_LINES);

				//colors
				if (counter ==1) {
					glColor3f(1,1,0);
				}
				else if (counter == 2){
					glColor3f(1,0 ,0);
				}
				else if (counter == 3){
					glColor3f(0,1,0);
				}
				else if (counter == 4){
					glColor3f(0, 0, 1);
					counter = 0;
				}else{
					glColor3f(1,1,1);
				}
				
				//'
				glVertex2f((0 + i * 5), (175)*2);
				glVertex2f((0 + i * 5), (185)*2);

				//Square
				glVertex2f((5 + i * 5), (175)*2);
                glVertex2f((5 + i * 5), (225)*2);

                glVertex2f((5 + i * 5), (225)*2);
                glVertex2f((55 + i * 5), (225)*2);

				glVertex2f((55 + i * 5), (225)*2);
                glVertex2f((55 + i * 5), (175)*2);

				glVertex2f((55 + i * 5), (175)*2);
                glVertex2f((5 + i * 5), (175)*2);
		
				//'
				glVertex2f((60 + i * 5), (175)*2);
				glVertex2f((60 + i * 5), (185)*2);
				//W
				glVertex2f((60+15 + i * 5), (175)*2);
				glVertex2f((60+15 + i * 5), (225)*2);
               

 				glVertex2f((60+15 + i * 5), (225)*2);
                glVertex2f((85+15 + i * 5), (200)*2);

 				glVertex2f((85+15 + i * 5), (200)*2);
                glVertex2f((110+15 + i * 5), (225)*2);

				glVertex2f((110+15 + i * 5), (225)*2);
				glVertex2f((110+15 + i * 5), (175)*2);

				//I
				glVertex2f((120+15 + i * 5), (225)*2);
				glVertex2f((120+15 + i * 5), (175)*2);

				//N
				glVertex2f((130+15 + i * 5), (225)*2);
                glVertex2f((130+15 + i * 5), (175)*2);

				glVertex2f((130+15 + i * 5), (175)*2);
				glVertex2f((180+15 + i * 5), (225)*2);

                glVertex2f((180+15 + i * 5), (225)*2);
                glVertex2f((180+15 + i * 5), (175)*2);

				//S
				glVertex2f((240+15 + i * 5), (175)*2);
                glVertex2f((190+15 + i * 5), (175)*2);

				glVertex2f((190+15 + i * 5), (175)*2);
				glVertex2f((240+15 + i * 5), (225)*2);

                glVertex2f((240+15 + i * 5), (225)*2);
                glVertex2f((190+15 + i * 5), (225)*2);
				
				glEnd();
				
				glutSwapBuffers();
				Sleep(100);
				if(i == 59){
					
					gameover = false;
					initgame();
				}
				
				counter++;
			}
			
		}
	
	}
	
	glutSwapBuffers();
}

//This function is called on windows resize
void reshape(int x, int y)
{
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, x, y, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
}



//main function of the program
int main(int argc, char **argv)
{
	initgame();
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(600,700);
	glutCreateWindow("Tic Tac Toe");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(KeyPress);
	glutIdleFunc(display);
	glutMainLoop();
	return 0;
}
