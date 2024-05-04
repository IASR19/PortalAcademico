#include <iostream>
#include <unordered_map>
#include <vector>
#include <iomanip>
#include <openssl/sha.h>

using namespace std;

// Função para hash da senha usando SHA-256
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

// Função para verificar se a senha inserida está correta
bool verificarSenha(const unordered_map<string, string>& usuarios, const string& nomeUsuario, const string& senha) {
    auto it = usuarios.find(nomeUsuario);
    if (it != usuarios.end()) {
        string senhaHashada = hashSenha(senha);
        return senhaHashada == it->second;
    }
    return false;
}

// Função para adicionar notas para um aluno
void adicionarNota(unordered_map<string, vector<pair<string, float>>>& notasAlunos, const string& nomeAluno, const string& disciplina, float nota) {
    notasAlunos[nomeAluno].push_back(make_pair(disciplina, nota));
}

// Função para marcar a presença de um aluno
void marcarPresenca(unordered_map<string, unordered_map<string, bool>>& frequenciaProfessores, const string& nomeProfessor, const string& nomeAluno, bool presente) {
    frequenciaProfessores[nomeProfessor][nomeAluno] = presente;
}

// Função para mostrar as notas de um aluno
void mostrarNotas(const unordered_map<string, vector<pair<string, float>>>& notasAlunos, const string& nomeAluno) {
    auto it = notasAlunos.find(nomeAluno);
    if (it != notasAlunos.end()) {
        cout << "Notas do aluno " << nomeAluno << ":" << endl;
        for (const auto& par : it->second) {
            cout << par.first << ": " << fixed << setprecision(1) << par.second << endl;
        }
    } else {
        cout << "Aluno nao encontrado." << endl;
    }
}

// Função para mostrar a frequência registrada por um professor
void mostrarFrequencia(const unordered_map<string, unordered_map<string, bool>>& frequenciaProfessores, const string& nomeProfessor) {
    auto it = frequenciaProfessores.find(nomeProfessor);
    if (it != frequenciaProfessores.end()) {
        cout << "Frequencia registrada pelo professor " << nomeProfessor << ":" << endl;
        for (const auto& par : it->second) {
            cout << par.first << ": " << (par.second ? "Presente" : "Ausente") << endl;
        }
    } else {
        cout << "Professor nao encontrado." << endl;
    }
}

int main() {
    unordered_map<string, string> usuarios; // Mapa de (nome de usuario, senha hashada)
    usuarios["joao"] = hashSenha("senha123");
    usuarios["maria"] = hashSenha("senha456");

    unordered_map<string, vector<pair<string, float>>> notasAlunos; // Mapa de (nome do aluno, vetor de (disciplina, nota))
    unordered_map<string, unordered_map<string, bool>> frequenciaProfessores; // Mapa de (nome do professor, mapa de (nome do aluno, presença))

    // Exemplo de uso
    string nomeUsuario, senha;
    cout << "Digite seu nome de usuario: ";
    cin >> nomeUsuario;
    cout << "Digite sua senha: ";
    cin >> senha;

    if (verificarSenha(usuarios, nomeUsuario, senha)) {
        cout << "Login realizado com sucesso!" << endl;
        string nomeAluno = "joao"; // Exemplo: Aluno Joao está logado
        string nomeProfessor = "maria"; // Exemplo: Professor Maria está logado

        // Adicionar notas para o aluno
        adicionarNota(notasAlunos, nomeAluno, "Matematica", 8.5);
        adicionarNota(notasAlunos, nomeAluno, "Fisica", 7.0);

        // Marcar presença para o aluno
        marcarPresenca(frequenciaProfessores, nomeProfessor, nomeAluno, true);
        marcarPresenca(frequenciaProfessores, nomeProfessor, nomeAluno, false);

        // Mostrar informações
        mostrarNotas(notasAlunos, nomeAluno);
        mostrarFrequencia(frequenciaProfessores, nomeProfessor);
    } else {
        cout << "Nome de usuario ou senha incorretos." << endl;
    }

    return 0;
}
