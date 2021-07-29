#include<GL/glut.h>   // Header file for Graphics Library.
#include<math.h>      // Header file for mathematical functions like Square Root and power function.
#include<stdbool.h>   // Header file for Boolean data types.
#include<stdio.h>     // Standard Header file for IO.

#define PI 3.14159265f  // defining PI value

// GLfloat is used as data type here as it defines a set size that does not change per system.
GLfloat ballRadius = 0.2, xradius = 0.2, xxradius = 1.0, xxxradius = 0.5;
GLfloat ballX = 0.0f;
GLfloat ballY = 0.0f;
GLfloat ballXMax, ballXMin, ballYMax, ballYMin; // max and min values for ball speed.
GLfloat xSpeed = 0.02f;
GLfloat ySpeed = 0.007f;
int refreshMills = 30;
int refreshend = 60000;
GLfloat angle = 0.0;
int xa, ya;
int flag = 0, flag1 = 0, flag2 = 0, flagl = 0, flagd = 0; // flag declarations.
int score = 0, score1 = 0, score2 = 0, endTimer, timer, i;
void* currentfont;
GLfloat  x, y;
GLdouble clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;


// Function declarations.
void balldisp();
void scoredisp();
void end();

// Function to display strings on the screen.
void drawstring(float x, float y, float z, char* string)
{
	char* c; // string to be displayed on the screen.
	// glRosterPos3f: Specifies the raster position for pixel operations.
	glRasterPos3f(x, y, z); // position where the string should be displayed(x,y,z).
	// for loop for displaying the string until '\0' is encountered.
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c); 
		// renders bitmap character, parameters - font,character.
	}
}

// The function to display the front screen.
void frontscreen(void)
{
	glClear(GL_COLOR_BUFFER_BIT); // clears buffers to pre-set values.
	// GL_COLOR_BUFFER_BIT: It is used to indicate the buffers that are currently enabled for colour writing.
	glBegin(GL_TRIANGLE_FAN); // starts collection of vertices for a new primitive mode.
	// GL_TRIANGLE_FAN: draws a connected group of triangles.
	glColor3f(1.0, 1.0, 0.0); // color of the changing background
	// Here, we have used GL_TRIANGLE_FAN to draw circles.
	for (angle = 0; angle < 360; angle += 1)
	{
		y = (cos(angle * PI / 180) * xradius); // the y position of the center point of the circle.  
		x = (sin(angle * PI / 180) * xradius); // the x position of the center point of the circle.
		glVertex2f(x, y); // specifies the (x,y) coordinates.
		// center of the circle.
	}
	glEnd(); // Terminating the list of vertices.
	xradius = xradius + 0.005;
	//glColor3f(1.0, 1.0, 0.0);
	//glBegin(GL_TRIANGLE_FAN);
	//for (angle = 0; angle < 360.0; angle += 1)
	//{
	//	y = (sin(angle * PI / 180) * xxradius);
	//	x = (cos(angle * PI / 180) * xxradius);
	//	glVertex2f(x, y);
	//}

	//glEnd();
	//xxradius = xxradius - 0.005;

	glColor3f(0.0, 0.0, 0.0); // color for the below string.
	drawstring(-0.42, 0.9, 0.0, "CGV MINI PROJECT"); // string to be displayed.
	glColor3f(1.0, 0.0, 0.0);
	drawstring(-0.3, 0.6, 0.0, "USING OPENGL");
	glColor3f(0.5, 0.0, 1.0);
	drawstring(-0.4, 0.4, 0.0, "BOUNCE BALL GAME");
	glColor3f(0.0, 0.0, 0.0);
	drawstring(-0.9, -0.0, 0.0, "BY:");
	glColor3f(0.0, 0.0, 0.0);
	drawstring(-0.9, -0.1, 0.0, "Rashmi Pai (2KE18CS032)");
	drawstring(-0.9, -0.2, 0.0, "Rohit Guru (2KE18CS033)");
	drawstring(-0.9, -0.3, 0.0, "Pradeep Natekal (2KE18CS027)");
	drawstring(-0.9, -0.4, 0.0, "Summaiya Dharwad(2KE18CS048)");
	drawstring(0.45, -0.0, 0.0, "GUIDE : ");
	drawstring(0.25, -0.15, 0.0, "Prof. Shridhar Allagi");
	glColor3f(0.0, 0.0, 1.5);
	drawstring(-0.4, -0.7, 0.0, "Press i for Instructions");
	//glColor3ub(rand() % 250, rand() % 250, rand() % 200);
	drawstring(-0.4, -0.9, 0.0, "Press ENTER to Start");
	drawstring(-0.5, -0.55, 0.0, "Academic Year : 2020-2021");
	glColor3f(0.0, 1.0, 0.4);

	glutSwapBuffers(); // Performs a buffer swap on the layer in use for the current window.
}

// Function to continue to level 2.
void level2()
{
	glClear(GL_COLOR_BUFFER_BIT); // clears buffers to pre-set values.
	drawstring(-0.175, 0.0, 0.0, "LEVEL 2 ");
	drawstring(-0.4, -0.25, 0.0, "Press c to Continue...");
	glutSwapBuffers(); // Performs a buffer swap on the layer in use for the current window.
}

// This function displays the end screen with the final score and scores of the other levels as well as the 
// final screen.
void finalsc()
{
	// initialization and declaration.
	int z, j = 0, k = 0, y, a = 0, b = 0, w, d = 0, e = 0;
	z = score; // final 
	y = score1; // level 2
	w = score2; // level 1
	glColor3f(0.7, 0.4, 1.0); // color of the scores displayed on the final screen.
	glLoadIdentity(); // Replaces the current matrix with the identity matrix.
	// Displaying final score.
	drawstring(-1.0, 1.0, 0.0, "FINAL SCORE : ");
	while (z > 9)
	{
		k = z % 10; 

		glRasterPos2f(-0.20, 1.0); // Raster position for pixel operations.
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 48 + k); // to display final score - level1 + level2.
		z /= 10; 
		glRasterPos2f(-0.25, 1.0); // Raster position for pixel operations.
	}
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 48 + z);
	// Displaying level 1 score.
	drawstring(-1.0, 0.9, 0.0, "LEVEL 1 : ");
	while (w > 9)
	{
		e = w % 10;

		glRasterPos2f(-0.20, 0.9); // Raster position for pixel operations.
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 48 + e); // to display level 1 score.
		w /= 10;
		glRasterPos2f(-0.25, 0.9); // Raster position for pixel operations.
	}
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 48 + w);
	// Displaying level 2 score.
	drawstring(-1.0, 0.8, 0.0, "LEVEL 2 : ");
	while (y > 9)
	{
		b = y % 10;

		glRasterPos2f(-0.20, 0.9); // Raster position for pixel operations.
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 48 + b); // to display level 2 score.
		y /= 10;
		glRasterPos2f(-0.25, 0.8); // Raster position for pixel operations.
	}
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 48 + y);
}

// Function for the end of the game.
void end()
{
	glClear(GL_COLOR_BUFFER_BIT); // clears buffers to pre-set values.
	// GL_COLOR_BUFFER_BIT: It is used to indicate the buffers that are currently enabled for colour writing.
	glClearColor(1.0, 1.0, 0.6, 1.0); // background color - light yellow.
	// parameters - RGB and alpha value.
	glColor3f(1.0, 1.0, 0.0); // seting the background color of emoji.
	glBegin(GL_TRIANGLE_FAN); // starts collection of vertices.
	// GL_TRIANGLE_FAN: draws a connected group of triangles.
	for (angle = 0; angle < 360; angle += 1)
	{
		y = 0.3 + (cos(angle * PI / 180) * xxxradius); // the y position of the center point of the circle.  
		x = (sin(angle * PI / 180) * xxxradius); // the x position of the center point of the circle.  
		glVertex2f(x, y); // specifies the (x,y) coordinates.
		// center of the circle
	}
	glEnd(); // Terminates the list of vertices.
	glColor3f(0.0, 0.0, 0.0); // color for the point and lines.
	glPointSize(15.0); // size of the point.
	glBegin(GL_POINTS); // starts the collection of vertices.
	// each vertex is treated as a point in GL_POINTS.
	glVertex2f(-0.2, 0.5); // first point.
	glVertex2f(0.2, 0.5); // second point.
	glEnd(); // Terminating the list of vertices.
	glLineWidth(10.0); // width of the line.
	glBegin(GL_LINES); // starts the collection of the vertices.
	// Each pair of vertices is considered as a line segment in GL_LINES.
	glVertex2f(0.0, 0.2); // starting point of the line.
	glVertex2f(0.0, 0.4); // end point of the line.
	glEnd(); // Terminating the list of vertices.
	glBegin(GL_LINES); // starts the collection of the vertices.
	// first line.
	glVertex2f(-0.2, 0.0); // starting point of the line.
	glVertex2f(0.0, 0.1); // end point of the line.
	// second line.
	glVertex2f(0.0, 0.1); // starting point of the line.
	glVertex2f(0.2, 0.0); // end point of the line.
	glEnd(); // Terminating the list of vertices.
	glColor3f(1.0, 0.0, 0.0); // color for the string below.
	drawstring(-0.3, -0.7, 0.0, "GAME OVER");
	finalsc(); // calling function function finalsc() for displaying the scores.
	glutSwapBuffers(); // Performs a buffer swap on the layer in use for the current window.

}

// Function for displaying all the instructions of the game.
void instr()
{
	glClear(GL_COLOR_BUFFER_BIT); // clears buffers to pre-set values.
	//glClear(GL_COLOR_BUFFER_BIT); // clears buffers to pre-set values.
	glClearColor(1.0, 1.0, 0.6, 1.0);
	glColor3f(0.5, 0.0, 1.0); 
	drawstring(-0.25, 0.85, 0.0, "Instructions");
	glColor3f(0.5, 0.0, 1.0);
	drawstring(-0.9, 0.55, 0.0, "1. The Player needs to click on the ball in order");
	drawstring(-0.8, 0.45, 0.0, "to score. ");
	drawstring(-0.9, 0.35, 0.0, "2. Per click score will be incremented by 1. ");
	drawstring(-0.9, 0.25, 0.0, "3. And the speed of the ball will increase ");
	drawstring(-0.9, 0.15, 0.0, "4. To Quit at any stage press q ");
	drawstring(-0.9, 0.05, 0.0, "5. Timer of 10 secs for two levels");
	//glColor3ub(rand() % 250, rand() % 250, rand() % 200);
	glColor3f(0.0, 0.0, 0.0);
	drawstring(-0.6, -0.9, 0.0, "PRESS ENTER TO START");
	glutSwapBuffers(); // Performs a buffer swap on the layer in use for the current window.
}

// Function for displaying the output screens appropriately.
void display()
{
	glClear(GL_COLOR_BUFFER_BIT); // clears buffers to pre-set values.
	glClearColor(1.0, 1.0, 0.6, 1.0); // background color.
	glMatrixMode(GL_MODELVIEW); // sets the current matrix mode.
	// GL_MODELVIEW: Applies subsequent matrix operations to the modelview matrix stack.
	// It defines how the objects are transformed(rotation, translation, scaling).
	glLoadIdentity(); // Replaces the current matrix with the identity matrix.
	balldisp(); // Calls balldisp() function for appropriate ball direction and speed.
	scoredisp(); // Call scoredisp() function for time and scores.

	glutSwapBuffers(); // Performs a buffer swap on the layer in use for the current window.

	// Setting the timer to stop in 10 seconds.
	endTimer += refreshMills;
	timer = endTimer / 1000; // 1000ms

}

// Function for displaying the appropriate window based of the key pressed.
void mydisplay(void)
{
	// displays the frontscreen if flag, flag1 and flagd are 0.
	if (flag == 0 && flag1 == 0 && flagd == 0)
		frontscreen();

	// displays instructions screen if flag1 is set to 1 but flag is still 0.
	if (flag1 == 1 && flag == 0)
		instr();

	// calls the display() function to start the game if flag is set to 1 but flagd is still 0.
	if (flag == 1 && flagd == 0)
	{
		display();

	}

	// if the score is >= to 10 and flag1 is 0 then it calls level2() function and resets the endTimer to 0 and sets
	// the flagd to 1.
	if (score >= 10 && flag1 == 0)
	{
		level2();
		endTimer = 0;
		flagd = 1;
		//level1sc=score;
	}

	// if the time exceeds 10 seconds but the score isnt >= 10 and flag is set to 1 then end() function is called 
	// to display the end screen and flagd is set to 1.
	if (endTimer >= 10000 && flag == 1)
	{

		end();
		flagd = 1;
	}
	// same for level 2.
	else if (endTimer >= 20000 && flag1 == 1)
	{
		end();
		flagd = 1;
	}
}

// Function to detect keyboard interactions.
void mykey(unsigned char key, int x, int y)
{
	switch (key)
	{
	
	// for 'enter' key -- 13 is the ASCII character for 'enter'.
	case 13:  if (flag == 0) // front to game
		flag = 1;
		//flag1=0;
		//ySpeed=ySpeed+0.01;
		break;

	// if 'i' is pressed -- instructions.
	case 'i': if (flag == 0) // front to intsructions
		flag1 = 1;
		break;

	// if 'c' is pressed -- continuing to level 2.
	case 'c':if (flagl == 0) // level 2 continue to level 2
	{
		flag1 = 1;
		flagd = 0;

		//score=0;
		ySpeed = ySpeed + 0.05;
	}

			break;

	// for 'q' or 'Q' -- quit the game.
	case 'q':
	case 'Q': exit(0);
		break;

	}

}

// Function for direction in which the ball should move and the speed changes accordingly.
// define the features of the ball.
void balldisp()
{
	glTranslatef(ballX, ballY, 0.0f); // multiplies the current matrix by a translation matrix.
	// ballX -- x coordinate of the translation matrix.
	// ballY -- y coordinate of the translation matrix.
	// 0.0f -- z coordinate of the translation matrix.
	glBegin(GL_TRIANGLE_FAN); // starts collection of vertices.
	// changing the ball color taking the score into consideration.
	if (score >= 10)
	{
		glColor3f(0, 0, 1); // ball color -- blue.
		//level1sc=score;
	}
	else
	{

		glColor3f(1, 0, 0); // ball color -- red.
	}
	glVertex2f(0.0f, 0.0f); // specifies vertex of the ball intially.
	int numSegments = 100;
	int i;
	for (i = 0; i <= numSegments; i++)
	{
		angle = i * 2.0f * PI / numSegments; // angle at which the ball should move.
		glVertex2f(cos(angle) * ballRadius, sin(angle) * ballRadius); // specifies the vertex of the ball.
	}

	glEnd(); // terminates the list of vertices.

	ballX += xSpeed; 
	ballY += ySpeed;

	// if speed of the ball is max(x coordinate).
	if (ballX > ballXMax)
	{
		xa = ballX;
		ballX = ballXMax;
		xSpeed = -xSpeed;

	}
	// if speed of the ball is min(x coordinate).
	else if (ballX < ballXMin)
	{
		xa = ballX;
		ballX = ballXMin;
		xSpeed = -xSpeed;

	}
	// if speed of the ball is max(y coordinate).
	if (ballY > ballYMax)
	{
		ya = ballY;
		ballY = ballYMax;
		ySpeed = -ySpeed;

	}
	// if speed of the ball is min(y coordinate).
	else if (ballY < ballYMin)
	{
		ya = ballY;
		ballY = ballYMin;
		ySpeed = -ySpeed;

	}


}

// Function for displaying the time and scores of each level.
void scoredisp()
{
	// initialization and declaration.
	int z, j = 0, k = 0, i, s = 0;
	z = score; // final score.
	glColor3f(0.7, 0.4, 1.0); // color in which the scores should be displayed.
	glLoadIdentity(); // Replaces the current matrix with the identity matrix.
	glRasterPos2f(0.28, 1); // Raster position for pixel operations.
	drawstring(0.38, 1, 0.0, "TIME : ");
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 48 + timer); // displaying time at top right corner.
	// displaying the level according to score at the top left corner.
	if (score >= 10)
		drawstring(-0.25, 1, 0, "LEVEL 2"); // if score >= 10 then 'level 2'.
	else
		drawstring(-0.25, 1, 0, "LEVEL 1"); // else 'level 1'.
	drawstring(-1, 1, 0.0, "SCORE : "); // displaying the score at top center.

	// score as the game proceeds.
	while (z > 9)
	{
		k = z % 10;
		glRasterPos2f(-0.58, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 48 + k);
		z /= 10;
		glRasterPos2f(-0.62, 1);
	}
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 48 + z);
}

// Function to check if the mouse click was on the ball.
bool isMouseOverBall(float worldClickX, float worldClickY, float ballX, float ballY)
{
	float distance = sqrt(pow(worldClickX-ballX, 2.0f) + pow(worldClickY-ballY, 2.0f));
	return distance < ballRadius;
}

// Window adjustments.
void windowToWorld(int windowX, int windowY, double* worldX, double* worldY)
{
	int x = windowX - 800 / 2; 
	int y = windowY - 800 / 2;

	*worldX = (float)x / 400.0f;
	*worldY = -(float)y / 400.0f;
}

// Function to increment the score by 1 on mouse click.
void onMouse(int button, int state, int x, int y)
{
	GLdouble worldClickX, worldClickY;
	windowToWorld(x, y, &worldClickX, &worldClickY); // mouse clicks.
	bool clicked = isMouseOverBall(ballX, ballY, worldClickX, worldClickY); // if clicked or not.
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		// if clicked on ball -- increase the score by 1.
		if (clicked)
		{
			score = score + 1;
			// setting score for level 2.
			if (score > 10)
			{
				score1 = score1 + 1;
				score2 = 10;
			}
			else
			{
				score2 = score;
			}
		}

	}



}

// Reshape function: defines what to do when the window is resized.
void reshape(GLsizei width, GLsizei height)
{
	if (height == 0) 
		height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height); // sets the extents for the current window.
	glMatrixMode(GL_PROJECTION); // sets the current matrix mode.
	// GL_PROJECTION: Applies subsequent matrix operations to the projection matrix stack.
	// To set zoom factor, aspect ratio etc.
	glLoadIdentity(); // Replaces the current matrix with the identity matrix.
	if (width >= height)
	{
		clipAreaXLeft = -1.0 * aspect;
		clipAreaXRight = 1.0 * aspect;
		clipAreaYBottom = -1.0;
		clipAreaYTop = 1.0;
	}
	else
	{
		clipAreaXLeft = -1.0;
		clipAreaXRight = 1.0;
		clipAreaYBottom = -1.0 / aspect;
		clipAreaYTop = 1.0 / aspect;
	}
	gluOrtho2D(clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop + 0.10);
	ballXMin = clipAreaXLeft + ballRadius;
	ballXMax = clipAreaXRight - ballRadius;
	ballYMin = clipAreaYBottom + ballRadius;
	ballYMax = clipAreaYTop - ballRadius;
}

// Function for the timer.
void Timer(int value)
{
	glutPostRedisplay(); // It marks the current window as needing to be redisplayed.
	glutTimerFunc(refreshMills, Timer, 5);
	// registers a timer callback to be triggered in a specified number of milliseconds.
}

// Main function.
int main(int argc, char* argv[])
{
	glutInit(&argc, argv); // to initialize the glut libraries.
	// 'argv' is a pointer to an array of nullterminated strings, and 'argc' says how large this array is.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Initialising Window Modes.
	// GLUT_DOUBLE: bit mask to select a double buffered window.
	// doubling makes the animation smoother.
	// GLUT_RGB: bit mask to select a color index mode window. (RGB)
	glutInitWindowSize(800, 800); // Initilising window size.
	glutInitWindowPosition(100, 100); // Initilising window position.
	glutCreateWindow("Bounce Ball"); // Naming window.
	glutMouseFunc(onMouse); // sets mouse callback for the current window according to onMouse() function.
	glutDisplayFunc(mydisplay); // sets the display callback for the current window according to mydisplay() function.
	glutKeyboardFunc(mykey); // sets the keyboard callback for the current window according to mykey() function.
	glutReshapeFunc(reshape); // sets the reshape callback for the current window according to reshape() function.
	glutTimerFunc(0, Timer, 0); // registers a timer callback to be triggered in a specified number of milliseconds.
	glutMainLoop();  // will call as necessary all the callbacks that have been registered.
	return 0;
}