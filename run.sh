#!/bin/bash

BIN="./bin/ajustePol"

INPUT="pontos.in"
OUTPUT="resultado.out"

likwid-perfctr -C 3 -g FLOPS_DP -m $BIN < $INPUT > $OUTPUT # | grep "DP MFLOP/s" | awk '{print $5}' | grep -v "|"

echo "Relatório gerado em $OUTPUT"
