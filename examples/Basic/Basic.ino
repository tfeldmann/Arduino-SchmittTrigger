#include <SchmittTrigger.h>

SchmittTrigger<int> st(800, 900);

void setup()
{
  pinMode(PIN_LED, OUTPUT);
}

void loop()
{
  st.input(analogRead(A0));
  digitalWrite(PIN_LED, st.output());
}
