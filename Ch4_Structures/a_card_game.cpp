/*
This program is a simple card-guessing game.

Concepts demonstrated:
-----------------------
• Using structures (struct) to group related data (card suit and number)
• Declaring symbolic constants for better readability
• Swapping values using a temporary variable
• Basic control flow (switch and if)
*/

#include <iostream>
using namespace std;

// enum suits
enum Suits
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

// Define a structure representing a card
struct Card
{
    int number; // Card number (2–10, 11=Jack, 12=Queen, 13=King, 14=Ace)
    Suits suit; // Suit (0=Clubs, 1=Diamonds, 2=Hearts, 3=Spades)
};

// Constants for face cards
const int JACK = 11, QUEEN = 12, KING = 13, ACE = 14;

int main()
{
    Card temp, prize, chosen;
    Card card1, card2, card3;
    int position;

    // Initialize the cards
    card1 = {JACK, CLUBS};
    cout << "Card 1 is Jack of Clubs.\n";

    card2 = {3, HEARTS};
    cout << "Card 2 is 3 of Hearts.\n";

    card3 = {KING, CLUBS};
    cout << "Card 3 is King of Clubs.\n";

    cout << "\nCard 2 is the prize card. Try to keep track!\n";
    prize = card2;

    // Shuffle the cards by swapping
    cout << "\nNow I'm shuffling the cards...\n";

    cout << "Swapping card1 and card2...\n";
    temp = card2;
    card2 = card1;
    card1 = temp;

    cout << "Swapping card2 and card3...\n";
    temp = card3;
    card3 = card2;
    card2 = temp;

    cout << "Swapping card1 and card3...\n";
    temp = card3;
    card3 = card1;
    card1 = temp;

    // Let player choose
    cout << "\nPick a card (1, 2, or 3): ";
    cin >> position;

    switch (position)
    {
    case 1:
        chosen = card1;
        break;
    case 2:
        chosen = card2;
        break;
    case 3:
        chosen = card3;
        break;
    default:
        cout << "Invalid choice!" << endl;
        return 1;
    }

    // Compare chosen card with the prize
    if (chosen.number == prize.number && chosen.suit == prize.suit)
        cout << "\n🎉 You guessed it right! You found the prize card!\n";
    else
        cout << "\n❌ Wrong guess. Better luck next time!\n";

    return 0;
}

/*
🃏 Notes:
---------
1. The Card struct holds two pieces of information: number and suit.
2. prize = card2 → sets the prize card before shuffling.
3. The cards are shuffled by swapping their contents three times.
4. The user guesses the card by number (1, 2, or 3).
5. If both number and suit match the prize, the guess is correct.
*/