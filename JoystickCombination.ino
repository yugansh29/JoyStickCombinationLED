const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
int Read[4];
int *head = Read;
int *tail = Read;
int ctr = 0;

int pass[]={1,-1,2,-2};

#define LED 13


void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(115200);


  pinMode(LED , OUTPUT);

}


void enqueue(int a){
  *tail = a;
  tail++;
  ctr++;
}

int dequeue(){
  return *head;
  head++;
  ctr--;
}

void resetQueue(){
  head -= 4;
  tail -= 4;
}

void loop() 
{
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(A0));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(A1));
  Serial.print("\n\n");
  

  delay(100);

// X_pin >= 1023 -> 1, <= 0 -> -1
// Y_pin >= 1023 -> 2, <= 0 -> -2
if(analogRead(X_pin)>=1023){
  enqueue(1);
}
if(analogRead(Y_pin)>=1023){
  enqueue(2);
}if(analogRead(X_pin)<=0){
  enqueue(-1);
}if(analogRead(Y_pin)<=0){
  enqueue(-2);
}

if(ctr == 4){
  if(dequeue() == pass[0] & dequeue() == pass[1] & dequeue() == pass[2] & dequeue() == pass[3]){
  digitalWrite(13,HIGH);
  resetQueue();
  }


}



  }