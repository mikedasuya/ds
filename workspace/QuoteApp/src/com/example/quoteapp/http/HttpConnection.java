package com.example.quoteapp.http;

import java.io.ByteArrayOutputStream;
import java.io.IOException;

import org.apache.http.HttpResponse;
import org.apache.http.HttpStatus;
import org.apache.http.StatusLine;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;

import android.R.string;

public class HttpConnection {

	public String result = null;
	
public HttpConnection() throws Exception {	
String URL = "http://www.iheartquotes.com/api/v1/random?sources=codehappy+fortune+liberty+literature+murphy++math+alberteinstein+osho&max_lines=4&max_characters=120";
String URL1 = "http://www.notableandquotable.com/GetRandomQuoteNoHTML";
String URL3 = "http://api.adviceslip.com/advice";


HttpClient httpclient = new DefaultHttpClient();
    HttpResponse response = null;
	try {
		System.out.println(" ----- send the command");
		response = httpclient.execute(new HttpGet(URL));
	    StatusLine statusLine = response.getStatusLine();
	    if(statusLine.getStatusCode() == HttpStatus.SC_OK){
	    	ByteArrayOutputStream out = new ByteArrayOutputStream();
        	response.getEntity().writeTo(out);
			out.close();
		    String responseString = out.toString();
		    result = responseString;
		    System.out.print(responseString);
        //..more logic
	    } else {
        	response.getEntity().getContent().close();
	    }
	    
	} catch (ClientProtocolException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
		throw e;
	} catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
		throw e;
	}  catch (IllegalStateException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
		throw e;
	}
}

public String getString() {
	// TODO Auto-generated method stub
	return result;
}


}