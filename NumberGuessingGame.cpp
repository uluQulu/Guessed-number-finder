// NumberGuessingGame.cpp : Defines the entry point for the console application.
// This is an easy game which asks user a number to guess in [1, 100] range and tries to find that number with no more than 7 questiosn :)

#include "stdafx.h"
#include "std_lib_facilities.h"

bool binary_search(int min, int max, int guess_num)
{
	string verify;
	cout << "Is the number you are guessing less than "<<guess_num<<"? (`yes` or `no`)\n";
	while (verify != "yes" || verify != "no")
	{
		cin >> verify;
		if (verify == "yes")
		{
			cout << "range:\t" << min << '\t' << guess_num - 1 << '\n';
			return true;
		}
		else if (verify == "no")
		{
			cout << "range:\t" << guess_num << '\t' << max << '\n';
			return false;
		}
		else
		{
			cout << "Phew! ~please enter either `yes` or `no`\n";
		}
	}
}


int main()
{
	cout << "\nHello there! Let's play a quick game :)\n\n";
	cout << "You will guess a number in your mind in [0, 128) range and I will find it by asking no more than 7 questions!\n\n";
	cout << "Alrighty! ~please, guess a number, type `yes` to start the game\n";
	
	string approval;
	while (approval != "yes" && approval != "cancel")
	{
		cin >> approval;
		if (approval == "yes")
		{
			cout << "Let's go!\n\n";
		}
		else if (approval == "no")
		{
			cout << "Not ready? ~think more or just type `yes` to start\n";
		}
		else if (approval == "cancel")
		{
			cout << "See you next time!\n\n";
		}
		else
		{
			cout << "Phew! ~please enter either `yes` to start or `cancel` to stop the game\n";
		}
	}
	
	string do_try = "yes";
	while (do_try == "yes" && approval != "cancel")
	{
		// Asking questions here:

		int guess_num = 64;   // initial separation point for [0, 128) range- 50
		bool approve;
		int min = 0;   // min value from [0, 128) range- 0
		int max = 127;   // max value from [0, 128) range- 100
		int phase = 0;   // count of attempts- 0

		while (max!=min)
		{
			++phase;
			cout << "\nPhase: " << phase << "\n";
			approve = binary_search(min, max, guess_num);
			if (approve == true)
			{
				min = min;
				max = guess_num - 1;
				guess_num = max - (max - min) / 2;
			}
			else if (approve == false)
			{
				min = guess_num;
				max = max;
				guess_num = max - (max - min) / 2;
			}

			if (max == min)
			{
				cout << "Hey! You have guessed " << max << " ;)\n\n";

			}
		}


		cout << "\n\nDo you want to try again? (`yes` or `no`)\n";
		cin >> do_try;
		while (do_try!="yes" && do_try!="no")
			{
				cout << "Phew! ~please enter either `yes` to replay or `no` to quit\n";
				cin >> do_try;
			}
		if (do_try == "yes")
		{
			cout << "\n\nGood luck! :)\n\n\n";
		}
		else if (do_try == "no")
		{
			cout << "\n\nCome back later to play more! :)\n\n\n";
			do_try = "no";
		}

	}
	
	keep_window_open();

}

