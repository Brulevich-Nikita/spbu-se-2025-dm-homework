#!/bin/bash

# Скрипт подготовки решений перед тестированием
# Компилирует все решения C и делает их исполняемыми

for i in {1..5}; do
    src="solutions/solution-0$i.c"
    exe="solutions/solution-0$i"

    if [ -f "$src" ]; then
        gcc -o "$exe" "$src"
        chmod +x "$exe"
    fi
done
