import java.util.Comparator;
import java.util.HashMap;

public class Post{

	public int timeStamp;
	public HashMap<String, Integer> tags = new HashMap<>();

	Post (int timeStamp, String content) {
		this.timeStamp = timeStamp;
		String contentHashTags[] = content.split(" #");
		for (int i = 1; i < contentHashTags.length; i++) {
			if (tags.containsKey(contentHashTags[i])) {
				tags.put(contentHashTags[i], tags.get(contentHashTags[i]) + 1);
			} else {
				tags.put(contentHashTags[i], 1);
			}
		}
	}

}
