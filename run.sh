#!/bin/bash

(time ./bin/Release/GeneticAlgorithm input/eil76_n75_bounded-strongly-corr_01.ttp) 2>&1 | grep real
