#include <simplecpp>
#include <cstdlib>
int mainCanvas(string name);//this brings in the main canvas
void instructions();//brings in the instruction terminal
void pattern();//prints the patterns
void about();//brings in the about terminal
void title();//prints the big title of the game
int rungame(string plname,int level,int& score);// is used to call the game
int levelSetter(int level,int arr[5][5]);//this sets the level each time
void scoreboard(string plname,int level,int score);//prints the score
void implant(Sprite &shape,int r,int g,int b,int Hide);
void thanksScreen();//appears to thank the user after the exit button is pressed
void finishScreen();//appears at last when all the levels are finished
struct brick{//this is to build the visual bricks
	double cx,cy;//center of the brick
	Polygon part[4];//parts of the brick
    void make_brick(double cx,double cy,double color)//consturcts the brick
    {
       double x=70,y=35;
       int rgb[3];
       double partV1[4][2]={{-x/4,0},{x/4,0},{x/2,-y/2},{-x/2,-y/2}},partV2[4][2]={{-x/4,0},{-x/2,y/2},{x/2,y/2},{x/4,0}},partV3[3][2]={{-x/2,y/2},{-x/2,-y/2},{-x/4,0}},partV4[3][2]={{x/4,0},{x/2,y/2},{x/2,-y/2}};//these arrays store the corners of the polygon that we use to make the brick
       part[0].reset(cx,cy,partV1,4);giveColor(color,1,rgb);part[0].setColor(COLOR(rgb[0],rgb[1],rgb[2]));part[0].setFill(1);
       part[1].reset(cx,cy,partV2,4);giveColor(color,2,rgb);part[1].setColor(COLOR(rgb[0],rgb[1],rgb[2]));part[1].setFill(1);
       part[2].reset(cx,cy,partV3,3);giveColor(color,3,rgb);part[2].setColor(COLOR(rgb[0],rgb[1],rgb[2]));part[2].setFill(1);
       part[3].reset(cx,cy,partV4,3);giveColor(color,4,rgb);part[3].setColor(COLOR(rgb[0],rgb[1],rgb[2]));part[3].setFill(1);
    }
    brick(){}//unparametrised constructor
    void hide()//hides the entire brick
    {
	  for(int i=0;i<4;i++)part[i].hide();
    }
    void giveColor(int color,int part,int rgb[])//to store in the rgb array the required color combinations
    {
		switch(color)//based on which color is needed the color function returns values of rgb
		{//the values were manually found
			case 0:switch(part)
			       {
					   case 1:rgb[0]=255;rgb[1]=215;rgb[2]=0;break;
					   case 2:
					   case 3:rgb[0]=218;rgb[1]=165;rgb[2]=32;break;
					   case 4:rgb[0]=255;rgb[1]=255;rgb[2]=0;break;
				   }
			      break;
			case 1:switch(part)
			       {
					   case 1:rgb[0]=50;rgb[1]=205;rgb[2]=50;break;
					   case 2:
					   case 3:rgb[0]=34;rgb[1]=139;rgb[2]=34;break;
					   case 4:rgb[0]=127;rgb[1]=255;rgb[2]=0;break;
				   }
			      break;
			case 2:switch(part)
			       {
					   case 1:rgb[0]=227;rgb[1]=18;rgb[2]=63;break;
					   case 2:
					   case 3:rgb[0]=130;rgb[1]=12;rgb[2]=27;break;
					   case 4:rgb[0]=245;rgb[1]=75;rgb[2]=12;break;
				   }
			      break;
			case 3:switch(part)
			       {
					   case 1:rgb[0]=128;rgb[1]=128;rgb[2]=128;break;
					   case 2:
					   case 3:rgb[0]=0;rgb[1]=0;rgb[2]=0;break;
					   case 4:rgb[0]=64;rgb[1]=64;rgb[2]=64;break;
				   }
			      break;
			case 4:switch(part)
			       {
					   case 1:rgb[0]=0;rgb[1]=0;rgb[2]=255;break;
					   case 2:
					   case 3:rgb[0]=0;rgb[1]=0;rgb[2]=153;break;
					   case 4:rgb[0]=102;rgb[1]=102;rgb[2]=255;break;
				   }
			      break;
			case 5:switch(part)
			       {
					   case 1:rgb[0]=255;rgb[1]=0;rgb[2]=255;break;
					   case 2:
					   case 3:rgb[0]=153;rgb[1]=0;rgb[2]=153;break;
					   case 4:rgb[0]=255;rgb[1]=102;rgb[2]=255;break;
				   }
			      break;
			case 6:switch(part)
			       {
					   case 1:rgb[0]=153;rgb[1]=76;rgb[2]=0;break;
					   case 2:
					   case 3:rgb[0]=51;rgb[1]=25;rgb[2]=0;break;
					   case 4:rgb[0]=204;rgb[1]=102;rgb[2]=0;break;
				   }
			      break;
			case 7:switch(part)
			       {
					   case 1:rgb[0]=127;rgb[1]=25;rgb[2]=229;break;
					   case 2:
					   case 3:rgb[0]=80;rgb[1]=11;rgb[2]=149;break;
					   case 4:rgb[0]=161;rgb[1]=77;rgb[2]=255;break;
				   }
			      break;
		}
	}
  };
  
int main()//main program
{
	int dialog=0,level=1,score=0;//dialog tells which dialog box to be opened..
	string plName;//stores the player name        Below we print E-Ball by using the ascii characters
	cout<< "                             ╭━━━╮╋╋╋╋╭━━╮╋╋╋╭╮╭╮ \n";
    cout<< "                             ┃╭━━╯╋╋╋╋┃╭╮┃╋╋╋┃┃┃┃ \n";
    cout<< "                             ┃╰━━╮╋╋╋╋┃╰╯╰┳━━┫┃┃┃ \n";
    cout<< "                             ┃╭━━╯╭━━╮┃╭━╮┃╭╮┃┃┃┃ \n";
    cout<< "                             ┃╰━━╮╰━━╯┃╰━╯┃╭╮┃╰┫╰╮ \n";
    cout<< "                             ╰━━━╯╋╋╋╋╰━━━┻╯╰┻━┻━╯ \n";
    cout<< "                            ¡¡ ǝɯɐƃ ɹǝʞɐǝɹq ʞɔıɹq ɐ \n" << "\n" << "\n";
    cout<<"                 WELCOME TO THIS THRILLING BRICK BREAKER GAME.\n";
    for(int i=0;i<2;i++) usleep(1000000);
    cout<<"HOLD UR BREATH WHILE THE GAME LOADS........ \n";
	usleep(2000000);
	cout<<"Enter the name of the player?\n";
	getline(cin,plName);
	usleep(1000000);
	while(dialog!=4)//main while loop on which our program runs . It executes til the exti button is clicked which is dialog=4
	{
	   dialog=mainCanvas(plName);//main canvas returns which dialog box is to be called
	   switch(dialog)
	   {
		   case 1:about();break;//calling about dialog
		   case 2:level=1,score=0;
		   while(level!=0)
		   {
			   level=rungame(plName,level,score);//when level=0 means the game is over and we need to restart from level 1
		   }
		   break;
		   case 3:instructions();break;//calls the instructions dialog
		   case 4:thanksScreen();break;//calls the thanks dialog
	   }
	}
	cout<<"THANKS FOR PLAYING\n";   
}

int mainCanvas(string name)//This function defines the welcome screen of our game
{
	initCanvas("BRICK BREAKER",1000,800);
	beginFrame();//begining of the frame for storing graphics
	Circle ArenaPaint;
	for(int i=0;i<5000;i++)//printing the canvas with the random circles of random atributes
	{
		ArenaPaint.reset(rand()%2000,rand()%2000,rand()%100);
		implant(ArenaPaint,rand()%255,rand()%255,rand()%255,0);
	}
	ArenaPaint.hide();
	Rectangle Arena(500,150,500,130);implant(Arena,255,200,200,0);//arena rectangle forms the background of the various captions that are seen on the welcome screen	
	title();//the function prints the title of the game "E-BALL"
	int ixCommon=700,iy1=400,iy2=490,iy3=580,iy4=670;//these are the cordinates telling where are the various buttons on our canvas
	//In 10 lines that follow we print the buttons available with the user
	Arena.reset(500,250,350,45);implant(Arena,0,100,60,0);
	Text Info(500,250,"A BRICK BREAKER GAME");Info.setColor(COLOR(255,255,255));Info.imprint();
	Arena.reset(ixCommon,iy1,250,45);implant(Arena,0,100,60,0);
	Info.reset(ixCommon,iy1,"1. ABOUT");Info.imprint();
	Arena.reset(ixCommon,iy2,250,45);implant(Arena,0,100,60,0);
	Info.reset(ixCommon,iy2,"2. PLAY GAME");Info.imprint();
	Arena.reset(ixCommon,iy3,250,45);implant(Arena,0,100,60,0);
	Info.reset(ixCommon,iy3,"3. INSTRUCTIONS");Info.imprint();
	Arena.reset(ixCommon,iy4,250,45);implant(Arena,0,100,60,0);
	Info.reset(ixCommon,iy4,"4. EXIT");Info.imprint();
	// the code below is to handle newton's cradle (a pendulum combinations) as well as for processing the events 
	Rectangle ArenaNC(300,500,300,300);implant(ArenaNC,200,200,255,1);//arenaNC is the background of the cradle system
	Circle ball[3];Line thread[3];//circle array defines the ball seen and the line array the threads seen
	for(int i=0;i<3;i++)//Here we set the atributes for the ball as well as thread
	{
		ball[i].setColor(COLOR(155,10,50));ball[i].setFill(1);
		thread[i].setColor(COLOR(155,10,50));thread[i].setFill(1);
	}//belw are the varibles related to the ball R-stores the thread length r-stores the radius of the ball
	int R=200,r=20;double ballPosTop[3][2]={{300-2*r,350},{300,350},{300+2*r,350}},ballPosBottom[3][2];//this array stores the top position of the threads 
	for(int i=0;i<3;i++)//Here we find  the bottom position of the ball according to available info
	    for(int j=0;j<2;j++)
	         ballPosBottom[i][j]=ballPosTop[i][j]+R*(j%2);
	for(int i=0;i<3;i++)//Here we initialise the bricks actually
	{
		 ball[i].init(ballPosBottom[i][0],ballPosBottom[i][1],r);
		 thread[i].init(ballPosTop[i][0],ballPosTop[i][1],ballPosBottom[i][0],ballPosBottom[i][1]);
	}
	endFrame();//end of the frame storing the graphics
	//defining events now-- means the dynamic part of the game starts now
	XEvent event;
	int x=300,direction=2,i=0,clicked=0;double yDis=0.2;
	while(1)//Here is the moving  balls realised and click events processed
	{
		if(x==350||x==250)//these are end points of the bal
		direction=-direction;//direction tell whether we need to increase or decrease the x cordinates 
		x+=direction;
		if(x!=300)
		i=1+((x-300)/abs((x-300)*1.0));//i is used to find whether we decrease y cordinate incease it
		else usleep(10000);
		ball[i].move(direction,direction*(1-i)*yDis);//moving the ball
		ballPosBottom[i][0]+=direction;             //changing the ball position acordingly
		ballPosBottom[i][1]+=(direction*(1-i)*yDis);
		thread[i].reset(ballPosTop[i][0],ballPosTop[i][1],ballPosBottom[i][0],ballPosBottom[i][1]);//moving the threads accordingly
	    //processing events
	    if(checkEvent(&event)){
	    if(mouseButtonPressEvent(&event))
	    {
			int clickx=event.xbutton.x,clicky=event.xbutton.y;
			if(clickx<ixCommon+100&&clickx>ixCommon-100)//if there is event in our required area we return those dialog that are to be opened 
			{
				if(clicky<iy1+25 && clicky>iy1-25)
				clicked=1;//clicked stores which dialog to open
				else if(clicky<iy2+25 && clicky>iy2-25)
				clicked=2;
				else if(clicky<iy3+25 && clicky>iy3-25)
				clicked=3;
				else if(clicky<iy4+25 && clicky>iy4-25)
				clicked=4;
				if(clicked!=0)
				break;//if there is a click we stop the procesing and return what is clicked
			}
		}
	}}
	closeCanvas();
	return clicked;	
}

void pattern()//use of function is to fill the canvas with a given pattern
{
	//basically the pattern is made by rotating a line and changing its color and imprinting it
	beginFrame();
	//four loops are basically for four parts of the plane
	for(int i=0; i<400; i++){
		Line l(0,400-i,1000,400+i);
		implant(l,200+55*abs(sin(i)),55*abs(sin(i))+200,255*abs(sin(i)),0);
	}
	for(int i=0; i<500; i++){
		Line l(i,0,1000-i,800);
		implant(l,200+55*abs(sin(i)),200+55*abs(sin(i)),255*abs(sin(i)),0);
	}
	for(int i=0; i<500; i++){
		Line l(500+i,0,500-i,800);
		implant(l,200+55*abs(sin(i)),200+55*abs(sin(i)),255*abs(sin(i)),0);
	}
	for(int i=0; i<400; i++){
		Line l(1000,i,0,800-i);
	    implant(l,200+55*abs(sin(i)),200+55*abs(sin(i)),255*abs(sin(i)),0);
	}
	endFrame();
}
void instructions()//function opens a new canvas for the instructions terminal
{
	initCanvas("Instructions",1000,800);
	pattern();
	int exitx=850,exity=700;//these are cordinates of the position of bach button
	beginFrame();//below we print the instructions for the user
	Text info(500,50,"-----------------------------------------------------------------------------------------------------------------------------------------");info.imprint();
	info.reset(500,70,"INSTRUCTIONS");info.imprint();
    info.reset(500,90,"-----------------------------------------------------------------------------------------------------------------------------------------");info.imprint();
    info.reset(480,200,"Welcome to the brand new dimension of the classic brick breaker game, E-Ball.");info.imprint();
    info.reset(485,270,"The mission is to break all the bricks on the screen and go through all the levels");info.imprint();
    info.reset(155,310,"to get maximum score.");info.imprint();
    info.reset(121,380,"1. Click to start.");info.imprint();
    info.reset(336,450,"2. Use the scroll button on the mouse to go left/right.");info.imprint();
    info.reset(372,520,"3. Prevent the ball from touching the bottom of the canvas.");info.imprint();
    info.reset(396,590,"4. Break all the bricks on one level to advance to the next level.");info.imprint();
    info.reset(exitx,exity,"BACK");info.imprint();
    endFrame();
	XEvent event;
	while(1)//in this we process if a click on the back button is done
	{
		nextEvent(&event);
		if(mouseButtonPressEvent(&event))
		{
			if(event.xbutton.x<exitx+100&&event.xbutton.x>exitx-100&&event.xbutton.y<exity+25&&event.xbutton.y>exity-25)
			break;
		}
	}
	closeCanvas();
}
void about()//function opens a new terminal for the about dialog
{
	initCanvas("About",1000,800);
	pattern();
	int exitx=850,exity=700;
	beginFrame();//below we print why the game was made and who made them
	Text info(500,100,"ABOUT");info.imprint();
	info.reset(500,200,"DEVELOPED EXCLUSIVELY BY: ");info.imprint();
	info.reset(500,300,"Nishant   Kumar   Singh   (120050043)");info.imprint();
	info.reset(500,400,"Aditya   Kumar   Akash   (120050046)");info.imprint();
	info.reset(500,500,"Ranveer   Aggarwal   (120050020)");info.imprint();
	info.reset(500,600,"Game developed as a part of CS101 PROJECT");info.imprint();
	info.reset(exitx,exity,"BACK");info.imprint();
	endFrame();
	XEvent event;
	while(1)//in this we process if a click on the back button is done
	{
		nextEvent(&event);
		if(mouseButtonPressEvent(&event))
		{
			if(event.xbutton.x<exitx+50&&event.xbutton.x>exitx-50&&event.xbutton.y<exity+25&&event.xbutton.y>exity-25)
			break;
		}
	}
	closeCanvas();
}
void title()//function prints the title "E BALL" using the polygons
{
	int r=180,g=55,b=0;
	double earray[12][2] = {{50,-50},{50,-30},{10,-30},{10,-10},{30,-10},{30,10},{10,10},{10,30},{50,30},{50,50},{-10,50},{-10,-50}};//working on E
	Polygon E(310,150,earray,12);implant(E,r,g,b,1);
	Rectangle dash(392.5,150,60,20);//working on "-"
	implant(dash,r,g,b,1);
	double barray[8][2] = {{10,2},{50,2},{50,50},{-10,50},{-10,-50},{50,-50},{50,-2},{10,-2}};//working on B
	Polygon B(455,150,barray,8);implant(B,r,g,b,1);
	Rectangle B1(475,124,20,8);implant(B1,255,200,200,1);//working on the rectangle in B 
	Rectangle B2(475,176,20,8);implant(B2,255,200,200,1);//working on the rectangle in B
	double aarray[8][2] = {{50,-50},{50,50},{30,50},{30,10},{10,10},{10,50},{-10,50},{-10,-50}};
	Polygon A(520,150,aarray,8);implant(A,r,g,b,1);//working on "A" 
	Rectangle A1(540,130,20,20);implant(A1,255,200,200,1);//worging on the rectangle in "A" 
    double larray[6][2] = {{10,-50},{10,30},{50,30},{50,50},{-10,50},{-10,-50}};
	Polygon L1(585,150,larray,6);implant(L1,r,g,b,1);//working on "L"
	Polygon L2(650,150,larray,6);implant(L2,r,g,b,1);//working on "L"
}
void implant(Sprite &shape,int r,int g,int b,int Hide)//function fills the color , imprints , hides any sprite object
{
	shape.setColor(COLOR(r,g,b));
	shape.setFill(1);
	shape.imprint();
	if(Hide) shape.hide();
}

int rungame(string plname,int level,int& score)//THIS IS THE ACTUAL GAME RUNNING METHOD	
{
 int a[5][5];// this stores -1 for the bricks which are to be made visible according to the levels and 0 for the hidden ones
 int std=levelSetter(level,a);//setting the bricks according to the level and returning how many of the are visible
 if(std==0)//if the number visible is 0 means the total levels are exhausted
 {
	scoreboard(plname,level,score);
	finishScreen();//thus we call the final screen
	return 0; 
 } 
 //THE BELOW PART OF CODE EXECUTES ONLY WHEN THERE ARE LEVELS FURTHER LEFT
 initCanvas("Brick Breaker",800,800);//setting up the canvas
 beginFrame();//beginig of the frame 
 Rectangle arena;//this rectangle as well as 3 below lines are to paint the canvas
 for(int i=0;i<100;i++)
 {arena.reset(8*i,400,100,800);implant(arena,0,200*abs(sine(i)),200*abs(sine(i)),0);}
 arena.hide();
 Text levels(350,45,"Level");levels.imprint();levels.reset(400,45,level);//printing the level as well as arena
 int baseDepth=600;Line base(0,baseDepth,800,baseDepth);//making a mark line for the movement of the plank
 int pausex=200,pausey=700,currentScore=0,scorex=600,scorey=700;//setting the values for where are scores and pause to be shown 
 Text tpause(pausex,pausey,"PAUSE");Text displayScore(scorex-150,scorey,"CURRENT SCORE");//this is to pause the game in between
 displayScore.imprint();displayScore.reset(scorex,scorey,currentScore);//displaying the scores
 XEvent event;
 {
  double cxr=500,cyr=baseDepth-10;
  Rectangle r(cxr,cyr,100,20);//setting up the plank which is denoted by rectangle r
  r.setColor(COLOR(210,98,32));
  r.setFill(1);
  int radius=8;//this is the radius of the ball
  double cx=cxr,cy=cyr-10-radius-2,vx=1,vy=1.3;//setting up values so that we initially have the ball just above the block
  Circle c(cx,cy,radius);//initialising the ball
  c.setColor(COLOR(200,255,0));
  c.setFill(1);
  brick x[5][5];//defining the bricks
  for(int i=0;i<5;i++)
	for(int j=0;j<5;j++)
	    if(a[i][j]==-1)//based on our previous array a we initialise the bricks or leave them as it is
	     x[i][j].make_brick(200+80*j,100+40*i,rand()%8);//making the bricks
  int sum=0;
  endFrame();//ending the frame
  while(1)//the loop to let user start the game from any point on the below line 
  {
	  if(checkEvent(&event))
	  {
		  if(mouseButtonPressEvent(&event))//here we move both ball and plank together
		  {
	         if(event.xbutton.button==5){ if(cxr+10<750){r.move(10,0);cxr+=10;c.move(10,0);cx+=10;}}
	         else if(event.xbutton.button==4) {if(cxr-10>50){r.move(-10,0);cxr-=10;c.move(-10,0);cx-=10;}}
             else if(event.xbutton.button==1) break;
          }         
	  }
  } 
  while (1){//starting the game in reality
  if(cx>800-radius || cx<radius) vx=-vx;//conditions for ball out of canvas
  if(cy>800-radius || cy<radius) vy=-vy;//out of canvas condition
  cx=cx+vx;//updating the variables of ball positions
  cy=cy+vy;
  c.moveTo(cx,cy);//moving the ball
  if(cy>baseDepth-20-radius && cy<baseDepth-20)//here we find if the ball hits the plank
  { 
    if(cx>=cxr-50&&cx<=cxr+50)//if there is a hit the velocity is reversed
	vy=-vy;
  }//below we see whether the ball misses the plank or not
 if(cy>baseDepth-20)//if ball misses
 {Text t(400,400,"GAME OVER") ;usleep(1000000);closeCanvas();score+=currentScore;scoreboard(plname,level,score);level=0;break;}//conditions of game being over
 if(checkEvent(&event)){ // returns false if no event has happened.
	if(mouseButtonPressEvent(&event)){//conditions for moving the plank according to the scroll 
	 if(event.xbutton.button==5){if(cxr+10<750) {r.move(10,0);cxr+=10;}}//to control the plank
	 else if(event.xbutton.button==4) {if(cxr-10>50){r.move(-10,0);cxr-=10;}}//to control the plank
	 else if(event.xbutton.button==1)//to manage the pause and resume button
	   {
		   if(event.xbutton.x<pausex+50&&event.xbutton.x>pausex-50&&event.xbutton.y<pausey+25&&event.xbutton.y>pausey-25)
	       {   
			   tpause.reset(pausex,pausey,"RESUME");
			   while(1)//we wait till the resume button is clicked again
			   {
				   int Click=getClick();
				   if(Click/65536<pausex+50&&Click/65536>pausex-50&&Click%65536<pausey+25&&Click%65536>pausey-25)
				   break;
			    }
			   tpause.reset(pausex,pausey,"PAUSE"); 
		    }
	    }
  } }//end of event management
  bool destroy=false;//this tells if a brick is destroyed or not in a particular hit
 for(int i=0;i<5;i++){//managing the bursting of the brick
	for(int j=0;j<5;j++){
		if(a[i][j]==-1){
		   if(abs(cx-200-80*j)<35&&abs(cy-100-40*i)<17.5)//this is the condition for the brick bursting
		   {destroy=true;//below conditions are for sensing whether they are from the shorter edge or longer
			 if(abs(cx-200+35-80*j)<2)vx=-vx;
			  else if(abs(cx-200-35-80*j)<2) vx=-vx;
			 if(abs(cy-100+17.5-40*i)<2) vy=-vy;
			  else if(abs(cy-100-17.5-40*i)<2) vy=-vy;
		     x[i][j].hide();sum++;//we hide the hit brick and inrease the count of bursted brick
		     a[i][j]=i;//below we modify array a as well as change the score on the scoreboard of the play canvas
		     currentScore+=((i+j)%3+1)*10;displayScore.reset(scorex,scorey,currentScore);
		     break;
		}}}if(destroy)break;//if we find a brick is destroyed we come out of loop
	}//below is condition for the winning which is by equating the no of bursted brick
	if(sum==std){ Text t2(400,400,"CONGRATULATIONS");usleep(1000000);score+=currentScore;closeCanvas();level++; break;}
}//close of the game loop
}
return level;//we return the next level of the brick which is incresed in the win condition
}

int levelSetter(int level,int arr[5][5])//function initialises the arr according to level and returns the number of bricks
{
	int count=0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			switch(level)//each case is each level and based on the i j values we initialise the arr array
			{
				case 1:if(i==0||i==1){ arr[i][j]=-1; count++;}
				       else arr[i][j]=0;break;
				case 2:if(i==j||(i+j==4)){ arr[i][j]=-1;count++;}
				       else arr[i][j]=0;break;
				case 3:if((i==j||(i+j==4))||(i==2||j==2)){arr[i][j]=-1;count++;}
				       else arr[i][j]=0;break;
				case 4:if((i+j==2)||(i+j==6)||((i==3&&j==1)||(i==1&&j==3))){arr[i][j]=-1;count++;}
				       else arr[i][j]=0;break;
				case 5:if(i==0&&j==2){arr[i][j]=-1;count++;}
				       else if(i>=1 && (j>=1&&j<=3)){arr[i][j]=-1;count++;}
				       else if(i==2 && (j==0||j==4)){arr[i][j]=-1;count++;}
				       else arr[i][j]=0;break;
				case 6:if(i%2==0||j%2==0){arr[i][j]=-1;count++;}
				       else arr[i][j]=0;break;
				case 7:arr[i][j]=-1;count++;break;   
			}
		}
	}
	return count;//we return how many bricks are used
}
void scoreboard(string plname,int level,int score)//this is the score board which comes after u lose or win the entire game
{
	initCanvas("SCORE BOARD",500,500);beginFrame();
	Rectangle arena;//these lines print the info as well print the pattern
    for(int i=0;i<155;i++)
    {
		arena.reset(250,i*(600/150),500,500/120);implant(arena,80,100+85*abs(sine(i)),80,0);;
	}
	Text Info(250,100,"SCORE BOARD");Info.imprint();Info.setColor(COLOR(0,0,100));
	Info.reset(125,200,"PLAYER ");Info.imprint();
	Info.reset(300,200,plname);Info.imprint();
	Info.reset(125,250,"LEVEL REACHED ");Info.imprint();
	Info.reset(300,250,level);Info.imprint();
	Info.reset(125,300,"SCORE");Info.imprint();
	Info.reset(300,300,score);Info.imprint();
	arena.reset(400,400,80,50);implant(arena,0,100,0,1);Info.setColor(COLOR(255,255,255));
	Info.reset(400,400," OK ");Info.imprint();endFrame();
	while(1)//we wait for user to click on ok button
	{
		int c=getClick();
		if(c/65536<400+25&&c/65536>400-25&&c%65536<400+25&&c%65536>400-25)
		break;
	}
	closeCanvas();
}
void thanksScreen()//final screen when u click on exit button
{
	initCanvas("Thanks Screen",700,300);
	beginFrame(); 
	for(int i=0;i<3000;i++){   //This loop serves the purpose of creating the background.
		int cx1=rand()%1000-200,cy1=rand()%1000-200,cx2=rand()%1000-200,cy2=rand()%1000-200;   //Declaring random variables for position of the lines.
		Line l(cx1,cy1,cx2,cy2);
		l.setColor(COLOR(cx1%255,cy1%255,cx2%255));   //Filling random colors in the lines. 
		l.imprint();
	}
	endFrame();
	Rectangle printer(0,0,10,10);      //Creating the printer rectangle.
	printer.setColor(COLOR("white"));
	printer.setFill(1);
	for(int i=0;i<17;i++){     //This loop is printing the 'THANKS'.
		for(int j=0;j<80;j++){
			usleep(4500);
			printer.reset(10*j,10*i,10,10);
			if(j==10) if(i>5&&i<15) printer.imprint();
			for(int x=0;x<4;x++){  //This loop prints the vertical lines.
				if(j==16+10*x) if(i>4&&i<15) printer.imprint();
			}
			for(int y=0;y<2;y++){  //This loop also prints the vertical lines.
				if(j==24+10*y) if(i>4&&i<15) printer.imprint();
			}
			if(j==48) if(i>4&&i<15) printer.imprint();  //Printing particular verical lines.
			if(j==55) if(i>=5&&i<=10) printer.imprint();//Printing particular verical lines.
			if(j==62) if(i>=10&&i<=14) printer.imprint();//Printing particular verical lines.
			if(i==5){    //Printing horizontal lines.
				if(j>5&&j<15) printer.imprint();
				if(j>26&&j<34) printer.imprint();
			}
			if(i==10){  //Printing horizontal lines.
				if(j>16&&j<24) printer.imprint();
				if(j>26&&j<34) printer.imprint();
			}
			if(j>=36&&j<46) if(i==(j-31)) printer.imprint();   //Printing the inclined lines.
			if(j>=48&&j<=53) if(i==(58-j)||i==(j-39)) printer.imprint();//Printing the inclined lines.
			if(j>=55&&j<63){//Printing the inclined lines.
				if(i==5||i==10) printer.imprint();
				if(i==14) printer.imprint();
			}
			}
	}
	Text t1(350,180,"FOR PLAYING");
	t1.setColor(COLOR("white"));usleep(50000);
	Text t2(350,240,"Hope you enjoyed the game");
	t2.setColor(COLOR("white"));
	usleep(1000000);
	t1.hide();t2.hide();     //Hiding the previous texts.
	for(double i=0;i<300;i++){
       Rectangle rub(350,i,700,10);implant(rub,255*abs(sine(i/4)),255*abs(sine(i/4)),255*abs(sine(i/4)),1);
    }
	Text t4(350,300,"DEVELOPERS"),t5(350,330,"Aditya Kumar Akash"),t6(350,360,"Nishant Kumar Singh"),t7(350,390,"Ranveer Aggarwal");
	for(int i=0;i<450;i++){  //This loop moves the names of developers upwards.
		usleep(5000);
		t4.moveTo(350,300-i);
		t5.moveTo(350,330-i);
		t6.moveTo(350,360-i);
		t7.moveTo(350,390-i);
	}
	usleep(100000);
	closeCanvas();
}
void finishScreen()//screen comes when final level is won
{
	initCanvas("GAME OVER",500,500);beginFrame();
	Rectangle arena(250,250,500,500);implant(arena,60,150,80,0);
	arena.reset(250,250,440,420);implant(arena,0,100,0,1);
	Text info(250,200,"YOU HAVE WON ALL THE LEVELS");info.setColor(COLOR(255,255,255));info.imprint();
	info.reset(250,280,"HOPE YOU ENJOYED PLAYING");info.imprint();
	info.reset(250,360,"NEXT VERSION IS COMING SOON");info.imprint();
	info.reset(250,100,"CONGRATS!!!");endFrame();
	usleep(2500000);
	closeCanvas();
}
