package slides;

import java.io.IOException;
import java.io.InputStream;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.poi.hslf.extractor.PowerPointExtractor;
import org.apache.poi.xslf.extractor.XSLFPowerPointExtractor;
import org.apache.poi.xslf.usermodel.XMLSlideShow;

import com.google.appengine.api.blobstore.BlobKey;
import com.google.appengine.api.blobstore.BlobstoreInputStream;
import com.google.appengine.api.users.User;
import com.google.appengine.api.users.UserService;
import com.google.appengine.api.users.UserServiceFactory;

@SuppressWarnings("serial")
public class SlidesServlet extends HttpServlet {
	private PowerPointExtractor ppt;
	private XSLFPowerPointExtractor pptx;

	@Override
	public void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws IOException {
		UserService userService = UserServiceFactory.getUserService();
		User user = userService.getCurrentUser();

		if (user != null) {
			resp.setContentType("text/plain");
			resp.getWriter().println("Hello, " + user.getNickname());
		} else {
			resp.sendRedirect(userService.createLoginURL(req.getRequestURI()));
		}

		BlobKey blobKey = new BlobKey(req.getParameter("blob-key"));

		BlobstoreInputStream blobInput = new BlobstoreInputStream(blobKey);
		InputStream input = (InputStream) blobInput;

		// ppt = new PowerPointExtractor(new HSLFSlideShow(input));

		// System.out.println(ppt.getNotes());
		
		pptx = new XSLFPowerPointExtractor(new XMLSlideShow(input));

		System.out.println(pptx.getText(false, true));
	}
}
