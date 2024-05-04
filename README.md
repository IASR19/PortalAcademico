
# Explicação do Código de Autenticação com Hash em C++


## 1. Incluir Bibliotecas
```
#include <iostream>
#include <unordered_map>
#include <vector>
#include <iomanip>
#include <openssl/sha.h> 
```

- iostream: Biblioteca para entrada/saída padrão.
- unordered_map: Estrutura de dados para mapeamento chave-valor.
- vector: Estrutura de dados para armazenar sequências dinâmicas.
- iomanip: Biblioteca para manipulação de formatação de saída.
- openssl/sha.h: Biblioteca OpenSSL para cálculo de hash SHA-256.

## 2. Função para Hash da Senha
```
string hashSenha(const string& senha) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, senha.c_str(), senha.length());
    SHA256_Final(hash, &sha256);
    
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}
```

- hashSenha: Função para calcular o hash SHA-256 da senha inserida pelo usuário.

## 3. Função para Verificar Senha
```
bool verificarSenha(const unordered_map<string, string>& usuarios, const string& nomeUsuario, const string& senha) {
    auto it = usuarios.find(nomeUsuario);
    if (it != usuarios.end()) {
        string senhaHashada = hashSenha(senha);
        return senhaHashada == it->second;
    }
    return false;
}
```
- verificarSenha: Função para verificar se a senha inserida está correta comparando o hash da senha inserida com o hash da senha armazenada no sistema.

## 4. Funções Principais do Sistema
```
void adicionarNota(unordered_map<string, vector<pair<string, float>>>& notasAlunos, const string& nomeAluno, const string& disciplina, float nota);
void marcarPresenca(unordered_map<string, unordered_map<string, bool>>& frequenciaProfessores, const string& nomeProfessor, const string& nomeAluno, bool presente);
void mostrarNotas(const unordered_map<string, vector<pair<string, float>>>& notasAlunos, const string& nomeAluno);
void mostrarFrequencia(const unordered_map<string, unordered_map<string, bool>>& frequenciaProfessores, const string& nomeProfessor);
```
- Funções principais para adicionar nota, marcar presença, mostrar notas e mostrar frequência.

## 5. Função Principal (main)
```
int main() {
    // Código principal do programa
    return 0;
}
```
- Função principal onde o programa inicia a execução.

## 6. Exemplo de Uso
```
// Exemplo de uso das funções e estruturas de dados
```
- Demonstração de como usar as funções e estruturas de dados para autenticação, adição de notas, presença, etc.