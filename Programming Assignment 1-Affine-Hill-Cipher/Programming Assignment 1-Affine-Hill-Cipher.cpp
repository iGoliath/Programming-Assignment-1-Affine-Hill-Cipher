#include <iostream>
#include <string>
#include <vector>
using namespace std;


const string alphabet = "abcdefghijklmnopqrstuvwxyz";
int ReturnVal(char x);
void HillCipher(int *key, vector<int> text);
void AffineEncrypt(int a, int b, string text);
void AffineDecrypt(int a, int b, string text);
void AffineBruteForce(int a, string text);
void AffineKnownPT(string CT, string KPT);
void RowTranspotitionEncrypt(int* key, string text);
void VegenereCipher(string text);
int main() {
	string temp;
	int a, b;
	cout << "Affine Ciphers:\n" << endl;

	//cout << "Please enter the plaintext you wish to encrypt using the affine cipher: ";
	//getline(cin, temp, '\n');
	//cout << "Please enter the coefficient 'a' of the affine function you wish to use: ";
	//cin >> a;
	//cout << "Please enter the coefficient 'b' of the affine function you wish to use: ";
	//cin >> b;
	//cin.ignore();

	//AffineEncrypt(a, b, temp);

	//cout << endl;
	//cout << "Please enter the ciphertext you wish to decrypt using the affine cipher: ";
	//getline(cin, temp, '\n');
	//cout << "Please enter the coefficient 'a' of the affine function you wish to use: ";
	//cin >> a;
	//cout << "Please enter the coefficient 'b' of the affine function you wish to use: ";
	//cin >> b;
	//cin.ignore();

	//AffineDecrypt(a, b, temp);
	
	//cout << "Please enter the ciphertext you wish to brute force using the affine cipher: ";
	//getline(cin, temp, '\n');
	//cout << "Please enter the coefficient 'a' of the affine function you wish to use: ";
	//cin >> a;
	//cin.ignore();
	//AffineBruteForce(a, temp);

	//cout << "Vegenere & Tansposition Ciphers: " << endl;

	string lol = "LCLLEWLJAZLNNZMVYIYLHRMHZA";
	VegenereCipher(lol);
	//int key[7] = {4, 3, 1, 2, 5, 6, 7};
	//string attack = "attack postponed until two am";
	//RowTranspotitionEncrypt(key, attack);
	//int hillkey[4];
	//cout << "Please enter the key for the hill cipher you wish to encrypt: ";
	//getline(cin, temp, '\n');
	//for (int i = 0; i < 4; i++) {
	//	hillkey[i] = stoi(temp.substr(i, 1));
	//}

	//vector<int> hilltext;
	//cout << "Please enter the plaintext to be encrypted: ";
	//getline(cin, temp, '\n');

	//for (int i = 0; i < temp.length(); i++) {
	//	if(isalpha(temp[i])) 
	//	hilltext.push_back(ReturnVal(tolower(temp[i])));
	//}

	
	//HillCipher(hillkey, hilltext);
	return 0;
}

void VegenereCipher(string text) {
	int freq[26] = { 0 };
	for (int i = 0; i < text.length(); i++) {
		switch (tolower(text[i])) {
		case 'a':
			freq[0]++;
			break;
		case 'b':
			freq[1]++;
			break;
		case 'c':
			freq[2]++;
			break;
		case 'd':
			freq[3]++;
			break;
		case 'e':
			freq[4]++;
			break;
		case 'f':
			freq[5]++;
			break;
		case 'g':
			freq[6]++;
			break;
		case 'h':
			freq[7]++;
			break;
		case 'i':
			freq[8]++;
			break;
		case 'j':
			freq[9]++;
			break;
		case 'k':
			freq[10]++;
			break;
		case 'l':
			freq[11]++;
			break;
		case 'm':
			freq[12]++;
			break;
		case 'n':
			freq[13]++;
			break;
		case 'o':
			freq[14]++;
			break;
		case 'p':
			freq[15]++;
			break;
		case 'q':
			freq[16]++;
			break;
		case 'r':
			freq[17]++;
			break;
		case 's':
			freq[18]++;
			break;
		case 't':
			freq[19]++;
			break;
		case 'u':
			freq[20]++;
			break;
		case 'v':
			freq[21]++;
			break;
		case 'w':
			freq[22]++;
			break;
		case 'x':
			freq[23]++;
			break;
		case 'y':
			freq[24]++;
			break;
		case 'z':
			freq[25]++;
			break;
		}
	}
	int mostFreq = 0;
	int HighestIndex = 0;
	for (int i = 0; i < 26; i++) {
		if (freq[i] > mostFreq) {
			mostFreq = freq[i];
			HighestIndex = i;
		}
		
	}

	int key = ReturnVal(alphabet[HighestIndex]) - 4;
	vector<char> calc;
	for (int i = 0; i < text.length(); i++) {
		int index = (ReturnVal(tolower(text[i])) - key);
		if (index < 0)
			index += 26;
		calc.push_back(alphabet[index]);
	}

	for (int i = 0; i < text.length(); i++) {
		cout << calc[i];
	}

}

void AffineEncrypt(int a, int b, string text) {
	vector<int> calc;
	string out = text;
	for (int i = 0; i < text.length(); i++) {
		calc.push_back(ReturnVal(text[i]));
		calc[i] = ((calc[i] * 7 + 8) % 26);
		out[i] = toupper(alphabet[calc[i]]);
	}

	cout << "Encryption of '" << text << "': " << out << endl;

}

void AffineDecrypt(int a, int b, string text) {
	vector<int> calc;
	string out = text;
	switch (a) {
	case 1:
		a = 1;
		break;
	case 3:
		a = 9;
		break;
	case 5:
		a = 21;
		break;
	case 7:
		a = 15;
		break;
	case 9:
		a = 3;
		break;
	case 11:
		a = 19;
		break;
	case 15: 
		a = 7;
		break;
	case 17:
		a = 23;
		break;
	case 19:
		a = 11;
		break;
	case 21:
		a = 5;
		break;
	case 23:
		a = 17;
		break;
	case 25:
		a = 25;
		break;
	default:
		cout << "Function has no inverse and therefore cannot be dectypted\n\n";
		return;
	}
	for (int i = 0; i < text.length(); i++) {
		calc.push_back(ReturnVal(tolower(text[i])));
		calc[i] = (((calc[i] - b) * a) % 26);
		while (calc[i] < 0) {
			calc[i] += 26;
		}
		out[i] = alphabet[calc[i]];
	}
	cout << "Decryption of '" << text << "': " << out << endl;
}

void AffineBruteForce(int a, string text) {
	switch (a) {
	case 1:
		a = 1;
		break;
	case 3:
		a = 9;
		break;
	case 5:
		a = 21;
		break;
	case 7:
		a = 15;
		break;
	case 9:
		a = 3;
		break;
	case 11:
		a = 19;
		break;
	case 15:
		a = 7;
		break;
	case 17:
		a = 23;
		break;
	case 19:
		a = 11;
		break;
	case 21:
		a = 5;
		break;
	case 23:
		a = 17;
		break;
	case 25:
		a = 25;
		break;
	default:
		cout << "Function has no inverse and therefore cannot be dectypted\n\n";
		return;
	}
	for (int i = 0; i < 26; i++) {
		string out = text;
		vector<int> calc;
		cout << "For b = " << i << " decryption is: ";
		for (int j = 0; j < text.length(); j++) {
			calc.push_back(ReturnVal(tolower(text[j])));
			calc[j] = (((calc[j] - i) * a) % 26);
			while (calc[j] < 0) {
				calc[j] += 26;
			}
			out[j] = alphabet[calc[j]];
		}
		cout << out << endl;
	}
}

void AffineKnownPT(string CT, string KPT) {
	int KPTCalc[2];
	vector<int> calc;
	KPTCalc[0] = ReturnVal(tolower(KPT[0]));
	KPTCalc[1] = ReturnVal(tolower(KPT[1]));
	for (int i = 0; i < CT.length(); i++) {
		calc.push_back(ReturnVal(tolower(CT[i])));
	}
	int right = KPTCalc[0] - KPTCalc[1];
	int left = calc[0] - calc[1];
	int alpha;
	if (left == 1 || left == -1) {
		if (right < 0)
			right *= -1;
		switch (right) {
		case 1:
			alpha = 1;
			break;
		case 3:
			alpha = 9;
			break;
		case 5:
			alpha = 21;
			break;
		case 7:
			alpha = 15;
			break;
		case 9:
			alpha = 3;
			break;
		case 11:
			alpha = 19;
			break;
		case 15:
			alpha = 7;
			break;
		case 17:
			alpha = 23;
			break;
		case 19:
			alpha = 11;
			break;
		case 21:
			alpha = 5;
			break;
		case 23:
			alpha = 17;
			break;
		case 25:
			alpha = 25;
			break;
		default:
			cout << "Function has no inverse and therefore cannot be dectypted\n\n";
			return;
		}
	}
	else
		alpha = left / right;
	int beta = ((calc[0] - alpha * KPTCalc[0]) % 26);
	while (beta < 0)
		beta += 26;
	AffineDecrypt(alpha, beta, CT);
}

void RowTranspotitionEncrypt(int* key, string text) {
	vector<char> calc;
	for (int i = 0; i < text.length(); i++) {
		if (isalpha(text[i]))
			calc.push_back(text[i]);
	}

	int rows = calc.size() / sizeof(key) + 1;
	if (calc.size() % rows != 0) {
		while (calc.size() < (rows * (sizeof(key) - 1))) {
			calc.push_back('x');
		}
	}

	vector<char> transpose(calc.size());
	int counter = 0;
	int useKey;
		for (int i = 0; i < (sizeof(key) - 1); i++) {
			useKey = key[i];
			counter = 0;
			for (int j = 0; j < rows; j++) {
				transpose[rows * (useKey - 1) + j] = calc[i + counter];
				counter += (sizeof(key) - 1);
			}
		}
		vector<char> transpose2(transpose.size());
		for (int i = 0; i < (sizeof(key) - 1); i++) {
			useKey = key[i];
			counter = 0;
			for (int j = 0; j < rows; j++) {
				transpose2[rows * (useKey - 1) + j] = transpose[i + counter];
				counter += (sizeof(key) - 1);
			}
		}
	cout << "Encryption using double transposition is: ";
	for (int i = 0; i < transpose2.size(); i++) {
		cout << transpose2[i];
	}
	
}

void HillCipher(int *key, vector<int> text) {
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