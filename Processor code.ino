long int x = 0;
long int x2 = 0;
long int x3 = 0;
long int x4 = 0;
long int buf = 0;
int inPin1 = 7;
int inPin2 = 8;
int inPin3 = 9;
int inPin4 = 10;
long int handle;
int distance ;
int distance2 ;
int distance3 ;
int distance4 ;
bool flag = true;
int i = 1;
int i2 = 1;
int i3 = 1;
int i4 = 1;
bool path1 = false;
bool path2 = false;
bool path3 = false;
bool path4 = false;
bool trigger = true;
int buff;
int buff2;
int buff3;
int buff4;
int bb = 1;
bool flager1 = false;
bool flager2 = false;
bool fnc = false;
double point[100][4] = {{20,20,20,-7.9},{20,60,20,-7.9}};
double vlc[100];
int delta[100][4];
int counter = 0;
float feedrate = 4;
float buf_frq;
float buf_frq2;
long int freq(float input)
{
  float fd = input;
  float buf = (fd * 1600)/3;
  long int frq  = round((16000000/(2*buf))-1);
  return frq;
}


void setup() {
    // now turn on interrupts
pinMode(9, OUTPUT);
pinMode(10,OUTPUT);
pinMode(12, OUTPUT);
pinMode(11,OUTPUT);
pinMode(2, OUTPUT);
pinMode(3,OUTPUT);
pinMode(5, OUTPUT);
pinMode(6,OUTPUT);
pinMode(7, INPUT);
pinMode(8,INPUT);
pinMode(9,INPUT);
pinMode(10,INPUT);
pinMode(45,INPUT);
pinMode(40,INPUT);
pinMode(49,OUTPUT);
pinMode(47,OUTPUT);
pinMode(46,OUTPUT);
  fnc = true;
  pinMode(51,OUTPUT);
  pinMode(53, OUTPUT);
  
  attachInterrupt(2, increment1, FALLING);
  attachInterrupt(3, increment2, FALLING);
  attachInterrupt(4, increment3, FALLING);
  attachInterrupt(5, increment4, FALLING);
  Serial.begin(9600);  //turn on serial communication
  
}




void multiplyMatrices(double firstMatrix[][3], double secondMatrix[][4], double mult[][4],int rowFirst, int columnFirst, int rowSecond, int columnSecond){

    int i, j, k;

       for(i = 0; i < rowFirst; ++i)
       {
           for(j = 0; j < columnSecond; ++j)
           {
               mult[i][j] = 0;
           }
       }

       for(i = 0; i < rowFirst; ++i)
       {
           for(j = 0; j < columnSecond; ++j)
           {
               for(k=0; k<columnFirst; ++k)
               {
                   mult[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
               }
           }
       }

}

void ColumnMultiplyer(double A[][3], double B[][4], double C[4]){
     
     int i,j;
         for (i=0;i<4;i++){
             for(j=0;j<3;j++){
                 C[i]+=A[i][j]*B[j][i];

             }

         }

 }

void inverkinematics()
{
    for(int des=0;des<bb;des++)
    {
              vlc[des] = sqrt(pow(point[des+1][0] - point[des][0],2) + pow(point[des + 1][1] - point[des][1],2) + pow(point[des + 1][2] - point[des][2],2) + pow(point[des+1][3] - point[des][3],2));
    }
    double l[4][1]={{518.8}, {605.8}, {509.5}, {530}};
    double alpha = 90*(M_PI)/180;
    double con = 63;
    double RR = 421;
    double dio[3][4]={{0,0,0,0}, {0,0,0,0}, {-1,-1,-1,-1}};
    double cio [3][4]={{1,0,-1,0}, {0,1,0,-1}, {0,0,0,0}};
    double B[3][4]={{-52.2,0,51.2,0}, {-93.82,107.99,-94.76,136.87}, {23.49,48.22,22.11,48.62}};
    double a[3][4]={{-304,-1.58,304,-4.36}, {-128.8,-303,-118.6,303}, {0,0,0,0}};
    double b[3][4]={0};
    double q[3][4]={0};
    double L[3][4]={0};
    double L_T[4][3]={0};
    double d[4]={0};
    double F1[4]={0};
    double F2[4]={0};
    double F3[4]={0};


    /***********************************************************/

     double P_X[100]={0};
     double P_Y[100]={0};
     double P_Z[100]={0};
     double Beta[100]={0};
     double P [100][3][1]={{0}};
     double D[100][4]={0};
     double p[3][1]={0};
     int m;
     int n=0;
     for(n=0;n<51;n++)
     {
       P_X[n] = point[n][0];
       P_Y[n] =  point[n][1];
       P_Z[n] =  point[n][2];
       Beta[n] = point[n][3];
       P[n][0][0]=P_X[n];
       P[n][1][0]= P_Y[n];
       P[n][2][0]= P_Z[n];
       Beta[n]= Beta[n]*(M_PI)/180;
       double R[3][3]={{1,0,0},{0,cos(Beta[n]),-sin(Beta[n])},{0,sin(Beta[n]),cos(Beta[n])}};
       p[0][0]=P_X[n];
       p[1][0]=P_Y[n];
       p[2][0]=P_Z[n];
       multiplyMatrices(R, B, b, 3, 3, 3, 4);
       b[2][0]+=16.84;;
                b[2][2]+=19.28;;

                for(int i=0;i<4;i++){
                        for ( int j=0;j<3;j++){

                            q[j][i]=p[j][0]+b[j][i];
                            L[j][i]=q[j][i]-a[j][i];
                            L_T[i][j]=L[j][i];



                        }
                }


                ColumnMultiplyer(L_T,dio,F1);
                ColumnMultiplyer(L_T,L,F2);
                ColumnMultiplyer(L_T,cio,F3);

                for(int s=0;s<4;s++){
                  d[s]=F1[s]-sqrt(pow(F1[s],2)-F2[s]+pow(l[s][0],2)-pow(con,2)+(2*con*F3[s]));
                  
       D [n][s]=d[s];
     }
     

    for (int ff=0; ff<4; ff++){
        F1[ff]=0;
        F2[ff]=0;
        F3[ff]=0;
    }

    m=n;

}

for (int k=1;k<bb+1;k++){
    for (int o=0; o<4;o++){
         delta[k][o]= round((abs(D[k][o])*100)-(abs(D[k-1][o])*100));
         Serial.println (delta[k][o]);
         
}
}
TCCR1A=0;//reset the register
TCCR1B=0;//reset tthe register


TCCR3A=0;//reset the register
TCCR3B=0;//reset tthe register


TCCR4A=0;//reset the register
TCCR4B=0;//reset tthe register


TCCR5A=0;//reset the register
TCCR5B=0;//reset tthe register



OCR1A=freq(abs(delta[1][0])/((vlc[0]/feedrate)*100));//control value
OCR5A=freq(abs(delta[1][1])/((vlc[0]/feedrate)*100));//control value
OCR4A=freq(abs(delta[1][2])/((vlc[0]/feedrate)*100));//control value
OCR3A=freq(abs(delta[1][3])/((vlc[0]/feedrate)*100));//control value
TCCR1A=0b01010011;// fast pwm mode
TCCR1B=0b00011001;// no prescaler and WGM02 is 1
TCCR3A=0b01010011;// fast pwm mode
TCCR3B=0b00011001;// no prescaler and WGM02 is 1
TCCR4A=0b01010011;// fast pwm mode
TCCR4B=0b00011001;// no prescaler and WGM02 is 1
TCCR5A=0b01010011;// fast pwm mode
TCCR5B=0b00011001;// no prescaler and WGM02 is 1

distance = delta[1][0];
distance2 = delta[1][1];
distance3 = delta[1][2];
distance4 = delta[1][3];
if(distance<0)
  {
    digitalWrite(53, LOW);
  }else
  {
    digitalWrite(53, HIGH);
  }


if(distance2<0)
  {
    digitalWrite(49, LOW);
  }else
  {
    digitalWrite(49, HIGH);
  }

  if(distance3<0)
  {
    digitalWrite(47, LOW);
  }else
  {
    digitalWrite(47, HIGH);
  }

  if(distance4<0)
  {
    digitalWrite(51, LOW);
  }else
  {
    digitalWrite(51, HIGH);
  }

fnc = false;
}


void refrence()
{ 

trigger = false; 
fnc = false;  
}


void loop() {

if(fnc == true)
{
inverkinematics();
}
Serial.print (x , DEC );
Serial.print ("," );
Serial.print (x2 , DEC );
Serial.print ("," );
Serial.print(x3 , DEC );
Serial.print ("," );
Serial.println (x4 , DEC );

}






void pid()
{

if(path1 && path2 && path3 && path4 == true)
  {
    buff = x;
    if (i == bb)
    {
      TCCR1A=0b00000000;// fast pwm mode
      TCCR1B=0b00000000;
      digitalWrite(53, LOW);
      
} else {
      i = i + 1;
      if(delta[i][0]<0)
  {
    digitalWrite(53, LOW);
  }else
  {
    digitalWrite(53, HIGH);
  }
      distance = delta[i][0] + buff ;
      OCR1A = freq(abs(delta[i][0])/((vlc[i-1]/feedrate)*100));
      
    }




    buff2 = x2;
    if (i2 == bb)
    {
      TCCR5A=0b00000000;// fast pwm mode
      TCCR5B=0b00000000;
      digitalWrite(49, LOW);
} else {
      i2 = i2 + 1;
      if(delta[i2][1]<0)
  {
    digitalWrite(49, LOW);
  }else
  {
    digitalWrite(49, HIGH);
  }
      distance2 = delta[i2][1] + buff2 ;
      OCR5A = freq(abs(delta[i2][1])/((vlc[i2-1]/feedrate)*100));
     
    }


    buff3 = x3;
    if (i3 == bb)
    {
      TCCR4A=0b00000000;// fast pwm mode
      TCCR4B=0b00000000;
      digitalWrite(47, LOW);
} else {
      i3 = i3 + 1;
      if(delta[i3][2]<0)
  {
    digitalWrite(47, LOW);
  }else
  {
    digitalWrite(47, HIGH);
  }
      distance3 = delta[i3][2] + buff3 ;
      OCR4A = freq(abs(delta[i3][2])/((vlc[i3-1]/feedrate)*100));

    }


    buff4 = x4;
    if (i4 == bb)
    {
      TCCR3A=0b00000000;// fast pwm mode
      TCCR3B=0b00000000;
      digitalWrite(51, LOW);
} else {
      i4 = i4 + 1;
      if(delta[i4][3]<0)
  {
    digitalWrite(51, LOW);
  }else
  {
    digitalWrite(51, HIGH);
  }
      distance4 = delta[i4][3] + buff4 ;
      OCR3A = freq(abs(delta[i4][3])/((vlc[i4-1]/feedrate)*100));

    }
    
path1 = false;
path2 = false;
path3 = false;
path4 = false;
  }   
}

















void increment1() {
  if(fnc == false)
  {
if (digitalRead(inPin1) == 1)
  {
    x++;
  } else {
    x--;
  }
if (distance == x)
  {
    OCR1A = freq(0);
    path1 = true;
    pid();
}


}
}






void increment2() {
  if(fnc == false)
  {
if (digitalRead(inPin2) == 1)
  {
    x2++;
  } else {
    x2--;
  }
if (distance2 == x2)
  {
    OCR5A = freq(0);
    path2 = true;
    pid();
}


}
}




void increment3() {
  if(fnc == false)
  {
if (digitalRead(inPin3) == 1)
  {
    x3++;
  } else {
    x3--;
  }
if (distance3 == x3)
  {
    OCR4A = freq(0);
    path3 = true;
    pid();
}


}
}




void increment4() {
  if(fnc == false)
  {
if (digitalRead(inPin4) == 1)
  {
    x4++;
  } else {
    x4--;
  }
if (distance4 == x4)
  {
    OCR3A = freq(0);
    path4 = true;
    pid();
}


}
}
