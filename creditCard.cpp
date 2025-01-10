#include <iostream>
#include <string>
#include <vector>

using namespace std;

string creditCardNum_As_String;
int cardLength;
int evenCheckSum;
int oddCheckSum;
int totalCheckSum;


bool checkSum()
{
    if (cardLength % 2 == 0) {
        for (int i = 0; i != cardLength; i++)
        {
            if (i % 2 == 0)
            {
                //cout << "CCNAS" << creditCardNum_As_String[i] << " ";
                int num = creditCardNum_As_String[i] - '0';
                int temp = (num * 2);
                cout << "Temp: " << temp << " ";
                string tempo = to_string(temp);
                int length = tempo.length();
                for (int j = 0; j != length; j++)
                {
                    int last_digit = temp % 10;
                    temp /= 10;
                    evenCheckSum += last_digit;
                }
            }
            if (i % 2 != 0)
            {
                //cout << "CCNAS" << creditCardNum_As_String[i] << " ";
                int num = creditCardNum_As_String[i] - '0';
                oddCheckSum += num;
            }
        }
    }
    if (cardLength % 2 != 0)
    {
        for (int i = 0; i != cardLength; i++)
        {
            if (i % 2 != 0)
            {
                //cout << "CCNAS" << creditCardNum_As_String[i] << " ";
                int num = creditCardNum_As_String[i] - '0';
                int temp = (num * 2);
                //cout << "Temp: " << temp << " ";
                string tempo = to_string(temp);
                int length = tempo.length();
                for (int j = 0; j != length; j++)
                {
                    int last_digit = temp % 10;
                    temp /= 10;
                    oddCheckSum += last_digit;
                }
            }
            if (i % 2 == 0)
            {
                //cout << "CCNAS" << creditCardNum_As_String[i] << " ";
                int num = creditCardNum_As_String[i] - '0';
                evenCheckSum += num;
            }
        }
    }

    totalCheckSum = evenCheckSum + oddCheckSum;
    string new_check = to_string(totalCheckSum);
    cout << "total: " << totalCheckSum << "\n";

    if (new_check[new_check.size() - 1] == '0')
    {
        return true;
    }
    return false;
} 

int main()
{
    long long creditCardNum;
    cout << "Credit Card: ";
    cin >> creditCardNum;
    creditCardNum_As_String = to_string(creditCardNum);
    cardLength = creditCardNum_As_String.length();
    //cout << creditCardNum_As_String << "\n";
    //cout << cardLength << "\n";

    bool credit = checkSum();   

    cout << credit << "\n"; 
    
    if (creditCardNum_As_String[0] == '4')
    {
        if (cardLength == 13 || cardLength == 16)
        {
            if (credit)
            { 
                cout << "VISA" << "\n";
                return 0;
            }
        }
    }
    if (creditCardNum_As_String[0] == '3')
    {
        if (cardLength == 15)
        {
            if (credit)
            { 
                cout << "AMEX" << "\n";
                return 0;
            }
        }
    }
    if (creditCardNum_As_String[0] == '5' || creditCardNum_As_String[0] == '2')
    {
        if (cardLength == 16)
        {
            if (credit)
            { 
                cout << "MASTERCARD" << "\n";
                return 0;
            }
        }
    }

cout << "INVALID" << "\n";
return 1;
}