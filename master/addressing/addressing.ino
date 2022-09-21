
#define firstpin 3
#define secondpin 5
#define thirdpin 7
#define fourthpin 9


void setup()
{
  pinMode(firstpin, OUTPUT);
  pinMode(secondpin, OUTPUT);
  pinMode(thirdpin, OUTPUT);
  pinMode(fourthpin, OUTPUT);
}

void loop()
{
  choosethird();
}

void choosefirst()
{
  digitalWrite(firstpin, 1);
  digitalWrite(secondpin, 1);
  digitalWrite(thirdpin, 1);
  digitalWrite(fourthpin, 1);
}

void choosesecond()
{
  digitalWrite(firstpin, 1);
  digitalWrite(secondpin, 0);
  digitalWrite(thirdpin, 0);
  digitalWrite(fourthpin, 0);
}

void choosethird()
{
  digitalWrite(firstpin, 1);
  digitalWrite(secondpin, 1);
  digitalWrite(thirdpin, 0);
  digitalWrite(fourthpin, 0);
}
