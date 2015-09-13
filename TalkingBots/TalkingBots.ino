//
#include <string>
const int MAX_RESP = 3;

void copy( char *array[], char *v );
void preprocess_input( char *str );
void UpperCase( char *str );
void cleanString( char *str );
bool isPunc(char c);

typedef struct {
	char *input;
	char *responses[MAX_RESP];
}record;


int phrase1 = 0;
double tempC = 0;
String message;
String recieved;
bool canSend = false;
EventHandler eventHandler = handler;
String sInput;
String text;

int led1 = A0; 
int led2 = D0;

void handler(const char* event, const char* data){
        
        digitalWrite(led2, HIGH);
        delay(1000);
        digitalWrite(led2, LOW);
        delay(1000);
        canSend = true;
        recieved = data;
}

void setup()
{
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    
     digitalWrite(led1, HIGH);
    if(System.deviceID() == "51ff6e065082554906351387"){
        
        Spark.subscribe("message", eventHandler, "54ff6f066678574939320667");
        text = "GRAPE";
    }
    else{
         digitalWrite(led2, HIGH);
        delay(1000);
        digitalWrite(led2, LOW);
        delay(1000);
        Spark.subscribe("message", eventHandler, "51ff6e065082554906351387");
        text = "Pineapple";
    }
    //just checks if its connected to the cloud
	if(!canSend){
	    Spark.publish("message","Hi there!");
	}
  // We'll leave it on for 1 second...
  delay(1000);

  // Then we'll turn it off...
  digitalWrite(led1, LOW);

  delay(1000);
	    //delay(1000);
}

void loop()
{
    if(canSend){
        
		message = text + "says hello";
		Spark.publish("message", message);
		
        digitalWrite(led1, HIGH);
		delay(1000);
        digitalWrite(led1, LOW);
        delay(1000);
        canSend = false;
    }
    delay(random(3000)+3000);
}

void kill_program(){
    
    System.reset();
}
