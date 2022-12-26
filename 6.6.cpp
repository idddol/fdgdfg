#include <iostream>
#include <map>
#include <string>

int main() {
    std::map <std::string, int> data;
    data.insert({ "all", 0 });
    std::string line;
    std::cout << "Enter the line: \n";
    getline(std::cin, line);
    line += ' ';

    std::string tmp_line = "";
    for (auto i : line) {
        if (i != ' ' and i != ',' and i != '.') //разделители слов
            tmp_line += tolower(i);
        else {
            if (tmp_line != "") {
                if (data.find(tmp_line) != data.end()) { //проверяем, есть ли слово в map
                    data[tmp_line]++;
                }
                else {
                    data.insert({ tmp_line, 1 });
                }
                data["all"]++;
            }
            tmp_line = "";
        }
    }

    std::cout << "\nresult:\n\tall words: " << data["all"] << '\n';
    for (auto i = ++data.begin(); i != data.end(); i++) {
        std::cout << "\t" << i->first << ": " << i->second / (data["all"] / 100.0) << "%\n";
    }
}
