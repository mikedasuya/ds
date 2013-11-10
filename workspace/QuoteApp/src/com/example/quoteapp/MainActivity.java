package com.example.quoteapp;

import com.example.quoteapp.common.CommonDefines;
import com.example.quoteapp.http.HttpConnection;
import com.example.quoteapp.service.DownloadService;
import com.example.quoteapp.service.interfaces.CallBack;
import com.example.quoteapp.service.interfaces.DownloadInterface;

import android.os.Bundle;
import android.os.Handler;
import android.os.IBinder;
import android.os.Message;
import android.os.RemoteException;
import android.annotation.SuppressLint;
import android.app.ActionBar;
import android.app.Activity;
import android.app.ProgressDialog;
import android.content.ComponentName;
import android.content.Intent;
import android.content.ServiceConnection;
import android.content.res.Configuration;
import android.graphics.Typeface;
import android.text.method.ScrollingMovementMethod;
import android.util.Log;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.widget.ProgressBar;
import android.widget.ShareActionProvider;
import android.widget.TextView;


public class MainActivity extends Activity {
	 private ProgressBar mProgress;
	 ProgressDialog pd;
	 TextView tx;
	 DownloadInterface remoteService = null;
	 private MenuItem menuItem;
	 ShareActionProvider mShareActionProvider;
	 Menu optionsMenu;
	 
	 @Override
	 public void onConfigurationChanged(Configuration newConfig) {
	     super.onConfigurationChanged(newConfig);
 
	 }
	 
    @SuppressLint("NewApi")
	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        tx = (TextView) findViewById(R.id.text_box);
        tx.setMovementMethod(new ScrollingMovementMethod());
     /*   Typeface face=Typeface.createFromAsset(getAssets(),
                "fonts/PhoenixScriptFLF.ttf");

        tx.setTypeface(face);*/
              
        ActionBar actionBar = getActionBar();
        actionBar.setDisplayOptions(ActionBar.DISPLAY_SHOW_HOME
            | ActionBar.DISPLAY_SHOW_TITLE | ActionBar.DISPLAY_SHOW_CUSTOM);
        //smProgress.show();
     // use this to start and trigger a service
        
        Intent i= new Intent(this, DownloadService.class);
        bindService(i, mConnection, this.BIND_AUTO_CREATE);
        //this.startService(i); 
       
    }
    @SuppressLint("NewApi")
	public void setRefreshActionButtonState(MenuItem refreshItem, final boolean refreshing) {
                    
    	if (refreshItem != null) {
    		if (refreshing) {
    			refreshItem.setActionView(R.layout.actionbar_indeterminate_progress);
            } else {
            		Log.d("quote", "----------set action null");
                    refreshItem.setActionView(null);
            }
        }
        
    }
    
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
      switch (item.getItemId()) {
      case R.id.action_refresh:
    	  setRefreshActionButtonState(item, true);
    	  fetchQuote();
        break;
      
      default:
        break;
      }

      return true;
    } 
    @SuppressLint("NewApi")
	@Override
    public boolean onCreateOptionsMenu(Menu menu) {
      optionsMenu = menu;
      MenuInflater inflater = getMenuInflater();
      inflater.inflate(R.menu.main, menu);
      MenuItem item = menu.findItem(R.id.menu_item_share);

      // Fetch and store ShareActionProvider
      mShareActionProvider = (ShareActionProvider) item.getActionProvider();
      mShareActionProvider.setShareIntent(getDefaultIntent());

      return true;
    }
    Handler handle = new Handler() {
    	public void handleMessage(Message msg) {
    		int res = (int) msg.arg1;
    		switch (res) {
    			
    			case CommonDefines.SUCCESS: {
    				handleResponseSuccess((String)msg.obj);
    			}
    			break;
    			case 2: {
    				handleError(CommonDefines.ERROR_CONNECTION_CODE);
    			}
    			break;
    			default: {
    				handleError(CommonDefines.ERROR_UNKNOWN);
    			}
       		} //switch case
    	}  //handle message;
    };
    
    private Intent getDefaultIntent() {
        Intent intent = new Intent(Intent.ACTION_SEND);
        intent.setType("text/plain");
        intent.putExtra(Intent.EXTRA_TEXT, tx.getText().toString());
        return intent;
    }
    void startProgress() {
    	 
    }
    
    
    void endProgress() {
		MainActivity.this.runOnUiThread(new Runnable() {
			public void run(){
				MenuItem item = optionsMenu.findItem(R.id.action_refresh);
				setRefreshActionButtonState(item, false);
 	
			}
		});

    }
    
    void handleError(int errorCode) {
    	endProgress();
    	if (errorCode == CommonDefines.ERROR_CONNECTION_CODE) {
    		MainActivity.this.runOnUiThread(new Runnable(){
			    public void run(){
			    	tx.setText(CommonDefines.ERROR_CONNECTION);
			    }
			});
    	} else if (errorCode == CommonDefines.ERROR_UNKNOWN) {
    		MainActivity.this.runOnUiThread(new Runnable(){
			    public void run(){
		    		tx.setText(CommonDefines.ERROR_UNKNOWN_TEXT);
					
			    }
			});
    	}
    }
    void fetchQuote() {
    	
    	String[] str = new String[2];
        try {
        		int result = remoteService.getQuote();
        	
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

    }
	
	@SuppressLint("NewApi")
	void handleResponseSuccess(final String str) {
		endProgress();
		if (str.isEmpty()) {
			handleError(CommonDefines.ERROR_EMPTY_STRING);
		} else {
			MainActivity.this.runOnUiThread(new Runnable(){
			    public void run() {
			    	tx.setText(str);
			        mShareActionProvider.setShareIntent(getDefaultIntent());
			    	
			    }
			});
		}

	}
    
    /** Defines callbacks for service binding, passed to bindService() */
    private ServiceConnection mConnection = new ServiceConnection() {

        @Override
        public void onServiceConnected(ComponentName className,
                IBinder service) {
            // We've bound to LocalService, cast the IBinder and get LocalService instance
        	remoteService = DownloadInterface.Stub.asInterface((IBinder)service);
        	try {
        		CallBackClient cb = new CallBackClient();
				remoteService.registerCallBack(cb);
			} catch (RemoteException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
           	fetchQuote();
        	
        	
        	            
        }

        @Override
        public void onServiceDisconnected(ComponentName arg0) {
        	
        }
    };
    
    @Override
    protected void onDestroy() {
    	super.onDestroy();
    	unbindService(mConnection);
    }
    
    class CallBackClient extends CallBack.Stub {

    	@Override
		public void onServerResponse(String result, int resultCode)
				throws RemoteException {
			// TODO Auto-generated method stub
    		Message msg = new Message();
    		msg.arg1 = resultCode;
    		msg.obj = result;
    		handle.sendMessage(msg);
    	}	
    	
    }
    
    
}
