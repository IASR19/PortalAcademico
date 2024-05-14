#include "authentication.h"

Authentication::Authentication() {
    // Inicialização do mapa de senhas
    userPasswords["aluno123"] = "hash_da_senha_123";
    userPasswords["user1"] = "hash_da_senha_456";
}

bool Authentication::login(const std::string& username, const std::string& password) {
    auto it = userPasswords.find(username);
    if (it != userPasswords.end() && it->second == password) {
        return true; // Usuário e senha corretos
    } else {
        return false; // Usuário ou senha incorretos
    }
}
