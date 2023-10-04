#!/bin/bash

likwid-perfctr -C 3 -g FLOPS_DP -m ./bin/ajustePol < pontos.in # | grep "DP MFLOP/s" | awk '{print $5}' | grep -v "|"
