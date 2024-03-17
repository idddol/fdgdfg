#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

class Course_of_currency {
private:
    string data, currency;
    double course;
public:
    Course_of_currency() {
    }
    Course_of_currency(string _data, string _currency, double _course) {
        this->data = _data;
        this->currency = _currency;
        this->course = _course;
    }
    void setData(string _data) {
        this->data = _data;
    }
    void setCurrency(string _currency) {
        this->currency = _currency;
    }
    void setCourse(double _course) {
        this->course = _course;
    }
    string getData() {
        return this->data;
    }
    double getCourse() {
        return this->course;
    }
    double rubtoCurrency(double rub) {
        return rub * course;
    }
    Course_of_currency(const Course_of_currency& c) { //конструктор копирования
        this->data = c.data;
        this->currency = c.currency;
        this->course = c.course;
    }
    friend ostream& operator<< (ostream&, const Course_of_currency&);
    friend istream& operator>> (istream&, Course_of_currency&);
    friend class Procurement_data;
};

class Procurement_data {
private:
    int number;
    double summa;
    Course_of_currency course_of_currency;
public:
    Procurement_data() {
    }
    Procurement_data(int _number, double _summa, Course_of_currency _course_of_currency) {
        this->number = _number;
        this->summa = _summa;
        this->course_of_currency = _course_of_currency;
    }
    void setNumber(int num) {
        this->number = num;
    }
    void setSumma(double sum) {
        this->summa = sum;
    }
    void setCourse_of_currency(Course_of_currency cor) {
        this->course_of_currency = cor;
    }
    double getSumma() {
        return this->summa;
    }
    Course_of_currency getCourse_of_currency() {
        return course_of_currency;
    }
    double suminRub() {
        return course_of_currency.getCourse() * summa;
    }
    Procurement_data(const Procurement_data& p) { //конструктор копирования
        this->number = p.number;
        this->summa = p.summa;
        this->course_of_currency = p.course_of_currency;
    }
    friend ostream& operator<< (ostream&, const Procurement_data&);
    friend istream& operator>> (istream&, Procurement_data&);
};
ostream& operator<< (ostream& out, const Course_of_currency& obj) {      //Перегрузка оператора <<
    out << "data: " << obj.data << " currency: " << obj.currency << " course: " << obj.course;
    return out;
}

istream& operator>> (istream& in, Course_of_currency& obj) {
    string data, currency, course;
    getline(in, data);
    getline(in, currency);
    getline(in, course);
    obj.setData(data);
    obj.setCurrency(currency);
    obj.setCourse(stod(course));
    return in;
}
ostream& operator<< (ostream& out, const Procurement_data& obj)       //Перегрузка оператора <<
{
    out << "number: " << obj.number << " summa: " << obj.summa << " " << obj.course_of_currency;
    return out;
}
istream& operator>> (istream& in, Procurement_data& obj) {
    string number, summa;
    getline(in, number);
    getline(in, summa);
    obj.setNumber(stoi(number));
    obj.setSumma(stod(summa));
    return in;
}

bool vibor() {
    string s;
    bool is_incorrect_input = true;
    while (is_incorrect_input)
    {
        cout << "How do you want to write the data? c/f > ";
        cin >> s;
        if (s.size() != 1)
        {
            return false;
        }
        else
        {
            if (s == "c" || s == "C")
                return true;
            else
                if (s == "f" || s == "F")
                    return false;
                else {
                    cout << "Try again. Incorrect input! " << endl;
                }
        }
    }
}

double proverka() {
    double var;
    string s, s2;
    bool is_incorrect_input = true;
    while (is_incorrect_input)
    {
        cin >> s;

        try
        {
            var = stod(s);
            s2 = to_string(var);
            s2.resize(s.size());
            if (s == s2)
                is_incorrect_input = false;
            else
                cout << "Incorrect input! Enter again: ";
        }
        catch (invalid_argument)
        {
            cout << "Incorrect input! Enter again: ";
        }
    }
    return var;
}
bool anscheck()
{
    string s;
    bool is_incorrect_input = true;
    while (is_incorrect_input)
    {
        cout << "Do you want to continue? y/n > ";
        cin >> s;
        if (s.size() != 1)
        {
            return false;
        }
        else
        {
            if (s == "y" || s == "Y")
                return true;
            else
                if (s == "n" || s == "N")
                    return false;
                else {
                    cout << "Try again. Incorrect input! " << endl;
                }
        }
    }
}

//void function(vector<Course_of_currency> course_of_currency, vector<Procurement_data> procurement_data) {
//    double summa = 0;
//    string s, s1, s2;
//    vector<string> arr;
//    if (procurement_data.size() == 1) {
//        s2 = course_of_currency[0].getData();
//        cout << "Viruchka za " << s2.substr(3, s2.length() - 1) << " month: " << procurement_data[0].suminRub() << endl;
//    }
//    else {
//        for (int i = 0; i < procurement_data.size() - 1; i++) {
//            s = course_of_currency[i].getData();
//            arr.push_back(s.substr(3, s.length() - 1));   
//            cout << "s " << s.substr(3, s.length() - 1) << endl;
//            for (int j = 1; j < procurement_data.size(); j++) {
//                s1 = course_of_currency[j].getData();
//                if (s.substr(3, s.length() - 1) == s1.substr(3, s1.length() - 1)) {
//                    arr.push_back(s1.substr(3, s1.length() - 1));
//                    cout << "s1 " << s1.substr(3, s1.length() - 1) << endl;
//                }
//            }
//            for (int k = 0; k < arr.size(); k++) {
//                summa += procurement_data[k].suminRub();
//            }
//            cout << "Viruchka za " << arr[0] << " month: " << summa << endl;
//            arr.clear();
//            summa = 0;
//        }
//    }
//}

void func(vector<Procurement_data> pr) {
    double summa = 0;
    string s, s1, s2;
    vector<string> arr;
    set<string> arr1;
    int c = 0;
    for (int i = 0; i < pr.size(); i++) {
        arr.push_back(pr[i].getCourse_of_currency().getData().substr(3, 4));
    }

    //for (int i = 0; i < arr.size(); i++) {
    //    bool unique = true;
    //    for (int j = 0; j < arr.size(); j++)
    //    {
    //        if (arr[j] == arr[i] && j != i)
    //        {
    //            unique = false;
    //            break;
    //        }
    //        else {
    //            arr1.insert(arr[i]);
    //        }
    //    }
    //}
    for (int i = 0; i < arr.size(); i++) {
        arr1.insert(arr[i]);
    }
   /* cout << "rabotaet" << arr1.size() << " " << arr.size() << endl;
    for (int i = 0; i < arr1.size(); i++) {
        cout << arr1[i] << endl;
    }*/
    for (string number : arr1) {
        for (int j = 0; j < pr.size(); j++) {
            if (number == pr[j].getCourse_of_currency().getData().substr(3, 4)) {
                summa += pr[j].suminRub();
            }
        }
        cout << "Viruchka za " << number << " month: " << summa << endl;
        summa = 0;
    }
}

int main()
{
    /*Course_of_currency course_of_currency("25.04", "USD", 35.065);
    Course_of_currency course_of_currency1();
    cout << course_of_currency << endl;
    Procurement_data procurement_data(12, 3600, course_of_currency);
    cout << procurement_data << endl;*/
    bool flag = true;
    while (flag) {
        string data, currency;
        double summa = 0, course = 0;
        int number = 0;
        bool answer1, answer2;
        answer1 = vibor();
        if (answer1) {
            vector<Course_of_currency> course_of_currency;
            vector<Procurement_data>procurement_data;
            int num;
            cout << "Enter a number of elements: ";
            cin >> num;
            for (int i = 0; i < num; i++) {
                cout << "Enter a data: " << endl;
                cin >> data;
                cout << "Enter a currency: " << endl;
                cin >> currency;
                cout << "Enter a course: " << endl;
                course = proverka();
                cout << "Enter a number: " << endl;
                number = proverka();
                cout << "Enter a summa: " << endl;
                summa = proverka();
                Course_of_currency obj1(data, currency, course);
                course_of_currency.push_back(obj1);
                Procurement_data obj2(number, summa, obj1);
                cout << obj2 << endl;
                procurement_data.push_back(obj2);
            }
            answer2 = vibor();
            if (answer2) {
                for (int i = 0; i < procurement_data.size(); i++) {
                    cout << procurement_data[i] << endl;
                    cout << "Viruchka:" << procurement_data[i].suminRub() << endl;
                }
            }
            else {
                ofstream fout;
                fout.open("output.txt");
                for (int i = 0; i < procurement_data.size(); i++) {
                    fout << procurement_data[i] << endl;
                    fout << "Viruchka:" << procurement_data[i].suminRub() << endl;
                }
            }
            func(procurement_data);
        }
        else {
                vector<Procurement_data> procurement_data;
            /*try{*/
                ifstream fin("input.txt");
                int num;
                string k;
                Course_of_currency obj(data, currency, course);
                getline(fin, k);
                num = stoi(k);
                for(int i = 0; i < num;i++){

                    /*fin >> obj;
                    Procurement_data obj1(number, summa, obj);
                    fin >> obj1;
                    procurement_data.push_back(obj1);
                    cout << obj1 << endl;*/
                    getline(fin, k);
                    data = k;
                    getline(fin, k);
                    currency = k;
                    getline(fin, k);
                    course = stod(k);
                    getline(fin, k);
                    number = stoi(k);
                    getline(fin, k);
                    summa = stod(k);
                    Course_of_currency obj(data, currency, course);
                    Procurement_data obj1(number, summa, obj);
                    procurement_data.push_back(obj1);
                    cout << obj1 << endl;
       
                }
                fin.close();
            /*}*/
            /*catch (exception e) {
                cout << "Error " << endl;
            }*/
            answer2 = vibor();
            if (answer2) {
                for (int i = 0; i < procurement_data.size(); i++) {
                    cout << procurement_data[i] << endl;
                    cout << "Viruchka:" << procurement_data[i].suminRub() << endl;
                }
            }
            else {
                ofstream fout;
                fout.open("output.txt");
                for (int i = 0; i < procurement_data.size(); i++) {
                    fout << procurement_data[i] << endl;
                    fout << "Viruchka:" << procurement_data[i].suminRub() << endl;
                }
            }
            func(procurement_data);
        }
        flag = anscheck();
    }
}
