#include <iostream>
using namespace std;

enum Suit
{
    clubs,
    diamonds,
    hearts,
    spades
};
const int JACK = 11, QUEEN = 12, KING = 13, ACE = 14;

class Card
{
private:
    int number;
    Suit suit;

public:
    Card() : number(2), suit(clubs) {}
    Card(int n, Suit s) : number((n < 2 || n > 14) ? 2 : n), suit(s) {}

    int getNumber() const { return number; }
    Suit getSuit() const { return suit; }

    void displayCard() const;
    bool isEqual(const Card &) const;
};

void Card::displayCard() const
{
    if (number >= 2 && number <= 10)
        cout << number << " of ";
    else
        switch (number)
        {
        case JACK:
            cout << "Jack of ";
            break;
        case QUEEN:
            cout << "Queen of ";
            break;
        case KING:
            cout << "King of ";
            break;
        case ACE:
            cout << "Ace of ";
            break;
        }

    switch (suit)
    {
    case clubs:
        cout << "clubs.";
        break;
    case diamonds:
        cout << "diamonds.";
        break;
    case hearts:
        cout << "hearts.";
        break;
    case spades:
        cout << "spades.";
        break;
    }
    cout << endl;
}

bool Card::isEqual(const Card &c) const
{
    return (number == c.number && suit == c.suit);
}

Card pickCard(const Card &, const Card &, const Card &);
void swapTwoCards(Card &, Card &);

int main()
{
    Card card1{KING, diamonds};
    Card card2(7, spades);
    Card card3{QUEEN, hearts};

    Card chosen, guess;

    cout << "Available Cards:\n";
    card1.displayCard();
    card2.displayCard();
    card3.displayCard();

    chosen = pickCard(card1, card2, card3);

    cout << "\nNow shuffling cards...\n";
    swapTwoCards(card1, card2);
    swapTwoCards(card3, card2);
    swapTwoCards(card1, card3);

    cout << "\nWhere is your card now?\n";
    guess = pickCard(card1, card2, card3);

    if (guess.isEqual(chosen))
        cout << "🎉 Right Choice!\n";
    else
        cout << "❌ Wrong Guess.\n";

    return 0;
}

Card pickCard(const Card &card1, const Card &card2, const Card &card3)
{
    Card chosen;
    int card;
    do
    {
        cout << "Pick your card (1/2/3): ";
        cin >> card;
    } while (card < 1 || card > 3);

    switch (card)
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
    }
    return chosen;
}

void swapTwoCards(Card &card1, Card &card2)
{
    Card temp = card1;
    card1 = card2;
    card2 = temp;
}