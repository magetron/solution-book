import java.io.File;
import java.io.IOException;
import java.util.*;

public class Hard {

	ArrayList<Post> posts = new ArrayList<>();

	public void parseFile (String fileName) throws IOException {
		File inputFile = new File(fileName);
		Scanner inputFileScanner = new Scanner(inputFile);
		while (inputFileScanner.hasNextLine()) {
			String timeStamp = inputFileScanner.nextLine();
			String postContent = inputFileScanner.nextLine();
			Post post;
			try {
				post = new Post(Integer.parseInt(timeStamp), postContent);
			} catch (NumberFormatException e) {
				break;
			}
			posts.add(post);
		}
		Collections.sort(posts, Comparator.comparingInt((Post post) -> post.timeStamp));
		String hottestTag = "";
		int maxOccurrences = 0;
		for (var post : posts) {
			HashMap<String, Integer> hashtagsRange = new HashMap<>();
			for (var next60post : posts) {
				if (next60post.timeStamp <= post.timeStamp + 60) {
					hashtagsRange.putAll(next60post.tags);
				} else break;
			}
			String hottestTagRange = "";
			int maxOccurrencesRange = 0;
			for (var tag : hashtagsRange.keySet()) {
				if (hashtagsRange.get(tag) > maxOccurrencesRange) {
					maxOccurrencesRange = hashtagsRange.get(tag);
					hottestTagRange = tag;
				}
			}
			if (maxOccurrencesRange > maxOccurrences) {
				maxOccurrences = maxOccurrencesRange;
				hottestTag = hottestTagRange;
			}
		}
		System.out.println(hottestTag);
	}


	public static void main(String[] args) throws IOException {
		new Hard().parseFile("input.txt");
	}
}


