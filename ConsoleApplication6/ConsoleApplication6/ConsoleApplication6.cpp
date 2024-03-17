#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int fact(int i)
{
	if (i == 0) return 1;
	else return i * fact(i - 1);
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
		cout << "Do you want to continue? y/n > " << endl;
		cin >> s;
		if (s == "y" || s == "Y")
			return true;
		else
		{
			if (s == "n" || s == "N")
				return false;
			else
				cout << "Try again. Incorrect input! " << endl;
		}
	}
}

int main()
{
	const double pi = 3.14;
	double sum = 0, x, xPred = 0, a, e = INTMAX_MAX;
	vector <double> An;
	vector <double> Sn;
	vector <double> En;
	bool flag = true;

	while (flag)
	{
		cout << "enter x: " << endl;
		x = proverka();
		cout << "enter a: " << endl;
		a = proverka();
		if (x == xPred)
		{
			if (a == round(a))
			{
				if (a == An.size())
				{
					cout << "We already have some values: " << endl;
					cout << "N" << "\t" << "An" << "\t" << "Sn" << "\t" << "e" << "\t" << endl;
					for (int n = 0; n < An.size(); n++)
						cout << n << "\t" << An[n] << "\t" << Sn[n] << "\t" << En[n] << "\t" << endl;
				}
				else
				{
					if (a > An.size())
					{
						cout << "We already have some values: " << endl;
						cout << "N" << "\t" << "An" << "\t" << "Sn" << "\t" << "e" << "\t" << endl;
						for (int n = 0; n < An.size(); n++)
							cout << n << "\t" << An[n] << "\t" << Sn[n] << "\t" << En[n] << "\t" << endl;
						cout << "New values are: " << endl;
						cout << "N" << "\t" << "An" << "\t" << "Sn" << "\t" << "e" << "\t" << endl;
						for (int n = An.size(); n < a; n++)
						{
							An.push_back((pow(2, n / 2) * sin(pi * n / 4) * pow(x, n)) / fact(n));
							cout << n << "\t" << (pow(2, n / 2) * sin(pi * n / 4) * pow(x, n)) / fact(n) << "\t";
							sum += (pow(2, n / 2) * sin(pi * n / 4) * pow(x, n)) / fact(n);
							cout << sum << "\t";
							Sn.push_back(sum);
							En.push_back(abs(((pow(2, (n + 1) / 2) * sin(pi * (n + 1) / 4) * pow(x, (n + 1)) / fact(n + 1))) / sum));
							e = abs(((pow(2, (n + 1) / 2) * sin(pi * (n + 1) / 4) * pow(x, (n + 1)) / fact(n + 1)) / sum));
							cout << e << endl;
						}
					}
					else
					{
						cout << "We already have some values: " << endl;
						cout << "N" << "\t" << "An" << "\t" << "Sn" << "\t" << "e" << "\t" << endl;
						for (int n = 0; n < An.size(); n++)
							cout << n << "\t" << An[n] << "\t" << Sn[n] << "\t" << En[n] << "\t" << endl;
					}
				}
			}
			else
			{
				//0.5 8
				//0.5 3.5
				if (a > En[En.size() - 1]) {
					int counter = 0;
					while (En[counter] >= a) {
						cout << counter << "\t" << An[counter] << "\t" << Sn[counter] << "\t" << En[counter] << "\t" << endl;
						counter++;
					}
				}
				if (a == En[En.size() - 1])
				{
					cout << "We already have some values: " << endl;
					cout << "N" << "\t" << "An" << "\t" << "Sn" << "\t" << "e" << "\t" << endl;
					int counter = 0;
					while (En[counter] >= a) {
						cout << counter << "\t" << An[counter] << "\t" << Sn[counter] << "\t" << En[counter] << "\t" << endl;
						counter++;
					}
					/*for (int n = 0; n < En.size(); n++)
						cout << n << "\t" << An[n] << "\t" << Sn[n] << "\t" << En[n] << "\t" << endl;*/
					/*cout << En.size() - 1 << "\t" << An[En.size() - 1] << "\t" << Sn[En.size() - 1] << "\t" << En[En.size() - 1] << "\t" << endl;*/
				}
				else
				{
					if (a < En[En.size() - 1])
					{
						cout << "We already have some values: " << endl;
						cout << "N" << "\t" << "An" << "\t" << "Sn" << "\t" << "e" << "\t" << endl;
						for (int n = 0; n < En.size(); n++)
							cout << n << "\t" << An[n] << "\t" << Sn[n] << "\t" << En[n] << "\t" << endl;
						cout << "New values are: " << endl;
						cout << "N" << "\t" << "An" << "\t" << "Sn" << "\t" << "e" << "\t" << endl;
						int n = En.size();
						while (e >= a)
						{
							An.push_back((pow(2, n / 2) * sin(pi * n / 4) * pow(x, n)) / fact(n));
							cout << n << "\t" << (pow(2, n / 2) * sin(pi * n / 4) * pow(x, n)) / fact(n) << "\t";
							sum += (pow(2, n / 2) * sin(pi * n / 4) * pow(x, n)) / fact(n);
							cout << sum << "\t";
							Sn.push_back(sum);
							En.push_back(abs(((pow(2, (n + 1) / 2) * sin(pi * (n + 1) / 4) * pow(x, (n + 1)) / fact(n + 1))) / sum));
							e = abs(((pow(2, (n + 1) / 2) * sin(pi * (n + 1) / 4) * pow(x, (n + 1)) / fact(n + 1)) / sum));
							cout << e << endl;
							n++;
						}
					}
					else
					{
						/*cout << "We already have some values: " << endl;
						cout << "N" << "\t" << "An" << "\t" << "Sn" << "\t" << "e" << "\t" << endl;
						int counter = 0;
						while (En[counter] >= a) {
							cout << counter << "\t" << An[counter] << "\t" << Sn[counter] << "\t" << En[counter] << "\t" << endl;
							counter++;
						}
						cout << counter+1 << "\t" << An[counter+1] << "\t" << Sn[counter+1] << "\t" << En[counter+1] << "\t" << endl;*/
						/*for (int n = 0; n < En.size(); n++) {
							if (En[n] < a) {
								break;
							}
							cout << n << "\t" << An[n] << "\t" << Sn[n] << "\t" << En[n] << "\t" << endl;
						}*/
						
						/*for (int n = 0; n < En.size(); n++) {
							if (En[n] >= a) {
								cout << n << "\t" << An[n] << "\t" << Sn[n] << "\t" << En[n] << "\t" << endl;
							}
						}*/
							

						/*int counter = 0;
						while (En[counter] >= a) {
							cout << counter << "\t" << An[counter] << "\t" << Sn[counter] << "\t" << En[counter] << "\t" << endl;
							counter++;
						}*/
					}
				}
			}
		}
		else
		{
			An.clear();
			Sn.clear();
			En.clear();
			if (a == round(a))
			{
				cout << "N" << "\t" << "An" << "\t" << "Sn" << "\t" << "e" << "\t" << endl;
				for (int n = 0; n < a; n++)
				{
					An.push_back((pow(2, n / 2) * sin(pi * n / 4) * pow(x, n)) / fact(n));
					cout << n << "\t" << (pow(2, n / 2) * sin(pi * n / 4) * pow(x, n)) / fact(n) << "\t";
					sum += (pow(2, n / 2) * sin(pi * n / 4) * pow(x, n)) / fact(n);
					cout << sum << "\t";
					Sn.push_back(sum);
					En.push_back(abs(((pow(2, (n + 1) / 2) * sin(pi * (n + 1) / 4) * pow(x, (n + 1)) / fact(n + 1))) / sum));
					e = abs(((pow(2, (n + 1) / 2) * sin(pi * (n + 1) / 4) * pow(x, (n + 1)) / fact(n + 1)) / sum));
					cout << e << endl;
				}
			}
			else
			{
				int n = 0;
				cout << "N" << "\t" << "An" << "\t" << "Sn" << "\t" << "e" << "\t" << endl;
				while (e >= a)
				{
					An.push_back((pow(2, n / 2) * sin(pi * n / 4) * pow(x, n)) / fact(n));
					cout << n << "\t" << (pow(2, n / 2) * sin(pi * n / 4) * pow(x, n)) / fact(n) << "\t";
					sum += (pow(2, n / 2) * sin(pi * n / 4) * pow(x, n)) / fact(n);
					Sn.push_back(sum);
					cout << sum << "\t";
					En.push_back(abs(((pow(2, (n + 1) / 2) * sin(pi * (n + 1) / 4) * pow(x, (n + 1)) / fact(n + 1))) / sum));
					e = abs(((pow(2, (n + 1) / 2) * sin(pi * (n + 1) / 4) * pow(x, (n + 1)) / fact(n + 1)) / sum));
					cout << e << endl;
					n++;
				}
			}
		}
		xPred = x;
		flag = anscheck();
	}
}