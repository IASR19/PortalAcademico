#include <iostream>
#include <string>
#include <cryptopp/cryptlib.h>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>

using namespace std;
using namespace CryptoPP;

string hashSenha(const string& senha) {
    SHA256 hash;
    byte digest[SHA256::DIGESTSIZE];
    hash.Update((const byte*)senha.data(), senha.size());
    hash.Final(digest);

    string hash_str;
    HexEncoder encoder(new StringSink(hash_str));
    encoder.Put(digest, sizeof(digest));
    encoder.MessageEnd();

    return hash_str;
}

bool verificarSenha(const string& senhaArmazenada, const string& senhaInserida) {
    return hashSenha(senhaInserida) == senhaArmazenada;
}

int main() {
    string senhaArmazenada = hashSenha("senha123");
    string senhaInserida;

    cout << "Digite sua senha: ";
    cin >> senhaInserida;

    if (verificarSenha(senhaArmazenada, senhaInserida)) {
        cout << "Login realizado com sucesso!" << endl;
        // Adicione aqui o código para determinar o tipo de acesso do usuário
    } else {
        cout << "Senha incorreta." << endl;
    }

    return 0;
}
