import java.util.Scanner;
import java.util.*;
public class Game{
	private int bankerWin =0; // store banker score
	private int playerWin = 0; // store player score
	private int draw = 0; // store the draw score
	private int roundNumber; // this will store the round number
	public static void main(String[] args){
		System.out.printf("Enter the number of decks (4), (6) or (8): "); // prompt for the amount of decks
		Scanner deckInput = new Scanner(System.in); // new scanner for user input
		int deckNumber = deckInput.nextInt(); // will hold the user input
		Game newGame = new Game(deckNumber); // new game object // this will call the playRound method in main
		newGame.playWithPrompt(); // this will call the playWithPrompt in main
	}

	private Shoe newShoe; // new shoe
	private Hand playerHand; // new player hand
	private Hand bankerHand; // new banker hand

	private Game(int numDecks){
		newShoe = new Shoe(numDecks); // deck number added
		newShoe.shuffle(); // the shoe will be shuffled
		playerHand = new Hand(); // player hand added to the game
		bankerHand = new Hand(); // banker hand added to the game
	}

// the playRound method is where the actual rules of the game will be applied
private void playRound(){
		roundNumber++; // increment round number
		System.out.println("Round " + roundNumber); // this will print the round numberf
		
		// two cards will be delt at the start
		playerHand.add(newShoe.deal());
		playerHand.add(newShoe.deal());
		bankerHand.add(newShoe.deal());
		bankerHand.add(newShoe.deal());

		// the hand of the player and the banker along with the score they hold will be printed
		System.out.println("Player Hand: " + playerHand);
		System.out.println("Player score: " + playerHand.value());
		System.out.println("Banker Hand: " + bankerHand);
		System.out.println("Banker score: " + bankerHand.value());

		// accroding to the baccarat rules if the playerHand value is less than 6 the player will draw a third card
		if(playerHand.value() < 6){
			Card thirdCard = newShoe.deal(); // needed to find the value of the third card
			playerHand.add(thirdCard); // deal player a third card
			System.out.println("Third card delt to player...");
			System.out.println("Player hand: " + playerHand);
			System.out.println("Player score: " + playerHand.value());
			
			// according to the rules of baccarat if the third cards value divided by 5 is less than or equal to the bankerHand value then the banker draws a card
			if(thirdCard.value() / 5 <= bankerHand.value()){
				bankerHand.add(newShoe.deal()); // deal a third card to the banker
				System.out.println("Third card delt to banker...");
				System.out.println("Banker hand: " + bankerHand);
				System.out.println("Banker score: " + bankerHand.value());
			}
		}

		// if banker's hand value is less than 6
		else if(bankerHand.value() < 6){ 
			Card thirdCard = newShoe.deal();
			bankerHand.add(thirdCard); // deal banker a third card
			System.out.println("Third card delt to banker...");
			System.out.println("Banker Hand: " + bankerHand);
			System.out.println("Banker score: " + bankerHand.value());
		}

		// if the player's hand is less than the banker hand then increment banker score
		if(playerHand.value() < bankerHand.value()){
			bankerWin++; // increment banker hand
			System.out.println("Banker Wins!"); // show banker wins 
		}

		// if player hand is greater then increment player score
		else if(bankerHand.value() < playerHand.value()){
			playerWin++; // increment player score
			System.out.println("Player Wins!"); // show player wins
		}

		// if both are equal increment draw value
		else if(bankerHand.value() == playerHand.value()){
			draw++; // increment draw value
			System.out.println("Draw!"); // show that it's a draw
		}
}

private void play(){
	// loop through playRound if the shoe is greater than or equal to 6
	while(newShoe.size() >= 6){
		playRound(); // play the round
		playerHand.discard(); // discard the previous cards 
		bankerHand.discard(); // discard the previous cards for banker
	}
}

// prompt that allows player to play another round
private void playWithPrompt(){
	Scanner choiceInput = new Scanner(System.in);
	char choicePlay = 'y'; // char variable to store the choice

	// while the shoe is more than or equal to 6 it will play next round only if the 
	// user has chosen "y"
	while(newShoe.size() >= 6){
		if(Character.toLowerCase(choicePlay) == 'y'){
			playRound(); // call playRound() method
			playerHand.discard(); // discard previos player cards
			bankerHand.discard(); // discard previos banker cards
			System.out.printf("Do you want to play the next round (Y) or (N) ?"); // user promp
			choicePlay = choiceInput.next().charAt(0); // choice
		}
		// if the input is n not case dependent then the round number and wins for each player will be displayed
		else if(Character.toLowerCase(choicePlay) == 'n'){
			System.out.println("Number of rounds: " + roundNumber);
			System.out.println("Player number of wins: " + playerWin);
			System.out.println("Banker number of wins: " + bankerWin);
			System.out.println("Draws: " + draw);
			break; // to break the while loop when n is entered 
		}
		else{
			// if either "y" or "n" are not entered then the following message will be displayed
			System.out.print("Index out of bounds! Enter (Y) or (N): ");
			choicePlay = choiceInput.next().charAt(0);
		}
	}

	// if the size of the shoe is less than 6 then it will display that the shoe is exhausted
	// and the number of rounds played along with the scores
	if(newShoe.size() < 6){
		System.out.println("The shoe has been exhausted!");
		System.out.println("Number of rounds: " + roundNumber);
		System.out.println("Player number of wins: " + playerWin);
		System.out.println("Banker number of wins: " + bankerWin);
		System.out.println("Draws: " + draw);
	}

}
}