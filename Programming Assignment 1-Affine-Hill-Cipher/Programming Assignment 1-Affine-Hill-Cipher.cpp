//Note for comments: "Alphabet value" refers to index of the alphabet
//a letter corresponds to. I.e. a = 0, b = 1, etc.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string alphabet = "abcdefghijklmnopqrstuvwxyz";
int ReturnVal(char x);

void AffineEncrypt(int a, int b, string text);
void AffineDecrypt(int a, int b, string text);
void AffineBruteForce(int a, string text);
void AffineKnownPT(string CT, string KPT);
void VegenereCipher(string text);
void RowTranspositionEncrypt(int* key, string text, int size);
void RowTranspositionDecrypt(int* key, string text, int size);
void HillCipher(int* key, string textIn);
void HillCipherDecrypt(int* key, string textIn);
void HillCipherKPT(string PT, string CT);
int main() {
	string temp, temp2;
	int a, b;
	cout << "Affine Ciphers:\n" << endl;

	cout << "Please enter the plaintext you wish to encrypt using the affine cipher: ";
	getline(cin, temp, '\n');
	cout << "Please enter the coefficient 'a' of the affine function you wish to use: ";
	cin >> a;
	cout << "Please enter the coefficient 'b' of the affine function you wish to use: ";
	cin >> b;
	cin.ignore();

	AffineEncrypt(a, b, temp);

	cout << endl;
	cout << "Please enter the ciphertext you wish to decrypt using the affine cipher: ";
	getline(cin, temp, '\n');
	cout << "Please enter the coefficient 'a' of the affine function you wish to use: ";
	cin >> a;
	cout << "Please enter the coefficient 'b' of the affine function you wish to use: ";
	cin >> b;
	cin.ignore();

	AffineDecrypt(a, b, temp);

	cout << "Please enter the ciphertext you wish to brute force using the affine cipher: ";
	getline(cin, temp, '\n');
	cout << "Please enter the coefficient 'a' of the affine function you wish to use: ";
	cin >> a;
	cin.ignore();
	AffineBruteForce(a, temp);

	cout << "Please enter the Cipher text to be decrypted using a known plaintext attack: ";
	getline(cin, temp, '\n');
	cout << "\nPlease enter the known plaintext: ";
	getline(cin, temp2, '\n');

	AffineKnownPT(temp, temp2);

	cout << "\nVegenere & Tansposition Ciphers: \n" << endl;

	cout << "Please enter the cipher text to be decrypted using the Vegenere Cipher: ";
	getline(cin, temp, '\n');

	VegenereCipher(temp);

	int key[7];
	int tempKey;
	cout << "\n\nPlease enter the key to be used for the row transposition cipher encryption: ";
	cin >> tempKey;
	cin.ignore();
	for (int i = 6; i >= 0; i--) {
		key[i] = tempKey % 10;
		tempKey /= 10;
	}
	cout << "\nPlease enter the text to be encrypted using double row transposition: ";
	getline(cin, temp, '\n');
	RowTranspositionEncrypt(key, temp, sizeof(key) / sizeof(key[0]));


	int key2[6];
	cout << "\n\nPlease enter the key to be used for the row transposition cipher decryption : ";
	cin >> tempKey;
	cin.ignore();
	for (int i = 5; i >= 0; i--) {
		key2[i] = tempKey % 10;
		tempKey /= 10;
	}

	cout << "\nPlease enter the cipher text to be decrypted using double row transposition: ";
	getline(cin, temp, '\n');
	RowTranspositionDecrypt(key2, temp, sizeof(key2) / sizeof(key2[0]));


	cout << "\n\nHill Ciphers:" << endl;

	int hillkey[4];
	cout << "\nPlease enter the first key value for the hill cipher you wish to encrypt: ";
	cin >> hillkey[0];
	cin.ignore();
	cout << "\nPlease enter the second key value for the hill cipher you wish to encrypt: ";
	cin >> hillkey[1];
	cin.ignore();
	cout << "\nPlease enter the third key value for the hill cipher you wish to encrypt: ";
	cin >> hillkey[2];
	cin.ignore();
	cout << "\nPlease enter the fourth key value for the hill cipher you wish to encrypt: ";
	cin >> hillkey[3];
	cin.ignore();
	

	string hilltext;
	cout << "\nPlease enter the plaintext to be encrypted: ";
	getline(cin, hilltext, '\n');

	HillCipher(hillkey, hilltext);

	cout << "\nPlease enter the first key value for the hill cipher you wish to decrypt: ";
	cin >> hillkey[0];
	cin.ignore();
	cout << "\nPlease enter the second key value for the hill cipher you wish to decrypt: ";
	cin >> hillkey[1];
	cin.ignore();
	cout << "\nPlease enter the third key value for the hill cipher you wish to decrypt: ";
	cin >> hillkey[2];
	cin.ignore();
	cout << "\nPlease enter the fourth key value for the hill cipher you wish to decrypt: ";
	cin >> hillkey[3];
	cin.ignore();

	cout << "\nPlease enter the ciphertext to be decrypted: ";
	getline(cin, hilltext, '\n');

	HillCipherDecrypt(hillkey, hilltext);

	cout << "\nPlease enter the plaintext to be used to deduce the key: ";
	getline(cin, temp, '\n');
	cout << "\nPlease enter the ciphertext to he used to deduce the key: ";
	getline(cin, temp2, '\n');

	HillCipherKPT(temp, temp2);
	return 0;
}

void AffineEncrypt(int a, int b, string text) {

	vector<int> calc;
	string out = text;
	for (int i = 0; i < text.length(); i++) {
		//Initialize the vector
		calc.push_back(ReturnVal(text[i]));
		//Perform the affine cipher
		calc[i] = ((calc[i] * a + b) % 26);
		//Convert alphabet positions to characters in string
		out[i] = toupper(alphabet[calc[i]]);
	}
	//Print out string
	cout << "Encryption of '" << text << "': " << out << endl;

}

void AffineDecrypt(int a, int b, string text) {
	vector<int> calc;
	string out = text;
	//Determine a^-1 for decryption
	//If none is found, let the user know and return
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
		//Initialize vector with alphabet positions of each letter
		calc.push_back(ReturnVal(tolower(text[i])));
		//Find decrypted value
		calc[i] = (((calc[i] - b) * a) % 26);
		while (calc[i] < 0) {
			calc[i] += 26;
		}
		//Convert back into characters
		out[i] = alphabet[calc[i]];
	}
	//Print
	cout << "Decryption of '" << text << "': " << out << endl << endl;
}

void AffineBruteForce(int a, string text) {
	//Find a^-1 value
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
		//Set up for each b value, as brute force tries all values of b for 0 <= b <= 25
		cout << "For b = " << i << " decryption is: ";
		for (int j = 0; j < text.length(); j++) {
			//Find and push alphabet value
			calc.push_back(ReturnVal(tolower(text[j])));
			//Decrypt with current value of i being in place for b
			calc[j] = (((calc[j] - i) * a) % 26);
			//Modulus
			while (calc[j] < 0) {
				calc[j] += 26;
			}
			//Convert to character
			out[j] = alphabet[calc[j]];
		}
		cout << out << endl << endl;
	}
}

void AffineKnownPT(string CT, string KPT) {
	int KPTCalc[2];
	vector<int> calc;
	//Find alphabet values of the Known Plaintext
	KPTCalc[0] = ReturnVal(tolower(KPT[0]));
	KPTCalc[1] = ReturnVal(tolower(KPT[1]));
	//Convert Cipher text to alphabet values
	for (int i = 0; i < CT.length(); i++) {
		calc.push_back(ReturnVal(tolower(CT[i])));
	}
	//Calculate left and right sides of equation 
	// Ciphertext[0] = alpha * plaintext[0]
	//-Ciphertext[1] = alpha * plaintext[1]
	int right = KPTCalc[0] - KPTCalc[1];
	int left = calc[0] - calc[1];
	int alpha;
	//If results of the ciphertext subtraction are 1, find the modulus inverse of 1 / plaintext subtractions
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
	//Other wise, alpha is just Ciphertext[0] - Ciphertext[1] / Plaintext[0] - Plaintext[1]
	else
		alpha = left / right;
	//Algebra to determine beta
	int beta = ((calc[0] - alpha * KPTCalc[0]) % 26);
	while (beta < 0)
		beta += 26;
	//Now with known alpha and beta values, decrypt
	AffineDecrypt(alpha, beta, CT);
}

void VegenereCipher(string text) {
	//Initialize array to hold frequency counts for each of the 26 letters
	int freq[26] = { 0 };
	//Increment the frequency array for each letter of the cipher text given
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
	//Search the frequency array to determine which letter occurs the most in the cipher text
	for (int i = 0; i < 26; i++) {
		if (freq[i] > mostFreq) {
			mostFreq = freq[i];
			HighestIndex = i;
		}

	}
	//Because of english frequencies, 'e' should be the most common letter.
	//Therefore alphabet value of the most common letter - alphabet value of 'e' = key.
	int key = ReturnVal(alphabet[HighestIndex]) - 4;
	//Decrypt the cipher text based on the determined key
	vector<char> calc;
	for (int i = 0; i < text.length(); i++) {
		int index = (ReturnVal(tolower(text[i])) - key);
		if (index < 0)
			index += 26;
		calc.push_back(alphabet[index]);
	}
	//Print plaintext
	cout << "\nThe key value was found to be: " << key << endl;
	cout << "\nThe decrypted plaintext is: ";
	for (int i = 0; i < text.length(); i++) {
		cout << calc[i];
	}

}

void RowTranspositionEncrypt(int* key, string text, int size) {
	//Create vector of only letters from plaintext
	vector<char> calc;
	for (int i = 0; i < text.length(); i++) {
		if (isalpha(text[i]))
			calc.push_back(text[i]);
	}
	//Pad with x's if size doesn't even divide
	while (calc.size() % size != 0) 
		calc.push_back('x');

		int rows = calc.size() / size;

		//Perform first round of transposition
		vector<char> transpose(calc.size());
		int counter = 0;
		int useKey;
		for (int i = 0; i < size; i++) {
			useKey = key[i];
			counter = 0;
			for (int j = 0; j < rows; j++) {
				transpose[rows * (useKey - 1) + j] = calc[i + counter];
				counter += size;
			}
		}

		//Perform second round of transposition
		vector<char> transpose2(transpose.size());
		for (int i = 0; i < size; i++) {
			useKey = key[i];
			counter = 0;
			for (int j = 0; j < rows; j++) {
				transpose2[rows * (useKey - 1) + j] = toupper(transpose[i + counter]);
				counter += size;
			}
		}
		//Print
		cout << "\nEncryption using double transposition is: ";
		for (int i = 0; i < transpose2.size(); i++) {
			cout << transpose2[i];
		}

	}

void RowTranspositionDecrypt(int* key, string text, int size) {
	//Create vector with only letters
	vector<char> onlyAlpha;
	for (int i = 0; i < text.length(); i++) {
		if (isalpha(text[i])) {
			onlyAlpha.push_back(tolower(text[i]));
		}
	}
	//De transpose first round
	vector<char> calc(onlyAlpha.size());
	int useKey;
	int counter = 0;
	int rows = onlyAlpha.size() / size;
	int test = 1;
	for (int i = 0; i < size; i++) {
		int useKey = key[i];
		counter = 0;
		for (int j = 0; j < rows; j++) {
			calc[counter * size + i] = onlyAlpha[j + (rows * (useKey - 1))];
			counter++;
		}
	}
	//Second round
	vector<char> transpose(calc.size());
	for (int i = 0; i < size; i++) {
		int useKey = key[i];
		counter = 0;
		for (int j = 0; j < rows; j++) {
			transpose[counter * size + i] = (calc[j + (rows * (useKey - 1))]);
			counter++;
		}
	}
	//Print
	cout << "\nDecryption using double row transposition: ";
	for (int i = 0; i < transpose.size(); i++) {
		cout << transpose[i];
	}

}

void HillCipher(int* key, string textIn) {
	//Create vector of alphabet values of given plaintext
	vector<int> text;
	for (int i = 0; i < textIn.length(); i++) {
		if (isalpha(textIn[i]))
			text.push_back(ReturnVal(tolower(textIn[i])));
	}
	//Matrix multiplication of the given key and 4 letters of the plaintext
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

		//Find out how many x's need to be pushed and encrypted so that there are 4 letters
		//to properly perform matrix multiplication on
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
		//Convert alphabet values to corresponding letters
		vector<char> output(calc.size());
		int temp;
		for (int j = 0; j < calc.size(); j++) {
			temp = calc[j];
			output[j] = toupper(alphabet[temp]);
		}
		//Print
		for (int a = 0; a < output.size(); a++) {
			cout << output[a];
		}

	}

void HillCipherDecrypt(int* key, string textIn) {
	//Create vector of alphabet values of given cipher text
	vector<int> text;
	for (int i = 0; i < textIn.length(); i++) {
		if (isalpha(textIn[i]))
			text.push_back(ReturnVal(tolower(textIn[i])));
	}
	//Find denominator of K inverse coefficient
	int oneOver = key[0] * key[3] - key[1] * key[2];
	//Starting values of K Inverse before multiplication
	int KInverse[4] = { key[3], -key[1], -key[2], key[0] };
	
	//Find modulus inverse of the coefficient
	if (oneOver < -1) {
		while (oneOver < -1)
			oneOver += 26;
		switch (oneOver) {
		case 1:
			oneOver = 1;
			break;
		case 3:
			oneOver = 9;
			break;
		case 5:
			oneOver = 21;
			break;
		case 7:
			oneOver = 15;
			break;
		case 9:
			oneOver = 3;
			break;
		case 11:
			oneOver = 19;
			break;
		case 15:
			oneOver = 7;
			break;
		case 17:
			oneOver = 23;
			break;
		case 19:
			oneOver = 11;
			break;
		case 21:
			oneOver = 5;
			break;
		case 23:
			oneOver = 17;
			break;
		case 25:
			oneOver = 25;
			break;
		default:
			cout << "Function has no inverse and therefore cannot be dectypted\n\n";
			return;
		}
	}
	else if (oneOver > 25) {
		while (oneOver > 25)
			oneOver -= 26;
		switch (oneOver) {
		case 1:
			oneOver = 1;
			break;
		case 3:
			oneOver = 9;
			break;
		case 5:
			oneOver = 21;
			break;
		case 7:
			oneOver = 15;
			break;
		case 9:
			oneOver = 3;
			break;
		case 11:
			oneOver = 19;
			break;
		case 15:
			oneOver = 7;
			break;
		case 17:
			oneOver = 23;
			break;
		case 19:
			oneOver = 11;
			break;
		case 21:
			oneOver = 5;
			break;
		case 23:
			oneOver = 17;
			break;
		case 25:
			oneOver = 25;
			break;
		default:
			cout << "Function has no inverse and therefore cannot be dectypted\n\n";
			return;
		}
	}

	//Multiply indicies of K Inverse by coefficient
	for (int i = 0; i < 4; i++) {
		KInverse[i] *= oneOver;
		KInverse[i] = KInverse[i] % 26;
		while (KInverse[i] < 0)
			KInverse[i] += 26;
	}

	//Matrix multiplication of cipher text and K Inverse to find plaintext 
	vector<char> calc;
	for (int i = 0; i < text.size(); i+=2) {
		int pushOne = (text[i] * KInverse[0]) + (text[i + 1] * KInverse[2]);
		while (pushOne < 0 || pushOne > 25)
			pushOne = pushOne % 26;
		int pushTwo = (text[i] * KInverse[1]) + (text[i + 1] * KInverse[3]);
		while (pushTwo < 0 || pushTwo > 25)
			pushTwo = pushTwo % 26;
		calc.push_back(tolower(alphabet[pushOne]));
		calc.push_back(tolower(alphabet[pushTwo]));
	}

	//Print
	cout << "The decrypted plaintext is: ";

	for (int i = 0; i < calc.size(); i++) {
		cout << calc[i];
	}
	cout << endl;
}

void HillCipherKPT(string PT, string CT) {
	bool found = false;
	//Create array of characters of only letters (exclude spaces)
	vector<char> onlyAlpha;
	for (int i = 0; i < PT.length(); i++) {
		if (isalpha(PT[i])) {
			onlyAlpha.push_back(tolower(PT[i]));
		}
	}
	int oneOver;
	int index = 2;
	//Initialize PInverse;
	int PInverse[4] = { ReturnVal(tolower(onlyAlpha[0])), ReturnVal(tolower(onlyAlpha[1])), ReturnVal(tolower(onlyAlpha[2])), ReturnVal(tolower(onlyAlpha[3])) };
	//Find 1/ad-bc value
	while (!found) {
		PInverse[2] = ReturnVal(tolower(onlyAlpha[index]));
		PInverse[3] = ReturnVal(tolower(onlyAlpha[index + 1]));
		oneOver = PInverse[0] * PInverse[3] - PInverse[1] * PInverse[2];
		if (oneOver < 0) {
			while (oneOver < 0)
				oneOver += 26;
		}
		else if (oneOver > 25) {
			while (oneOver > 25)
				oneOver -= 26;
		}
		if (oneOver % 2 == 0 || oneOver == 13) {
			index += 2;
			continue;
		}
		else {
			switch (oneOver) {
			case 1:
				oneOver = 1;
				break;
			case 3:
				oneOver = 9;
				break;
			case 5:
				oneOver = 21;
				break;
			case 7:
				oneOver = 15;
				break;
			case 9:
				oneOver = 3;
				break;
			case 11:
				oneOver = 19;
				break;
			case 15:
				oneOver = 7;
				break;
			case 17:
				oneOver = 23;
				break;
			case 19:
				oneOver = 11;
				break;
			case 21:
				oneOver = 5;
				break;
			case 23:
				oneOver = 17;
				break;
			case 25:
				oneOver = 25;
				break;
			default:
				cout << "Function has no inverse and therefore cannot be dectypted\n\n";
				return;
			}
			found = true;
		}
	}
	//Find proper P^-1 values
	PInverse[0] = oneOver * ReturnVal(tolower(onlyAlpha[index + 1]));
	while (PInverse[0] < 0)
		PInverse[0] += 26;
	while (PInverse[0] > 25)
		PInverse[0] -= 26;
	PInverse[1] = oneOver * -ReturnVal(tolower(onlyAlpha[1]));
	while (PInverse[1] < 0)
		PInverse[1] += 26;
	while (PInverse[1] > 25)
		PInverse[1] -= 26;
	PInverse[2] = oneOver * -ReturnVal(tolower(onlyAlpha[index]));
	while (PInverse[2] < 0)
		PInverse[2] += 26;
	while (PInverse[2] > 25)
		PInverse[2] -= 26;
	PInverse[3] = oneOver * ReturnVal(tolower(onlyAlpha[0]));
	while (PInverse[3] < 0)
		PInverse[3] += 26;
	while (PInverse[3] > 25)
		PInverse[3] -= 26;
	//Find Alphabet values of the ciphertext values corresponding to the indicies of the plaintext values
	//a proper inverse of was found
	int correspondingCT[4] = { ReturnVal(tolower(CT[0])), ReturnVal(tolower(CT[1])),  ReturnVal(tolower(CT[index])),  ReturnVal(tolower(CT[index + 1])) };

	//Matrix multiplication to find key values and modulus
	int Key[4] = { (PInverse[0] * correspondingCT[0]) + (PInverse[1] * correspondingCT[2]), (PInverse[0] * correspondingCT[1]) + (PInverse[1] * correspondingCT[3]), (PInverse[2] * correspondingCT[0]) + (PInverse[3] * correspondingCT[2]), (PInverse[2] * correspondingCT[1]) + (PInverse[3] * correspondingCT[3])};
	while (Key[0] < 0)
		Key[0] += 26;
	while (Key[0] > 25)
		Key[0] -= 26;
	while (Key[1] < 0)
		Key[1] += 26;
	while (Key[1] > 25)
		Key[1] -= 26;
	while (Key[2] < 0)
		Key[2] += 26;
	while (Key[2] > 25)
		Key[2] -= 26;
	while (Key[3] < 0)
		Key[3] += 26;
	while (Key[3] > 25)
		Key[3] -= 26;
	
	cout << "The key matrix is: [" << Key[0] << ", " << Key[1] << ", " << Key[2] << ", " << Key[3] << "]";
	
}

int ReturnVal(char x) { return (int)x - 97; }