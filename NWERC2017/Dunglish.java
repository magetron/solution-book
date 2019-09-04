import java.util.HashMap;
import java.util.Scanner;

public class Dunglish {

	public static class Node {
		int correct, incorrect;
		int appr = 0;
		String eng;
		Node (int correct, int incorrect, String eng) {
			this.correct = correct;
			this.incorrect = incorrect;
			this.eng = eng;
		}

		void addCorrect () {
			correct++;
		}

		void addIncorrect () {
			incorrect++;
		}

		void addAppr () {
			appr++;
		}
	}

	public static void main (String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		scanner.nextLine();
		String dutchSentence = scanner.nextLine();
		int m = scanner.nextInt();
		scanner.nextLine();
		String[] orginalEntries = new String[m];
		for (int i = 0; i < m; i++) orginalEntries[i] = scanner.nextLine();
		HashMap<String, Node> dict = new HashMap<>();
		for (String originalEntry : orginalEntries) {
			String[] originalEntrySplit = originalEntry.split(" ");
			//System.out.println(originalEntry);
			if (!dict.containsKey(originalEntrySplit[0]))
				if (originalEntrySplit[2].equals("correct"))
					dict.put(originalEntrySplit[0], new Node(1, 0, originalEntrySplit[1]));
				else
					dict.put(originalEntrySplit[0], new Node(0, 1, originalEntrySplit[1]));
			else
				if (originalEntrySplit[2].equals("correct"))
					dict.get(originalEntrySplit[0]).addCorrect();
				else
					dict.get(originalEntrySplit[0]).addIncorrect();
		}
		String [] dutchWords = dutchSentence.split(" ");
		for (String dutchWord : dutchWords) dict.get(dutchWord).addAppr();
		long tot = 1;
		long cor = 1;
		for (String dutchWord : dict.keySet()) {
			Node entry = dict.get(dutchWord);
			tot *= Math.pow((entry.correct + entry.incorrect), entry.appr);
			cor *= Math.pow(entry.correct, entry.appr);
		}
		if (tot > 1) {
			System.out.println(cor + " correct");
			System.out.println(tot - cor + " incorrect");
		} else {
			boolean allCorrect = true;
			String translation = "";
			for (String dutchWord : dutchWords) {
				Node node = dict.get(dutchWord);
				if (allCorrect && node.incorrect > 0) allCorrect = false;
				translation += node.eng + " ";
			}
			System.out.println(translation);
			if (allCorrect) System.out.println("correct");
			else System.out.println("incorrect");
		}
	}
}

