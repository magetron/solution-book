import java.io.File;
import java.io.IOException;
import java.util.*;

public class Medium {
	HashMap<String, Integer> hashTags = new HashMap<>();

	public void parseFile (String fileName) throws IOException {
		File inputFile = new File(fileName);
		Scanner inputFileScanner = new Scanner(inputFile);
		while (inputFileScanner.hasNextLine()) {
			String timeStamp = inputFileScanner.nextLine();
			String postContent = inputFileScanner.nextLine();
			String contentHashTags[] = postContent.split(" #");
			Set<String> stringSet = new HashSet<>(Arrays.asList(contentHashTags));
			for (var hashTagString : stringSet) {
				System.out.println(hashTagString);
				if (hashTags.containsKey(hashTagString)) {
					hashTags.put(hashTagString, hashTags.get(hashTagString) + 1);
				} else {
					hashTags.put(hashTagString, 1);
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
		new Medium().parseFile("input.txt");
	}
}
