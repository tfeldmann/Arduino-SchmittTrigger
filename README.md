# Arduino-SchmittTrigger

[![tests](https://github.com/tfeldmann/Arduino-SchmittTrigger/actions/workflows/tests.yml/badge.svg)](https://github.com/tfeldmann/Arduino-SchmittTrigger/actions/workflows/tests.yml)

## Installation

```
pio lib install "tfeldmann/SchmittTrigger"
```

## Example usage:

Assumes you have a potentiometer connected to A0 and a led connected to `PIN_LED`.

This will turn `PIN_LED` on potentiometer readings higher than `900`.
On readings lower than `800` `PIN_LED` will be pulled `LOW`.
On readings between `800` and `900` the LED state persists.

```cpp
#include <SchmittTrigger.h>

// 800 is the switch off point
// 900 is the switch on point
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
```
