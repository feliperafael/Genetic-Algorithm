#!/bin/bash

t=180

for i in `seq 10 14`;
do
	./bin/Release/GeneticAlgorithm input/eil51-ttp/eil51_n50_bounded-strongly-corr_01.ttp 180 $i
done
echo input/eil51-ttp/eil51_n50_bounded-strongly-corr_01.ttp

for i in `seq 10 14`;
do
	./bin/Release/GeneticAlgorithm input/eil51-ttp/eil51_n50_bounded-strongly-corr_02.ttp 180 $i
done
echo input/eil51-ttp/eil51_n50_bounded-strongly-corr_02.ttp

for i in `seq 10 14`;
do
	./bin/Release/GeneticAlgorithm input/eil51-ttp/eil51_n50_bounded-strongly-corr_05.ttp 180 $i	
done
echo input/eil51-ttp/eil51_n50_bounded-strongly-corr_05.ttp
