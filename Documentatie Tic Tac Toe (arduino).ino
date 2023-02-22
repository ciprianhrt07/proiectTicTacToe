
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  // Robojax 4x3 keypad test
  Serial.begin(9600);
  Serial.println("TIC TAC TOE KEYPAD:");
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
}

int positions[3][3] = {{ 0 , 0 , 0} , {0,0,0} , {0,0,0}};

/*
void printInit(){
    String grid1 =("_________________________________________\n|            |            |             |\n|            |            |             |\n|            |            |             |\n|            |            |             |\n|____________|____________|_____________|\n");
    String grid2 = ("|            |            |             |\n|            |            |             |\n|            |            |             |\n|            |            |             |\n|____________|____________|_____________|\n");
    String grid3 = ("|            |            |             |\n|            |            |             |\n|            |            |             |\n|            |            |             |\n|____________|____________|_____________|");

    Serial.print(grid1);
    Serial.print(grid2);
    Serial.println(grid3);
}
*/

/*
 * Algoritm minimax:
 * 
 */
 



void printInit(int matrix[3][3])
{
  int i,j;

  char grid[16][41];

  strcpy(grid[0], "_____________________________________");

  //careu1:

  for(i=1;i<5;i++)
    {for(j=0;j<38;j++)
       if(j%12==0)
        grid[i][j]='|';
       else
        grid[i][j]=' ';
    }

  for(j=0;j<37;j++)
       if(j%12==0)
        grid[i][j]='|';
       else
        grid[i][j]='_';

  //careu2:

  for(i=6;i<10;i++)
    {for(j=0;j<38;j++)
       if(j%12==0)
        grid[i][j]='|';
       else
        grid[i][j]=' ';
    }

  for(j=0;j<37;j++)
       if(j%12==0)
        grid[i][j]='|';
       else
        grid[i][j]='_';

   //careu3:

   for(i=11;i<15;i++)
    {for(j=0;j<38;j++)
       if(j%12==0)
        grid[i][j]='|';
       else
        grid[i][j]=' ';
    }

  for(j=0;j<37;j++)
       if(j%12==0)
        grid[i][j]='|';
       else
        grid[i][j]='_';

/*
  grid[1][1] = '0';
  grid[2][3] ='0';
  grid[3][5] ='0';
  grid[4][7] ='0';
  grid[5][9] ='0';

  grid[1][9] = '0';
  grid[2][7] ='0';
  grid[3][5] ='0';
  grid[4][3] ='0';
  grid[5][1] ='0';

  grid[1][18]= '0';
  grid[2][15] ='0';
  grid[2][21] ='0';
  grid[3][14] ='0';
  grid[3][22] ='0';
  grid[4][15] ='0';
  grid[4][21] ='0';
  grid[5][18] ='0';
*/

// 1 = X , 2 = O


  if(matrix[0][0]==1){

  grid[1][1] ='0';
  grid[2][3] ='0';
  grid[3][5] ='0';
  grid[4][7] ='0';
  grid[5][9] ='0';

  grid[1][9] = '0';
  grid[2][7] ='0';
  grid[3][5] ='0';
  grid[4][3] ='0';
  grid[5][1] ='0';

  }else if(matrix[0][0]==2)
  {
    grid[1][6]= '0';
    grid[2][3] ='0';
    grid[2][9] ='0';
    grid[3][10] ='0';
    grid[3][2] ='0';
    grid[4][9] ='0';
    grid[4][3] ='0';
    grid[5][6] ='0';

  }

 if(matrix[0][1]==1){

  grid[1][13] ='0';
  grid[2][15] ='0';
  grid[3][17] ='0';
  grid[4][19] ='0';
  grid[5][21] ='0';

  grid[1][21] = '0';
  grid[2][19] ='0';
  grid[3][17] ='0';
  grid[4][15] ='0';
  grid[5][13] ='0';

  }else if(matrix[0][1]==2)
  {
    grid[1][18]= '0';
    grid[2][15] ='0';
    grid[2][21] ='0';
    grid[3][14] ='0';
    grid[3][22] ='0';
    grid[4][15] ='0';
    grid[4][21] ='0';
    grid[5][18] ='0';

  }

  if(matrix[0][2]==1){

  grid[1][25] ='0';
  grid[2][27] ='0';
  grid[3][29] ='0';
  grid[4][31] ='0';
  grid[5][33] ='0';

  grid[1][33] = '0';
  grid[2][31] ='0';
  grid[3][29] ='0';
  grid[4][27] ='0';
  grid[5][25] ='0';

  }else if(matrix[0][2]==2)
  {
    grid[1][30]= '0';
    grid[2][33] ='0';
    grid[2][27] ='0';
    grid[3][34] ='0';
    grid[3][26] ='0';
    grid[4][27] ='0';
    grid[4][33] ='0';
    grid[5][30] ='0';

  }
//-------------------- gata prima linie -------------------


  if(matrix[1][0]==1){

  grid[6][1] ='0';
  grid[7][3] ='0';
  grid[8][5] ='0';
  grid[9][7] ='0';
  grid[10][9] ='0';

  grid[6][9] = '0';
  grid[7][7] ='0';
  grid[8][5] ='0';
  grid[9][3] ='0';
  grid[10][1] ='0';

  }else if(matrix[1][0]==2)
  {
    grid[6][6]= '0';
    grid[7][3] ='0';
    grid[7][9] ='0';
    grid[8][10] ='0';
    grid[8][2] ='0';
    grid[9][9] ='0';
    grid[9][3] ='0';
    grid[10][6] ='0';

  }

 if(matrix[1][1]==1){

  grid[6][13] ='0';
  grid[7][15] ='0';
  grid[8][17] ='0';
  grid[9][19] ='0';
  grid[10][21] ='0';

  grid[6][21] = '0';
  grid[7][19] ='0';
  grid[8][17] ='0';
  grid[9][15] ='0';
  grid[10][13] ='0';

  }else if(matrix[1][1]==2)
  {
    grid[6][18]= '0';
    grid[7][15] ='0';
    grid[7][21] ='0';
    grid[8][14] ='0';
    grid[8][22] ='0';
    grid[9][15] ='0';
    grid[9][21] ='0';
    grid[10][18] ='0';

  }

  if(matrix[1][2]==1){

  grid[6][25] ='0';
  grid[7][27] ='0';
  grid[8][29] ='0';
  grid[9][31] ='0';
  grid[10][33] ='0';

  grid[6][33] = '0';
  grid[7][31] ='0';
  grid[8][29] ='0';
  grid[9][27] ='0';
  grid[10][25] ='0';

  }else if(matrix[1][2]==2)
  {
    grid[6][30]= '0';
    grid[7][33] ='0';
    grid[7][27] ='0';
    grid[8][34] ='0';
    grid[8][26] ='0';
    grid[9][27] ='0';
    grid[9][33] ='0';
    grid[10][30] ='0';

  }

//------------------------- gata a doua linie---------

if(matrix[2][0]==1){

  grid[11][1] ='0';
  grid[12][3] ='0';
  grid[13][5] ='0';
  grid[14][7] ='0';
  grid[15][9] ='0';

  grid[11][9] = '0';
  grid[12][7] ='0';
  grid[13][5] ='0';
  grid[14][3] ='0';
  grid[15][1] ='0';

  }else if(matrix[2][0]==2)
  {
    grid[11][6]= '0';
    grid[12][3] ='0';
    grid[12][9] ='0';
    grid[13][10] ='0';
    grid[13][2] ='0';
    grid[14][9] ='0';
    grid[14][3] ='0';
    grid[15][6] ='0';

  }

 if(matrix[2][1]==1){

  grid[11][13] ='0';
  grid[12][15] ='0';
  grid[13][17] ='0';
  grid[14][19] ='0';
  grid[15][21] ='0';

  grid[11][21] = '0';
  grid[12][19] ='0';
  grid[13][17] ='0';
  grid[14][15] ='0';
  grid[15][13] ='0';

  }else if(matrix[2][1]==2)
  {
    grid[11][18]= '0';
    grid[12][15] ='0';
    grid[12][21] ='0';
    grid[13][14] ='0';
    grid[13][22] ='0';
    grid[14][15] ='0';
    grid[14][21] ='0';
    grid[15][18] ='0';

  }

  if(matrix[2][2]==1){

  grid[11][25] ='0';
  grid[12][27] ='0';
  grid[13][29] ='0';
  grid[14][31] ='0';
  grid[15][33] ='0';

  grid[11][33] = '0';
  grid[12][31] ='0';
  grid[13][29] ='0';
  grid[14][27] ='0';
  grid[15][25] ='0';

  }else if(matrix[2][2]==2)
  {
    grid[11][30]= '0';
    grid[12][33] ='0';
    grid[12][27] ='0';
    grid[13][34] ='0';
    grid[13][26] ='0';
    grid[14][27] ='0';
    grid[14][33] ='0';
    grid[15][30] ='0';

  }

  // ------------- gata si a 3-a


 for(i=0;i<=15;i++)
   {for(j=0;j<37;j++)
      Serial.print(grid[i][j]);
    Serial.println();
   }
}

 


int checkForWinner(){

    //check for 0-player : 

    // verificare pe verticala 
    if (positions[0][0] == 1 && positions[1][0] == 1 && positions[2][0] == 1)
          return 1;

    if (positions[0][1] == 1 && positions[1][1] == 1 && positions[2][1] == 1)
          return 1;

    if (positions[0][2] == 1 && positions[1][2] == 1 && positions[2][2] == 1)
          return 1;

     // verificare pe orizontala: 
    if (positions[0][0] == 1 && positions[0][1] == 1 && positions[0][2] == 1)
          return 1;

    if (positions[1][0] == 1 && positions[1][1] == 1 && positions[1][2] == 1)
          return 1;

    if (positions[2][0] == 1 && positions[2][1] == 1 && positions[2][2] == 1)
          return 1;      

    //verificare in x , adica diagonal

    if (positions[0][0] == 1 && positions[1][1] == 1 && positions[2][2] == 1)
          return 1;

    if (positions[0][2] == 1 && positions[1][1] == 1 && positions[2][0] == 1)
          return 1;

    //---------------------------- final verificare pentru 0------------------


    //check for 1-player : 

    // verificare pe verticala 
    if (positions[0][0] == 2 && positions[1][0] == 2 && positions[2][0] == 2)
          return 2;

    if (positions[0][1] == 2 && positions[1][1] == 2 && positions[2][1] == 2)
          return 2;

    if (positions[0][2] == 2 && positions[1][2] == 2 && positions[2][2] == 2)
          return 2;

     // verificare pe orizontala: 
    if (positions[0][0] == 2 && positions[0][1] == 2 && positions[0][2] == 2)
          return 2;

    if (positions[1][0] == 2 && positions[1][1] == 2 && positions[1][2] == 2)
          return 2;

    if (positions[2][0] == 2 && positions[2][1] == 2 && positions[2][2] == 2)
          return 2;      

    //verificare in x , adica diagonal

    if (positions[0][0] == 2 && positions[1][1] == 2 && positions[2][2] == 2)
          return 2;

    if (positions[0][2] == 2 && positions[1][1] == 2 && positions[2][0] == 2)
          return 2;

    //---------------------------- final verificare pentru 1------------------
    
    bool empty = false;

          for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(positions[i][j] == 0)
                  empty = true;

    if(empty==true)
      return 0;
    else
      return -1;
}




void printMatrix(){

  for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
        Serial.print(positions[i][j]);
      Serial.println();
    }
  
}

void turnOn(int mat[3][3]){

  if(mat[0][0]!=0)
  digitalWrite(13,HIGH);

  if(mat[0][1]!=0)
  digitalWrite(12,HIGH);

  if(mat[0][2]!=0)
  digitalWrite(11,HIGH);

  if(mat[1][0]!=0)
  digitalWrite(10,HIGH);
  
  if(mat[1][1]!=0)
  digitalWrite(9,HIGH);
  
  if(mat[1][2]!=0)
  digitalWrite(A0,HIGH);
  
  if(mat[2][0]!=0)
  digitalWrite(A1,HIGH);
  
  if(mat[2][1]!=0)
  digitalWrite(A2,HIGH);

  if(mat[2][2]!=0)
  digitalWrite(A3,HIGH);
  
}

int cnt = 0;
int turn = 0;
void loop() {

 
  
  // keypad test
  char key = keypad.getKey();
  // just print the pressed key
  
  if (key &&(key >='1' && key <= '9')) {
  
    int value=(int)key - 48;
    int linie,coloana;

    switch(value){

      case 1: linie =0 ; coloana = 0; break;
      case 2: linie =0 ; coloana = 1; break;
      case 3: linie =0 ; coloana = 2; break;
      case 4: linie =1 ; coloana = 0; break;
      case 5: linie =1 ; coloana = 1; break;
      case 6: linie =1 ; coloana = 2; break;
      case 7: linie =2 ; coloana = 0; break;
      case 8: linie =2 ; coloana = 1; break;
      case 9: linie =2 ; coloana = 2; break; 

      default : break;
    }

    if(positions[linie][coloana] == 0)
     {  
        if(turn == 0)
          positions[linie][coloana] = 1;
        else 
          positions[linie][coloana] = 2;
         
        Serial.println(key);
        printInit(positions);
        printMatrix();
    
        ++cnt;
       
        Serial.println(turn);  
        turn = 1-turn; 


        //turn on the led:

        turnOn(positions);

        
        int win = checkForWinner();
        if(win==1 || win ==2){
          Serial.print("Congratulations for player: ");
          Serial.print(win);
          Serial.print(" ");
          Serial.println("The game ends here bye");
          Serial.flush();
          exit(0);
        }else
        if(win== -1){
          Serial.println("Congratulations for player: 1 and 2 result is tie , game ends here bye!");
        }

         if(cnt == 11)
          exit(0);
    

        
     }
  }
  // this checkes if 4 is pressed, then do something. Here  we print the text but you can control something.
  //if (key == '4') {
    // if key matches what you are looking for
 //   Serial.println("Key 4 is pressed");
 // }

}
