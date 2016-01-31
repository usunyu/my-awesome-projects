using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public static class ActionMaster2 {
	public enum Action {Tidy, Reset, EndTurn, EndGame, Undefined};
	
	public static Action NextAction (List<int> rolls) {
		Action nextAction = Action.Undefined;
		
		for (int i = 0; i < rolls.Count; i++) { // Step through rolls
			
			if (i == 20) {
				nextAction = Action.EndGame;
			} else if ( i >= 18 && rolls[i] == 10 ){ // Handle last-frame special cases
				nextAction = Action.Reset;
			} else if ( i == 19 ) {
				if (rolls[18]==10 && rolls[19]==0) {
					nextAction = Action.Tidy;
				} else if (rolls[18] + rolls[19] == 10) {
					nextAction = Action.Reset;
				} else if (rolls [18] + rolls[19] >= 10) {  // Roll 21 awarded
					nextAction = Action.Tidy;
				} else {
					nextAction = Action.EndGame;
				}
			} else if (i % 2 == 0) { // First bowl of frame
				if (rolls[i] == 10) {
					rolls.Insert (i, 0); // Insert virtual 0 after strike
					nextAction = Action.EndTurn;
				} else {
					nextAction = Action.Tidy;
				}
			} else { // Second bowl of frame
				nextAction = Action.EndTurn;
			}
		}
		
		return nextAction;
	}
}