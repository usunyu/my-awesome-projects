package sun;

import java.net.*;
import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

import de.l3s.boilerpipe.BoilerpipeProcessingException;
import de.l3s.boilerpipe.extractors.ArticleExtractor;
import de.l3s.boilerpipe.extractors.DefaultExtractor;
import name.fraser.neil.plaintext.*;

public class ContentMatch {
	
	/**
	 * @param urlStr the url of content
	 * @return the content of url
	 */
	public static String getContent(String urlStr) {
		String content = "";
		try {
			URL url = new URL(urlStr);
	        BufferedReader in = new BufferedReader(new InputStreamReader(url.openStream()));

	        String inputLine;
	        while ((inputLine = in.readLine()) != null)
	        	content += inputLine;
	        in.close();
		} catch(Exception e) {
			e.printStackTrace();
		}
		return content;
	}
	
	/**
	 * @return input
	 */
	public static String getString() {
		System.out.println("Please enter the url of content:");
		
		String str = null;
		try{
		    BufferedReader bufferRead = new BufferedReader(new InputStreamReader(System.in));
		    str = bufferRead.readLine();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
		
		return str;
	}
	
	/**
	 * reference: http://zebardast.ir/en/how-to-get-pure-content-from-html-page-in-java-via-regex/
	 * @param htmlContent full content of page with HTML codes.
	 * @return a pure content 
	 */
	public static String getPureContent(String htmlContent) {
		// 1- Remove the script tags and inclusive content:
		Pattern pattern;
		String content;
		pattern = Pattern.compile("<script.*?>.*?</script>", Pattern.DOTALL | Pattern.CASE_INSENSITIVE);
		content = pattern.matcher(htmlContent).replaceAll("");
		
		// 2- Remove the style tags and inclusive content:
		pattern = Pattern.compile("<style.*?>.*?</style>", Pattern.DOTALL | Pattern.CASE_INSENSITIVE);
		content = pattern.matcher(content).replaceAll("");
		
		// 3- Remove all HTML tags without inclusive content.
		pattern = Pattern.compile("<[^>]*>");
		content = pattern.matcher(content).replaceAll("");
		
		// 4- Replace new lines, tabs and multiple spaces with a single space.
		content = content.replaceAll("\n+", " ");
		content = content.replaceAll("\t+", " ");
		content = content.replaceAll("(  )+", "");
		
		return content;
	}

	
	public static void main(String[] args) {
		// String urlStr1 = getString();
		// String urlStr2 = getString();
		
		// test
		String urlStr1 = "http://online.wsj.com/article/SB10001424052702304213904579090660766011326.html";
		String urlStr2 = "http://www.marketwatch.com/story/kenya-assault-on-shopping-mall-stuns-nation-2013-09-22";
		
		//String content1 = getContent(urlStr1);
		//String content2 = getContent(urlStr2);
		
		//String pureContent1 = getPureContent(content1);
		//System.out.println(pureContent1);
		//String pureContent2 = getPureContent(content2);
		
		String pureContent1 = "", pureContent2 = "";
		try {
			URL url1 = new URL(urlStr1);
			URL url2 = new URL(urlStr2);
			
			// reference: http://code.google.com/p/boilerpipe/wiki/QuickStart
			String content1 = DefaultExtractor.INSTANCE.getText(url1);
			String content2 = DefaultExtractor.INSTANCE.getText(url2);
			pureContent1 = getPureContent(content1);
			pureContent2 = getPureContent(content2);
			//System.out.println(pureContent1);
		} catch (Exception e) {
			e.printStackTrace();
		}

		// reference: http://code.google.com/p/google-diff-match-patch/wiki/API
		diff_match_patch dmp = new diff_match_patch();
		LinkedList<Diff> diffs = dmp.diff_main(pureContent1, pureContent2);
		
		StringBuilder equalBuilder = new StringBuilder();
		StringBuilder insertBuilder = new StringBuilder();
		StringBuilder deleteBuilder = new StringBuilder();
		
		dmp.diff_cleanupSemantic(diffs);
		
		ListIterator<Diff> iterator = diffs.listIterator();
		while(iterator.hasNext()) {
			Diff difference = iterator.next();
			
			if(difference.operation == Operation.EQUAL)
				equalBuilder.append(difference.text);
			
			if(difference.operation == Operation.INSERT)
				insertBuilder.append(difference.text);
			
			if(difference.operation == Operation.DELETE)
				deleteBuilder.append(difference.text);
		}
		
		//int distance = dmp.diff_levenshtein(diffs);
		//System.out.println("Distance: " + distance);
		
		String equalStr = equalBuilder.toString();
		String insertStr = insertBuilder.toString();
		String deleteStr = deleteBuilder.toString();
		
		System.out.println("Report:");
		System.out.println("Content 1's length: " + pureContent1.length());
		System.out.println("Content 2's length: " + pureContent2.length());
		//System.out.println("Equal string: " + equalStr); 
		//System.out.println("Insert string: " + insertStr); 
		//System.out.println("Delete string: " + deleteStr); 
		System.out.println("Equal's length: " + equalStr.length());
		System.out.println("Insert's length: " + insertStr.length());
		System.out.println("Delete's length: " + deleteStr.length());
	}
}
