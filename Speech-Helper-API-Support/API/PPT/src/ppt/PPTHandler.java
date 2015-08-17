package ppt;

import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintWriter;

import org.apache.poi.hslf.HSLFSlideShow;
import org.apache.poi.hslf.model.Notes;
import org.apache.poi.hslf.model.Slide;
import org.apache.poi.hslf.model.TextRun;
import org.apache.poi.hslf.usermodel.SlideShow;
import org.apache.poi.poifs.filesystem.POIFSFileSystem;

public class PPTHandler {
	// http://www.coderanch.com/how-to/java/ReadPowerPoint
	public static void main(String[] args) throws Exception {
		if (args.length == 0) {
			System.out.println("Usage: java PPTHandler <PPT file>");
			System.exit(0);
		}
		String filePath = args[0];
		File file = new File(filePath);
		PrintWriter writer = new PrintWriter(filePath + ".txt", "UTF-8");
		
		if(!file.exists() || file.isDirectory()) {
			System.err.println(filePath + "not exists or it is directory");
			writer.println("error");
			writer.close();
			System.exit(0);
		}
		
		InputStream fis = new FileInputStream(filePath);
		
		try {
			POIFSFileSystem fs = new POIFSFileSystem(fis);
			HSLFSlideShow show = new HSLFSlideShow(fs);
			
			// slide
	        SlideShow ss = new SlideShow(show);
	        Slide[] slides = ss.getSlides();
	        
	        writer.println("correct");
	        for (int i=0; i<slides.length; i++) {
	        	// text runs
	        	TextRun[] runs = slides[i].getTextRuns();
	        	
	        	 // notes
	            Notes notes = slides[i].getNotesSheet();
	            if (notes != null) {
	                runs = notes.getTextRuns();
	                writer.println(i + 1 + ":" + runs[0].getText());
	            }
	        }
	        writer.close();
		}
		catch (Exception e) {
			System.err.println(e.getMessage());
			writer.println("error");
			writer.close();
			System.exit(0);
		}
	}
}
