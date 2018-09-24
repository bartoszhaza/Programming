import java.util.Collections;
public class Shoe extends CardCollection{
	private int numDecks;
	Shoe(int numDecks){
		// if statement that if the number of decks isn't 4, 6 or 8 it will print out an error message
		if(numDecks != 4 && numDecks != 6 && numDecks != 8){
			System.out.println("The number of decks specified is invalid!");
		}
		else {
			// this will loop through the number of decks from 4 - 8
			for(int i = 0; i < numDecks; i++)
			{
				// loop through the ranks, there are 13 of them so it will loop until it reaches 13
				for(int k = 0; k < 13; k++)
				{
					// mew variable rank that will get ranks and get the number that k ends up being as it increments
					char rank = Card.getRanks().get(k);

					// loop through the suits, there are 4 of them so it will stop at 4
					for(int j = 0; j < 4; j++)
					{
						// suit variable to get the suits appropriate to the number j is
						char suit = Card.getSuits().get(j);
						// new baccarat object for ranks and suits
						BaccaratCard newCard = new BaccaratCard(rank, suit);
						// add the new BaccaratCarc object
						cards.add(newCard);
					}
				}
			}
		}
	}
	
	// deal method that removes the top card and removes it
	public Card deal(){
		Card topCard = cards.get(cards.size()-1);
		cards.remove(cards.size()-1);
		return topCard;
	}
	
	// method to shuffle the cards
	public void shuffle(){
		Collections.shuffle(cards);
	}
}