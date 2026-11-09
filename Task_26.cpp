#include <iostream>
#include <map>
#include <string>



int main()
{
    std::string Text;
    std::string Word;
    std::string maxWord;
    int maxCounts = 0;


    std::map<std::string, int> words;

    std::getline(std::cin, Text);

    for (char c : Text)
    {
        if (c == ' ')
        {
            if (!Word.empty())
            {
                words[Word]++;
                Word.clear();
            }
        }
        else
        {
            if (c >= 'A' && c <= 'Z')
            {
                c = c + ('a' - 'A');
            }
            Word.push_back(c);
        }
    }

    if (!Word.empty())
    {
        words[Word]++;
    }

    for (auto item : words)
    {
        std::cout << item.first << ' ' << item.second << '\n';
    }

    for (const auto& item : words)
    {
	    if (item.second > maxCounts)
	    {
            maxCounts = item.second;
            maxWord = item.first;
	    }
    }

    std::cout << maxWord << " -> " << maxCounts << '\n';

}

