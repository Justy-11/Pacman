//Gaming project **pacman** group-28

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<windows.h>
#include<conio.h>

using namespace std;

bool startGame = true;
int count =20;
char ch;
int x=1;  //x,y -> Pacman's coordinates or positions
int y=1;  
int X=37; //X,Y -> Ghost1(G)'s coordinates or positions
int Y=1;
int m=14; //m,n -> Ghost2(&)'s coordinates or positions
int n=6;
int M=37,N=12;   //M,N -> Ghost3(%)'s coordinates or positions
int u=1,v=12;   //u,v -> Ghost4($)'s coordinates or positions
int t;   //sleep time
int pnts = 0;   //points!
int playAgain;
bool easyOrHard = 0;

enum move {UP,DOWN,LEFT,RIGHT}direction;    //for pac
enum ghost_move {UP1,DOWN1,LEFT1,RIGHT1} ghost_dir,ghost2_dir,ghost3_dir,ghost4_dir;  //for ghosts

	char map[15][40]=
	{
		"#######################################",
		"|@...................................G|",
		"|.############.##########.###########.|",
		"|.|          |.|        |.|         |.|",
		"|.|          |.|        |.|         |.|",
		"|.############.##########.###########.|",
		"|.............&.......................|",
		"|.############.##########.###########.|",
		"|.|          |.|        |.|         |.|",
		"|.|          |.|        |.|         |.|",
		"|.|          |.|        |.|         |.|",
		"|.############.##########.###########.|",
		"|$...................................%|",
		"#######################################",
	};
	
//function for the front screen of the game
void startScreen()
{   
cout <<endl;
    cout << "        ********       *          ******    **     **        *        **      *   	   "<< endl;
    cout << "        **    **      * *        **    **   * *   * *       * *       ***     *       "<< endl;
    cout << "        **    **     *   *      **          *  * *  *      *   *      *  *    *  	   "<< endl;
    cout << "        ********    *******     **          *   *   *     *******     *   *   * 	   "<< endl;
    cout << "        **         *       *    **          *       *    *       *    *    *  *	   "<< endl;
    cout << "        **        *         *    **    **   *       *   *         *   *     ***	   "<< endl;
    cout << "--------**       *           *    ******    *       *  *           *  *      **-------BY: GROUP-28"<< endl;   
   	cout << endl<<endl;
    
	cout<<"\tGame Info:\n";
	cout<<"\t\t1)@ is the Pac-man\n\t\t2)G,&,% and $ are the ghosts\n\t\t3)Don't get caught by ghosts\n\t\t4)Use w,a,s,d keys to move the Pac-man\n\n";
    cout<<"\t\tChoose difficulty level\n\n\t\t\tEasy-press 0\n\t\t\tHard-press 1\n";
    cin>>easyOrHard;
    
    
    if(easyOrHard == 0)
    { t = 100;}
    else if(easyOrHard == 1)
    { t = 40;}
    
    //else default is taken as 0 (easy)
}

//function to print the map
void print_Map()
{       system("cls");
 		for(int display=0;display<15;display++)
 		{
 			cout<<map[display]<<endl;
		 }
		 cout<<"Points : "<<pnts;
		//system("pause<nul");
}

//function for the movement of pacman
void move_pac(enum move dir)
{
    if(dir==UP)
    {
        if(map[y-1][x]!='#'&& map[y-1][x]!='|')
        {
        if(map[y-1][x] == '.')
         {
		   map[y][x]=' ';
           map[y-1][x]='@';
           pnts++;
           y--;
           Sleep(t);}
           else
          {
		   map[y][x]=' ';
           map[y-1][x]='@';
           y--;
           Sleep(t);}
            
        }
    }
    else if(dir==DOWN)

    {
        if(map[y+1][x]!='#'&& map[y+1][x]!='|')
      {
      	if(map[y+1][x] == '.')
          {
		   map[y][x]=' ';
           map[y+1][x]='@';
           pnts++;
           y++;
           Sleep(t);}
           else
           {
		   map[y][x]=' ';
           map[y+1][x]='@';
           y++;
           Sleep(t);}
           
      }
    }
    if(dir==LEFT)
    {
       if(map[y][x-1]!='#'&& map[y][x-1]!='|')
       {
       	if(map[y][x-1] == '.')
           {
		   map[y][x]=' ';
           map[y][x-1]='@';
           pnts++;
           x--;
          Sleep(t);}
        else
       {
		 map[y][x]=' ';
           map[y][x-1]='@';
           x--;
          Sleep(t);}
      }
    }
    else if(dir==RIGHT)

    {
       if(map[y][x+1]!='#'&& map[y][x+1]!='|')
       {
       	if(map[y][x+1] == '.')
           {
		   map[y][x]=' ';
           map[y][x+1]='@';
           pnts++;
           x++;
           Sleep(t);}
           else
          {
		   map[y][x]=' ';
           map[y][x+1]='@';
           x++;
           Sleep(t);}
       }
    }
}

//function for random directions of the ghost 1 -Intelligent ghost
void ghostDirection()
{
	srand(time(NULL));
    int ghost = rand()%4 + 1;
    switch(ghost)
    {
    	case 1:ghost_dir = LEFT1; break;
    	case 2:ghost_dir = RIGHT1; break;
    	case 3:ghost_dir = UP1; break;
    	case 4:ghost_dir = DOWN1; break;
    	default:;
	}
}

//function for random directions of the ghost 2 -> Semi-stupid ghost
void ghost2Direction()
{
	
	int ghost2 = rand()%4 + 1;
    switch(ghost2)
    {
    	case 1:ghost2_dir = LEFT1; break;
    	case 2:ghost2_dir = RIGHT1; break;
    	case 3:ghost2_dir = UP1; break;
    	case 4:ghost2_dir = DOWN1; break;
    	default:;
	}
}

//function for random directions of the ghost 3 -> Semi-stupid ghost
void ghost3Direction()
{
	
	int ghost3 = rand()%4 + 1;
    switch(ghost3)
    {
    	case 1:ghost3_dir = LEFT1; break;
    	case 2:ghost3_dir = RIGHT1; break;
    	case 3:ghost3_dir = UP1; break;
    	case 4:ghost3_dir = DOWN1; break;
    	default:;
	}
}

//function for random directions of the ghost 4 -> Stupid ghost
void ghost4Direction()
{
	
	int ghost4 = rand()%4 + 1;
    switch(ghost4)
    {
    	case 1:ghost4_dir = LEFT1; break;
    	case 2:ghost4_dir = RIGHT1; break;
    	case 3:ghost4_dir = UP1; break;
    	case 4:ghost4_dir = DOWN1; break;
    	default:;
	}
}

//function for movements of the ghost 1
void ghostMovement(enum ghost_move ghost_dir)
{
if(ghost_dir ==LEFT1)
{
	if(map[Y][X-1]!='#'&& map[Y][X-1]!='|'){
	
   if(map[Y][X-1] == '.')
		{
			map[Y][X] = '.';
			map[Y][X-1] = 'G';
			X--;
		}else
		{
			map[Y][X] = ' ';
			map[Y][X-1] = 'G';	
			X--;
		}
  } 
}
else if(ghost_dir ==RIGHT1)
{
	if(map[Y][X+1]!='#'&& map[Y][X+1]!='|'){

  	if(map[Y][X+1] == '.')
		{
			map[Y][X] = '.';
	    	map[Y][X+1] = 'G';
	    	X++;
		}else
		{
			map[Y][X] = ' ';
		    map[Y][X+1] = 'G';
		    X++;
		}
}
}else if(ghost_dir == UP1)
{
	if(map[Y-1][X]!='#'&& map[Y-1][X]!='|'){
	
  	if(map[Y-1][X] == '.')
		{
			map[Y][X] = '.';
			map[Y-1][X] = 'G';
			Y--;
		}else
		{
			map[Y][X] = ' ';
		    map[Y-1][X] = 'G';	
		    Y--;
		}
}
}else if(ghost_dir == DOWN1)
{
if(map[Y+1][X]!='#'&& map[Y+1][X]!='|'){

  	if(map[Y+1][X] == '.')
		{
			map[Y][X] = '.';
			map[Y+1][X] = 'G';
			Y++;
		}else
		{
			map[Y][X] = ' ';
			map[Y+1][X] = 'G';	
			Y++;
		}
  
} }
}

//function for movements of the ghost 2
void ghost2Movement(enum ghost_move ghost2_dir)
{
if(ghost2_dir ==LEFT1)
{
	if(map[n][m-1]!='#'&& map[n][m-1]!='|'){
	
   if(map[n][m-1] == '.')
		{
			map[n][m] = '.';
			map[n][m-1] = '&';
			m--;
		}else
		{
			map[n][m] = ' ';
			map[n][m-1] = '&';	
			m--;
		}
  } 
}
else if(ghost2_dir ==RIGHT1)
{
	if(map[n][m+1]!='#'&& map[n][m+1]!='|'){

  	if(map[n][m+1] == '.')
		{
			map[n][m] = '.';
	    	map[n][m+1] = '&';
	    	m++;
		}else
		{
			map[n][m] = ' ';
		    map[n][m+1] = '&';
		    m++;
		}
}
}else if(ghost2_dir == UP1)
{
	if(map[n-1][m]!='#'&& map[n-1][m]!='|'){
	
  	if(map[n-1][m] == '.')
		{
			map[n][m] = '.';
			map[n-1][m] = '&';
			n--;
		}else
		{
			map[n][m] = ' ';
		    map[n-1][m] = '&';	
		    n--;
		}
}
}else if(ghost2_dir == DOWN1)
{
if(map[n+1][m]!='#'&& map[n+1][m]!='|'){

  	if(map[n+1][m] == '.')
		{
			map[n][m] = '.';
			map[n+1][m] = '&';
			n++;
		}else
		{
			map[n][m] = ' ';
			map[n+1][m] = '&';	
			n++;
		}
  
} }
}

//function for movements of the ghost 3
void ghost3Movement(enum ghost_move ghost3_dir)
{
if(ghost3_dir ==LEFT1)
{
	if(map[N][M-1]!='#'&& map[N][M-1]!='|'){
	
   if(map[N][M-1] == '.')
		{
			map[N][M] = '.';
			map[N][M-1] = '%';
			M--;
		}else
		{
			map[N][M] = ' ';
			map[N][M-1] = '%';	
			M--;
		}
  } 
}
else if(ghost3_dir ==RIGHT1)
{
	if(map[N][M+1]!='#'&& map[N][M+1]!='|'){

  	if(map[N][M+1] == '.')
		{
			map[N][M] = '.';
	    	map[N][M+1] = '%';
	    	M++;
		}else
		{
			map[N][M] = ' ';
		    map[N][M+1] = '%';
		    M++;
		}
}
}else if(ghost3_dir == UP1)
{
	if(map[N-1][M]!='#'&& map[N-1][M]!='|'){
	
  	if(map[N-1][M] == '.')
		{
			map[N][M] = '.';
			map[N-1][M] = '%';
			N--;
		}else
		{
			map[N][M] = ' ';
		    map[N-1][M] = '%';	
		    N--;
		}
}
}else if(ghost3_dir == DOWN1)
{
if(map[N+1][M]!='#'&& map[N+1][M]!='|'){

  	if(map[N+1][M] == '.')
		{
			map[N][M] = '.';
			map[N+1][M] = '%';
			N++;
		}else
		{
			map[N][M] = ' ';
			map[N+1][M] = '%';	
			N++;
		}
  
} }
}

//function for movements of the ghost 4
void ghost4Movement(enum ghost_move ghost4_dir)
{
if(ghost4_dir ==LEFT1)
{
	if(map[v][u-1]!='#'&& map[v][u-1]!='|'){
	
   if(map[v][u-1] == '.')
		{
			map[v][u] = '.';
			map[v][u-1] = '$';
			u--;
		}else
		{
			map[v][u] = '.';
			map[v][u-1] = '$';	
			u--;
		}
  } 
}
else if(ghost4_dir ==RIGHT1)
{
	if(map[v][u+1]!='#'&& map[v][u+1]!='|'){

  	if(map[v][u+1] == '.')
		{
			map[v][u] = '.';
	    	map[v][u+1] = '$';
	    	u++;
		}else
		{
			map[v][u] = '.';
		    map[v][u+1] = '$';
		    u++;
		}
}
}else if(ghost4_dir == UP1)
{
	if(map[v-1][u]!='#'&& map[v-1][u]!='|'){
	
  	if(map[v-1][u] == '.')
		{
			map[v][u] = '.';
			map[v-1][u] = '$';
			v--;
		}else
		{
			map[v][u] = '.';
		    map[v-1][u] = '$';	
		    v--;
		}
}
}else if(ghost4_dir == DOWN1)
{
if(map[v+1][u]!='#'&& map[v+1][u]!='|'){

  	if(map[v+1][u] == '.')
		{
			map[v][u] = '.';
			map[v+1][u] = '$';
			v++;
		}else
		{
			map[v][u] = '.';
			map[v+1][u] = '$';	
			v++;
		}
  
} }
}


//function for chasing pacman for ghost-1 by changing the directions in the nodes
void ghost1ChasingPac()
{
	unsigned int dx = X-x;
    unsigned int dy = Y-y;
	    
	if(map[Y][X] == map[1][25] || map[Y][X] == map[1][14])
	{
	 if((x<X) && (dx<dy))
	{ ghost_dir = LEFT1; }
	else if((y==Y) && (x<X))
	{ ghost_dir = LEFT1; }
	 else if((y>Y) && (dy<dx))
	{ ghost_dir = DOWN1; }
	else if((x==X) && (y>Y))
	{ ghost_dir = DOWN1; }
	else if((x>X) && (dx<dy))
	{ ghost_dir = RIGHT1; }
	else if((y==Y) && (x>X))
	{ ghost_dir = RIGHT1; }
	
	}else if(map[Y][X] == map[6][37])
	{
	 if((x<X) && (dx<dy))
	{ ghost_dir = LEFT1; }
	else if((y==Y) && (x<X))
	{ ghost_dir = LEFT1; }
	 else if((y>Y) && (dy<dx))
	{ ghost_dir = DOWN1; }
	else if((x==X) && (y>Y))
	{ ghost_dir = DOWN1; }
	 else if((y<Y) && (dy<dx))
	{ ghost_dir = UP1; }
	else if((x==X) && (y<Y))
	{ ghost_dir = UP1; }

	
	}else if(map[Y][X] == map[1][37])
	{
	if((x<X) && (dx<dy))
	{ ghost_dir = LEFT1; }
	else if((y==Y) && (x<X))
	{ ghost_dir = LEFT1; }
	 else if((y>Y) && (dy<dx))
	{ ghost_dir = DOWN1; }
	else if((x==X) && (y>Y))
	{ ghost_dir = DOWN1; }

	
    }else if(map[Y][X] == map[6][25] || map[Y][X] == map[6][14])  
    {
	 if((x<X) && (dx<dy))
	{ ghost_dir = LEFT1; }
	else if((y==Y) && (x<X))
	{ ghost_dir = LEFT1; }
	 else if((y>Y) && (dy<dx))
	{ ghost_dir = DOWN1; }
	else if((x==X) && (y>Y))
	{ ghost_dir = DOWN1; }
	 else if((y<Y) && (dy<dx))
	{ ghost_dir = UP1; }
	else if((x==X) && (y<Y))
	{ ghost_dir = UP1; }
	else if((x>X) && (dx<dy))
	{ ghost_dir = RIGHT1; }
	else if((y==Y) && (x>X))
	{ ghost_dir = RIGHT1; }
	
    }else if(map[Y][X] == map[12][37])
    {
	 if((x<X) && (dx<dy))
	{ ghost_dir = LEFT1; }
	else if((y==Y) && (x<X))
	{ ghost_dir = LEFT1; }
	 else if((y<Y) && (dy<dx))
	{ ghost_dir = UP1; }
	else if((x==X) && (y<Y))
	{ ghost_dir = UP1; }

	
    }else if(map[Y][X] == map[12][14] || map[Y][X] == map[12][25])
	{
	 if((x<X) && (dx<dy))
	{ ghost_dir = LEFT1; }
	else if((y==Y) && (x<X))
	{ ghost_dir = LEFT1; }
	 else if((y<Y) && (dy<dx))
	{ ghost_dir = UP1; }
	else if((x==X) && (y<Y))
	{ ghost_dir = UP1; }
	else if((x>X) && (dx<dy))
	{ ghost_dir = RIGHT1; }
	else if((y==Y) && (x>X))
	{ ghost_dir = RIGHT1; }
	
    }else if(map[Y][X] == map[1][1])
    {

	 if((y>Y) && (dy<dx))
	{ ghost_dir = DOWN1; }
	else if((x==X) && (y>Y))
	{ ghost_dir = DOWN1; }
	else if((x>X) && (dx<dy))
	{ ghost_dir = RIGHT1; }
	else if((y==Y) && (x>X))
	{ ghost_dir = RIGHT1; }
	
    }else if(map[Y][X] == map[6][1])
    {

	 if((y>Y) && (dy<dx))
	{ ghost_dir = DOWN1; }
	else if((x==X) && (y>Y))
	{ ghost_dir = DOWN1; }
	 else if((y<Y) && (dy<dx))
	{ ghost_dir = UP1; }
	else if((x==X) && (y<Y))
	{ ghost_dir = UP1; }
	else if((x>X) && (dx<dy))
	{ ghost_dir = RIGHT1; }
	else if((y==Y) && (x>X))
	{ ghost_dir = RIGHT1; }
	
    }else if(map[Y][X] == map[12][1])
    {

	if((y<Y) && (dy<dx))
	{ ghost_dir = UP1; }
	else if((x==X) && (y<Y))
	{ ghost_dir = UP1; }
	else if((x>X) && (dx<dy))
	{ ghost_dir = RIGHT1; }
	else if((y==Y) && (x>X))
	{ ghost_dir = RIGHT1; }
    }
}

//function for chasing pacman for ghost-2 (if both on same axis)
void ghost2ChasingPac()
{
	if(x==m && y>n)
	{
        ghost2_dir = DOWN1;
	}else if(x==m && y<n)
	{
		ghost2_dir = UP1;
	}else if(y==n && x<m)
	{
		ghost2_dir = LEFT1;
	}else if(y==n && x>m)
	{
		ghost2_dir = RIGHT1;
	}
}

//function for chasing pacman for ghost-3 (if both on same axis)
void ghost3ChasingPac()
{
	if(x==M && y>N)
	{
        ghost3_dir = DOWN1;
	}else if(x==M && y<N)
	{
		ghost3_dir = UP1;
	}else if(y==N && x<M)
	{
		ghost3_dir = LEFT1;
	}else if(y==N && x>M)
	{
		ghost3_dir = RIGHT1;
	}
}


int main()
{	
   startScreen();
   print_Map();
	while (startGame=true)
 	 {		
 	 
	print_Map();
		
    if(_kbhit())
    {
    ch=_getch();
    switch(ch)
    {
    case 'd': direction=RIGHT; break;
    case 'a': direction=LEFT; break;
    case 'w': direction=UP; break;
    case 's': direction=DOWN; break;
    default: ;
    }
}
    ghostDirection();
    ghost2Direction();
    ghost3Direction();
    ghost4Direction();
    
    if(map[Y][X]==map[y][x] || map[n][m]==map[y][x] || map[N][M]==map[y][x] || map[v][u]==map[y][x] )
    {
    cout<<"\t\tGAME OVER"<<endl;
    break;
    
    }else if(pnts == 200)
    {
    cout<<"\t\tYOU WON"<<endl;
    break;
	}
	
	move_pac(direction);
	ghostMovement(ghost_dir);
	ghost2Movement(ghost2_dir);
	ghost3Movement(ghost3_dir);
	ghost4Movement(ghost4_dir);
	ghost1ChasingPac();
	ghost2ChasingPac();
	ghost3ChasingPac();
	//system("cls");
	
} 

    return 0; //end of program
} 




