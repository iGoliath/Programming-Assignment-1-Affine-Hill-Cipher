#include <iostream>
#include <string>
#include <vector>
using namespace std;

int ReturnVal(char x);
void HillCipher(int *key, vector<int> text);
int main() {
	
	
	string temp;
	int hillkey[4];
	cout << "Please enter the key for the hill cipher: ";
	getline(cin, temp, '\n');
	for (int i = 0; i < 4; i++) {
		hillkey[i] = stoi(temp.substr(i, 1));
	}

	vector<int> hilltext;
	cout << "Please enter the plaintext, in lower case, to be encrypted: ";
	getline(cin, temp, '\n');

	for (int i = 0; i < temp.length(); i++) {
		if(isalpha(temp[i])) 
		hilltext.push_back(ReturnVal(tolower(temp[i])));
	}


	HillCipher(hillkey, hilltext);
	return 0;
}


void HillCipher(int *key, vector<int> text) {
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	vector<int> calc;
	int counter = 0;
	int i = 0;
	do {
		calc.push_back(((text[i] * key[0]) + (text[i + 1] * key[2])) % 26);
		calc.push_back(((text[i] * key[1]) + (text[i + 1] * key[3])) % 26);
		calc.push_back(((text[i + 2] * key[0]) + (text[i + 3] * key[2])) % 26);
		calc.push_back(((text[i + 2] * key[1]) + (text[i + 3] * key[3])) % 26);
		counter++;
		i += 4;
	} while (counter < text.size() / 4);
	
	if (i < text.size())
	{
		int need = 4 - (text.size() - i);
		counter = 1;
		while (need > 0) {
			text.push_back(23);
			need--;
			counter++;
		}
		calc.push_back(((text[i] * key[0]) + (text[i + 1] * key[2])) % 26);
		calc.push_back(((text[i] * key[1]) + (text[i + 1] * key[3])) % 26);
		calc.push_back(((text[i + 2] * key[0]) + (text[i + 3] * key[2])) % 26);
		calc.push_back(((text[i + 2] * key[1]) + (text[i + 3] * key[3])) % 26);
	}
	vector<char> output(calc.size());
	int temp;
	for (int j = 0; j < calc.size(); j++) {
		temp = calc[j];
		output[j] = toupper(alphabet[temp]);
	}
	
	for (int a = 0; a < output.size(); a++) {
		cout << output[a];
	}

}


int ReturnVal(char x) {
	return (int)x - 97;
}