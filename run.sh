#!/bin/bash

INPUT="teste.in"
BIN="./bin/ajustePol"

likwid-perfctr -C 3 -g FLOPS_DP -m $BIN < $INPUT | sed -n -e 6,9p
likwid-perfctr -C 3 -g FLOPS_DP -m $BIN < $INPUT | grep "MFLOP/s"
likwid-perfctr -C 3 -g ENERGY -m $BIN < $INPUT | grep "Energy \[J\]"
