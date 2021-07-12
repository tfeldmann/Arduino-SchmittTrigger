# Arduino-SchmittTrigger

[![CI](https://github.com/tfeldmann/Arduino-SchmittTrigger/actions/workflows/test.yml/badge.svg)](https://github.com/tfeldmann/Arduino-SchmittTrigger/actions/workflows/test.yml)

# Usage:

```cpp
include <schmitt_trigger.h>

SchmittTrigger<int> st(800, 900);

void setup() {}

void loop() {
    st.input(analogRead(A0));
    digitalWrite(PIN_LED, st.output());
}
```
