#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11); // RX, TX
#include <math.h>

#define mx 345
#define my 345
#define lmy 350


int XR_pin = A3;     
int YR_pin = A4;
int Left = A2;

int flag=0;
char trans;

void setup()
{
  Serial.begin(9600);  
  mySerial.begin(9600);    //  setup serial
}

void loop()
{
  int X_Rval = analogRead(XR_pin);
  int Y_Rval = analogRead(YR_pin);
  int Lval = analogRead(Left); 
  
  
  
  int dx =abs( X_Rval - mx);
  int dy =abs( Y_Rval - my);
  int ldy=abs( Lval - lmy);
  if((Lval<(lmy+40) && Lval>(lmy-30) )&& flag==0)
  {
  if(dx<dy )
  {
    if( Y_Rval>(my-20) && Y_Rval<(my+30) )
    {
      trans='n';
      
    }
    else if(Y_Rval<my)
    {
      
     //if(dy<40){
        
         trans='f';
     //}
     // else {
       // trans='g';
      //}
      
    }
    else if(Y_Rval>my)
    {trans='b';
    }
  }
  else
  {
    if( X_Rval>(mx-30) && X_Rval<(mx+30) )
    {
      trans='o';    //110
    }
     else if(X_Rval<mx)
    {
      trans='r'; //102
    }
    else if(X_Rval>mx)
    {
      trans='l';//102
    }
  }
  }
  else if( (Lval>(lmy+40) )&& flag==0){
    
    trans='p';flag=1;
    
  }
  else if( Lval>(lmy+30) && flag==1){
     
  if(dx<dy )
  {
    if( Y_Rval>(my-20) && Y_Rval<(my+20) )
    {
      trans='n';    //110
    }
    else if(Y_Rval<my)
    {
      
      //if(dy<50)
         trans='f'; //102
      //else 
       //trans='g';
      
    }
    else if(Y_Rval>my)
    {
         trans='b'; //98 
    }
  }
  else
  {
    if( X_Rval>(mx-20) && X_Rval<(mx+20) )
    {
      trans='o';    //110
    }
     else if(X_Rval<mx)
    {
      trans='r'; //102
    }
    else if(X_Rval>mx)
    {
      trans='l'; //102
    }
  }   
  }
  else if(Lval<(lmy+30) && flag==1)//(Lval<(lmy-30) )&& flag==1)
  {
    
    trans='q';
    flag=0;
  }
  
 mySerial.write(trans); 
      Serial.print(flag); 
            Serial.print("\t");
                  Serial.println(trans);
}
