#include <iostream>

#include <string>

using namespace std;


int search(string dict[], string word, int left, int right)
{
	if (left > right)
	return -1;
	
	
	int mid = (left + right) / 2;
	
	
	if (dict[mid] == word)
	return mid;
	
	
	if (dict[mid] < word)
	return search(dict, word, mid+1, right);
	
	
	else
	return search(dict, word, left, mid-1);
}

int main()
{
	string dict[3];
	dict[0] = "apple";
	dict[1] = "Drum";
	dict[2] = "Yellow";
	string word;
	
	cout << "Enter a word to search: ";
	cin >> word;
	
	int result = search(dict, word, 0, 2);
	
	if (result == -1)
	cout << "Word not found in dictionary." << endl;
	else
	cout << "Word \"" << word << "\" found at position " << result + 1 << "." << endl;
	
	return 0;
}
