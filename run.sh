#!/bin/bash

BIN="./bin/ajustePol"
INPUT="pontos.in"

likwid-perfctr -C 3 -g "FLOPS_DP" -m $BIN < $INPUT | grep "MFLOP/s"
likwid-perfctr -C 3 -g "FLOPS_AVX" -m $BIN < $INPUT | grep "MFLOP/s"
likwid-perfctr -C 3 -g "ENERGY" -m $BIN < $INPUT | grep "Energy"
