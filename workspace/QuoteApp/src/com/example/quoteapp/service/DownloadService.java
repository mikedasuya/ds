package com.example.quoteapp.service;
import java.net.URL;

import com.example.quoteapp.common.CommonDefines;
import com.example.quoteapp.http.HttpConnection;
import com.example.quoteapp.service.interfaces.CallBack;
import com.example.quoteapp.service.interfaces.DownloadInterface;

import android.annotation.SuppressLint;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.net.ConnectivityManager;
import android.os.AsyncTask;
import android.os.Handler;
import android.os.IBinder;
import android.os.Message;
import android.os.RemoteException;


public class DownloadService extends Service {
	
	private CallBack callBack;
	Handler mHandler = new Handler() {
	 	public void handleMessage(Message msg) {
	 			try {
	 				String res = optimiseString((String) msg.obj);
					callBack.onServerResponse(res, msg.arg1);
				} catch (RemoteException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
	 		}
	 		
	 	};
	 	
	private String optimiseString(String input) {
		String res = null;
		String res2 = null;
		if (input == null || input.length() == 0) {
			return null;
		} else {
			
			String str3 = "&quot";
			if (input.contains(str3)) {
				res = input.replaceAll("&quot", "");
			} else {
				res = input;
			}
			if (res.contains("[")) {
				res2 = res.substring(0, res.indexOf("["));
				res = res2;
			}
		}
		return res;
	}
	
	private final DownloadInterface.Stub mBinder = new DownloadInterface.Stub() {
	    
	    
		@Override
		public int registerCallBack(CallBack cb) throws RemoteException {
			// TODO Auto-generated method stub
			callBack = cb;
			if (callBack == null) {
				System.out.println("\n ---quote -------------------1111---cb null");
			} else {
				System.out.println("\n ---quote -------------------1111---cb set");
			}
			
			return 0;
		}

		@Override
		public int getQuote() throws RemoteException {
			// TODO Auto-generated method stub
			new DownloadFilesTask(mHandler).execute("JUST");
			return 0;
		}
	};
	
  @Override
  public int onStartCommand(Intent intent, int flags, int startId) {
    //TODO do something useful
	 
	  

    return Service.START_NOT_STICKY;
  }

 
@Override
public IBinder onBind(Intent arg0) {
	// TODO Auto-generated method stub
	
	return mBinder;
}

boolean isConnectionAvailable() {
	final ConnectivityManager connMgr = (ConnectivityManager) this
            .getSystemService(Context.CONNECTIVITY_SERVICE);
	final android.net.NetworkInfo wifi = connMgr
            .getNetworkInfo(ConnectivityManager.TYPE_WIFI);
	final android.net.NetworkInfo mobile = connMgr
            .getNetworkInfo(ConnectivityManager.TYPE_MOBILE);
	if (wifi.isAvailable()) {
		return true;
    } else if (mobile.isAvailable()) {
        /*
         * check.setImageResource(R.drawable.tick);
         * check.setVisibility(View.VISIBLE); noInterntet.setText("");
         */
        return true;
    } else {
        return false;
    }
}

private class DownloadFilesTask extends AsyncTask<String, Void, String> {
	Handler mHandler;
	DownloadFilesTask(Handler handle) {
		mHandler = handle;
	}
   
    @SuppressLint("NewApi")
	@Override
    protected void onPostExecute(String result) {
    	Message msg = new Message();
    	if (result != null && !result.isEmpty()
    			&& !(result.compareTo(CommonDefines.ERROR_CONNECTION) == 0) ) {
    		msg.arg1 = CommonDefines.SUCCESS;
    		msg.obj = result;
    	} else if (result != null && result.compareTo(CommonDefines.ERROR_CONNECTION) == 0){
    		msg.arg1 = CommonDefines.ERROR_CONNECTION_CODE;
    		msg.obj = result;
    	} else if (result == null){
    		msg.arg1 = CommonDefines.ERROR_UNKNOWN;
    		msg.obj = result;
    	}  
    	mHandler.sendMessage(msg);
    }

	@Override
	protected String doInBackground(String... params) {
		// TODO Auto-generated method stub
		String result = null;
		if (isConnectionAvailable()) {
			HttpConnection conn;
			try {
				conn = new HttpConnection();
				result = conn.getString();
				System.out.println("Got the --------------rsult in service" + result);
			
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				//result = (String) CommonDefines.ERROR_UNKNOWN_TEXT;
			}
		} else {
			result = CommonDefines.ERROR_CONNECTION;
		}
		return result;
		
	}
}

} 