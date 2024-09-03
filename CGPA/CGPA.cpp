// CGPA.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <numeric>
#include <ios>

struct Student {
    std::string last_name{};
    std::string name{};
    std::vector<std::string> course_vec;
    std::vector<std::vector<int>> grade;
};

int main()
{
    Student s;
    std::string course_name{};
    int num_of_courses{};
    int grade{};
    float aver_rat_course{};
    float aver_rat_all{};
    std::string str{};
    int count{};
    std::vector <std::string> read_file;
    int mode{};
    int flag = 1;

    std::cout << "Enter the student's last and first names: ";
    std::cin >> s.last_name >> s.name;
    
    std::ifstream MF("D:\\students\\" + s.last_name + ".txt");

    if (!MF.is_open()) {
        std::cout << "The student has not been found. A new file will be created." << std::endl;

        std::ofstream MF2("D:\\students\\" + s.last_name + ".txt");
        MF2 << s.last_name << "\t" << s.name << "\n";
        std::cout << "\nEnter the number of courses: ";
        std::cin >> num_of_courses;
        for (int i = 0; i < num_of_courses; i++) {
            str = {};
            std::cout << "\nEnter the name of course: ";
            std::cin >> course_name;
            MF2 << course_name << "\t";
            std::cout << "\nEnter the grades for this course using the space bar: ";
            std::cin.get();
            std::getline(std::cin, str);
            std::istringstream ss(str);
            while (ss >> grade) {
                MF2 << grade << " ";
            }
            MF2 << "\n";
            MF2.close();
        }
    }
    else {
        while(std::getline(MF, str)){
            read_file.push_back(str);
        }
        std::ofstream MF2("D:\\students\\" + s.last_name + ".txt",std::ios_base::app);
       
        std::cout << count << std::endl;
        std::cout << "If you want to add a course to a student" << s.last_name << " " << s.name << ", press 1\n" <<
            "If you want to add grades to a student" << s.last_name << " " << s.name << ", press 2\n" <<
            "If you want average grade for the course, press 3\n" <<
            "If you want to know the average grade of a student " << s.last_name << " " << s.name << "for all courses, press 4\n";
        std::cin >> mode;
        size_t ind{};
        while(flag){
            switch (mode) {
            case 1:
                std::cout << "Enter the name of course: ";
                std::cin >> course_name;
                MF2 << course_name << "\t";
                break;
            case 2:
                std::cout << "Enter the name of course: ";
                std::cin >> course_name;
                for (std::string& i : read_file) {
                    if (i.find(course_name) == std::string::npos) {
                        count++;
                    }

                }
                if (count) {
                    std::cout << "\nEnter the grades for this course using the space bar: ";
                    std::cin.get();
                    std::getline(std::cin, str);
                    read_file[count] += str;
                    std::ofstream MF3("D:\\students\\" + s.last_name + ".txt");
                    for (std::string& i : read_file) {
                        MF3 << i << "\n";
                    }

                }
                break;
            case 3:

            default: std::cout << "Exit"; flag = 0;
            }
        }
    }

    
}




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
