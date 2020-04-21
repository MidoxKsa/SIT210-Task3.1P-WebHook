int analogvalue = 0;


void setup()
{
  pinMode(A0, INPUT);
  Particle.subscribe("hook-response/get_temp", myHandler, MY_DEVICES);
}

void myHandler(const char *event, const char *data) {
  // Handle the webhook response
}

void loop()
{ 

  // Read the analog value of the sensor
  analogvalue = analogRead(A0);
  //Convert the reading into degree
  String temp = String(int(analogvalue*0.0115183246));
  
  Particle.publish("temp", temp, PRIVATE);
  delay(30000);
}
