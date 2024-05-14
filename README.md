
# Portal Acadêmico
O Portal Acadêmico é um sistema de gerenciamento acadêmico simples desenvolvido em C++ como parte de um projeto acadêmico. Ele permite o registro de notas e frequência para alunos, bem como a consulta desses registros.

## Funcionalidades
Autenticação de usuários (professores e alunos) usando nome de usuário e senha.
Registro de notas pelos professores para cada aluno.
Registro de frequência (presença/ausência) pelos professores para cada aluno.
Consulta de notas e frequência pelos alunos após o login.
Pré-requisitos
Certifique-se de ter o compilador C++ instalado no seu sistema. Este projeto também depende da biblioteca Crypto++ para algumas operações de autenticação.

### Compilação e Execução
Navegue até o diretório do projeto:
```
cd PortalAcademico
```
Compile o código-fonte:
```
g++ -o PortalAcademico main.cpp authentication.cpp student.cpp -lcryptopp
```
Execute o programa:
```
./PortalAcademico
```
Siga as instruções no terminal para autenticar-se como professor ou aluno e usar as funcionalidades do sistema.

## Exemplo de Uso
### Como Professor:

Faça login com seu nome de usuário e senha.
Registre notas para cada aluno usando a opção correspondente no menu.
Registre a frequência (presença/ausência) dos alunos usando a opção correspondente no menu.

### Como Aluno:

Faça login com seu nome de usuário e senha.
Consulte suas notas e frequência usando a opção correspondente no menu.