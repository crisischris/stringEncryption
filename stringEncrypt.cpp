/******************************************************************************
** Author: Chris Nelson 
** Date: 
** Description: 
******************************************************************************/

#include<iostream>
#include<string>
#include"helper.cpp"

int main()
{

	int choice = 1;
	int option = 0;

	std::string prompt = "Enter 1 to encrypt \nEnter 2 to decrypt";
	std::string stringPrompt = "What message would you like to encrypt?";
	std::string decryptPrompt = "What message would you like to decrypt?";
	std::string cipherPrompt = "Enter the cipher string";

	helper::splashScreen(" ENCRYPT / DECRYPT ",1);

	while(choice == 1)
	{
		
		//get the option
		option = helper::getInt(1, 1, 2, prompt);
		
		//main logic
		switch(option)
		{
			case 1: 	
			{
				std::string secret = helper::getString(stringPrompt);
				std::string cipher = helper::getString(cipherPrompt);

				helper::newLine(1);
				std::cout << "Secret message: " << secret << std::endl;
				std::cout << "Cipher: " << cipher << std::endl;
	
				std::string encryptString = secret;

				int k = 0;
				for(int i = 0; i < encryptString.length(); i++)
				{
					if(k == cipher.length())
						k = 0;	

					for(int j = 0; j < cipher[k]; j++)
					{
						if(encryptString[i] == 126)
							encryptString[i] = 32;
						else
							encryptString[i]++;
					}	

					k++;
				}
				
				std::cout << "Encrypted message: " << encryptString << std::endl;

				helper::newLine(2);
				break;
			}
			case 2:
			{
				std::string encryptString = helper::getString(decryptPrompt);
				std::string cipher = helper::getString(cipherPrompt);

				helper::newLine(1);
				std::cout << "Encrypted message: " << encryptString << std::endl;
				std::cout << "Cipher: " << cipher << std::endl;
				
				int k = 0;
				for(int i = 0; i < encryptString.length(); i++)
				{
					if(k == cipher.length())
						k = 0;	

					for(int j = 0; j < cipher[k]; j++)
					{
						if(encryptString[i] == 32)
							encryptString[i] = 126;
						else
							encryptString[i]--;
					}	

					k++;
				}

				std::cout << "Decrypted message: " << encryptString << std::endl;

				helper::newLine(2);
				break;
			}

		}

		choice = helper::getInt(1, "Enter 1 to continue, 0 to exit");
		if(choice == 0)
			break;
		else
			choice = 1;

		helper::newLine(2);
	}	

	return 0;
}
