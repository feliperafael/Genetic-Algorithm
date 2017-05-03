#
all: create_folders 
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c include/City.cpp -o obj/Release/include/City.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c include/Item.cpp -o obj/Release/include/Item.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c include/TravelingThiefCrossover.cpp -o obj/Release/include/TravelingThiefCrossover.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c include/TravelingThiefDatabase.cpp -o obj/Release/include/TravelingThiefDatabase.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c include/TravelingThiefIndividual.cpp -o obj/Release/include/TravelingThiefIndividual.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c include/TravelingThiefIndividualBuilder.cpp -o obj/Release/include/TravelingThiefIndividualBuilder.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c include/TravelingThiefLocalSearch.cpp -o obj/Release/include/TravelingThiefLocalSearch.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c include/TravelingThiefMutation.cpp -o obj/Release/include/TravelingThiefMutation.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c include/TravelingThiefParser.cpp -o obj/Release/include/TravelingThiefParser.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c main.cpp -o obj/Release/main.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c src/Configures.cpp -o obj/Release/src/Configures.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c src/Crossover.cpp -o obj/Release/src/Crossover.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c src/Database.cpp -o obj/Release/src/Database.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c src/Individual.cpp -o obj/Release/src/Individual.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c src/IndividualBuilder.cpp -o obj/Release/src/IndividualBuilder.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c src/IndividualSelector.cpp -o obj/Release/src/IndividualSelector.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c src/LocalSearch.cpp -o obj/Release/src/LocalSearch.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c src/Mutation.cpp -o obj/Release/src/Mutation.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c src/Parser.cpp -o obj/Release/src/Parser.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c src/PopulationReplacement.cpp -o obj/Release/src/PopulationReplacement.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c src/SearchEngine.cpp -o obj/Release/src/SearchEngine.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c src/SimpleCrossover.cpp -o obj/Release/src/SimpleCrossover.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c src/SimpleIndividual.cpp -o obj/Release/src/SimpleIndividual.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c src/SimpleIndividualBuilder.cpp -o obj/Release/src/SimpleIndividualBuilder.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c src/SimpleIndividualSelector.cpp -o obj/Release/src/SimpleIndividualSelector.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c src/SimpleMutation.cpp -o obj/Release/src/SimpleMutation.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c src/SimpleParser.cpp -o obj/Release/src/SimpleParser.o
	g++ -O3 -Wall -fexceptions -std=c++11 -fopenmp -fopenmp -Isrc -Iinclude -c src/SimpleReplacement.cpp -o obj/Release/src/SimpleReplacement.o

	g++  -o bin/Release/GeneticAlgorithm obj/Release/include/City.o obj/Release/include/Item.o obj/Release/include/TravelingThiefCrossover.o obj/Release/include/TravelingThiefDatabase.o obj/Release/include/TravelingThiefIndividual.o obj/Release/include/TravelingThiefIndividualBuilder.o obj/Release/include/TravelingThiefLocalSearch.o obj/Release/include/TravelingThiefMutation.o obj/Release/include/TravelingThiefParser.o obj/Release/main.o obj/Release/src/Configures.o obj/Release/src/Crossover.o obj/Release/src/Database.o obj/Release/src/Individual.o obj/Release/src/IndividualBuilder.o obj/Release/src/IndividualSelector.o obj/Release/src/LocalSearch.o obj/Release/src/Mutation.o obj/Release/src/Parser.o obj/Release/src/PopulationReplacement.o obj/Release/src/SearchEngine.o obj/Release/src/SimpleCrossover.o obj/Release/src/SimpleIndividual.o obj/Release/src/SimpleIndividualBuilder.o obj/Release/src/SimpleIndividualSelector.o obj/Release/src/SimpleMutation.o obj/Release/src/SimpleParser.o obj/Release/src/SimpleReplacement.o  -s -lgomp -pthread

create_folders:
	mkdir obj
	mkdir obj/Release
	mkdir obj/Release/src
	mkdir obj/Release/include
	mkdir bin
	mkdir bin/Release

clean:
	rm -rf obj/
	rm -rf bin/

