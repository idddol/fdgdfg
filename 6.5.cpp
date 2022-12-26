#include <iostream>
#include <list>
#include <map>
#include <string>

int main() {

    std::map <std::string, std::string> p;
    std::list <std::string> data;
    std::string line;

    std::cout << "Enter the group number, space, surname: \n";
    getline(std::cin, line);
    while (line != "-") {
        if (p.find(line.substr(0, line.find(' '))) != p.end()) { //есть ли такая группа
            //std::find проверяет, есть ли в data такая строка
            auto num = ++find(data.begin(), data.end(), p[line.substr(0, line.find(' '))]);
            data.insert(num, line); //добавляем в список под нужным номером
            //меняем последнюю строку
            p[line.substr(0, line.find(' '))] = line;
        }
        else {
            //если слова нет
            data.push_back(line);
            p.insert(std::pair<std::string, std::string>(line.substr(0, line.find(' ')), line));
        }
        std::cout << "Enter the group number, space, surname: \n";
        getline(std::cin, line);
    }

    std::cout << "\nresult:\n";
    for (auto i = data.begin(); i != data.end(); i++) {
        std::cout << *i << '\n';
    }
}
