using System;
using System.Collections.Generic;
//using NUnit.Framework;
//using UnityEngine;
//using System.Linq;
//
//[TestFixture]
//public class OurScoreDisplayTest {
//	
//	[Test]
//	public void T00PassingTest () {
//		Assert.AreEqual (1, 1);
//	}
//
//	[Test]
//	public void T01Bowl1 () {
//		int[] rolls = {1};
//		string rollsString = "1";
//		Assert.AreEqual (rollsString, ScoreDisplay.FormatRolls (rolls.ToList()));
//	}
//
//	[Test]
//	public void T02BowlX () {
//		int[] rolls = {10};
//		string rollsString = "X "; // Remember the space
//		Assert.AreEqual (rollsString, ScoreDisplay.FormatRolls (rolls.ToList()));
//	}
//
//	[Test]
//	public void T03Bowl19 () {
//		int[] rolls = {1,9};
//		string rollsString = "1/"; // Remember the space
//		Assert.AreEqual (rollsString, ScoreDisplay.FormatRolls (rolls.ToList()));
//	}
//
//	[Test]
//	public void T04BowlStrikeInLastFrame () {
//		int[] rolls = {1,1, 1,1, 1,1, 1,1, 1,1, 1,1, 1,1, 1,1, 1,1, 10,1,1};
//		string rollsString = "111111111111111111X11"; // Remember the space
//		Assert.AreEqual (rollsString, ScoreDisplay.FormatRolls (rolls.ToList()));
//	}
//
//	[Test]
//	public void T05Bowl0 () {
//		int[] rolls = {0};
//		string rollsString = "-"; // Remember the space
//		Assert.AreEqual (rollsString, ScoreDisplay.FormatRolls (rolls.ToList()));
//	}
//
//	
//
//	//http://guttertoglory.com/wp-content/uploads/2011/11/score-2011_11_28.png
//	[Category ("Verification")]
//	[Test]
//	public void TG01GoldenCopyB1of3 () {
//		int[] rolls = { 10, 9,1, 9,1, 9,1, 9,1, 7,0, 9,0, 10, 8,2, 8,2,10};
//		string rollsString = "X 9/9/9/9/7-9-X 8/8/X";
//		Assert.AreEqual (rollsString, ScoreDisplay.FormatRolls(rolls.ToList()));
//	}
//	
//	//http://guttertoglory.com/wp-content/uploads/2011/11/score-2011_11_28.png
//	[Category ("Verification")]
//	[Test]
//	public void TG02GoldenCopyB2of3 () {
//		int[] rolls = { 8,2, 8,1, 9,1, 7,1, 8,2, 9,1, 9,1, 10, 10, 7,1};
//		string rollsString = "8/819/718/9/9/X X 71";
//		Assert.AreEqual (rollsString, ScoreDisplay.FormatRolls(rolls.ToList()));
//	}
//	
//	//http://guttertoglory.com/wp-content/uploads/2011/11/score-2011_11_28.png
//	[Category ("Verification")]
//	[Test]
//	public void TG03GoldenCopyB3of3 () {
//		int[] rolls = { 10, 10, 9,0, 10, 7,3, 10, 8,1, 6,3, 6,2, 9,1,10};
//		string rollsString = "X X 9-X 7/X 8163629/X";
//		Assert.AreEqual (rollsString, ScoreDisplay.FormatRolls(rolls.ToList()));
//	}
//	
//	// http://brownswick.com/wp-content/uploads/2012/06/OpenBowlingScores-6-12-12.jpg
//	[Category ("Verification")]
//	[Test]
//	public void TG04GoldenCopyC1of3 () {
//		int[] rolls = { 7,2, 10, 10, 10, 10, 7,3, 10, 10, 9,1, 10,10,9};
//		string rollsString = "72X X X X 7/X X 9/XX9";
//		Assert.AreEqual (rollsString, ScoreDisplay.FormatRolls(rolls.ToList()));
//	}
//	
//	// http://brownswick.com/wp-content/uploads/2012/06/OpenBowlingScores-6-12-12.jpg
//	[Category ("Verification")]
//	[Test]
//	public void TG05GoldenCopyC2of3 () {
//		int[] rolls = { 10, 10, 10, 10, 9,0, 10, 10, 10, 10, 10,9,1};
//		string rollsString = "X X X X 9-X X X X X91";
//		Assert.AreEqual (rollsString, ScoreDisplay.FormatRolls(rolls.ToList()));
//	}
//
//}