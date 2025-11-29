#!/bin/bash
set -e

SOL_DIR="solutions"

for file in $SOL_DIR/*.c; do
    base=$(basename "$file" .c)
    out="$SOL_DIR/$base"
    echo "Компиляция $file → $out"
    gcc "$file" -O2 -std=c11 -o "$out"
done

echo "Готово!"
