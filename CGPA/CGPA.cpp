// CGPA.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <numeric>

struct Student {
    std::string last_name{};
    std::string name{};
    std::vector<std::string> course_vec;
    std::vector<std::vector<int>> grade;
    //int average_rat{};
};

int main()
{
    Student s;
    std::string course_name{};
    int num_of_courses{};
    int grade{};
    float aver_rat_course{};
    float aver_rat_all{};
    std::cout << "Enter the student's last and first names: ";
    std::cin >> s.last_name >> s.name;
    std::ofstream MF("D:\\students\\" + s.last_name + ".txt");
    MF << s.last_name << "\t" << s.name << "\n";
    std::cout << "\nEnter the number of courses: ";
    std::cin >> num_of_courses;
    std::string str{};
    std::vector<int> grade_in;
    for (int i = 0; i < num_of_courses; i++) {
        str = {};
        grade_in = {};
        std::cout << "\nEnter the name of course: ";
        std::cin >> course_name;
        s.course_vec.push_back(course_name);
        MF << course_name<<"\t";
        std::cout << "\nEnter the grades for this course using the space bar: ";
        std::cin.get();
        std::getline(std::cin, str);
        std::istringstream ss(str);
        while (ss >> grade) {
            grade_in.push_back(grade);
            MF << grade << "\t";
        }
        aver_rat_course = (float)std::accumulate(grade_in.begin(), grade_in.end(), 0) / std::size(grade_in);
        MF << "\t" << aver_rat_course << "\t";
        std::cout << aver_rat_course << std::endl;
        s.grade.push_back(grade_in);
        aver_rat_all += aver_rat_course;
        MF << "\n";
    }
    aver_rat_all /= num_of_courses;
    MF << "Average grade for all courses: " << aver_rat_all;

    
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
