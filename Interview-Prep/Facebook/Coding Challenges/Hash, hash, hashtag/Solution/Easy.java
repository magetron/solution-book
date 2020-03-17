import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;

public class Easy {

	HashMap<String, Integer> hashTags = new HashMap<>();

	public void parseFile (String fileName) throws IOException {
		File inputFile = new File(fileName);
		Scanner inputFileScanner = new Scanner(inputFile);
		while (inputFileScanner.hasNextLine()) {
			String timeStamp = inputFileScanner.nextLine();
			String postContent = inputFileScanner.nextLine();
			String contentHashTags[] = postContent.split(" #");
			for (int i = 1; i < contentHashTags.length; i++) {
				if (hashTags.containsKey(contentHashTags[i])) {
					hashTags.put(contentHashTags[i], hashTags.get(contentHashTags[i]) + 1);
				} else {
					hashTags.put(contentHashTags[i], 1);
				}
			}
			if (inputFileScanner.hasNextLine()) {
				inputFileScanner.nextLine();
			}
		}
		int max = 0;
		String maxTag = "";
		for (var key : hashTags.keySet()) {
			if (hashTags.get(key) > max) {
				max = hashTags.get(key);
				maxTag = key;
			}
		}
		System.out.println(maxTag);
	}

	public static void main(String[] args) throws IOException {
		new Easy().parseFile("input.txt");
	}
}

