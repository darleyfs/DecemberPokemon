#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

// Helper class that contains user interface components
class UI {
public:

	UI() {

	}

	// Pauses the console, and waits for the user to press enter to continue.
	void PressEnterToContinue() {
		std::cout << "Press enter to continue...";
		std::cin.get();
	}

	void ClearScreen() {
		system("CLS");
	}

	void TypeWriterEffect(std::string message) {

		for (int i = 0; i < message.size(); i++) {
			// Display one letter at a time
			std::cout << message[i];

			// And then wait for 20 milliseconds
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
	}

	/// <summary>
	/// Displays a message in a formatted message box
	/// </summary>
	/// <param name="message">Text to be displayed as a message</param>
	void DisplayMessage(std::string message) {
		ClearScreen();

		std::cout << "============================================================\n" << std::endl;

		std::cout << "  ";

		TypeWriterEffect(message);

		std::cout << "\n" << std::endl;

		std::cout << "============================================================\n" << std::endl;

		PressEnterToContinue();
	}

	void DisplayMessage(std::string subject, std::string message) {
		ClearScreen();

		std::cout << "============================================================\n" << std::endl;

		std::cout << "  " << subject << ": ";

		TypeWriterEffect(message);

		std::cout << "\n" << std::endl;

		std::cout << "============================================================\n" << std::endl;

		PressEnterToContinue();
	}

	std::string PromptUser(std::string primeText, std::string promptText) {
		std::string result = "";

		do {
			ClearScreen();
			std::cout << primeText << std::endl;
			std::cout << promptText << ": ";
			getline(std::cin, result);

			if (result == "") {
				std::cout << promptText << " can not be empty! Please try again." << std::endl;
				PressEnterToContinue();
			}

		} while (result == "");


		return result;
	}

	int PromptUserWithMenu(std::string primeText, std::vector<std::string> menuOptions, std::string promptText = "Choice") {

		int choice = 0;

		do {
			system("cls");

			std::string tempChoice = "";

			std::cout << primeText << "\n" << std::endl;

			for (int i = 0; i < menuOptions.size(); i++) {
				std::cout << "[" << (i + 1) << "] " << menuOptions[i] << std::endl;
			}

			std::cout << "\n" << promptText << ": ";

			getline(std::cin, tempChoice);
			choice = std::stoi(tempChoice);

			if (choice < 1 || choice > menuOptions.size()) {
				std::cout << "Invalid menu selection. Please try again." << std::endl;
				PressEnterToContinue();
			}
		} while (choice < 1 || choice > menuOptions.size());

		return choice;
	}
};