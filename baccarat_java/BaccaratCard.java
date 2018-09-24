public class BaccaratCard extends Card{ 
	// two baccarat card constructors 
	BaccaratCard(char rank, char suit){
		super(rank, suit);
	}
	BaccaratCard(String code){
		super(code);
	}

	// method to obtain the value of a card/ hand
	public int value(){
		return super.value() % 10;
	}


}