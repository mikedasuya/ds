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
	
public HttpConnection() {	
String URL = "http://www.iheartquotes.com/api/v1/random";
String URL1 = "http://www.notableandquotable.com/GetRandomQuoteNoHTML";
String URL3 = "http://api.adviceslip.com/advice";
HttpClient httpclient = new DefaultHttpClient();
    HttpResponse response = null;
	try {
		System.out.println(" ----- send the command");
		response = httpclient.execute(new HttpGet(URL));
	} catch (ClientProtocolException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	} catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
    StatusLine statusLine = response.getStatusLine();
    if(statusLine.getStatusCode() == HttpStatus.SC_OK){
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        try {
			response.getEntity().writeTo(out);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        try {
			out.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        String responseString = out.toString();
        System.out.print(responseString);
        //..more logic
    } else{
        //Closes the connection.
        try {
			response.getEntity().getContent().close();
		} catch (IllegalStateException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        try {
			throw new IOException(statusLine.getReasonPhrase());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    }
}


}