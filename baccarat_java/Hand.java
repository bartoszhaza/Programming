public class Hand extends CardCollection{
	// method to ovveride the to string
	@Override
	public String toString(){
		String returnValue = " ";
		if(cards.size() == 2){
			returnValue = String.format("%s %s", cards.get(0).toString(), cards.get(1).toString());
		}
		if(cards.size() == 3){
			returnValue = String.format("%s %s %s", cards.get(0).toString(), cards.get(1).toString(), cards.get(2).toString());
		}
		return returnValue;
	}
	// method to count the score of a deck
	public int value(){
		int totalScore = 0;
		for(Card x : cards){
			totalScore = totalScore + x.value();
		}
		return totalScore % 10;
	}
}