# GeneticAlgorithm

Genetic algorithm implemented in C++ object-oriented<br>
Project uses IDE codeblocks
<br>
<b>Requirements</b>: Need C++ 11 or higher<br>
<b>How to compile?</b> Open a window in the terminal and execute the make command
<br>
<b>How to run?</b> ./bin/Release/GeneticAlgorithm input/input_file MAX_TIME SEED<br>
<b>How is the code organized?</b><br>
<p>The /src is where all the basic source codes of the genetic algorithm are, including abstract classes and default implementations.</p>
<p>The /input is where the input files are dependent on the problem being solved</p>
<p>In the /include folder should be all files added to the basic source code /src or all derived classes implemented</p>

<p>The algorithm implementation is being used to address the traveling thief problem, however the code can be adapted to solve any problem. Simply extend the classes and make the necessary adaptations</p>

<b>How to adapt the code to a new problem?</b>


----------


<b>Como está organizado o código?</b>
<br>
<b>Configures.h</b>
Contém todas configurações e parâmetros necessários no código. Pode ser acessado de qualquer classe.

<b>Crossover.h</b><br>
Classe abstrata responsável pelo cruzamento dos indivíduos. Você deve estender essa classe e implementar sua função de cruzamento, a qual recebe um vetor de indivíduos e seu tamanho.<br><br>

<pre>void cross(Individual ** vec_individuos, int num_individuos);</pre>
<br>
<b>Database.h</b>
Classe abstrata de dados responsável pelos dados utilizados pelo AG. caso você use leitura de arquivos diferentes do formato padrão você deve estender a função loadBase conforme sua necessidade.<br><br>
 
<pre>void loadBase(string base_name);</pre><br>

onde base_name é o nome do arquivo de entrada<br><br>

<b>Individual.h</b><br>
Classe abstrata com a representação do indivíduo. Possui atributo aptidão, o qual indica o quão apto está minha solução/individuo. Essa classe deve ser estendida conforme a necessidade do problema a ser resolvido.<br><br>

<b>IndividualBuilder.h</b><br>
Classe abstrata responsável pela criação de um indivíduo. Quando criado um novo indivíduo também deve ser criado um individuoBuilder responsável pela sua geração.<br><br>

<pre>Individual * generateIndividuo();</pre>

<b>IndividualSelector.h</b><br>
Classe abstrata responsável pela seleção dos indivíduos da população para cruzamento e mutação.<br>

Individual * selects(Individual ** pop);<br><br>

<b>LocalSearch.h</b><br>
Classe abstrata responsável por realizar busca local/ ajuste de parâmetros em um dado indivíduo. Deve ser estendida conforme o tipo de indivíduo do problema.
<br><br>
<b>Mutation.h</b><br><br>
Classe abstrata responsável pela mutação de um dado indivíduo.  Deve ser estendida conforme o tipo de indivíduo do problema.<br><br>
<b>Parser.h</b><br>
Classe abstrata responsável por avaliar a qualidade de uma solução/individuo. Também  deve ser estendida conforme o tipo de indivíduo do problema.
<br><br>

<b>PopulationReplacement.h</b><br>
Classe abstrata responsável pela junção dos indivíduos da antiga população com a nova população do AG. Pode ser estendida conforme características do problema.<br><br>

<b>SearchEngine.h</b><br>
Parte central do Algoritmo Genético, essa classe é responsável por fazer as chamadas dos operadores genéticos e por guiar todo o processo de busca.O método void Evolve(); é responsável por evoluir uma população de soluções com as características setadas em SearchEngine e com os parâmetros setados no arquivo de configuração Configures.h. Essa classe possui diversos métodos sets para setar classes que foram estendidas segundo características do problema:<br><br>
<pre>
void setCrossover(Crossover * opCrossover);
void setMutation(Mutation * opMutation);
void setIndividualBuilder(IndividualBuilder * indBuilder);
void setPopulationReplace(PopulationReplacement * popReplace);
void setParser(Parser * parser);
void setSelection(IndividualSelector * seletor);
void setLocalSearch(LocalSearch * localSearch);
</pre>
