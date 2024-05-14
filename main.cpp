#include <iostream>
#include "authentication.h"
#include "student.h"

int main()
{
    Authentication auth;

    // Incluindo registro de notas e frequência
    Student student("aluno123");
    student.registerGrade(80);
    student.registerAttendance(true);


    std::string username, password;
    std::cout << "Digite o nome de usuário: ";
    std::cin >> username;
    std::cout << "Digite a senha: ";
    std::cin >> password;

    if (auth.login(username, password))
    {
        std::cout << "Login bem-sucedido!" << std::endl;

        // Simulação de consulta de notas e frequência
        std::vector<double> grades = student.getGrades();
        std::vector<bool> attendance = student.getAttendance();

        std::cout << "Notas: ";
        for (double grade : grades)
        {
            std::cout << grade << " ";
        }
        std::cout << std::endl;

        std::cout << "Frequência: ";
        for (bool attended : attendance)
        {
            std::cout << (attended ? "Presente" : "Ausente") << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Login falhou!" << std::endl;
    }
    

    return 0;
}
