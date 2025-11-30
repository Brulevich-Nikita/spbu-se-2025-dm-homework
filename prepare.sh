#!/bin/bash

# Компиляция решений на C
for i in 1 2 3 4 5
do
    SRC="solutions/solution-0$i.c"
    OUT="solutions/solution-0$i"

    if [ -f "$SRC" ]; then
        echo "Compiling $SRC → $OUT"
        gcc "$SRC" -O2 -std=c11 -o "$OUT"
        chmod +x "$OUT"
    fi
done
