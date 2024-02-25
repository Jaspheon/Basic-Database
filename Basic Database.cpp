#include <iostream>
#include <cstring>
#include <string>

// Armazena informações dos Empregados
struct Employers {
    std::string Knows;
    std::string Name;
    double Salary;
    int Age;
};


Employers Infos[30]; // Modifique isso se quiser mudar a quantidade

int CurrentEmployers = 0;

// Contrata empregados novos
void CreateEmployers() {
    std::cout << "Employer Infos: \n\n";

    // Entrada para adicionar novo funcionario
    std::cout << "Name: ";
    std::string Name;
    std::getline(std::cin, Name);

    std::cout << "Age: ";
    int Age;
    std::cin >> Age;

    std::cin.ignore();

    std::cout << "Knows: ";
    std::string Know;
    std::getline(std::cin, Know);

    std::cout << "Salary: ";
    double Salary;
    std::cin >> Salary;

    system("cls");

    // Armazena as informações inputadas dentro da struct
    Employers Employer;
    Employer.Salary = Salary;
    Employer.Knows = Know;
    Employer.Name = Name;
    Employer.Age = Age;
    
    // Adiciona o funcionario novo
    Infos[CurrentEmployers++] = Employer;
}

// Cria a função de "view Employers"
void ViewEmployers() {
    for (int K = 0; K < CurrentEmployers; K++) {

        std::cout << "Employer ID" << " " << K+1 << "\n\n";

        std::cout << "Name: " << Infos[K].Name << '\n';
        std::cout << "Salary: " << Infos[K].Salary << '\n';
        std::cout << "Knows: " << Infos[K].Knows << '\n';
        std::cout << "Age: " << Infos[K].Age << '\n';
        
    }

}

// Usado pra editar employers ja existentes
void EditEmployers() {
    int Id;
    std::cout << "Employer id: ";
    std::cin >> Id;

    std::cout << "Name: ";
    std::string Name;
    std::getline(std::cin, Name);

    std::cout << "Age: ";
    int Age;
    std::cin >> Age;

    std::cin.ignore();

    std::cout << "Knows: ";
    std::string Know;
    std::getline(std::cin, Know);

    std::cout << "Salary: ";
    double Salary;
    std::cin >> Salary;

    Employers EditEmployer;
    EditEmployer.Age = Age;
    EditEmployer.Name = Name;
    EditEmployer.Knows = Know;
    EditEmployer.Salary = Salary;

    Infos[Id-1] = EditEmployer;
}

void DeleteEmployers() {
    std::cout << "Employer Id: ";
    int Id;
    std::cin >> Id;
    Id--; // Botar -1 no id do employer, pra iniciar no 1

    std::memmove(&Infos[Id], &Infos[Id + 1], sizeof(Employers) * (30 - Id - 1));
    CurrentEmployers--;
}

int main() {

    while (true) {
        // Opções de entrada
        std::cout << "Panel of Options: \n\n";

        std::cout << "1 - Register Employ \n";

        std::cout << "2 - View Employers List \n";

        std::cout << "3 - Edit Employers \n";

        std::cout << "4 - Delete Employer \n";

        std::cout << "5 - Exit \n\n";

        std::cout << "Select Any Option: ";
        int Option;
        std::cin >> Option;

        std::cin.ignore();

        // Escoolhe as opções de acordo com o numero digitado em Entrada
        system("cls");
        switch (Option) {
        case 1:
            CreateEmployers();
            break;
        case 2:
            ViewEmployers();
            break;
        case 3:
            EditEmployers();
            break;
        case 4:
            DeleteEmployers();
            break;
        case 5:
            return 0;
        default:
            std::cerr << "Invalid Number option.";
        }

    }

    return 0;
}
