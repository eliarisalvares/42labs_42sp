# Processo de Seleção para o 42Labs

<p align="center">
  <img src="https://creazilla-store.fra1.digitaloceanspaces.com/cliparts/79332/coding-clipart-md.png" width="320" height="110"/></p>

# API

Uma API de tipo RESTful que usa restrições HTTP para extrair dados dados da BoredAPI, uma API que faz sugestões divertidas de atividades aleatórias para quando se está entediado. O retorno da requisição do tipo "GET" está no formato JSON  e tem status HTTP *200 OK.* Todos os logs com data e status HTTP são automaticamente armazenados no arquivo "log.txt".

## Como usar

**COMPILAÇÃO:**
 - [ ] 'git clone https://github.com/42sp/42labs-selection-process-v2-eliarisalvares';
 - [ ] 'cd ./42labs-selection-process-v2-eliarisalvares';
 - [ ] 'cd ./API'
 - [ ] 'make';

 **EXECUÇÃO**

Comece a execução digitando './activity'.  Se a seguinte mensagem for exibida
  <p align="center">"Framework initialized - PORT 8080. Go to your browser and type 'localhost:8080'": </p>

Vá até o seu navegador e acesse localhost:8080. O retorno será exibido no terminal e um arquivo de tipo .txt será criado na pasta "API". A cada vez que a página for acessada/recarregada, uma nova lista de atividades será exibida no terminal e armazenada no arquivo "log.txt".

⚠️ A maioria dos erros na inicialização do Framework ocorrem quando já existe um terminal executando a "./activity".

# Aplicação CLI
A aplicação CLI exibe no terminal: hora da requisição, status HTTP, corpo do retorno e número total de requisições "GET".

## Como usar

**COMPILAÇÃO:**
 - [ ] 'git clone https://github.com/42sp/42labs-selection-process-v2-eliarisalvares';
 - [ ] 'cd ./42labs-selection-process-v2-eliarisalvares';
 - [ ] 'cd ./CLI'
 - [ ] 'make';

:warning: É necessário que a API esteja em execução ou tenha sido executada, ou seja, que o arquivo "log.txt" exista para que os logs sejam exibidos. Caso contrário, uma mensagem de erro será retornada.

**EXECUÇÃO**

Comece a execução digitando './cli'. Então, para que os logs sejam exibidos, digite "logs". Para sair, digite "close".

# :toolbox: Ferramentas utilizadas

:small_orange_diamond: **ULFIUS**

Ulfius é uma framework de REST API escrita em C. É possível utilizá-la para criar serviços web de maneira fácil. Neste projeto, ela foi utilizada para permitir a conexão localhost na porta 8080. Usando as funções da biblioteca ulfius em conjunto com a libcurl foi possível iniciar o framework, realizar requisição de tipo HTTP GET e retornar o corpo da resposta da requisição.

:small_orange_diamond: **LIBCURL**

A libcurl é uma biblioteca de transferência de URL do lado do cliente  para aplicações escritas em C gratuita e fácil de usar. Ela foi escolhida sobre a Mangoose pela facilidade de se encontrar informações e tutoriais sobre seu uso para APIs em C. A libcurl permite receber e processar com facilidade o conteúdo do corpo e do header da requisição através da função curl_easy_setopt().

:small_orange_diamond: **GET_NEXT_LINE**

O get_next_line foi meu segundo projeto do cursus da 42. Se mostrou interessante para a aplicação CLI. O board da função original pode ser acessado através do seguinte link: https://miro.com/app/board/o9J_ly1mdHE=/.

:small_orange_diamond: **GITHUB PROJECTS**

<p align="center"><img src="https://user-images.githubusercontent.com/85964972/155887844-0dd6594e-d28c-4735-935d-5858a8521e73.png" width="420" height="197.1"/></p>

GitHub Projects é uma ferramenta de organização que permite gerenciar projetos e atribuir tarefas.

:small_orange_diamond: **DOCKER**

Docker é uma plataforma de conteinerização de código aberto. Permite aos programadores empacotar aplicações em contêineres - componentes executáveis padronizados que combinam o código fonte da aplicação com as bibliotecas do sistema operacional ( OS ) e as dependências necessárias para executar esse código em qualquer ambiente.

Para usar o Docker é necessário digitar e rodar o comando **'docker build . -t image ; docker run -it image'** em cada uma das pastas das aplicações ("./42labs-selection-process-v2-eliarisalvares/API" e "./42labs-selection-process-v2-eliarisalvares/CLI").

:small_orange_diamond: **GITHUB ACTIONS**

GitHub Actions é uma plataforma de integração e entrega contínua (CI/CD) que permite automatizar o pipeline de construção, teste e implementação. Pode criar fluxos de trabalho que constroem e testam cada pull request para o repositório, ou fazer o deploy de merged pull requests.

<p align="center">
 <img src="https://github.com/42sp/42labs-selection-process-v2-eliarisalvares/actions/workflows/norminette.yml/badge.svg"></p>

:small_orange_diamond: **DOXYGEN**

Doxygen é uma excelente ferramenta para documentação de funções. Usa uma formatação específica, para, através de uma extensão, identificar e extrair informações passadas por comentários. A partir disso, permite a visualização da documentação das funções do usuário em qualquer parte do código. Nesse projeto, o Doxygen é sempre usado nos arquivos ".h".

<p align= "center"><img src="https://user-images.githubusercontent.com/85964972/155901939-7cbb7941-3bb2-4695-8e25-f37101d210c5.png" width="157" height="92"></p>

## :red_circle: Problemas

A intenção inicial era que o retorno da "Bored API" fosse exibido em "https://localhost:8080". Acredito que seria possível através da formação de um banco de dados em conjunto com a função "ulfius_set_string_body_response()" da biblioteca Ulfius. Não houve tempo hábil para a implementação de um banco de dados, o que gerou o inconveniente de que a resposta é gerada através do navegador, mas exibida no terminal e armazenada no arquivo "log.txt".

# :floppy_disk: Referências

**WSL**

* "Configurar um ambiente de desenvolvimento WSL" (https://docs.microsoft.com/pt-br/windows/wsl/setup/environment#set-up-your-linux-username-and-password).

**APIs e REST APIs**

* "API // Dicionário do Programador" (https://www.youtube.com/watch?v=vGuqKIRWosk);
* "REST x SOAP: entenda a diferença de uma vez por todas!" (https://www.youtube.com/watch?v=YWPT2UOxbUg);
* "API REST" (https://www.redhat.com/pt-br/topics/api/what-is-a-rest-api).

**BORED API**

* "About Bored API" (https://www.boredapi.com/about).

**PUBLIC APIS**

* "Public APIs: A collective list of free APIs for use in software and web development" (https://github.com/public-apis/public-apis#news).

**DOCKERFILE**

* "What is Dockerfile | How to create and build Dockerfile | Dockerfile Basic Commands" (https://www.youtube.com/watch?v=LQjaJINkQXY);
* "Docker Docs: docker build" (https://docs.docker.com/engine/reference/commandline/build/);
* "What is build-essential Ubuntu, how to install and use it?" (https://linuxhint.com/install-build-essential-ubuntu/).

**LIBCURL**

* "Easy Networking in C (libcurl)" (https://www.youtube.com/watch?v=daA-KBKfJ_o);
* "libcurl video tutorial: simplest" (https://www.youtube.com/watch?v=Uha3JGPRIQs);
* "How to approach and use libcurl as an absolute beginner" (https://www.youtube.com/watch?v=ItbpJ51VvS0&list=PLR3hK5bvJmWqz1UI-AgV3ZWLnZUQntcnv&index=2);
* "Make an HTTP Request with the C Programming Language" (https://www.youtube.com/watch?v=x2PaEz1URso);
* "Libcurl Overview" (https://curl.se/libcurl/).

**ULFIUS**

* "Ulfius" (https://babelouest.io/ulfius/);
* "Ulfius API Documentation" (https://babelouest.github.io/ulfius/).

**GITHUB ACTIONS**

* "Learn GitHub Actions" (https://docs.github.com/en/actions/learn-github-actions).

**ARQUIVO LOG**

* "Redirecting standard output in C" (https://www.youtube.com/watch?v=5fnVr-zH-SE);
* "printf(3) — Linux manual page" (https://man7.org/linux/man-pages/man3/printf.3.html).
