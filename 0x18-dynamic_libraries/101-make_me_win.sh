#!/bin/bash
wget -P .. https://raw.githubusercontent.com/KipruttoMutai/alx-low_level_programming/master/0x18-dynamic_libraries/liback.so
export LD_PRELOAD="PWD/../liback.so"
