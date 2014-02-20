// Learning MapReduce by Nitesh J.
// Word Count Mapper. 
import java.io.IOException;
import java.util.StringTokenizer;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class WordCountMapper extends
		Mapper<LongWritable, Text, Text, IntWritable> {

	private final static IntWritable one = new IntWritable(1);
	private Text word = new Text();

	@Override
	public void map(LongWritable key, Text value, Context context)
			throws IOException, InterruptedException {
		String line = value.toString();
		StringTokenizer itr = new StringTokenizer(line);

		while (itr.hasMoreTokens()) {
			// just added the below line to convert everything to lower case
			word.set(itr.nextToken().toLowerCase());
			// the following check is that the word starts with an alphabet.
			if (Character.isAlphabetic((word.toString().charAt(0)))) {
				context.write(word, one);
			}
		}
	}

}
