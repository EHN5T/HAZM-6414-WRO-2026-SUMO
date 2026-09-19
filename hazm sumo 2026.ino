
int MSens = 10;
int LFSens = 8;
int RFSens = 11;
int RSens = 12;
int LSens = 7;

//// Line Sensors

int LEdge = A3;
int REdge = A2;
int BEdge = A0;//// Motors

int LPwm = 3 ;
int RPwm = 6;
int REn = A1;
int LEn =5;

//// Switches

int DS1 = 0;
int DS2 = 1;
int DS3 = 2;
int StartModule = 4;
int Buzzer = A5;
int StartSwitch = 9;
void setup() {

pinMode(LPwm,OUTPUT);
pinMode(RPwm,OUTPUT);
pinMode(REn,OUTPUT);
pinMode(LEn,OUTPUT);
pinMode(LSens,INPUT);
pinMode(LFSens,INPUT);
pinMode(MSens,INPUT);
pinMode(RFSens,INPUT);
pinMode(RSens,INPUT);
pinMode(StartModule,INPUT);
pinMode(StartSwitch,INPUT);
pinMode(LEdge,INPUT);
pinMode(REdge,INPUT);
pinMode(BEdge,INPUT);
pinMode(Buzzer,OUTPUT);
pinMode(DS1,INPUT);
pinMode(DS2,INPUT);
pinMode(DS3,INPUT);
digitalWrite(LSens,HIGH);
digitalWrite(LFSens,HIGH);
digitalWrite(MSens,HIGH);
digitalWrite(RFSens,HIGH);
digitalWrite(RSens,HIGH);
digitalWrite(StartSwitch,HIGH);

digitalWrite(DS1,HIGH);
digitalWrite(DS2,HIGH);
digitalWrite(DS3,HIGH);

}
void ileri(){
digitalWrite(3,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(A1,HIGH);
}
void geri(){
digitalWrite(5,HIGH);
digitalWrite(3,LOW);
digitalWrite(A1,LOW);
digitalWrite(6,HIGH);
}
void sol(){
digitalWrite(5,HIGH);
digitalWrite(3,LOW);
digitalWrite(6,LOW);
digitalWrite(A1,HIGH);
}
void sag(){
digitalWrite(3,HIGH);
digitalWrite(5,LOW);
digitalWrite(A1,LOW);
digitalWrite(6,HIGH);
}
void dur(){
digitalWrite(3,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(A1,LOW);
}
void loop() {
taktik :

if(digitalRead(StartSwitch) == LOW || digitalRead(StartModule)== LOW ){
 for (int i=0; i <= 5; i++){
    tone(A5, 523, 300);
  delay(300);
  noTone(A5);
  delay(400);
  }
if(digitalRead(DS1)==LOW  && digitalRead(DS2)==HIGH  && digitalRead(DS3)==HIGH   ){
  sol();
  delay(140);
   goto Start;
}
if(digitalRead(DS1)==HIGH  && digitalRead(DS2)==HIGH  && digitalRead(DS3)==LOW ){
  sag();
   delay(140);
  goto Start;
}
if(digitalRead(DS1)==HIGH  && digitalRead(DS2)==LOW && digitalRead(DS3)==HIGH   ){
    ileri();
    delay(50);
   goto Start;
}
if(digitalRead(DS1)==LOW && digitalRead(DS2)==LOW && digitalRead(DS3)==HIGH   ){
  sol();
  delay(100);
  ileri();
  delay(300);
  sag();
  delay(200);
  goto Start;
}
if(digitalRead(DS1)==HIGH  && digitalRead(DS2)==LOW && digitalRead(DS3)==LOW  ){
   sag();
  delay(100);
  ileri();
  delay(300);
  sol();
  delay(200);
 
  goto Start;
}
if(digitalRead(DS1)==LOW && digitalRead(DS2)==HIGH  && digitalRead(DS3)==LOW  ){
  sag();
  delay(400);
  ileri();
  delay(20);
  goto Start;
}
if(digitalRead(DS1)==HIGH  && digitalRead(DS2)==HIGH && digitalRead(DS3)==HIGH  ){
  geri();
  delay(100);

  goto Start;
}else{
dur();
}
}else{
if(digitalRead(LSens)==HIGH && digitalRead(LFSens)==HIGH && digitalRead(MSens)==HIGH && digitalRead(RFSens)==HIGH && digitalRead(RSens)==HIGH ){
   noTone(A5);
    dur();
}else{
 tone(A5, 523, 1);
}
}
goto taktik ;

Start :

if(analogRead(REdge)<500 && analogRead(LEdge)>500 ){
geri();
 delay(300);
sol();
 delay(200);
}else
if(analogRead(LEdge)<500 && analogRead(REdge)>500  ){
  geri();
 delay(300);
sag();
 delay(200);
}else
if( digitalRead(MSens)==LOW ){
ileri();
}else
if( digitalRead(LFSens)==LOW ){
sol();
}else
if( digitalRead(RFSens)==LOW ){
 sag();
}else
if( digitalRead(LSens)==LOW ){
 sol();
}else
if( digitalRead(RSens)==LOW ){
 sag();
}else
{
ileri();
}

goto Start;

}

