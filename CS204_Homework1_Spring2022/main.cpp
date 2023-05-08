#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
struct cell
{
	char letter;
	char color;

};

// Find if there is any duplicate char in the guessed string
bool uniqueCharacters(string str)
{
 

    for (int i = 0; i < str.length() - 1; i++) {
        for (int j = i + 1; j < str.length(); j++) {
            if (str[i] == str[j]) {
                return false;
            }
        }
    }
 

    return true;
}
int main()
{
	string input_file;
	string guess;
	string word;
	string limit;
	int lim;

	// Using below vector to check if guess word was guessed before.
	vector<string> guessed_words;

	// After guesssing, if there is match in word and guessed word, matched char indexes push back to this vector.
	vector<int>green_index;
	cout << "Welcome to the Swordle" << endl;
	cout << "Please enter the file name: ";
	cin >> input_file;

	// Open and Read the txt file
	ifstream textfile;
	textfile.open(input_file);
	while(!textfile)
	{
		cout << "Couldn't find the file!"<< endl;
		cout << "Please enter the file name: ";
		cin >> input_file;
		textfile.open(input_file);
	}
	if (textfile.is_open())
	{
		getline(textfile,limit);
		lim = stoi(limit);
		getline(textfile,word);
		cout << "The word that you will guess has " << word.length() << " letters and you have " << lim << " attempts." << endl;
	}

	
	// vector of vector of struct with lim rows and word.length() cols and initiliazed to - for both letter and color in below for loop.
	vector<vector<cell>> Game_Arena(lim, vector<cell>(word.length()));

	for(int i = 0; i<lim; i++)
	{
		for (int j = 0; j < word.length(); j++)
		{
			Game_Arena[i][j].letter = '-';
			Game_Arena[i][j].color = '-';
		}
	}


	int counter = 0;
	do
	{
		// Length 
		cout << "What's your guess? ";
		cin >> guess;
		if (guess.length() > word.length())
		{
			cout << "The word is too long" << endl;
		}
		else if (guess.length() < word.length())
		{
			cout << "The word is too short" << endl;
			cout << word.length() << endl;
			cout << word.length() << endl;
		}

		// Illegality 
		else if(!all_of(guess.begin(),guess.end(), islower))
		{
			cout << "Your input has illegal letters!" << endl;
		
		}
		
		// Tried before or not 
		else if (find(guessed_words.begin(), guessed_words.end(), guess) != guessed_words.end())
		{
			cout << "You've already tried this word!"<< endl;
		}
		else
		{
			// Uniquetiy 
			if (!uniqueCharacters(guess))
			{
				cout << "Your input has a duplicate letter!" << endl;
			}

			// Matched char in the guessed word and main word
			else if (green_index.size() != 0)
			{
				bool green_changed = false;
				for (int i=0; i<green_index.size();i++)
				{
					if (guess[green_index[i]] != word[green_index[i]])
					{
						green_changed = true;
					}
				}
				if (green_changed)
				{
					cout << "You didn't use the green letter in your word!" << endl;
				}
				else
				{
					guessed_words.push_back(guess);
					for (int i = 0; i < word.length(); i++)
					{
						Game_Arena[counter][i].letter = guess[i];
						if (guess[i]  == word[i])
						{
							Game_Arena[counter][i].color = 'G';
							green_index.push_back(i);
						
						}
						if (word.find(guess[i]) < word.length())
						{
							if (word[i] != guess[i])
							{
								Game_Arena[counter][i].color = 'Y';
							}
						}
						else
						{
							Game_Arena[counter][i].color = 'B';
						}
					}
					for(int i = 0; i<lim; i++)
					{
						for (int j = 0; j < word.length(); j++)
						{
							cout << "||" << Game_Arena[i][j].letter << "," << Game_Arena[i][j].color;
						}
						cout << "||";
						cout <<endl;
					}
					counter += 1;
				}
			}
			else
			{
				guessed_words.push_back(guess);
				for (int i = 0; i < word.length(); i++)
				{
					Game_Arena[counter][i].letter = guess[i];
					if (guess[i]  == word[i])
					{
						Game_Arena[counter][i].color = 'G';
						green_index.push_back(i);
						
					}
					if (word.find(guess[i]) < word.length())
					{
						if (word[i] != guess[i])
						{
							Game_Arena[counter][i].color = 'Y';
						}
					}
					else
					{
						Game_Arena[counter][i].color = 'B';
					}
				}
				for(int i = 0; i<lim; i++)
				{
					for (int j = 0; j < word.length(); j++)
					{
						cout << "||" << Game_Arena[i][j].letter << "," << Game_Arena[i][j].color;
					}
					cout << "||";
					cout <<endl;
				}
				counter += 1;
			
			}
		
		}


	}while((counter != lim) && (word != guess));

	if (word == guess)
	{
		cout << "You win!" << endl;
	}
	else 
	{
		cout << "You lose!" << endl;
	}



	
	return 0;
}